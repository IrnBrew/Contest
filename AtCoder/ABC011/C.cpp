#include <algorithm>
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

void solve(int N, int ng[]){
  vector<vector<bool>> dp(101, vector<bool>(N+1, false));

  dp[0][0] = true;

  REP(i, 1, 101){
    REP(j, 0, N+1){
      if((j != ng[0] && j != ng[1] && j != ng[2]) &&
         ((j > 0 && dp[i-1][j-1]) ||
          (j > 1 && dp[i-1][j-2]) ||
          (j > 2 && dp[i-1][j-3]) ||
          dp[i-1][j])){
        dp[i][j] = true;
      }
      // cout << dp[i][j] << " ";
    }
    // cout << endl;
  }

  bool flag = false;

  REP(i, 0, 101){
    if(dp[i][N] == true){
      cout << "YES" << endl;
      flag = true;
      // cout << i << ":" << N << " " << dp[i][N] << endl;
      break;
    }
  }

  if(flag != true){
    cout << "NO" << endl;
  }

  return;
}

int main(){
  int N, ng[3];

  cin >> N >> ng[0] >> ng[1] >> ng[2];

  solve(N, ng);

  return 0;
}
