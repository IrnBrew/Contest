#include <algorithm>
#include <climits>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
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
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int main(){
  string s;

  cin >> s;

  bool f1 = false, ans = false;

  REP(i, 0, s.size()){
    if(f1 == false && s[i] == 'C'){
      f1 = true;
    } else if(f1 == true && s[i] == 'F'){
      ans = true;
    }
  }

  if(ans == true){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
