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

VI hop(const vector<VI>& f, int x, int y, const VI& inst, VI& res){
  const int dx[4] = {-1, 0, 1, 0};
  const int dy[4] = {0, -1, 0, 1};

  int nx = x;
  int ny = y;
  res[0] = f[y][x];
  int cnt = 1;
  REP(i, 0, inst.size()){
    nx = nx + dx[inst[i]];
    ny = ny + dy[inst[i]];
    if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
      res[cnt] = f[ny][nx];
      cnt++;
    } else {
      res[0] = -1;
      break;
    }
  }
  return res;
}

int main(){
  vector<VI> f(5, VI(5));

  REP(i, 0, 5){
    REP(j, 0, 5){
      scanf("%d ", &f[i][j]);
    }
  }

  vector<VI> steps(pow(4,5));
  int cnt = 0;
  REP(a, 0, 4){
    REP(b, 0, 4){
      REP(c, 0, 4){
        REP(d, 0, 4){
          REP(e, 0, 4){
            steps[cnt].push_back(a);
            steps[cnt].push_back(b);
            steps[cnt].push_back(c);
            steps[cnt].push_back(d);
            steps[cnt].push_back(e);
            cnt++;
          }
        }
      }
    }
  }

  set<VI> s;
  VI ins(6);
  REP(i, 0, 5){
    REP(j, 0, 5){
      REP(k, 0, steps.size()){
        hop(f, j, i, steps[k], ins);
        if(ins[0] != -1 && s.find(ins) == s.end()){
          s.insert(ins);
        }
      }
    }
  }

  printf("%d\n", (int)s.size());
  return 0;
}
