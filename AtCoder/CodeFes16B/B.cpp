#include <algorithm>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
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
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int main(){
  int N, A, B, cnt = 0, frn = 0;
  string s;
  cin >> N >> A >> B;
  cin >> s;

  vector<string> pass(N);

  REP(i, 0, N){
    if(s[i] == 'a' && cnt < A+B){
      cnt++;
      pass[i] = "Yes";
    } else if(s[i] == 'b' && cnt < A + B && frn < B){
      cnt++;
      frn++;
      pass[i] = "Yes";
    } else {
      pass[i] = "No";
    }
  }

  REP(i, 0, N){
    cout << pass[i] << endl;
  }

  return 0;
}
