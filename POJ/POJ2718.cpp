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

int vtoi(int s, int e, const VI& v){
  if(v[s] == 0 && e > 1){
    return INF;
  }
  int res = 0;
  REP(i, s, e){
    res = res * 10 + v[i];
  }
  return res;
}

int main(){
  int N;
  cin >> N; cin.ignore();
  string s;

  while(getline(cin, s)){
    VI v;
    for(int i = 0; i < (int)s.size(); i += 2){
      v.push_back(s[i] - '0');
    }

    int num = v.size()/2;
    int ans = INF;

    do{

      int x = vtoi(0, num, v);
      int y = vtoi(num, v.size(), v);

      ans = min(ans, abs(x-y));
    } while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
  }
  return 0;
}
