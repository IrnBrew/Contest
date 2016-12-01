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
inline double dist(PII a, PII b){
  //printf("%f\n", sqrt(pow((a.fst-b.fst), 2) + pow((a.snd-b.snd),2)));
  return sqrt(pow((a.fst-b.fst), 2) + pow((a.snd-b.snd),2));
}

bool comp(PII a, PII b){
  bool ans;
  if(ans = (a.snd > b.snd)){
    return ans;
  } else if(ans = ((a.fst < b.fst) && a.snd == b.snd)){
    return ans;
  }
  return false;
}

int main(){
  int cs = 0;
  vector<PII> il(1001);
  set<int> s;
  while(1){
    cs++;
    s.clear();
    int n, d;
    scanf("%d %d\n", &n, &d);
    if(n == 0 && d == 0){
      break;
    }

    REP(i, 0, n){
      PII a;
      scanf("%d %d", &a.fst, &a.snd);
      il[i] = a;
    }
    scanf("%*c");
    sort(il.begin(), il.begin()+n, comp);

    int num = n;
    int cnt = 0;
    int rader = 0;

    while(num > 0){
      PII pos = MP(il[cnt].fst, 0);
      //printf("land: %d\n", cnt);
      if(dist(pos, il[cnt]) > d){
        rader = -1;
        break;
      }
      if(s.find(cnt) != s.end()){
        //printf("omit: %d\n", cnt);
        continue;
      }
      rader++;
      num--;
      REP(i, cnt + 1, n){
        //printf("land: %d\n", i);
        if(dist(pos, il[i]) <= d){
          s.insert(i);
          num--;
        }
      }
      cnt++;
    }
    printf("Case %d: %d\n", cs, rader);
  }
  return 0;
}
