#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
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
#define PI = 3.14159265358979323846
/*------------------------------------------------------------------------------*/

int main(){
  int N;
  scanf("%d\n", &N);

  int seq[100010] = {};
  REP(i, 0, N){
    int tmp;
    scanf("%d ", &tmp);
    seq[tmp]++;
  }

  int ans = 0;
  if((N % 2) == 0){
    ans = 1;
    REP(i, 0, N){
      if((i % 2 == 0) && seq[i] != 0){
        ans = 0;
      } else if((i % 2 == 1) && seq[i] != 2) {
        ans = 0;
      }
    }
  } else if(seq[0] == 1){
    ans = 1;
    REP(i, 1, N){
      if((i % 2 == 1) && seq[i] != 0){
        ans = 0;
      } else if((i % 2 == 0) && seq[i] != 2){
        ans = 0;
      }
    }
    ans = pow(ans, N / 2);
  } else {
    ans = 0;
  }
  int m = pow(10, 9) + 7;
  REP(i, 0, N/2){
    ans = (ans * 2) % m;
  }
  printf("%d\n", ans);

  return 0;
}
