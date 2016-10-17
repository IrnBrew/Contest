#include <algorithm>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <stack>
#include <string>
#include <vector>

#define INF INT_MAX/3

#define REP(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;

ll nary_sum(ll n, ll cur){
  ll sum = 0;

  while(n > 0){
    sum += n % cur;
    n /= cur;
  }

  return sum;
}

ll solve(ll n, ll s){
  ll ans;

  ll min = 1, max = s;
  ll cur = (min + max) / 2;

  REP(i, 0, 1000){
    ll tmp = nary_sum(n, cur);
    if(tmp > s){
      
    }
  }

  return ans;
}
int main(){
  ll n, s;

  cin >> n >> s;

  cout << solve(n, s);
  return 0;
}
