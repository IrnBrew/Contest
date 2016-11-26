#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
#include <set>
#include <stack>
#include <string>
//#include <unordered_map>
#include <vector>

#define REP(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define fst first
#define snd second
#define MP make_pair //incase c++11 or later is not available

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int main(){
  int data, N, S;
  scanf("%d\n", &data);

  REP(i, 0, data){
    scanf("%d %d\n", &N, &S);
    VI seq(N);

    REP(i, 0, N){
      scanf("%d ", &seq[i]);
    }

    int sum = 0;
    sum += seq[0];
    int head = 1, tail = 0, ans = INF;

    while(tail < (int)seq.size()){
      if((sum >= S && tail < head) || head >= (int)seq.size()){
        if(sum >= S){
          ans = min(ans, head-tail);
        }
        sum -= seq[tail];
        tail++;
      } else {
        sum += seq[head];
        head++;
      }
    }

    if(ans == INF){
      printf("0\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
