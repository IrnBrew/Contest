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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

typedef struct{
  PII pos;
  int cost;
  int move;
} Curl;

void dfs(Curl t,
         priority_queue<int, VI, greater<int> >& ans,
         vector<VI > f){

  int y = t.pos.fst;
  int x = t.pos.snd;
  int m = t.move;
  
  if(t.move == -1){
    t.cost++;
    REP(i, 0, 4){
      if(f[y + dy[i]][x + dx[i]] != 1 &&
         f[y + dy[i]][x + dx[i]] != 4){
        t.move = i;
        dfs(t, ans, f);
      }
    }
  } else if(t.cost > 10){
    return;
  } else {
    int ny = y;
    int nx = x;
    while(1){
      ny += dy[m];
      nx += dx[m];
      if(f[ny][nx] == 4){
        break;
      } else if(f[ny][nx] == 3){
        ans.push(t.cost);
        break;
      } else if(f[ny][nx] == 1){
        t.move = -1;
        t.pos = MP(ny - dy[m], nx - dx[m]);
        f[ny][nx] = 0;
        dfs(t, ans, f);
        break;
      }
    }
  }

  return;
}


int main(){
  int H, W;

  while(1){
    cin >> W >> H;
    if(W == 0 && H == 0){
      break;
    }
    vector<VI > f(H+2, (VI(W+2, 4)));

    PII b;
    REP(i, 1, H+1){
      REP(j, 1, W+1){
        int x;
        cin >> x;
        f[i][j] = x;
        if(x == 2){
          b = MP(i, j);
        }
      }
    }

    REP(i, 0, H+2){
      REP(j, 0, W+2){
        cout << f[i][j];
      }
      cout << endl;
    }

    priority_queue<int, VI, greater<int> > ans;
    ans.push(INF);

    Curl ini;
    ini.pos = b;
    ini.cost = 0;
    ini.move = -1;

    dfs(ini, ans, f);
    int a = ans.top();
    if(a == INF){
      cout << -1 << endl;
    } else {
      cout << a << endl;
    }
    cout << "-----------------------------" << endl;
  }

  return 0;
}
