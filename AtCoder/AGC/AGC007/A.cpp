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

int main(){
  int W, H;
  cin >> H >> W;

  vector<vector<char>> f(H, vector<char>(W));
  REP(i, 0, H){
    REP(j, 0, W){
      cin >> f[i][j];
    }
  }

  PII a = {0, 0};
  while(1){

    PII u = {a.fst - 1, a.snd};
    PII b = {a.fst, a.snd-1};

    if((u.fst >= 0 && f[u.fst][u.snd] == '#') ||
       (b.snd >= 0 && f[b.fst][b.snd] == '#')){
      cout << "Impossible" << endl;
      break;
    }

    if(a.fst == H - 1 && a.snd == W - 1){
      cout << "Possible" << endl;
      break;
    }
    
    PII x = {a.fst, a.snd+1};
    PII y = {a.fst + 1, a.snd};
    
    char cx = '.', cy = '.';
    if(x.snd < W){
      cx = f[x.fst][x.snd];
    }
    if(y.fst < H){
      cy = f[y.fst][y.snd];
    }
    if(cx == '.' && cy == '.'){
      cout << "Impossible" << endl;
      break;
    }
    if(cx == '#' &&  cy == '#'){
      cout << "Impossible" << endl;
      break;
    }
    f[a.fst][a.snd] = '.';
    if(cx == '#'){
      a = x;
    } else {
      a = y;
    }
  }
  return 0;
}
