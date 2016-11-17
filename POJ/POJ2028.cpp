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
  while(1){
    int N, Q;
    cin >> N >> Q;

    if(N == 0 && Q == 0){
      break;
    }

    int meet = 0;
    int pre = Q-1;

    int date[100] = {};

    REP(i, 0, N){
      int a;
      cin >> a;
      REP(j, 0, a){
        int tmp;
        cin >> tmp;
        date[tmp]++;
      }
    }

    REP(i, 0, 100){
      if(date[i] > pre){
        meet = i;
        pre = date[i];
      }
    }

    cout << meet << endl;
  }

  return 0;
}
