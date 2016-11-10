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
  int Z;
  cin >> Z;
  REP(i, 0, Z){
    int M, H;
    cin >> M;
    cin >> H;
    vector<PLL> v(H);
    REP(i, 0, v.size()){
      cin >> v[i].fst >> v[i].snd;
    }
    ll ans = 0;
    REP(j, 0, v.size()){
      ll pa = v[j].fst % M, b = v[j].snd, res = 1;
      for(ll j = b; j > 0; j = j >> 1, pa = (pa * pa) % M){
        if(j & 0x1){
          res = (res * pa) % M;
        }
      }
      ans = (ans + res) % M;
    }
    cout << ans << endl;
  }

  return 0;
}
