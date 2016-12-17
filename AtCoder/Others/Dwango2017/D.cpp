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
  int N, M;
  scanf("%d %d", &N, &M);
  VI x, y;
  REP(i, 0, N){
    int a, b;
    scanf("%d %d", &a, &b);
    x.push_back(a);
    y.push_back(b);
  }

  priority_queue<int, VI, greater<int>> que;
  int ans = 0;
  REP(i, 0, M-1){
    if(i >= N){
      break;
    }
    ans += x[i];
    que.push(x[i]-y[i]);
  }
  int sum = ans;
  REP(i, M-1, N){
    sum = sum + x[i];
    ans = max(ans, sum);
    que.push(x[i] - y[i]);
    sum -= que.top();
    que.pop();
  }
  printf("%d\n", ans);
  return 0;
}
