#include <algorithm>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <stack>
#include <string>
#include <vector>

#define INF INT_MAX/3

#define REP(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;

ll solve(ll N, ll K, ll X, ll Y){
  ll ans = 0;

  REP(i, 0, N){
    if(i < K){
      ans += X;
    } else {
      ans += Y;
    }
  }
  
  return ans;
}

int main(){
  ll ans = 0, N, K, X, Y;
  cin >> N >> K >> X >> Y;

  ans = solve(N, K, X, Y);

  cout << ans << endl;

  return 0;
}
