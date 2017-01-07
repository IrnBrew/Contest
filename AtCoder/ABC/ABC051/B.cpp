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
  int K, S, s;
  scanf("%d %d", &K, &S);

  s = S / 3;
  int ans = 0;
  int a, b, c;
  REP(i, 0, max(K, s)+1){
    a = i;
    REP(j, a, max(K, s)+1){
      b = j;
      c = S - a - b;
      if(a > b || b > c){
        break;
      }
      if(c <= K){
        if(a + b + c == S){
          if(a == b && b == c && c == a){
            ans++;
          } else if(a != b && b != c && c != a){
            ans += 6;
          } else {
            ans += 3;
          }
        }
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
