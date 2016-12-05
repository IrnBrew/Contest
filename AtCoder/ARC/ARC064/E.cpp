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

/*------------------------------------------------------------------------------*/

double dist(PLL f, PLL t){
  return sqrt((f.fst - t.fst) * (f.fst - t.fst) + (f.snd - t.snd) * (f.snd - t.snd));
}

int main(){
  PLL st, ed;
  scanf("%lld %lld %lld %lld\n", &st.fst, &st.snd, &ed.fst, &ed.snd);

  int N;
  scanf("%d\n", &N);

  vector<PLL> vs;
  VL rs;
  vs.push_back(st);
  rs.push_back(0);
  REP(i, 0, N){
    PLL a;
    ll c;
    scanf("%lld %lld %lld\n", &a.fst, &a.snd, &c);
    vs.push_back(a);
    rs.push_back(c);
  }
  vs.push_back(ed);
  rs.push_back(0);

  double es[1002][1002];
  REP(i, 0, N + 1){
    REP(j, i, N + 2){
      if(i == j){
        es[i][j] = 0;
      } else {
        es[i][j] = es[j][i] = max(0.0, dist(vs[i], vs[j]) - rs[i] - rs[j]);
      }
    }
  }

  bool used[1002] = {false};
  double d[1002];
  fill_n(d, 1002, pow(10, 19));
  d[0] = 0;

  REP(i, 0, N + 2){
    int v = -1;
    REP(j, 0, N+2){
      if(!used[j] && (v == -1 || d[v] > d[j])){
        v = j;
      }
    }
    if(v == -1){
      break;
    }
    used[v] = true;
    REP(i, 0, N + 2){
      d[i] = min(d[i], d[v] + es[v][i]);
    }
  }
  printf("%.10lf\n", d[N+1]);
  return 0;
}
