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
bool comp(PLL a, PLL b){
  if(a.fst > b.fst){
    return true;
  } else if(a.fst == b.fst && a.snd >= b.snd){
    return true;
  }
  return false;
}

int main(){
  ll N, C;
  scanf("%lld %lld\n", &N, &C);

  vector<PLL> vp;
  ll ans = 0;

  REP(i, 0, N){
    ll t1, t2;
    scanf("%lld %lld\n", &t1, &t2);

    if(t1 >= C){
      ans += t2;
      vp.push_back(MP(0, 0));
    } else {
      vp.push_back(MP(t1, t2));
    }
  }

  sort(vp.begin(), vp.end(), comp);

  bool update = true;
  while(update){
    update = false;
    int sum = 0;
    vector<PII> stock;
    REP(i, 0, N){
      if(vp[i].snd <= 0){
        continue;
      }
      int num = 0;
      while(sum + vp[i].fst < C){
        sum += vp[i].fst;
        vp[i].snd--;
        num++;
        if(vp[i].snd == 0){
          break;
        }
        //printf("%d-> sum: %d, stock %lld\n", i, sum, vp[i].snd);
      }
      stock.push_back(MP(i, num));
    }
    REP(i, 0, N){
      if(vp[N-i-1].snd <= 0){
        continue;
      }
      if(sum + vp[N-i-1].fst >= C){
        //printf("%lld-> OVER THE THRESH %lld\n", N-i-1, vp[N-i-1].fst);
        vp[N-i-1].snd--;
        ans++;
        update = true;

        bool flag = false;
        REP(j, 0, stock.size()){
          if(stock[j].fst == N-i-1){
            stock[j].snd++;
            flag = true;
          }
        }
        if(!flag){
          stock.push_back(MP(N-i-1, 1));
        }
        ll add = INF;
        REP(j, 0, stock.size()){
          if(stock[j].snd > 0){
            add = min(add, (vp[stock[j].fst].snd / stock[j].snd));
          }
        }
        ans += add;
        if(add != INF){
          REP(j, 0, stock.size()){
            vp[stock[j].fst].snd -= stock[j].snd * add;
          }
        }
        break;
      }
    }
  }

  printf("%lld\n", ans);
  return 0;
}
