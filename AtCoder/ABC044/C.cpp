#define _GLIBCXX_DEBUG

#include <algorithm>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <stack>
#include <string>
#include <vector>

#define INF (INT_MAX/3)

#define REP(i,s,n) for(int i = (int)(s); i < (int)(n); i++)

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;

ll solve(int N, int A, VI v){
  ll ans = 0;

  vector<vector<VL>> dp(N+1, vector<VL>(N+1, VL(N * A + 1)));

  REP(i, 0, N+1){
    REP(j, 0, N+1){
      REP(k, 0, N * A + 1){
        if(j == 0 && k == 0){
          dp[i][0][0] = 1;
        } else if(v[i] > k && j > 0){
          dp[i][j][k] = dp[i-1][j][k];
        } else if(v[i] <= k && i > 0 && j > 0){
          dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-v[i]];
        } else {
          dp[i][j][k] = 0;
        }
      }
    }
  }
  
  REP(i, 1, N+1){
    ans += dp[N][i][i*A];
  }

  return ans;
}

int main(){
  int N, A;

  cin >> N >> A;

  VI v(N+1);
  v[0] = 0;

  // int i = 1;
  // while(cin >> v[i]){
  //   i++;
  // }
  REP(i, 1, N+1){
    cin >> v[i];
  }

  ll ans = solve(N, A, v);

  cout << ans << endl;

  return 0;
}
