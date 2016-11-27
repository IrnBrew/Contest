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

/*------------------------------------------------------------------------------*/

int main(){
  int N, n1, n2;
  scanf("%d %d %d ", &N, &n1, &n2);
  VI wlt(N);
  REP(i, 0, N){
    scanf("%d ", &wlt[i]);
  }

  sort(wlt.begin(), wlt.end(), greater<int>());
  if(n1 > n2){
    int tmp = n2;
    n2 = n1;
    n1 = tmp;
  }
  ll a1 = 0, a2 = 0;
  REP(i, 0, n1){
    a1 += wlt[i];
  }
  REP(i, 0, n2){
    a2 += wlt[i + n1];
  }

  printf("%.10f\n", (double)a1/n1 + (double)a2/n2);

  return 0;
}
