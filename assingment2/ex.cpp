#include <iostream>

unsigned int length (const char* str){
  
  if(str == NULL){
    return 0;
  }

  unsigned int i = 0;

  while(str[i] != '\0'){
    i+=1;
  }

  return i;

}

char* copy (char* dest, const char* src){
  int srcLen = length(src); // will not include \0
  int destLen = length(dest); // this will always be 1 small

  int dst2 = sizeof(dest) / sizeof(char);

  std::cout<<srcLen<<std::endl;
  std::cout<<dst2<<"x"<<std::endl;
  return dest;
}

int indexOf(char c , const char* str){

  for(int i = 0 ; i < length(str); i++){
    if(str[i] == c){
      return i;
    }
  }

  return -1;
}

char* substring(int i , int j, const char* str){
  int strLength = length(str);

  if(i<0 || j <0 || i>j || i>strLength-1 || j>strLength-1){
    return NULL;
  }

  if(i==j){
    char* temp = "";
    return temp;
  }

  const int newLength = (j-1)+1; // +1 added for /0 at endl

  char substr[newLength] = {};

  for(int p = i; p < j; p++){
    substr[p-i] = str[p];
  }

  substr[j] = '/0';

  return substr;
}

char* replace(char c, char p, const char* str){
  const int strLength = length(str);
  char newstr[strLength] = {};

  for(int i = 0 ; i < strLength ; i++){
    if(str[i] == c){
      newstr[i] =p;
    }else{
      newstr[i] =c;
    }
  }

  newstr[strLength] = '/0';



  return newstr;
}

int main(){
  
  const char* startString = "hello";
  char secondString[6] = {};

  unsigned int len = length(startString); //1
  char* ans = copy(secondString, startString); //2
  int index = indexOf('l', startString); //3
  char* substr = substring(1,2,startString);
  char* repl = replace('l' , 'x' , startString);

  std::cout<<"len: "<<len<<" copy: "<<ans<<" index "<<index<<" substr: "<<substr<<" replace : "<<repl<<" "<<std::endl;
  return 0;
}


