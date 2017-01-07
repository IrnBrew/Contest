#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdio>
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
typedef pair<ll, ll> PLL;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;
#define PI = 3.14159265358979323846
/*------------------------------------------------------------------------------*/

typedef struct{
  int u, v, c;
} edge;

int main(){
  int V, M;
  scanf("%d %d\n", &V, &M);

  vector<VI> g(V, VI(V, INF));
  vector<edge> es;
  REP(i, 0, M){
    int a, b, cost;
    scanf("%d %d %d\n", &a, &b, &cost);
    g[a-1][b-1] = cost;
    g[b-1][a-1] = cost;
    edge e;
    e.u = a-1; e.v = b-1; e.c = cost;
    es.push_back(e);
  }

  REP(i, 0, V){
    g[i][i] = 0;
  }

  REP(k, 0, V){
    REP(i, 0, V){
      REP(j, 0, V){
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  int ans = 0;
  for(auto i = es.begin(); i != es.end(); i++){
    if(g[i->u][i->v] < i->c){
      ans++;
    }
  }
  printf("%d\n", ans);

  return 0;
}
