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
#include <unordered_map>
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

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

bool solve(int N, vector<pair<PII, int> > es){
  bool ans = false;

  REP(i, 1, N+1){
    VI d(N+1, INF);
    d[i] = 0;
    int cnt = 0;
    while(1){
      bool update = false;
      if(cnt == N){
        if(d[i] < 0){
          ans = true;
          goto ANS;
        }
        break;
      }
      cnt++;

      REP(j, 0, es.size()){
        pair<PII, int> e = es[j];
        int u = e.fst.fst;
        int v = e.fst.snd;
        int cost = e.snd;
        if(d[u] != INF && d[v] > d[u] + cost){
          update = true;
          d[v] = d[u] + cost;
        }
      }
      if(!update){
        break;
      }
    }
  }
 ANS:
  return ans;
}

int main(){
  int F;

  cin >> F;

  REP(i, 0, F){
    int N, M, W;

    cin >> N >> M >> W;
    vector<pair<PII, int> > es(0);

    REP(i, 0, M){
      int a, b, c;
      cin >> a >> b >> c;
      es.push_back(MP(MP(a, b), c));
      es.push_back(MP(MP(b, a), c));
    }
    REP(i, 0, W){
      int a, b, c;
      cin >> a >> b >> c;
      es.push_back(MP(MP(a,b), -c));
    }
    if(solve(N, es)){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
