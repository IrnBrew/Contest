#include <algorithm>
#include <cmath>
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
typedef pair<ll, ll> PLL;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, -1, 0, 1};

PII s;

int bfs(vector<vector<char> > f, int H, int W, int n, PII sp){
  int res = 0;
  vector<VI > cost(H, VI(W, INF));
  int ini_y = sp.fst, ini_x = sp.snd;
  cost[ini_y][ini_x] = 0;

  queue<pair<PII, int> > q;
  q.push(MP(MP(ini_y, ini_x), 0));

  while(!q.empty()){
    pair<PII, int> p = q.front();
    q.pop();
    int y = p.fst.fst, x = p.fst.snd, c = p.snd;
    if(f[y][x] == (char)('0' + n)){
      res = c;
      s.fst = y;
      s.snd = x;
      break;
    }
    REP(i, 0, 4){
      int ny = y + my[i], nx = x + mx[i];
      if(ny >= 0 && ny < H && nx >= 0 && nx < W &&
         f[ny][nx] != 'X' && cost[ny][nx] > c + 1){
        cost[ny][nx] = c + 1;
        q.push(MP(MP(ny,nx), c + 1));
      }
    }
  }

  return res;
}

int solve(vector<vector<char> > f, int H, int W, int N, PII p){
  int ans = 0;
  s = p;

  REP(i, 1, N+1){
    ans += bfs(f, H, W, i, s);
  }
  return ans;
}

int main(){
  int H, W, N;
  cin >> H >> W >> N;

  vector<vector<char> > f(H, vector<char>(W));
  int y, x;
  REP(i, 0, H){
    REP(j, 0, W){
      cin >> f[i][j];
      if(f[i][j] == 'S'){
        y = i;
        x = j;
      }
    }
  }

  cout << solve(f, H, W, N, MP(y, x)) << endl;
  return 0;
}
