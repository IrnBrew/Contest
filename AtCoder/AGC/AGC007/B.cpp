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

/*------------------------------------------------------------------------------*/

int main(){
  int N;
  VI v;

  cin >> N;

  REP(i, 0, N){
    int t;
    cin >> t;
    v.push_back(t-1);
  }

  VI a(N);
  VI b(N);
  REP(i, 0, N){
    a[i] = i * (N+1) + N + 1;
    b[N-i-1] = i * (N+1) + N + 1;
  }

  int cnt = N;
  REP(i, 0, N){
    int index = v[i];
    a[index] -= cnt;
    cnt--;
  }

  REP(i, 0, N){
    cout << a[i] << " ";
  }
  cout << endl;
  REP(i, 0, N){
    cout << b[i] << " ";
  }
  cout << endl;

  return 0;
}
