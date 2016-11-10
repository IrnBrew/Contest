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

void dfs(vector<vector<char> >& f, int y, int x, int N, int M, char cur){
  if(f[y][x] == cur){
    f[y][x] = '.';
    REP(i, -1, 2){
      REP(j, -1, 2){
        int ny = y + i;
        int nx = x + j;
        if(ny >= 0 && ny < N && nx >= 0 && nx < M && f[ny][nx] == cur){
          dfs(f, ny, nx, N, M, cur);
        }
      }
    }
  }
  return;
}

int main(){
  int N, M;

  cin >> N >> M;

  vector<vector<char> > f(N, vector<char>(M));

  REP(i, 0, N){
    REP(j, 0, M){
      cin >> f[i][j];
    }
  }

  int ans = 0;
  REP(i, 0, N){
    REP(j, 0, M){
      char cur = f[i][j];
      if(cur == 'W'){
        dfs(f, i, j, N, M, cur);
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
