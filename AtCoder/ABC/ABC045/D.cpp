#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<long long int> solve(long long int H, long long int W, long long int N, vector<pair<long long int, long long int> > square){
  vector<long long int> ans(10);
  for(long long int i = 0; i < 10; i++){
    ans[i] = 0;
  }

  sort(square.begin(), square.end());
  vector<pair<long long int, long long int> > list;

  for(long long int i = 0; i < N; i++){
    for(long long int j = 0; j < 3; j++){
      for(long long int k = 0; k < 3; k++){
        if(square[i].first - j > 0 && square[i].second - k > 0 &&
           square[i].first - j + 2 <= H && square[i].second - k + 2 <= W){
          list.push_back({square[i].first - j, square[i].second - k});
        }
      }
    }
  }
  sort(list.begin(), list.end());

  pair<long long int, long long int> tmp(-1, -1);
  long long int cont = 0;
  for(long long int i = 0; i < (long long int)list.size(); i++){
    if(list[i].first != tmp.first || list[i].second != tmp.second){
      ans[cont]++;
      cont = 0;
      tmp.first = list[i].first;
      tmp.second = list[i].second;
    }
    cont++;
  }
  ans[cont]++;

  ans[0] = (H - 2) * (W - 2);
  for(long long int i = 1; i < 10; i++){
    ans[0] -= ans[i];
  }

  return ans;
}

int main(){

  long long int H, W, N;
  cin >> H >> W >> N;

  vector<pair<long long int, long long int> > square(N);
  for(long long int i = 0; i < N; i++){
    long long int a, b;
    cin >> a >> b;
    square[i] = make_pair(a, b);
  }

  vector<long long int> result(10);
  result = solve(H, W, N, square);

  for(long long int i = 0; i < 10; i++){
    cout << result[i] << endl;
  }
  
  return 0;
}
