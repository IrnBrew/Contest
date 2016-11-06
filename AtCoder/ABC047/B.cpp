#include <algorithm>
#include <climits>
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

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int main(){
  int W, H, N;
  cin >> W >> H >> N;
  vector<PII> d(N);
  VI a(N);

  REP(i, 0, N){
    cin >> d[i].fst >> d[i].snd >> a[i];
  }

  int w = 0, h = 0;

  REP(i, 0, N){
    if(a[i] == 1){
      w = max(w, d[i].fst);
    } else if(a[i] == 2){
      W = min(W, d[i].fst);
    } else if (a[i] == 3){
      h = max(h, d[i].snd);
    } else if(a[i] == 4){
      H = min(H, d[i].snd);
    }
  }

  int ans = (W - w) * (H - h);
  if(W-w <= 0 || H-h <= 0){
    ans = 0;
  }
  cout << ans << endl;
  return 0;
}
