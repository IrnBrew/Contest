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

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};

int solve(int w, int h, vector<vector<char> > t, vector<PII> p){
  int ans = 1;

  vector<char> s(0);

  while(true){
    if(p.size() == 0){
      break;
    }
    PII cur = p.back();
    p.pop_back();
    REP(i, 0, 4){
      if(cur.first+x[i] < w+1 && cur.second+y[i] < h+1){
        if(t[cur.first+x[i]][cur.second+y[i]] == '.'){
          p.push_back({cur.first+x[i], cur.second+y[i]});
          t[cur.first+x[i]][cur.second+y[i]] = '#';
          ans++;
        }
      }
    }
  }

  return ans;
}

int main(){
  int w, h;

  while(true){
    cin >> w >> h;
    if(w == 0 && h == 0){
      break;
    }
    vector<vector<char> > t(w+1, vector<char>(h+1));
    vector<PII> p(0);

    REP(i, 1, h+1){
      REP(j, 1, w+1){
        cin >> t[j][i];
        if(t[j][i] == '@'){
          p.push_back({j, i});
          t[j][i] = '#';
        }
      }
    }

    cout << solve(w, h, t, p) << endl;
  }
  return 0;
}
