#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string solve(std::string str){
  std::string a(str.begin(), str.begin()+4);
  
  return a;
}

int main(){
  std::string str;
  std::cin >> str;
  int tmp = str.size();

  std::string result = solve(str);

  std::cout << result << ' ';
  for(int i = 0; i < tmp - 4; i++){
    std::cout << str[i + 4];
  }

  std::cout << std::endl;
  
  return 0;
}
