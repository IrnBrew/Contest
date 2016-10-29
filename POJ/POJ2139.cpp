#include <algorithm>
#include <climits>
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

  REP(i, 1, N+1) {
    VI d(N+1, INF);
    VI used(N+1, 0);
    d[i] = 0;
    while(1){
      int v = -1;
      REP(j, 1, N+1){
        if(used[j] != 1 && (v == -1 || d[v] > d[j])){
          v = j;
        }
      }
      if(v == -1){
        break;
      }
      used[v] = 1;

      for(set<int>::iterator ite = ss[v].begin(); ite != ss[v].end(); ite++){
        if(*ite != v && d[*ite] > d[v] + 1){
          d[*ite] = d[v] + 1;
        }
      }
    }
    REP(j, 1, N+1){
      //cout << "v:" << i << " d[" << j << "]: " << d[j] << endl;
      m[i] += d[j];
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
