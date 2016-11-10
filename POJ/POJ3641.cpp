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

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/
bool prime(ll p){
  for(int i = 2; i * i <= p; i++){
    if(p % i == 0){
      return false;
    }
  }
  return true;
}

bool solve(ll sp, ll a){
  ll pa = a;
  ll res = 1;
  for(int i = sp; i > 0; i = i >> 1){
    if(i & 0x1){
      //cout << i << endl;
      res = (res * pa) % sp;
    }
    pa = (pa * pa) % sp;
    //cout << "res: " << res << endl;
    //cout << "pa: " << pa << endl;
  }

  return res == a;
}

int main(){
  ll sp, a;

  while(cin >> sp >> a){
    if(sp == 0 && a == 0){
      break;
    }
    if(!prime(sp) && solve(sp, a)){
      cout << "yes";
    } else {
      cout << "no";
    }
    cout << endl;
  }

  return 0;
}
