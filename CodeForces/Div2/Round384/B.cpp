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
ll Ptwo[51];

int main(){
  ll n, k;
  scanf("%lld %lld", &n, &k);

  ll ans = n;
  Ptwo[1] = 1;
  REP(i, 2, 51){
    Ptwo[i] = Ptwo[i-1] * 2;
  }
  if(k % 2 == 1){
    printf("1\n");
  } else {
    while(1){
      if(k % Ptwo[ans] == 0){
        printf("%lld\n", ans);
        break;
      }
      k %= Ptwo[ans];
      ans--;
    }
  }
  return 0;
}
