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

vector<bool> b(1000000000, true);
VL a(0);

ll N = 1000000;

VL v(100, INF*3);

int main(){
  b[0] = false;
  b[1] = false;

  REP(i, 2, N){
    if(b[i]){
      a.push_back(i);
      for(int j = 2 * i; j < N; j += i){
        b[j] = false;
      }
    }
  }

  bool update = true;

  int cnt = 0;
  while(update && cnt < 50000) {
    int index = 0;
    REP(i, 0, 100){
      if((index == 0 || v[index] < v[i]) && (v[i] * a[cnt] < 1000000 || v[i] == INF * 3)){
        index = i;
      }
    }
    if(v[index] == INF * 3){
      v[index] = a[cnt];
    } else if(index == -1){
      break;
    } else {
      v[index] *= a[cnt];
    }
    cnt++;
  }

  REP(i, 0, 100){
    int j = 0;
    while(v[i] * a[j] < 1000000000){
      v[i] *= a[j];
      j++;
    }
  }

  REP(i, 0, 100){
    int j = 0;
    while(v[i] * a[j] < 1000000000){
      v[i] *= a[j];
      j++;
    }
  }

  REP(i, 1, 100){
    cout << v[i] << endl;
  }
  return 0;
}
