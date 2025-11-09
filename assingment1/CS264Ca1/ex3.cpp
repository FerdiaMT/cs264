#include <iostream>

int main(){

  // Palindrome Number

  int input;
  
  std::cout<<"Please provide the int to check if palindrome: ";
  std::cin>>input;

  // the case on the question -12221 is false due to it being minus means it will be impossible for 
  // ANY minus number to be a palindrome in this question.
  
  // this brings up the wierd case of the minus 0
  // 0 is palindrome, -0 is not, but 0 = -0
  // i will presume -0 will be treated as 0 in this question since thats how it is treated in runtime
  
  if (input<0){
    std::cout<<"false";
    return 1;
  }

  // my approach here is to do the same solution as 1, reverse integer, but only do half of it, as only half is needed

  int halfRev{};

  while(input > halfRev){ // not doing == incase of case where input is odd
                          
    //doing the same as q1, take rightmost int and shift input num to the right (removing rightmost num)
    //then this functions shifts res num to left, and adding previously taken rightmost num to the res
    int rightMost = input%10;
    input /= 10;

    halfRev*=10;
    halfRev+= rightMost;
  }

  bool res = (input == halfRev); // check if the 2 halfs are the same

  //IMPORANT CASE// 
  //
  // the res case just used there will not work if the amount of digits in the number is ODD 
  // so we must recheck by taking the rightmost digit off of halfRev, the bigger int in this case
  // said int we are removing is not important, it is the "x" in 
  // Y = 123x321 , no matter what x is (as a 1-9 digit), Y is valid

  res |= (input == (halfRev/10)); // if res is already true, itl stay true

  if(res){
    std::cout<<"true";
  }else{
    std::cout<<"false";
  }

  return 0;
  
}
