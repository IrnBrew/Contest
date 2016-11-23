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
  ll n, a, b, c;
  scanf("%lld %lld %lld %lld", &n, &a, &b, &c);

  int x = n % 4;
  if(x == 1){
    ll res = min(a*3, a+b);
    res = min(res, c);
    printf("%lld\n", res);
  } else if(x == 2){
    ll res = min(a*2, b);
    res = min(res, c*2);
    printf("%lld\n", res);
  } else if(x == 3){
    ll res = min(a, b+c);
    res = min(res, c*3);
    printf("%lld\n", res);
  } else {
    printf("0\n");
  }

  return 0;
}
