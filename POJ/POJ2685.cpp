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

int mystoi(string s){
  int ans = 0;
  int pf = 1;
  REP(i, 0, s.size()){
    if(s[i] >= '2' && s[i] <= '9'){
      pf = s[i] - '0';
    } else {
      switch(s[i]){
      case 'm':
        ans += pf * 1000;
        pf = 1;
        break;
      case 'c':
        ans += pf * 100;
        pf = 1;
        break;
      case 'x':
        ans += pf * 10;
        pf = 1;
        break;
      case 'i':
        ans += pf * 1;
        pf = 1;
        break;
      }
    }
  }
  return ans;
}

string myitos(int x){
  int d = 1000;
  string s;
  while(d > 0){
    int t = x / d;
    if(t > 0){
      if(t > 1){
        s.push_back(t+'0');
      }
      switch(d){
      case 1000:
        s.push_back('m');
        break;
      case 100:
        s.push_back('c');
        break;
      case 10:
        s.push_back('x');
        break;
      case 1:
        s.push_back('i');
        break;
      }
    }
    x %= d;
    d = d / 10;
  }
  return s;
}

int main(){
  int n;
  cin >> n;

  REP(i, 0, n){
    string a, b;
    cin >> a >> b;
    int x = mystoi(a) + mystoi(b);
    cout << myitos(x) << endl;
  }

  return 0;
}
