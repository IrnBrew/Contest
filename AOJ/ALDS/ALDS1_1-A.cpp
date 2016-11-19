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

int main(){
  int N;
  cin >> N;
  VI seq(N);
  REP(i, 0, N){
    cin >> seq[i];
  }

  REP(i, 0, N){
    if(i > 0){
      cout << " ";
    }
    cout << seq[i];
  }
  cout << endl;

  REP(i, 1, N){
    int key = seq[i];
    int j = i-1;
    while(j >= 0 && seq[j] > key){
      seq[j+1] = seq[j];
      j--;
    }
    seq[j+1] = key;
    REP(k, 0, N){
      if(k > 0){
        cout << " ";
      }
      cout << seq[k];
    }
    cout << endl;
  }

  return 0;
}
