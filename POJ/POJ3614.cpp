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

int solve(priority_queue<PII, vector<PII>, greater<PII> > q, vector<PII> l){
  int ans = 0;

  sort(l.begin(), l.end());
  while(q.size()){
    PII c = q.top();
    //cout << "c:" << c.fst << " " << c.snd << endl;
    q.pop();
    REP(i, 0, l.size()){
      if(l[i].snd > 0 && c.snd <= l[i].fst && c.fst >= l[i].fst){
        //cout << "use " << l[i].fst << endl;
        l[i].snd--;
        ans++;
        break;
      }
    }
  }
  return ans;
}

int main(){
  int C, L;
  cin >> C >> L;
  priority_queue<PII, vector<PII>, greater<PII> > q;
  vector<PII> l(L);

  REP(i, 0, C){
    int min, max;
    cin >> min >> max;
    q.push(MP(max, min));
  }
  REP(i, 0, L){
    int s, n;
    cin >> s >> n;
    l[i] = MP(s, n);
  }

  cout << solve(q, l) << endl;
  
  return 0;
}
