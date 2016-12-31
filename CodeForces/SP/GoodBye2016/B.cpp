#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdio>
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
typedef pair<ll, ll> PLL;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;
#define PI = 3.14159265358979323846
/*------------------------------------------------------------------------------*/

int main(){
  int n;
  cin >> n;

  int np = 0;

  REP(i, 0, n){
    int a;
    string s;
    cin >> a >> s;
    if(((np == 0) && (s[0] != 'S')) || ((np == 20000) && (s[0] != 'N'))){
      np = -1;
      break;
    }
    if(s[0] == 'N'){
      np -= a;
    } else if(s[0] == 'S'){
      np += a;
    }
    if(np < 0 || np > 20000){
      break;
    }
  }

  if(np == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
