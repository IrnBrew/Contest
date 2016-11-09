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

int cost[1100][1100];

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  vector<string> s;

  s.push_back(string(W+2, 'X'));
  REP(i, 0, H){
    string tmp;
    cin >> tmp;
    s.push_back('X' + tmp + 'X');
  }
  s.push_back(string(W+2, 'X'));

  vector<PII> v(N+1);
  REP(i, 0, H+2){
    REP(j, 0, W+2){
      char c = s[i][j];
      if(c >= '1' && c <= '9'){
        v[c-'0'] = {i, j};
      } else if(c == 'S'){
        v[0] = {i, j};
      }
    }
    cout << s[i] << endl;
  }

  int dest = 0, res = 0;
  REP(i, 0, N){
    queue<PII> q;
    q.push(v[dest]);
    memset(cost, -1, sizeof(cost));
    cost[v[dest].fst][v[dest].snd] = 0;
    while(!q.empty()){
      PII a = q.front(); q.pop();
      const int dx[4] = {-1, 0, 1, 0};
      const int dy[4] = {0, -1, 0, 1};
      if(s[a.fst][a.snd] == i + '1'){
        res += cost[a.fst][a.snd];
        dest++;
        break;
      }
      REP(i, 0, 4){
        int ny = a.fst + dy[i];
        int nx = a.snd + dx[i];
        if(s[ny][nx] != 'X' && !(cost[ny][nx] + 1)){//cost[ny][nx] + 1 == 0 if not searched
          cost[ny][nx] = cost[a.fst][a.snd] + 1;
          q.push({ny, nx});
        }
      }
    }
  }
  cout << res << endl;

  return 0;
}
