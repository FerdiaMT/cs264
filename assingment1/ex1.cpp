#include <iostream>

int main(){
  // REVERSE AN INTEGER

  int input; // initialize the input variable

  std::cout<<"Please provide an input: ";
  std::cin>>input;

  int inputCopy = input; // copying this for final print
                         
  bool isNegative; // before reversing integer, we have to check if the number is isNegative

  if(input <0){
    isNegative = true;
    input*=-1; // sets the number to positive in order to properly execute integer swap
  }else{
    isNegative = false;
  }

  int res{}; // final number that will be printed
              
  while(input > 0){ //while there are values to take from the number

    int lastDigit = input%10; //take out the current last digit from the number
    input = input/10; //shift the number one to the right (removes most recently taken)

    res *= 10; // shift the resolution to the left
    res += lastDigit; // add on the digit we took off of the input

  }

  if (isNegative){
    res *=-1; // if number was originally a negative, make it one again
  }

  std::cout<<res;

  return 0;

}
