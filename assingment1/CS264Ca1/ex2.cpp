#include <iostream>

int greatestCommonDivisor(int a, int b){//this is the recursive algorithm, maths explained in main
  if(a==0) return b; // base case
  int newA = b%a; // modulo down the number until we reach 0
                  
  return greatestCommonDivisor(newA, a); // further down recursion until 1 num is 0
}


int main(){
  // GREATEST COMMON DIVISOR
  
  // Im going to use euclidean algorithm (learned it from leetcode). 
  
  int inputA, inputB; // declare the 2 inputs
  
  std::cout<<"Please provide integer 1: "; // asks for input1
  std::cin>>inputA;  // takes in input1
  std::cout<<"Please provice integer 2: "; // asks for input2 
  std::cin>>inputB; // takes in input2

  int res = greatestCommonDivisor(inputA,inputB); // call the recursive method and save to int res

  std::cout<<res<< std::endl; // print output
  
  return 0;


  //==============================//
  //RECURSIVE FORMULA EXPLENATION //
  //==============================//

  // the maths here is that given a,b  
  // the common divisor of a,b is same as b%a,a (recursion)
  // once you get (int c, 0), you have found the greatest common divisor (int c in this case)
}
