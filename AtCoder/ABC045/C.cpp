#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define type long long int

type solve(std::vector<int> nums){
  type ans = 0;

  int N = 1;

  for(int i = 0; i < (int)nums.size() - 1; i++){
    N = N * 2;
  }
  
  for(int i = 0; i < N; i++){
    long long int tmp = 0;
    int plus = i;
    for(int j = 0; j < (int)nums.size(); j++, plus = plus >> 1){
      if((plus & 0x1) == 0x1){
        tmp = tmp * 10 + nums[j];
        ans += tmp;
        tmp = 0;
      } else {
        tmp = tmp * 10 + nums[j];
      }
    }
    ans += tmp;
  }

  return ans;
}

int main(){

  std::string seq;
  std::cin >> seq;

  std::vector<int> nums(seq.size());

  for(int i = 0; i < (int)seq.size(); i++){
    nums[i] = seq[i] - '0';
  }

  type result = solve(nums);

  std::cout << result << std::endl;
  
  return 0;
}
