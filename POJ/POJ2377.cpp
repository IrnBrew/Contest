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

int u_f[1001];
int rnk[1001];

void union_init(int N){
  REP(i, 1, N+1){
    u_f[i] = i;
    rnk[i] = 0;
  }
  return;
}

int find(int i){
  if(u_f[i] == i){
    return i;
  }
  return u_f[i] = find(u_f[i]);
}

void unite(int a, int b){
  int x = find(a);
  int y = find(b);

  if(x == y){
    return;
  }
  if(rnk[x] > rnk[y]){
    u_f[y] = x;
  } else {
    u_f[x] = y;
    if(rnk[x] == rnk[y]){
      rnk[y]++;
    }
  }
  return;
}

bool same(int a, int b){
  return find(u_f[a]) == find(u_f[b]);
}

bool comp(pair<PII, int> a, pair<PII, int> b){
  return a.snd > b.snd;
}

int main(){
  int N, M;
  scanf("%d %d\n", &N, &M);

  vector<pair<PII, int> > v;
  REP(i, 0, M){
    int a, b, c;
    scanf("%d %d %d\n", &a, &b, &c);
    v.push_back(MP(MP(a, b), c));
  }
  sort(v.begin(), v.end(), comp);

  union_init(N);
  ll cost = 0;
  int cnt = 0;
  REP(i, 0, M){
    PII e = v[i].fst;
    if(!same(e.fst, e.snd)){
      cost += v[i].snd;
      unite(e.fst, e.snd);
      cnt++;
    }
  }
  if(cnt == N - 1){
    printf("%lld\n", cost);
  } else{
    printf("-1\n");
  }
  return 0;
}
