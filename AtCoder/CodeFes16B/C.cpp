#include <algorithm>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <stack>
#include <string>
#include <vector>

#define REP(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

ll solve(int W, int H, VL p, VL q){
  ll ans = 0;

  vector<bool> flag(W * H);
  VL w(W * H);
  VI parent(W*H);
  REP(i, 0, W*H){
    flag[i] = false;
    w[i] = INF;
  }

  w[0] = 0;
  parent[0] = -1;

  while(1){
    int min = INF;
    int next = -1;
    REP(i, 0, W*H){
      if(flag[i] == false && w[i] < min){
        min = w[i];
      }
      next = i;
    }
    if(min == INF){
      break;
    }
    flag[next] = true;

    REP(i, 0, W*H){

  }

  

  return ans;
}

int main(){
  int W, H;
  cin >> W >> H;

  VL p(W);
  VL q(H);

  REP(i, 0, W){
    cin >> p[i];
  }
  REP(i,0,H){
    cin >> q[i];
  }

  ll ans = solve(W, H, p, q);

  cout << ans << endl;
  return 0;
}
