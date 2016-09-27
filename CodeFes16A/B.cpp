#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int num = 0;

int solve(int N, std::vector<int> r){
  int ans = 0;

  std::vector<int> check(N);

  for(int i = 0; i < N; i++){
    if(i == r[r[i]]){
      ans++;
      check[num] = r[i];
      num++;
      r[r[i]] = -1;
      }
  }

  return ans;
}

int main(){
  int N;
  std::cin >> N;

  std::vector<int> r(N);

  for(int i = 0; i < N; i++){
    std::cin >> r[i];
    r[i] -= 1;
  }

  int result = solve(N, r);

  std::cout << result << std::endl;
  
  return 0;
}
