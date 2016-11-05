#include <algorithm>
#include <cmath>
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

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

double arc(double c, double r){
  double ac = acos(c / r);

  return r * sin(ac) * 2;
}

double solve(double R, int N, int M){
  double ans = 0;

  REP(i, 1, N+M){
    if(i - M < 1){
      double cut = abs(R - (double)((2 * R / N) * i));
      //cout << "cut1 " << cut << endl;

      double tmp = arc(cut, R);
      //cout << "ans " << tmp << endl;
      ans += tmp;
    } else if(i >= N){
      double cut = abs(R - (double)((2 * R / N) * (i - M)));
      //cout << "cut2 " << cut << endl;

      double tmp = arc(cut, R);
      //cout << "ans " << tmp << endl;
      ans += tmp;
    } else {
      double cut1 = abs(R - (double)((2 * R / N) * (i - M)));
      double cut2 = abs(R - (double)((2 * R / N) * i));
      //cout << "cut1e " << cut1 << endl;
      //cout << "cut2e " << cut2 << endl;

      double tmp = max(arc(cut1, R), arc(cut2,R));
      //cout << "ans " << tmp << endl;
      ans += tmp;
    }
    //cout << "---------------------" << endl;
  }
  return ans;
}

int main(){
  double R;
  int N, M;

  cin >> R >> N >> M;

  cout << fixed << setprecision(8) << solve(R, N ,M) << endl;
  
  return 0;
}
