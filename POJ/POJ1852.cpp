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

  cin >> N;

  REP(i, 0, N){
    int len, n;
    cin >> len >> n;

    int e = 0, l = 0;
    REP(j, 0, n){
      int c;
      scanf("%d", &c);
      int early, late;
      early = min(c, len - c);
      late = max(c, len - c);

      if(e < early){
        e = early;
      }
      if(l < late){
        l = late;
      }
    }
    cout << e << " " << l << endl;
  }

  return 0;
}
