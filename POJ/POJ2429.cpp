#include <algorithm>
#include <cmath>
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

void solve(stack<ll>& s, ll gl){
  for(ll i = 2; i * i <= gl; i++){
    while(gl % i == 0){
      gl /= i;
      s.push(i);
    }
  }
  if(gl > 1){
    s.push(gl);
  }
  return;
}

int main(){
  ll g, l;

  while(cin >> g >> l){
    stack<ll> s;
    solve(s, l / g);

    ll a = 1, b = 1;
    while(!s.empty()){
      ll m = s.top();
      s.pop();
      if(a < b){
        a *= m;
      } else {
        b *= m;
      }
    }

    cout << a * g << " " << b * g << endl;
  }
  return 0;
}
