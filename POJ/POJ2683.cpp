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
  int m;
  cin >> m;

  REP(i, 0, m){
    ll b, y, n;
    cin >> b; cin >> y; cin >> n;
    //cout << b << " " << y << " " << n << endl;
    vector<pair<int, double> > o(n);
    VI c(n);
    REP(j, 0, n){
      int s;
      double f;
      int m;
      cin >> s >> f >> m;
      o[j] = MP(s, f);
      c[j] = m;
      //cout << o[i].fst << " " << setprecision(20) << o[i].snd << " " << c[i] << endl;
    }
    ll ans = 0;
    REP(j, 0, n){
      pair<int, double> t = o[j];
      if(t.fst == 0){
        ll f1 = b;
        ll cum = 0;
        REP(k, 0, y){
          //cout << "product " << f1 * t.snd << endl;
          cum += (ll)(f1 * t.snd);
          f1 -= c[j];
          //cout << cum << endl;
        }
        ans = max(ans, f1 + cum);
      } else {
        ll f2 = b;
        REP(k, 0, y){
          f2 += (ll)(f2 * t.snd);
          f2 -= c[j];
          //cout << f2 << endl;
        }
        ans = max(ans, f2);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
