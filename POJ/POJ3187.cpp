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
  int N, sum;
  scanf("%d %d", &N, &sum);

  VI v(N);
  REP(i, 0, N){
    v[i] = i + 1;
  }

  VI res(N, 0);
  REP(i, 0, N){
    VI sim(N, 0);
    sim[i] = 1;
    int cnt = N;
    while(cnt > 1){
      REP(i, 1, cnt){
        sim[i-1] = sim[i] + sim[i-1];
      }
    cnt--;
    }
    res[i] = sim[0];
  }

  do{
    int acm = 0;
    REP(i, 0, N){
      acm += v[i] * res[i];
    }
    if(acm == sum){
      REP(i, 0, v.size()){
        printf("%d ", v[i]);
      }
      puts("");
      break;
    }
  } while(next_permutation(v.begin(), v.end()));

  return 0;
}
