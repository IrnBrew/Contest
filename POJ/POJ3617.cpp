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

int main(){
  int N;
  vector<char> v;
  string ans;

  cin >> N;
  REP(i, 0, N){
    char tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  int h = 0, t = N - 1;
  REP(i, 0, N){
    int a = h, b = t, id = h;
    while(a < b){
      if(v[a] < v[b]){
        id = h;
        h++;
        break;
      } else if(v[a] > v[b]){
        id = t;
        t--;
        break;
      }
      a++; b--;
    }
    ans.push_back(v[id]);
  }

  REP(i, 0, N){
    if(i != 0 && i % 80 == 0){
      cout << endl;
    }
    cout << ans[i];
  }

  return 0;
}
