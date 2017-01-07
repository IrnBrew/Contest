#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdio>
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
#define PI = 3.14159265358979323846
/*------------------------------------------------------------------------------*/

int main(){
  int sx, sy, tx, ty;
  scanf("%d %d %d %d", &sx, &sy, &tx, &ty);

  int x = tx - sx;
  int y = ty - sy;
  REP(i, 0, y){
    printf("U");
  }
  REP(i, 0, x){
    printf("R");
  }
  REP(i, 0, y){
    printf("D");
  }
  REP(i, 0, x){
    printf("L");
  }

  printf("L");
  REP(i, 0, y + 1){
    printf("U");
  }
  REP(i, 0, x + 1){
    printf("R");
  }
  printf("D");
  printf("R");
  REP(i, 0, y + 1){
    printf("D");
  }
  REP(i, 0, x + 1){
    printf("L");
  }
  printf("U\n");

  return 0;
}
