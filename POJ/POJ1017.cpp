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
  VI pack(6);
  while(1){
    REP(i, 0, 6){
      scanf("%d ", &pack[i]);
    }
    bool stop = true;
    REP(i, 0, 6){
      if(pack[i] != 0){
        stop = false;
      }
    }
    if(stop){
      break;
    }
    int ans = 0;
    REP(i, 0, 6){
      int siz = 6 - i;
      while(pack[siz-1] > 0){
        switch(siz){
        case 6:
          ans += pack[siz-1];
          pack[siz-1] = 0;
          break;
        case 5:
          pack[siz-1]--;
          ans++;
          if(pack[0] > 0){
            pack[0] -= 11;
          }
          break;
        case 4:
          pack[siz-1]--;
          ans++;
          if(pack[1] > 0 && pack[1] >= 5){
            pack[1] -= 5;
          } else {
            int a = pack[1];
            pack[1] = 0;
            pack[0] -= (20 - a * 4);
          }
          break;
        case 3:{
          int inc = pack[siz-1] / 4;
          ans += inc;
          int p3 = pack[siz-1] % 4;
          if(p3 > 0){
            ans++;
            int dec;
            if(pack[1] >= 5 - 2*p3){
              dec = 5 - 2 * (p3 - 1);
              pack[1] -= dec;
            } else {
              dec = pack[1];
              pack[1] = 0;
            }
            pack[0] -= (36 - 9 * p3) - dec * 4;
          }
          pack[siz-1] = 0;
          break;
          }
        case 2:{
          int inc = pack[siz-1]/9;
          ans += inc;
          if(pack[siz-1] % 9 != 0){
            pack[0] -= 36 - (pack[siz-1] % 9) * 4;
            ans++;
          }
          pack[siz-1] = 0;
          break;
        }
        case 1:{
          int inc = pack[siz-1]/36;
          ans += inc;
          if(pack[siz-1] % 36 != 0){
            ans++;
          }
          pack[0] = 0;
        }
          break;
        }
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
