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

typedef struct{
  int x;
  int y;

} Pxy;

int main(){
  vector<Pxy> p(3);
  REP(i, 0, 3){
    scanf("%d %d\n", &p[i].x, &p[i].y);
  }

  printf("3\n");
  REP(i, 0, 3){
    Pxy tmp;
    int next = (i+1) % 3;
    int rest = (i+2) % 3;
    tmp.x = p[i].x - p[next].x;
    tmp.y = p[i].y - p[next].y;
    printf("%d %d\n", p[rest].x + tmp.x, p[rest].y + tmp.y);
  }

  return 0;
}
