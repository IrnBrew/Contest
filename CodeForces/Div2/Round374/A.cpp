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

int ans;
vector<int> v(100);
int num = 0;

void solve(int N, string s){
  int b_count = 0;

  REP(i, 0, N){
    char c = s[i];
    if(c == 'W' && b_count > 0){
      v[num] = b_count;
      b_count = 0;
      num++;
    } else if(c == 'B'){
      b_count++;
    }
  }
  if(b_count > 0){
    v[num] = b_count;
    num++;
  }

  return;
}

int main(){
  int N;
  string s;

  cin >> N;
  cin >> s;

  solve(N, s);

  cout << num << endl;
  REP(i, 0, num){
    cout << v[i] << ' ';
  }
  cout << endl;

  return 0;
}
