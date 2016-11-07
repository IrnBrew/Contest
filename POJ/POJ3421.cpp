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

void devs(vector<ll>& v, ll N){
  for(ll i = 2; i * i <= N; i++){
    ll num = 0;
    while(N % i == 0 && N > 0){
      N /= i;
      num++;
    }
    if(num > 0){
      v.push_back(num);
    }
  }
  if(N > 1){
    v.push_back(1);
  }
  return;
}

int main(){
  ll N;

  while(cin >> N){
    vector<ll> v;
    devs(v, N);
    ll length = 0, div = 1;
    REP(i, 0, v.size()){
      length += v[i];
      for(ll j = v[i]; j > 0; j--){
        div *= j;
      }
    }
    ll ans = 1;
    for(ll i = length; i > 0; i--){
      ans *= i;
    }
    ans /= div;
    cout << length << " " << ans << endl;
  }
  return 0;
}
