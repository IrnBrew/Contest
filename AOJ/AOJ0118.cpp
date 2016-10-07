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

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<ll> VL;
typedef pair<int, int> PII;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};

void dfs(char c, int u, int v, int W, int H, vector<vector<char>> &p){
  p[u][v] = '.';
  REP(i, 0, 4){
    int nx, ny;
    nx = u + x[i];
    ny = v + y[i];
    if(nx > 0 && ny > 0 && nx <= W && ny <= H && c == p[nx][ny]){
      dfs(c, nx, ny, W, H, p);
    }
  }
 return;
}

int solve(int H, int W, vector<vector<char>> p){
  int ans = 0;
  REP(i, 1, W+1){
    REP(j, 1, H+1){
      if(p[i][j] != '.'){
        ans++;
        char c = p[i][j];
        dfs(c, i, j, W, H, p);
      }
    }
  }
  return ans;
}

int main(){
  int H, W;

  while(1){
    cin >> H >> W;

    if(H == 0 && W == 0){
      break;
    }
    vector<vector<char>> p(W+1, vector<char>(H+1));//p[x][y] (x, y)

    REP(i, 1, W+1){
      REP(j, 1, H+1){
        cin >> p[i][j];
      }
    }
    int ans = solve(H, W, p);
    cout << ans << endl;
  }
  
  return 0;
}
