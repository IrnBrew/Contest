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

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/
int par[1002];
int rnk[1002];

int find(int n){
  if(n == par[n]){
    return n;
  } else {
    return par[n] = find(par[n]);
  }
}

void unite(int n1, int n2){
  int x = find(n1);
  int y = find(n2);

  if(x == y){
    return;
  } if(rnk[x] < rnk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if(rnk[x] == rnk[y]){
      rnk[x]++;
    }
  }
  return;
}

bool same(int n1, int n2){
  return find(n1) == find(n2);
}

int dist_sqr(PII v1, PII v2){
  return abs((v1.fst - v2.fst) * (v1.fst - v2.fst) + (v1.snd - v2.snd) *  (v1.snd - v2.snd));
}

void solve(int N, int d, vector<PII> vs){
  VI f(N+1, 0);
  REP(i, 1, N+1){
    par[i] = i;
    rnk[i] = 0;
  }
  char o;
  while(cin >> o){
    if(o == 'O'){
      int n;
      cin >> n;
      f[n] = 1;
      REP(i, 1, N+1){
        if(i != n && f[i] == 1 && dist_sqr(vs[i], vs[n]) <= d * d){
          unite(n, i);
        }
      }
    } else {
      int n1, n2;
      cin >> n1 >> n2;
      if(same(n1, n2)){
        cout << "SUCCESS" << endl;
      } else {
        cout << "FAIL" << endl;
      }
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  int N, d;
  cin >> N >> d;

  vector<PII> vs(N+1);

  REP(i, 1, N+1){
    int x, y;
    cin >> x >> y;
    vs[i] = MP(x, y);
  }

  solve(N, d, vs);

  return 0;
}
