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

bool comp(PII a, PII b){
  if(a.fst < b.fst){
    return true;
  } else if(a.snd <= b.snd && a.fst == b.fst){
    return true;
  }
  return false;
}

int main(){
  int cs = 1;
  vector<PII> il(1001);
  while(1){
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

    int x = il[0].fst;
    int y = il[0].snd;

    double raderX = x + sqrt(d*d - y*y);
    int rader = 1;
    if(y > d){
      rader = -1;
      goto RESULT;
    }
    REP(i, 1, n){
      if(il[i].snd > d){
        rader = -1;
        break;
      }
      double lhs = il[i].fst - sqrt(d*d - il[i].snd * il[i].snd);
      if(lhs > raderX){
        raderX = il[i].fst + sqrt(d*d - il[i].snd * il[i].snd);
        rader++;
      } else {
        raderX = min(raderX, il[i].fst + sqrt(d*d - il[i].snd * il[i].snd));
      }
    }

  RESULT:
    printf("Case %d: %d\n", cs, rader);
    cs++;
  }
  return 0;
}
