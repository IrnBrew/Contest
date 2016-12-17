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
  int N;
  queue<int> q;
  int cnt[4] = {};
  int d[4] = {};
  scanf("%d", &N);
  int ans = 0;
  REP(i, 0, N){
    int tmp;
    scanf("%d", &tmp);
    if(tmp == 4){
      ans++;
      continue;
    }
    cnt[tmp]++;
    q.push(tmp);
  }

  while(!q.empty()){
    int h = q.front(); q.pop();
    //printf("front: %d\n", h);
    if(d[h] > 0){
      d[h]--;
      continue;
    }
    ans++;
    cnt[h]--;
    int lim = 4 - h;
    for(int i = 4 - h; lim > 0;){
      //printf("cnt[%d]: %d \n", i, cnt[i]);
      if(cnt[i] > 0 && lim - i >= 0){
        //printf("found %d\n", i);
        lim -= i;
        cnt[i]--;
        d[i]++;
      } else {
        if(i == 1){
          break;
        }
        i--;
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
