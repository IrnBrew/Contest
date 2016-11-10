#include <algorithm>
#include <climits>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
#include <set>
#include <stack>
#include <string>
//#include <unordered_map>
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

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

bool ps[10000];

void primes(){
  fill(ps, ps + 10000, true);
  ps[0] = false;
  ps[1] = false;
  REP(i, 2, 10000){
    if(ps[i]){
      for(int j = i * 2; j < 10000; j += i){
        ps[j] = false;
      }
    }
  }
  return;
}
    

int solve(int s, int e){
  bool cp[10000];
  REP(i, 0, 10000){
    cp[i] = ps[i];
  }

  queue<PII> q;
  q.push(MP(s, 0));
  cp[s] = false;

  while(q.size() > 0){
    PII num = q.front();
    q.pop();
    //1000
    REP(i, 1, 10){
      int p = i * 1000 + (num.fst % 1000);
      //cout << "p1000: " << p << " " << num.snd + 1 << endl;
      if(cp[p]){
        cp[p] = false;
        q.push(MP(p, num.snd + 1));
        if(p == e){
          return num.snd + 1;
        }
      }
    }
    REP(i, 0, 10){
      int p = (num.fst / 1000) * 1000 + i * 100 + (num.fst % 100);
      //cout << "p100: " << p << " " << num.snd + 1 << endl;
      if(cp[p]){
        cp[p] = false;
        q.push(MP(p, num.snd + 1));
        if(p == e){
          return num.snd + 1;
        }
      }
    }
    REP(i, 0, 10){
      int p = (num.fst / 100) * 100 + i * 10 + (num.fst % 10);
      //cout << "p10: " << p << " " << num.snd + 1 << endl;
      if(cp[p]){
        cp[p] = false;
        q.push(MP(p, num.snd + 1));
        if(p == e){
          return num.snd + 1;
        }
      }
    }
    for(int i = 1; i < 10; i += 2){
      int p = (num.fst / 10) * 10 + i * 1;
      //cout << "p1: " << p << " " << num.snd + 1 << endl;
      if(cp[p]){
        cp[p] = false;
        q.push(MP(p, num.snd + 1));
        if(p == e){
          return num.snd + 1;
        }
      }
    }
  }

  return 0;
}

int main(){
  int N;
  cin >> N;

  primes();
  REP(i, 0, N){
    int s, e;
    cin >> s >> e;

    cout << solve(s, e) << endl;
  }
  return 0;
}
