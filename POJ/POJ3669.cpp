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

int f[301][301];
bool r[301][301] = {};

int dx[5] = {-1, 0, 1, 0, 0};
int dy[5] = {0, -1, 0, 1, 0};

typedef struct{
  int x;
  int y;
  int t;
} pt;

int main(){
  REP(i, 0, 301){
    fill_n(f[i], 301, 1001);
  }
  int M;
  cin >> M;

  int lim = 0;
  REP(i, 0, M){
    int y, x, t;
    cin >> x >> y >> t;
    REP(j, 0, 5){
      int nx = x + dx[j], ny = y + dy[j];
      if(nx >= 0 && ny >= 0 && nx <= 300 && ny <= 300 && f[ny][nx] > t){
        f[ny][nx] = t;
      }
    }
    if(lim < t){
      lim = t;
    }
  }
  // REP(i, 0, lim+1){
  //   REP(j, 0, lim - i + 1){
  //     cout << f[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  queue<pt> pos;
  pt init;
  init.x = 0, init.y = 0, init.t = 0;
  pos.push(init);

  int mini = INF;
  while(!pos.empty()){
    pt cur = pos.front(); pos.pop();
    if(f[cur.y][cur.x] == 1001){
      mini = cur.t;
      //cout << "safe point: " << cur.x << " " << cur.y << endl;
      break;
    }
    REP(i, 0, 4){
      pt next;
      next.x = cur.x + dx[i]; next.y = cur.y + dy[i]; next.t = cur.t + 1;

      if((next.x >= 0 && next.y >= 0 && next.x <= 300 && next.y <= 300) &&
         !r[next.y][next.x] && next.t < f[next.y][next.x]){
        //cout << "x:y:t " <<  next.x << " " << next.y << " " << next.t << endl;
        pos.push(next);
      }
      r[next.y][next.x] = true;
    }
  }
  if(mini == INF){
    cout << -1 << endl;
  } else {
    cout << mini << endl;
  }
  return 0;
}
