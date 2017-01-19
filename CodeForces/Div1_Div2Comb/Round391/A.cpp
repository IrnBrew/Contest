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
  string s;
  cin >> s;

  VI cs(7, 0);
  REP(i, 0, s.size()){
    switch(s[i]){
    case 'B':
      cs[0]++;
      break;
    case 'u'://two
      cs[1]++;
      break;
    case 'l':
      cs[2]++;
      break;
    case 'b':
      cs[3]++;
      break;
    case 'a'://two
      cs[4]++;
      break;
    case 's':
      cs[5]++;
      break;
    case 'r':
      cs[6]++;
      break;
    }
  }

  int ans = 0;
  while(1){
    bool f = true;
    REP(i, 0, 7){
      if(i == 1 || i == 4){
        if(cs[i] < 2){
          f = false;
          break;
        } else {
          cs[i] -= 2;
        }
      } else {
        if(cs[i] < 1){
          f = false;
          break;
        } else {
          cs[i] -= 1;
        }
      }
    }
    if(!f){
      break;
    }
    ans++;
  }
  cout << ans << endl;

  return 0;
}
