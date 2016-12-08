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
int par[200100];
int rnk[200100];

void init(int n){
  REP(i, 0, n){
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y){
    return;
  }

  if(rnk[x] < rnk[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(rnk[x] == rnk[y]){
      rnk[x]++;
    }
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

int main(){
  int T, N, M;
  scanf("%d\n", &T);
  REP(i, 0, T){
    scanf("%d%d\n", &N, &M);
    init(N * 2 + 10);
    REP(j, 0, M){
      char c;
      int a, b;
      scanf("%c %d %d\n", & c, &a, &b);
      if(c == 'A'){
        if(same(a * 2, b * 2)){
          printf("In the same gang.\n");
        } else if(same(a * 2, b * 2 + 1)){
          printf("In different gangs.\n");
        } else {
          printf("Not sure yet.\n");
        }
      } else {
        unite(a * 2, b * 2 + 1);
        unite(a * 2 + 1, b * 2);
      }
    }
  }
  return 0;
}
