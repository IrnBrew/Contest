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

ll solve(int N){
  ll ans = -1;

  VL v(N);

  //v[0] = 1;
  v[1] = 1;

  REP(i, 2, N+1){
    if(i % 2 == 1){
      v[i] = v[i-1] % 1000000000;
    } else {
      v[i] = (v[i/2] + v[i-1]) % 1000000000;
    }
  }
  ans = v[N];

  return ans;
}

int main(){
  int N;

  cin >> N;

  ll ans = solve(N);

  cout << ans << endl;

  return 0;
}
