#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string solve(std::string str, int K){
  char tmp;
  int i = 0;
  int fin = str.size();
  
  while(K != 0){
    tmp = str[i];
    int diff = tmp - 'a';
    if(26 - diff <= K && tmp != 'a'){
      str[i] = 'a';
      K -= 26 - diff;
    }
    i++;
    if(i == fin){
      K %= 26;
      str[i-1] = str[i-1] + K;
      if(str[i-1] > 'z'){
        str[i-1] = 'a' + K - 1;
      }
      break;
    }
  }

  return str;
}

int main(){
  std::string str;
  int K;
  std::cin >> str;
  std::cin >> K;

  std::string result = solve(str, K);

  std::cout << result << std::endl;
  
  return 0;
}
