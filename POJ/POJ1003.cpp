#include <algorithm>
#include <climits>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
#include <set>
#include <stack>
#include <string>
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

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int main(){
  map<int, double> mem;
  mem[0] = 0;
  REP(i, 1, 301){
    double tmp = 1.0 / (i + 1.0);
    mem[i] = mem[i-1] + tmp;
    //cout << i << ":" << mem[i] << endl;
  }
  while(1){
    double d;
    cin >> d;
    if(d == 0.00){
      break;
    }
    int ub = 300;
    int lb = 0;
    while(ub - lb > 1){
      int b = (ub + lb) / 2;
      double s = mem[b];
      if(s < d){
        lb = b;
      } else {
        ub = b;
      }
    }
    cout << ub << " card(s)" << endl;
  }

  return 0;
}
