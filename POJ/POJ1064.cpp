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
  int N, K;
  scanf("%d %d%*c", &N, &K);

  vector<double> cable(N);
  REP(i, 0, N){
    scanf("%lf%*c", &cable[i]);
  }

  double lb = 0.00;
  double ub = INF;
  REP(j, 0, 100){
    double md = (lb + ub) / 2;
    int res = 0;
    REP(i, 0, N){
      res += (int)(cable[i] / md);
    }
    if(res >= K){
      lb = md;
    } else {
      ub = md;
    }
  }
  
  ub = floor((ub * 100)) / 100;
  printf("%.2lf\n", ub);

  return 0;
}
