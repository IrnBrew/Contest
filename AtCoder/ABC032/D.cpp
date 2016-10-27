#include <algorithm>
#include <climits>
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
#define LINF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/
// N <= 30
ll solve(int N, ll lim, VL V, VL W){
  ll ans = 0;
  int a = N / 2;
  int b = N - a;

  VL V1(0);
  VL W1(0);
  VL V2(0);
  VL W2(0);

  REP(i, 0, a) {
    REP(j, i+1, a) {
      V1.push_back(V[i]+V[j]);
      W1.push_back(W[i]+W[j]);
    }
  }

  REP(i, 0, b) {
    REP(j, i+1, b) {
      V2.push_back(V[a+i]+V[a+j]);
      W2.push_back(W[a+i]+W[a+j]);
    }
  }

  VL VV(0);
  VL WW(0);

  REP(i, 0, V1.size()){
    REP(j, 0, V2.size()){
      VV.push_back(V1[i]+V2[j]);
      WW.push_back(W1[i]+W2[j]);
    }
  }

  REP(i, 0, VV.size()){
    if(VV[i] > ans && WW[i] <= lim){
      ans = VV[i];
    }
  }
  
  return ans;
}

// lim <= 1000
ll solve1(int N, ll lim, VL V, VL W, int maxW) {

  vector<VL> dp(N+1, VL(maxW+1));

  REP(i, 0, N+1){
    REP(j, 0, lim+1){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      } else if(W[i] <= j && V[i] + dp[i-1][j-W[i]] > dp[i-1][j]) {
        dp[i][j] = V[i] + dp[i-1][j-W[i]];
      } else {
        dp[i][j] = dp[i-1][j];
      }
      //cout << i << ":" << j << " " << dp[i][j] << " ";
    }
    //cout << endl;
  }

  return dp[N][lim];
}

// V <= 1000
ll solve2(int N, ll lim, VL V, VL W, int maxV){

  vector<VL> dp(N+1, VL(maxV+1, INF * 3));

  dp[0][0] = 0;

  REP(i, 0, N+1){
    REP(j, 0, maxV+1){
      if(i == 0){
        continue;
      } else if(j == 0) {
        dp[i][j] = 0;
      } else if(V[i] <= j && W[i] + dp[i-1][j-V[i]] < dp[i-1][j]
                && W[i] + dp[i-1][j-V[i]] <= lim) {
        dp[i][j] = W[i] + dp[i-1][j-V[i]];
      } else {
        dp[i][j] = dp[i-1][j];
      }
      //cout << i << ":" << j << " " << dp[i][j] << " ";
    }
    //cout << endl;
  }

  ll ans = 0;

  REP(i, 0, maxV){
    if(dp[N][i] <= lim){
      ans = i;
    }
  }

  return ans;
}

int main(){
  int N;
  ll lim;

  cin >> N >> lim;

  VL V(N+1), W(N+1);

  bool flag = true;

  REP(i, 1, N+1){
    cin >> V[i] >> W[i];
    if(W[i] > 1000){
      flag = false;
    }
  }

  if(N <= 30){
    cout << solve(N, lim, V, W) << endl;
  } else if(flag){//W[i] <= 1000
    int maxW = 0;
    REP(i, 0, N){
      maxW += W[i];
    }
    cout << solve1(N, lim, V, W, maxW) << endl;
  } else {//V[i] <= 1000
    int maxV = 0;
    REP(i, 0, N){
      maxV += V[i];
    }
    cout << solve2(N, lim, V, W, maxV) << endl;
  }

  return 0;
}
