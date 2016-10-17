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

/*------------------------------------------------------------------------------*/

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool solve(int fst, int snd){
  bool ans = false;

  int mod = snd - fst;
  if(mod < 0){
    mod = 7 + mod;
  }

  //cout << "mod: " << mod << endl;

  // REP(i, 0, 12){
  //   //cout << "res: " << month[i] % mod << endl;
  //   if(month[i] % 7 == mod){
  //     ans = true;
  //     break;
  //   }
  // }
  if(mod == 2 || mod == 3 || mod == 0){
    ans = true;
  }
  return ans;
}

int main(){
  string a, b;
  int fst = -1, snd = -1;

  cin >> a;
  cin >> b;

  //cout << a << endl << b << endl;

  if(a[0] == 'm'){
    fst = 0;
  } else if(a[0] == 't'){
    if(a[1] == 'u'){
      fst = 1;
    } else {
      fst = 3;
    }
  } else if(a[0] == 'w'){
    fst = 2;
  } else if(a[0] == 'f'){
    fst = 4;
  } else if(a[0] == 's'){
    if(a[1] == 'a'){
      fst = 5;
    } else {
      fst = 6;
    }
  }

  if(b[0] == 'm'){
    snd = 0;
  } else if(b[0] == 't'){
    if(b[1] == 'u'){
      snd = 1;
    } else {
      snd = 3;
    }
  } else if(b[0] == 'w'){
    snd = 2;
  } else if(b[0] == 'f'){
    snd = 4;
  } else if(b[0] == 's'){
    if(b[1] == 'a'){
      snd = 5;
    } else {
      snd = 6;
    }
  }

  if(solve(fst, snd)){
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}
