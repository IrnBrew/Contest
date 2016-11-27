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

bool isPrime(int N){
  for(int i = 2; i * i <= N; i++){
    if(N % i == 0){
      return false;
    }
  }
  return true;
}

int main(){
  ll N;
  scanf("%lld\n", &N);

  
  if(isPrime(N)){
    printf("1\n");
  } else if(N >= 4 && (N % 2 == 0 || isPrime(N-2))){
    printf("2\n");
  } else {
    printf("3\n");
  }
  return 0;
}
