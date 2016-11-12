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
  int K, T;

  cin >> K >> T;

  VI nums(T);
  int max = 0, index = 0;

  REP(i, 0, T){
    cin >> nums[i];
    if(max < nums[i]){
      max = nums[i];
      index = i;
    }
  }

  int rest = 0;
  REP(i, 0, T){
    if(i != index){
      rest += nums[i];
    }
  }

  int ans = nums[index] - rest;

  if(ans < 0){
    cout << 0 << endl;
  } else {
    cout << ans - 1 << endl;
  }

  return 0;
}
