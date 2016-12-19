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
#define PI = 3.14159265358979323846
/*------------------------------------------------------------------------------*/

int main(){
  int N;
  queue<int> seq;
  scanf("%d\n", &N);
  int numD = 0, numR = 0;
  REP(i, 0, N){
    char tmp;
    scanf("%c ", &tmp);
    if(tmp == 'D'){
      numD++;
    } else {
      numR++;
    }
    seq.push(tmp);
  }

  int d = 0, r = 0;
  while(numD > 0 && numR > 0){
    char vote = seq.front(); seq.pop();
    if(vote == 'D'){
      if(d > 0){
        d--;
        numD--;
      } else {
        r++;
        seq.push(vote);
      }
    } else {
      if(r > 0){
        r--;
        numR--;
      } else {
        d++;
        seq.push(vote);
      }
    }
  }
  if(numD == 0){
    printf("R\n");
  } else {
    printf("D\n");
  }

  return 0;
}
