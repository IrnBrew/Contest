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

bool comp(PII a, PII b){
  if(a.fst == b.fst){
    return a.snd < b.snd;
  } else {
    return a.fst < b.fst;
  }
}

int main(){
  while(1){
    int N;
    cin >> N;
    if(N == 0){
      break;
    }
    int W, H;
    cin >> W >> H;

    vector<vector<char> > f(H, vector<char>(W, '.'));
    REP(i, 0, N){
      int x, y;
      cin >> x >> y;
      f[y-1][x-1] = '*';
    }
    int S, T;
    cin >> S >> T;

    int m = 0;
    REP(i, 0, H-T+1){
      REP(j, 0, W-S+1){
        int tmp = 0;
        REP(k, i, i+T){
          REP(l, j, j+S){
            if(f[k][l] == '*'){
              tmp++;
            }
          }
        }
        if(m < tmp){
          m = tmp;
        }
      }
    }
    cout << m << endl;
  }

  return 0;
}
