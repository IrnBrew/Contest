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

  VI nums(101010, 0);
  REP(i, 0, n){
    int a;
    scanf("%d ", &a);
    for(int j = 1; j * j <= a; j++){
      if(a % j == 0){
        nums[j]++;
        if(j * j != a){
          nums[a/j]++;
        }
      }
    }
  }

  int ans = 1;
  REP(i, 2, 101010){
    ans = max(ans, nums[i]);
  }
  printf("%d\n", ans);

  return 0;
}
