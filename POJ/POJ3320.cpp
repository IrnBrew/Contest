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
  int P;
  scanf("%d\n", &P);
  VI tp(P);
  set<int> topics;
  REP(i, 0, P){
    scanf("%d ", &tp[i]);
    topics.insert(tp[i]);
  }

  const int kinds = topics.size();
  map<int, int> sub;
  int num = 0;
  int lb = 0, ub = 0;
  int res = INF;

  while(lb < P){
    if(kinds > num && ub < P){
      if(sub[tp[ub]] == 0){
        num++;
      }
      sub[tp[ub]]++;
      ub++;
    }
    if(num == kinds){
      res = min(res, ub-lb);
    }
    if(kinds <= num || ub >= P){
      if(sub[tp[lb]] == 1){
        num--;
      }
      sub[tp[lb]]--;
      lb++;
    }
  }
  printf("%d\n", res);

  return 0;
}
