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

/*------------------------------------------------------------------------------*/

int main(){
  ll N, x;
  scanf("%lld %lld\n", &N, &x);

  VL v(N);
  REP(i, 0, N){
    scanf("%lld ", &v[i]);
  }

  ll lb = 0, ub = pow(10, 18) + 2;
  while(ub - lb > 1){
    VL seq = v;
    ll used = 0;
    ll mid = (lb + ub) / 2;

    REP(i, 0, N-1){
      if(seq[i] + seq[i+1] > x){
        int sub = (seq[i] + seq[i+1]) - x;
        used += sub;
        if(seq[i+1] >= sub){
          seq[i+1] -= sub;
        } else {
          sub -= seq[i+1];
          seq[i+1] = 0;
          seq[i] -= sub;
        }
      }
    }
    if(used >= mid){
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%lld\n", lb);

  return 0;
}
