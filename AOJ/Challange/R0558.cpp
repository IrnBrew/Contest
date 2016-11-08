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

PII s;

int bfs(const vector<string>& f, int H, int W, int N, PII sp){
  int res = 0;
  int n = 1;
  vector<VI> cost(H, VI(W, INF));
  const vector<VI> init(H, VI(W, INF));
  int ini_y = sp.fst, ini_x = sp.snd;
  cost[ini_y][ini_x] = 0;

  queue<PII> q;
  q.push(MP(ini_y, ini_x));

  int mx[4] = {-1, 0, 1, 0};
  int my[4] = {0, -1, 0, 1};

  while(!q.empty()){
    PII p = q.front();
    q.pop();
    int y = p.fst, x = p.snd;
    if(f[y][x] == (char)('0' + n)){
      res += cost[y][x];
      while(!q.empty()){
        q.pop();
      }
      q.push({y, x});
      cost.assign(init.begin(), init.end());
      cost[y][x] = 0;
      n++;
      if(n == N+1){
        break;
      }
    }
    REP(i, 0, 4){
      int ny = y + my[i], nx = x + mx[i];
      if(f[ny][nx] != 'X' && cost[ny][nx] > cost[y][x] + 1){
        cost[ny][nx] = cost[y][x] + 1;
        q.push({ny,nx});
      }
    }
  }

  return res;
}

int main(){
  int H, W, N;
  cin >> H >> W >> N;

  vector<string> f;
  f.push_back(string(W+2, 'X'));
  REP(i, 0, H){
    string tmp;
    cin >> tmp;
    f.push_back('X' + tmp + 'X');
  }
  f.push_back(string(W+2, 'X'));

  REP(i, 0, f.size()){
    cout << f[i] << endl;
  }

  int y, x;
  REP(i, 1, H+1){
    REP(j, 1, W+1){
      if(f[i][j] == 'S'){
        y = i;
        x = j;
      }
    }
  }

  cout << bfs(f, H+2, W+2, N, {y, x}) << endl;
  return 0;
}
