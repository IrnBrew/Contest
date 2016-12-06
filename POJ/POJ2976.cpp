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
  while(1){
    int n, k;
    scanf("%d %d", &n, &k);
    if(n == 0 && k == 0){
      break;
    }
    VL as(n);
    VL bs(n);
    vector<double> ws(n);
    REP(i, 0, n){
      scanf("%lld ", &as[i]);
    }
    REP(i, 0, n){
      scanf("%lld ", &bs[i]);
    }
    double lb = 0, ub = 100;
    while(ub - lb >= 0.00001){
      double mid = (lb + ub) / 2;
      //double m = (double)mid / 100;
      REP(i, 0, n){
        ws[i] = 100 * as[i] - mid * bs[i];
      }
      sort(ws.begin(), ws.end());
      double ca = 0;
      REP(i, k, n){
        ca += ws[i];
      }
      if(ca >= 0){
        lb = mid;
      } else {
        ub = mid;
      }
    }
    printf("%d\n", (int)(lb + 0.5));
  }

  return 0;
}
