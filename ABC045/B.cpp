#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define type std::string

char solve(std::string a, std::string b, std::string c){

  char current = a[0];
  int A, B, C;
  A = a.size();
  B = b.size();
  C = c.size();

  int ai = 1, bi = 0, ci = 0;

  while(ai != A+1 && bi != B+1 && ci != C+1){
    if(current == 'a'){
      current = a[ai];
      ai++;
    }
    if(current == 'b'){
      current = b[bi];
      bi++;
    }
    if(current == 'c'){
      current = c[ci];
      ci++;
    }
  }  

  if(ai == A+1){
    current = 'A';
    ai++;
  }
  if(bi == B+1){
    current = 'B';
    bi++;
  }
  if(ci == C+1){
    current = 'C';
    ci++;
  }

  return current;
}

int main(){

  std::string a, b, c;

  getline(std::cin, a);
  //std::cin.ignore();
  getline(std::cin, b);
  //std::cin.ignore();
  getline(std::cin, c);

  char result = solve(a, b, c);

  std::cout << result << std::endl;
  
  return 0;
}
