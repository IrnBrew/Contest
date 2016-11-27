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
  int N, k;
  scanf("%d %d ", &N, &k);

  int G, T;
  vector<char> seq(N, '.');

  REP(i, 0, N){
    char c;
    scanf("%c ", &c);
    if(c == 'G'){
      G = i;
    } else if(c == 'T'){
      T = i;
    } else if(c == '#'){
      seq[i] = '#';
    }
  }
  bool imp = false;
  if(G < T){
    while(G < T){
      if(G+k < N && seq[G+k] == '#'){
        imp = true;
        break;
      }
      G += k;
    }
    if(G != T){
      imp = true;
    }
  } else if(G > T){
    while(G-k >= 0 && G > T){
      if(seq[G-k] == '#'){
        imp = true;
        break;
      }
      G -= k;
    }
    if(G != T){
      imp = true;
    }
  }

  if(imp){
    printf("NO\n");
  } else {
    printf("YES\n");
  }

  return 0;
}
