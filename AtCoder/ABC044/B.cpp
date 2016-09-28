#include <algorithm>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <stack>
#include <string>
#include <vector>

#define INF (INT_MAX/3)

#define REP(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;

bool solve(string w){
  sort(w.begin(), w.end());

  char head = w[0];
  ll count = 0;
  bool ans = true;

  if(w.size() % 2 == 0){
    REP(i, 0, w.size()){
      if(head != w[i]){
        if((count % 2) != 0){
          ans = false;
          break;
        }
        head = w[i];
      }
      count++;
    }
  } else {
    ans = false;
  }
  return ans;
}

int main(){
  string w;

  cin >> w;

  if(solve(w)){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
