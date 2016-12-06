#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
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
  int T, W;
  scanf("%d %d", &T, &W);

  VI aps;
  int pos = 0;
  int cnt = 0;
  REP(i, 0, T){
    int tmp;
    scanf("%d", &tmp);
    if(pos != tmp - 1){
      aps.push_back(cnt);
      pos = (pos + 1) % 2;
      cnt = 0;
      cnt++;
    } else {
      cnt++;
    }
  }
  if(cnt > 1){
    aps.push_back(cnt);
  }

  vector<VI > dp(W+1, VI(aps.size()+1, 0));
  REP(i, 0, W+1){
    REP(j, 1, aps.size()+1){
      if((j+1) % 2 == i % 2 && i == 0){
        dp[i][j] = max(dp[i][j-1] + aps[j-1], dp[i][j-1] + aps[j-1]);
      } else if((j+1) % 2 == i % 2 && i > 0){
        dp[i][j] = max(dp[i][j-1] + aps[j-1], dp[i-1][j-1] + aps[j-1]);
      } else {
        dp[i][j] = dp[i][j-1];
      }
    }
  }
  int mx = -1;
  REP(i, 0, W+1){
    if(mx < dp[i][aps.size()]){
      mx = dp[i][aps.size()];
    }
  }
  printf("%d\n", mx);
  return 0;
}
