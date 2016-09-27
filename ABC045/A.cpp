#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define type int

type solve(int a, int b, int h){
  type ans = (a + b) * h / 2;

  return ans;
}

int main(){

  int a, b, h;
  std::cin >> a >> b >> h;

  type result = solve(a, b, h);

  std::cout << result << std::endl;
  
  return 0;
}
