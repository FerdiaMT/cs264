#include <iostream>

double pow(int x, int y){ // needs to be double to handle -y

  // the logic here is divide and conquer
  // say you had 2^6 , this would be 2*2*2*2*2*2 if written out
  // but, this could also be written as 2^3 * 2^3 , in which we would only have to find one of these values
  // you can do the same with 2^3 (the odd n case) as (2^1*2^1) * 2 , we add that 2 in the end for odd numbers
  //
  // if you do this with any y (where the input to the program is 2^y), it will always go down to 2^0 , which is 1.
  // since you are HALVING the amount to go down the recursion tree outlined here, and reusing that data  
  // and since it is o(y) , where y is halving itself each time 

  // this function will run at Olog(n) ,where n == y


  //this is the recursive base case, as we are decrementing y in each loop, 
  //it will eventually reach x^y where y=0, which is 1
  //I would make it y==1 return x, but that doesnt handle edge case y==0 for the original input
  if (y==0) return 1;

  //here we will go all the way down the recursion tree until we reach x^1 as base case then build up 
  double cur = pow(x, y/2); 

  //since we have found 1 half, we will multiple cur by itself to make the complete amount
  cur = cur*cur;

  //finally we check if given y was odd, in which we multiple an extra x to cur, say y=5, (x^2*x^2) would need one more x
  //it is provided here by checking if the y was odd
  if(y%2!=0){
    cur*=x;
  }

  return cur; // we return the currently found segment, this will be multiplied by itself if not the base of the stack
              // in this recursion, if it is it will just return to main


}

int main(){
  // POWER FUNCTION
  //
  // the way to do this is a recursive function , the sheet hints at this with saying to make the function pow(x,y)
  
  int x,y;
  std::cout<<"Please give the base number: ";
  std::cin>>x;
  std::cout<<"Please give the number to be the power of previous number: ";
  std::cin>>y;

  //since the positive and negative powers work slightly differently, i will have to remember first

  bool isNegativeY = false;
  if(y<0){
    isNegativeY=true; // we use this since pow(x,y) where y is negative is equal to 1/pow(x,-y) where -y is positive
    y*=-1; // we change y to be positive since otherwise recursion goes on forever
  }

  int res = pow(x,y);

  if(!isNegativeY){ // positive case
    std::cout<<res;
  }else{ // negative case
    double negativeCase = 1.0/res;
    std::cout<< negativeCase;
  }
  return 0;
}
