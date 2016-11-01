#include <algorithm>
#include <climits>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
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
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;
#define MP make_pair //incase c++11 or later is not available

/*------------------------------------------------------------------------------*/
bool comp(pair<PII, int> a, pair<PII, int> b){
  return a.snd < b.snd;
}

int par[101];
int rnk[101];

void init_union(int N){
  REP(i, 0, N){
    par[i] = i;
    rnk[i] = 0;
  }
  return;
}

int find(int a){
  if(par[a] == a){
    return a;
  } else {
    return par[a] = find(par[a]);
  }
}

void unite(int a, int b){
  int x = find(a);
  int y = find(b);

  if(x == y){
    return;
  } else if(rnk[x] < rnk[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(rnk[x] == rnk[y]){
      rnk[x]++;
    }
  }

  return;
}

bool same(int a, int b){
  return find(a) == find(b);
}

int solve(int N, vector<pair<PII, int> > es){
  int ans = 0;

  sort(es.begin(), es.end(), comp);
  init_union(N+1);
  REP(i, 0, es.size()){
    int u = es[i].fst.fst;
    int v = es[i].fst.snd;
    int c = es[i].snd;
    if(!same(u, v)){
      unite(u, v);
      ans += c;
    }
  }

  return ans;
}

// void pr(pair<PII, int> e){
//   cout << "u->v: " << e.fst.fst << "->" << e.fst.snd << " cost: " << e.snd << endl; 
// }

int main(){

  int N;
  while(cin>>N){

    vector<pair<PII, int> > es(0);
    REP(i, 1, N+1){
      REP(j, 1, N+1){
        if(i != j){
          int tmp;
          cin >> tmp;
          es.push_back(MP(MP(i, j), tmp));
          //pr(es.back());
        } else {
          int tmp;
          cin >> tmp;
        }
      }
    }
    cout << solve(N, es) << endl;
  }

  return 0;
}
