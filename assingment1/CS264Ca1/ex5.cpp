#include <iostream>

bool powOfTwo(int k){
  // the trick here involves the fact that a power of two will always have only one bit set
  // example: 2^0 = 1, 2^1 = 10, 2^2 = 100, 2^3 = 1000 (where second num is in binary)

  // so, if we subtracted 1 from any of these values, we would get all 0 bits set to 1, and the 1 bit set to 0
  // example: 2^3 = 1000, 2^3 - 1 = 0111
  // therefore, if we & (bitwise and) these two nums together, we will get 0
  int kMinusOne = k - 1;
  bool isPowerOfTwo = (k & kMinusOne) == 0; // will be true if these 2 nums anded are equal to 0 (only happens when a power of two)

  return isPowerOfTwo;
}

int main(){
  // POWER OF TWO
  int input;

  std::cout << "Please provide the number to be checked: ";
  std::cin >> input; // take in the input

  if(powOfTwo(input)){ // check if given input is a power of two
    std::cout<<"true"<<std::endl;
  }else{
    std::cout<<"false"<<std::endl;
  }
  
  return 0;
}
