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
  int n;
  scanf("%d\n", &n);

  bool inf = true;
  int min_R = -(INF - 1), max_R = INF;

  REP(i, 0, n){
    int change, div;
    scanf("%d %d\n", &change, &div);

    if(div == 2){
      inf = false;
    }
    if(div == 1){
      min_R = max(1900, min_R);
    } else {
      max_R = min(1899, max_R);
    }
    min_R += change;
    max_R += change;
  }

  if(inf){
    printf("Infinity\n");
  } else if(min_R > max_R){
    printf("Impossible\n");
  } else {
    printf("%d\n", max_R);
  }

  return 0;
}
