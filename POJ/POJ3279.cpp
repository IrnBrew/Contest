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

void reverse(int x, int y, vector<VI>& flip, int& num){
  flip[y][x]++;
  num++;
  return;
}

bool isWhite(int x, int y, int W, int H, const vector<VI>& brd, const vector<VI>& flip){
  int f = flip[y][x];
  REP(i, 0, 4){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx >= 0 && ny >= 0 && nx < W && ny < H){
      f += flip[ny][nx];
    }
  }
  if((brd[y][x] + f) % 2 == 0){
    return true;
  }
  return false;
}

int main(){
  int H, W;
  scanf("%d %d ", &H, &W);

  vector<VI> brd(H, VI(W));
  REP(i, 0, H){
    REP(j, 0, W){
      scanf("%d ", &brd[i][j]);
    }
    scanf("\n");
  }

  int ans = INF;
  vector<VI> flip_ans(H, VI(W, 0));
  vector<VI> flip(H, VI(W, 0));

  REP(i, 0, pow(2, W)){
    int cnt = W-1;
    int num = 0;
    REP(i, 0, H){
      REP(j, 0, W){
        flip[i][j] = 0;
      }
    }
    for(int j = i; j > 0; j = j >> 1, cnt--){
      if(j & 0b1){
        reverse(cnt, 0, flip, num);
      }
    }

    REP(j, 1, H){
      REP(k, 0, W){
        if(!isWhite(k, j-1, W, H, brd, flip)){
          reverse(k, j, flip, num);
        }
      }
    }
    bool clear = true;
    REP(j, 0, W){
      if(!isWhite(j, H-1, W, H, brd, flip)){
        clear = false;
        break;
      }
    }
    if(clear && ans > num){
      ans = num;
      flip_ans = flip;
    }
  }

  if(ans == INF){
    printf("IMPOSSIBLE\n");
  } else {
    REP(i, 0, H){
      REP(j, 0, W){
        printf("%d ", flip_ans[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
