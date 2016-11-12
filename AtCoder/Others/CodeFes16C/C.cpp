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

ll solve(int N, VL T, VL A){

  VL def(N, 0);
  ll max = 0;
  VL ans(N, 1);

  bool wrong = false;

  REP(i, 0, N){
    if(max < T[i]){
      def[i] = T[i];
      max = T[i];
    } else {
      ans[i] = T[i];
    }
  }

  max = 0;

  for(int i = N-1; i >= 0; i--){
    if(max < A[i]){
      if(def[i] != 0 && A[i] > def[i]){
        //cout << "upper " << i << endl;
        wrong = true;
        break;
      } else if(max < A[i]) {
        def[i] = A[i];
        max = A[i];
        ans[i] = 1;
      }
    } else if(def[i] != 0 && A[i] < def[i]) {
      //cout << "downer " << i << endl;
      wrong = true;
      break;
    } else {
      ans[i] = min(A[i], ans[i]);
    }
  }

  ll ret = 0;

  if(!wrong){
    ret = 1;
    REP(i, 0, N){
      ret = (ret * (ans[i] % (1000000000 + 7))) % (1000000000 + 7);
    }
  }

  if(T[N-1] != A[0]){
    ret = 0;
  }

  return ret;
}

int main(){
  int N;
  cin >> N;

  VL T(N), A(N);

  REP(i, 0, N){
    cin >> T[i];
    T[i];
  }

  REP(i, 0, N){
    cin >> A[i];
    A[i];
  }

  cout << solve(N, T, A) << endl;

  return 0;
}
