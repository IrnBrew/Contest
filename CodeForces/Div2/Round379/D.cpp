#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdio>
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

bool bis(PII a, PII b){
  int px = a.snd - b.snd;
  int py = a.fst - b.fst;
  if(py != 0 && abs(px) % abs(py) == 0){
    return true;
  }
  return false;
}

bool rook(PII a, PII b){
  int px = a.snd - b.snd;
  int py = a.fst - b.fst;
  if(px == 0 || py == 0){
    return true;
  }
  return false;
}

bool in_way_bis(PII a, PII b, PII o){
  int x1 = min(a.snd, b.snd);
  int x2 = max(a.snd, b.snd);
  int y1 = min(a.fst, b.fst);
  int y2 = max(a.fst, b.fst);

  if(x1 < o.snd && x2 > o.snd && y1 < o.fst && y2 > o.fst && bis(b, o)){
    return true;
  }
  return false;
}

bool in_way_rook(PII a, PII b, PII o){
  int x1 = min(a.snd, b.snd);
  int x2 = max(a.snd, b.snd);
  int y1 = min(a.fst, b.fst);
  int y2 = max(a.fst, b.fst);

  if(x1 < o.snd && x2 > o.snd && y1 < o.fst && y2 > o.fst){
    return true;
  }
  return false;  
}

int main(){
  int n;
  cin >> n;
  PLL k;
  cin >> k.snd >> k.fst;

  queue<PLL> r;
  queue<PLL> b;
  queue<PLL> q;

  REP(i, 0, n){
    char p;
    PLL c;
    cin >> p >> c.snd >> c.fst;
    if(p == 'R'){
      r.push(c);
    } else if(p == 'B'){
      b.push(c);
    } else {
      q.push(c);
    }
  }

  vector<PLL> b_check;
  vector<PLL> r_obst;
  while(!b.empty()){
    PLL o = b.front(); b.pop();
    if(bis(o, k)){
      b_check.push_back(o);
    } else if(rook(o, k)){
      r_obst.push_back(o);
    }
  }

  vector<PLL> b_obst;
  bool check = false;

  while(!r.empty()){
    PLL o = r.front(); r.pop();
    if(rook(o, k)){
      bool flag = true;
      REP(i, 0, r_obst.size()){
        if(in_way_rook(o, k, r_obst[i])){
          flag = false;
          break;
        }
      }
      if(flag){
        check = true;
        break;
      }
    } else if(bis(o, k)){
      b_obst.push_back(o);
    }
  }

  if(check){
    cout << "YES" << endl;
  } else {
    while(!q.empty()){
      PLL o = q.front(); q.pop();
      if(rook(o, k)){
        r_check.push_back(o);
      }
      if(bis(o, k)){
        b_check.push_back(o);
      }
    }
  }

  return 0;
}
