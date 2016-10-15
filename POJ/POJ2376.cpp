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

int solve(int N, int T, vector<PII> w){
  int ans = 0;

  sort(w.begin(), w.end());

  int e = 0, mx = 0;

  REP(i, 0, N){
    if(e < w[i].first && w[i].first <= mx + 1){
      ans++;
      e = mx + 1;
      if(mx < w[i].second){
        mx = w[i].second;
      }
    } else if(w[i].first <= e && w[i].second > mx){
      mx = w[i].second;
    } else if(w[i].first > mx + 1){
      ans = -1;
      break;
    }

    if(mx == T){
      break;
    }
  }

  if(mx != T){
    ans = -1;
  }

  return ans;
}

int main(){
  int N, T;

  cin >> N >> T;

  vector<PII> w_time(N);
  vector<PII> re_time(N);

  REP(i, 0, N){
    cin >> w_time[i].first >> w_time[i].second;
  }

  cout << solve(N, T, w_time) << endl;

  return 0;
}
