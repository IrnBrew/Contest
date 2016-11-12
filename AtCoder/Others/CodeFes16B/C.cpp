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
#define fst first
#define snd second


using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/
bool comp(pair<pair<PII, PII>, int> a, pair<pair<PII, PII>, int> b){
  return a.snd < b.snd;
}

void init_union(map<PII, PII> &par, map<PII, int> &rank, int W, int H){
  REP(i, 0, W+1){
    REP(j, 0, H+1){
      par.insert({{i,j}, {i,j}});
      rank.insert({{i,j}, 0});
    }
  }
  return;
}

PII find(map<PII, PII> &par, PII k){
  if(par[k] == k){
    return k;
  } else {
    return par[k] = find(par, par[k]);
  }
}

bool same(map<PII, PII> &par, PII k1, PII k2){
  return find(par, k1) == find(par, k2);
}

void unite(map<PII, PII> &par, map<PII, int> &rank, PII k1, PII k2){
  PII x = find(par, k1);
  PII y = find(par, k2);
  if(x == y){
    return;
  }
  
  if(rank[x] < rank[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(rank[x] == rank[y]){
      rank[x]++;
    }
  }
  return;
}

ll solve(int W, int H, VL p, VL q){
  ll ans = 0;

  vector<pair<pair<PII, PII>, int>> es(0);

  REP(i, 0, W+1){
    REP(j, 0, H+1){
      if(i < W){
        es.push_back({{{i, j}, {i+1, j}}, p[i]});
      }
      if(j < H){
        es.push_back({{{i, j}, {i, j+1}}, q[j]});
      }
    }
  }

  sort(es.begin(), es.end(), comp);//sort es

  map<PII, PII> par;
  map<PII, int> rank;
  init_union(par, rank, W, H);
  REP(i, 0, es.size()){
    if(!same(par, es[i].fst.fst, es[i].fst.snd)){
      unite(par, rank, es[i].fst.fst, es[i].fst.snd);
      ans += es[i].snd;
    }
  }

  return ans;
}

int main(){
  int W, H;
  cin >> W >> H;

  VL p(W);
  VL q(H);

  REP(i, 0, W){
    cin >> p[i];
  }
  REP(i,0,H){
    cin >> q[i];
  }

  ll ans = solve(W, H, p, q);

  cout << ans << endl;
  return 0;
}
