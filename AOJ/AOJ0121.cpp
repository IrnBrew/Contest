#include <algorithm>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <stack>
#include <string>
#include <vector>
#include <queue>

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

VI ans = {0, 1, 2, 3, 4, 5, 6, 7};

map<VI, int> m;

void solve(){
  queue<pair<VI,int>> q;
  q.push({ans, 0});
  m.insert({ans, 0});

  while(true){
    if(q.size() == 0){
      break;
    }
    pair<VI,int> tmp = q.front();

    q.pop();

    if((*m.begin()).first != tmp.first){
      if(m.find(tmp.first) != m.end()){
        continue;
      }
    }
    m.insert(tmp);

    int p;
    REP(i, 0, 8){
      if(tmp.first[i] == 0){
        p = i;
      }
    }
    if(p > 0 && p != 4){
      VI v = tmp.first;
      int j = p - 1;
      int res = v[p];
      v[p] = v[j];
      v[j] = res;
      q.push({v, tmp.second + 1});
    }
    if(p < 4){
      VI v = tmp.first;
      int j = p + 4;
      int res = v[p];
      v[p] = v[j];
      v[j] = res;
      q.push({v, tmp.second + 1});
    }
    if(p < 7 && p != 3){
      VI v = tmp.first;
      int j = p + 1;
      int res = v[p];
      v[p] = v[j];
      v[j] = res;
      q.push({v, tmp.second + 1});
    }
    if(p >= 4){
      VI v = tmp.first;
      int j = p - 4;
      int res = v[p];
      v[p] = v[j];
      v[j] = res;
      q.push({v, tmp.second + 1});
    }
  }
  return;
}

int main(){
  VI in(8);

  solve();

  while(cin){
    bool f = false;
    REP(i, 0, 8){
      cin >> in[i];
      if(cin.eof()){
        f = true;
        break;
      }
    }
    if(f == true){
      break;
    }
    int tmp = m[in];
    cout << tmp << endl;
  }
  return 0;
}
