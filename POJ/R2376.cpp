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

int solve(int N, int T, vector<PII> vp){
  int ans = 0;

  int e = 0, mx = 0;

  sort(vp.begin(), vp.end());

  REP(i, 0, N){
    if(mx + 1 < vp[i].first){
      ans = -1;
      break;
    } else if(mx + 1 >= vp[i].first && e + 1 < vp[i].first){
      ans++;
      e = mx;
      if(mx < vp[i].second){
        mx = vp[i].second;
      }
    } else if(vp[i].first <= e + 1 && vp[i].second > mx){
      mx = vp[i].second;
    }
    if(T == mx){
      ans++;
      break;
    }
  }
  if(T != mx){
    ans = -1;
  }

  return ans;
}

int main(){
  int N, T;

  cin >> N >> T;

  vector<PII> shifts(N);

  REP(i, 0, N){
    cin >> shifts[i].first >> shifts[i].second;
  }

  cout << solve(N, T, shifts) << endl;

  return 0;
}
