#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
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
typedef pair<ll, ll> PLL;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;
#define PI 3.14159265258979

/*------------------------------------------------------------------------------*/

int main(){
  int c;
  scanf("%d\n", &c);
  REP(i, 0, c){
    double R;
    int n;
    scanf("%lf %d\n", &R, &n);
    double alpha = PI / n;
    double sa = sin(alpha);
    
    printf("Scenario #%d:\n%.3f\n\n", i+1, (R * sa) / (1 + sa));
  }
  return 0;
}
