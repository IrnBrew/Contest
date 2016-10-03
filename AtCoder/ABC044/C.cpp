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

int solve(int N, int A, VI v){
  int ans = 0;

  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N, vector<int>(N * A)));

  cout << dp.size() << " " << dp[0].size() << " " << dp[0][0].size() << endl;
  dp[1][0][0] = 1;
  cout << dp[1][0][0] << endl;
  REP(i, 0, N+1){
    REP(j, 0, N){
      REP(k, 0, N * A + 1){
        dp[1][0][0] = i;
        cout << i << j << k << endl;
        dp[i][j][k] = 0;
      }
    }
  }

  REP(i, 0, N+1){
    REP(j, 0, N){
      REP(k, 0, N * A + 1){
        if(i == 0 && j == 0 && k == 0){
          dp[0][0][0] = 1;
        } else if(v[i] > k && i > 0 && j > 0){
          cout << "1,i, j, k: " << i << " " << j << " " << k << endl;
          cout << "dp[i][j][k]: " << dp[i][j][k] << endl;
          dp[i][j][k] = dp[i][j-1][k];
        } else if(v[i] <= k && i > 0 && j > 0){
          cout << "2,i, j, k-v[i]: " << i << " " << j << " " << k-v[i] << endl;
          cout << dp[i-1][j-1][k-v[i]] << endl;
          cout << dp[i][j-1][k] << endl;
          dp[i][j][k] = dp[i][j-1][k] + dp[i-1][j-1][k-v[i]];
        } else {
          cout << "3,i, j, k: " << i << " " << j << " " << k << endl;
          dp[i][j][k] = 0;
        }
      }
    }
  }

  REP(i, 0, N){
    ans += dp[N][i][i*N];
  }

  return ans;
}

int main(){
  int N, A;

  cin >> N >> A;

  VI v(N);

  int i = 0;
  while(cin >> v[i]){
    i++;
  }

  int ans = solve(N, A, v);

  cout << ans << endl;

  return 0;
}
