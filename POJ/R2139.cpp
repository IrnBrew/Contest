#include <algorithm>
#include <climits>
#include <cstring> //memset
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
#include <set>
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
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int solve(int N, vector<set<int> > ss) {
  VI m(N+1, 0);

  int d[301][301];
  //memset(d[0], 0x3f, sizeof(d));
  fill(d[0], d[301], INF);
  REP(i, 1, N+1){
    REP(j, 1, N+1){
      if(i == j){
        d[i][j] = 0;
      } else if(ss[i].find(j) != ss[i].end()){
        d[i][j] = 1;
      }
      //cout << i << ":" << j << " " << d[i][j] << endl;
    }
  }
  REP(i, 1, N+1) {
    REP(j, 1, N+1){
      REP(k, 1, N+1){
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }

  REP(i, 1, N+1){
    REP(j, 1, N+1){
      //cout << "v:" << i << " d[" << j << "]: " << d[i][j] << endl;
      m[i] += d[i][j];
    }
    m[i] = (int)((double)m[i] * 100 / (double)(N-1));
  }

  int ans = INF;

  REP(i, 1, N+1){
    //cout << "m[" << i << "]: " << m[i] << endl;
    if(ans > m[i]){
      ans = m[i];
    }
  }

  return ans;
}

int main() {
  int N, M;

  cin >> N >> M;

  vector<set<int> > ss(N+1);

  REP(i, 0, M){
    int tmp;
    cin >> tmp;
    VI es(tmp);

    REP(j, 0, tmp) {
      cin >> es[j];
    }
    REP(j, 0, tmp){
      REP(k, j+1, tmp){
        ss[es[j]].insert(es[k]);
        ss[es[k]].insert(es[j]);
      }
    }
  }

  cout << solve(N, ss) << endl;
  // REP(i, 1, N+1){
  //   for(set<int>::iterator ite = ss[i].begin(); ite != ss[i].end(); ite++){
  //     cout << i << ":" << *ite << endl;
  //   }
  // }

  return 0;
}
