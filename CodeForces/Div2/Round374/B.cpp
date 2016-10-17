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

pair<int, int> solve(int N, int K, vector<pair<int, string>> ps, pair<int, string> c){
  pair<int, int> ans;

  sort(ps.begin(), ps.end());

  int s = 0;
  REP(i, 0, N){
    if(c.second == ps[i].second){
      s = ps[i].first;
      break;
    }
  }

  int num = 0;
  int wrong = 0;
  int min = 0, max = 0;
  while(s > ps[num].first){
    if(wrong >= K){
      min += 5;
      wrong = 0;
    }
    min++;
    wrong++;
    num++;
  }

  //s == ps.first
  if(wrong >= K){
    min += 5;
    wrong = 0;
  }
  min++;
  wrong++;

  ans.first = min;
  num++;
  max = min;

  while(s == ps[num].first || num < N){
    if(wrong >= K){
      max += 5;
      wrong = 0;
    }
    max++;
    wrong++;
    num++;
  }
  ans.second = max;

  return ans;
}

int main(){
  PII ans;
  int N, K;
  string tmp;

  cin >> N >> K;
  vector<pair<int, string>> ps(N);
  pair<int, string> c;

  REP(i, 0, N){
    cin >> ps[i].second;
    ps[i].first = (int)ps[i].second.size();
  }
  cin >> c.second;
  c.first = c.second.size();

  
  ans = solve(N, K, ps, c);
  cout << ans.first << ' ' << ans.second << endl;
  return 0;
}
