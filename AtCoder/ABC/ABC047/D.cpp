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
  int N, T;

  cin >> N >> T;

  VI v(N);
  REP(i, 0, N){
    cin >> v[i];
  }

  int maxv = 0, minv = v[0], index = 0, min_ind = 0, ini_max, ans = 0;
  REP(i, 1, N){
    if(maxv < v[i] - minv){
      maxv = v[i] - minv;
      min_ind = index;
      ini_max = maxv;
    }
    maxv = max(maxv, v[i] - minv);
    if(minv > v[i]){
      minv = v[i];
      index = i;
    }
  }

  v[min_ind]++;
  ans++;
  //cout << "ind:" << min_ind << " " << v[min_ind] << endl;

  maxv = 0; minv = v[0];
  int same_num = 1;
  REP(i, 1, N){
    maxv = max(maxv, v[i] - minv);
    if(maxv == ini_max){
      ans += same_num;
      maxv = 0;
      minv = INF*3;
      same_num = 1;
    }
    if(minv == v[i]){
      same_num++;
    }
    if(minv > v[i]){
      minv = v[i];
      same_num = 1;
    }
  }

  cout << ans << endl;

  return 0;
}
