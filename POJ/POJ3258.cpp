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
  ll L, N, M;
  scanf("%lld %lld %lld\n", &L, &N, &M);

  VL seq;
  REP(i, 0, N){
    ll tmp;
    scanf("%lld\n", &tmp);
    seq.push_back(tmp);
  }

  sort(seq.begin(), seq.end());

  ll lb = 1, ub = pow(10, 10);
  while(ub - lb > 1){
    ll mid = (ub + lb) / 2;
    ll base = 0;
    int cnt = 0;
    REP(i, 0, N){
      if(seq[i] - base >= mid){
        base = seq[i];
      } else {
        cnt++;
        if(cnt > M){
          break;
        }
      }
    }
    if(L - base < mid){
      cnt++;
    }
    if(cnt > M){
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%lld\n", lb);

  return 0;
}
