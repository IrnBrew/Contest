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
    int n, r;
    cin >> n >> r;
    if(n == 0 && r == 0){
      break;
    }
    VI v(n);
    REP(i, 0, n){
      v[n-i-1] = i + 1;
    }
    queue<int> q, tmp;
    REP(i, 0, r){
      int p, c;
      cin >> p >> c;
      p--;
      REP(j, 0, p + c){
        if(j < p){
          tmp.push(v[j]);
        } else {
          q.push(v[j]);
        }
      }
      REP(j, 0, p+c){
        if(j < c){
          v[j] = q.front(); q.pop();
        } else {
          v[j] = tmp.front(); tmp.pop();
        }
      }
    }
    cout << v[0] << endl;
  }

  return 0;
}
