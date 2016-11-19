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

int main(){
  int N;
  scanf("%d\n", &N);
  VI c(N);
  REP(i, 0, N){
    char tmp;
    scanf("%c ", &tmp);
    if(tmp == 'B'){
      c[i] = 1;
    } else {
      c[i] = 0;
    }
  }

  int K = 0;
  int ans = INF;

  REP(i, 1, N+1){
    int k = i;
    int res = 0;
    int sum = 0;
    VI f(N, 0);
    REP(j, 0, N-k+1){
      //printf("sum + c[%d] = %d\n", j, sum+c[j]);
      if(((sum + c[j]) % 2) != 0){
        //printf("%d: %d sum: %d\n", i, j, sum);
        res++;
        f[j]++;
        //printf("%d res:%d\n", j, res);
      }
      sum += f[j];
      if(j-k+1 >= 0){
        sum -= f[j-k+1];
      }
    }
    bool face = true;
    REP(j, N-k+1, N){
      //printf("%d %d: face? sum: %d c[%d]: %d\n", k, j, sum, j, c[j]);
      if((sum + c[j]) % 2 != 0){
        face = false;
        break;
      }
      if(j - k + 1 >= 0){
        //printf("f[%d] %d\n", j-k+1, f[j-k+1]);
        sum -= f[j-k+1];
      }
    }
    if(ans > res && face){
      //printf("i: %d, res:%d\n", i, res);
      ans = res;
      K = k;
    }
    //printf("--------------------\n");
  }
  if(ans != INF){
    printf("%d %d\n", K, ans);
  } else {
    printf("0 0\n");
  }

  return 0;
}
