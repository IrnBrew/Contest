#include <algorithm>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
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

ll solve(ll N, vector<VL> v){
  ll ans = 0;

  vector<VL> s(N+1, VL(N+1));


  REP(i, 0, N){
    REP(j, 0, i+1){
      if(i == 0 && j == 0){
        s[0][0] = v[0][0];
      } else if(j == 0){
        s[i][j] = s[i-1][j] + v[i][j];
      } else if(j == i){
        s[i][j] = s[i-1][j-1] + v[i][j];
      } else {
        if(s[i-1][j-1] > s[i-1][j]){
          s[i][j] = s[i-1][j-1] + v[i][j];
        } else {
          s[i][j] = s[i-1][j] + v[i][j];
        }
      }
      cout << "s[" << i << "][" << j << "]: " << s[i][j] << endl;
    }
  }

  REP(i, 0, N){
    if(ans < s[N-1][i]){
      ans = s[N-1][i];
    }
  }
  
  return ans;
}

int main(){
  ll N, ans;
  cin >> N;

  vector<VL> v(N+1, VL(N+1));

  REP(i, 0, N+1){
    REP(j, 0, i){
      cin >> v[i-1][j];
    }
  }

  ans = solve(N, v);

  cout << ans << endl;
  
  return 0;
}
