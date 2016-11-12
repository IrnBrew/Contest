#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define REP(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int main(){
  int N;

  cin >> N;

  vector<pair<ll, ll>> vp(N);

  REP(i, 0, N){
    cin >> vp[i].first >> vp[i].second;
  }

  ll a, b;
  a = vp[0].first;
  b = vp[0].second;

  REP(i, 1, N){
    ll x, y;

    // x = (ll)ceil((double)a / (double)vp[i].first);
    // y = (ll)ceil((double)b / (double)vp[i].second);

    x = a / vp[i].first;
    if(a % vp[i].first != 0){
      x++;
    }

    y = b / vp[i].second;
    if(b % vp[i].second != 0){
      y++;
    }

    if(x < y){
      x = y;
    }
    a = vp[i].first * x;
    b = vp[i].second * x;
  }
  ll ans = a + b;

  cout << ans << endl;

  return 0;
}
