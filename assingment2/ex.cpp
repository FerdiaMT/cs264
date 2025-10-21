#include <iostream>

unsigned int length(const char* str){
  if(str == NULL){ // if string is null, dont iterate through it
    return 0; // null string is length 0
  }
  unsigned int i = 0; // we use this as a counter for the length, unsigned as itl be returned
  while(str[i] != '\0'){ // keep iterating until we find the '\0' (indicates end of string)
    i += 1;
  }
  return i; // return the fursthest we get iterating through the string before finding the '\0'
}

char* copy(char* dest, const char* src){
  if(dest == NULL || src == NULL){ // if either of src or dest is null, return before it crashes
    return NULL;
  }

  if(length(src)>length(dest)){ // make sure source is smaller or equal to the destination
    return NULL;
  }
  
  int i = 0; // declare the iterator for the while loop
  while(src[i] != '\0'){ // keep iterating until we find the '\0' (indicates end of string)
    dest[i] = src[i]; // copy dest into source 
    i++;
  }
  dest[i] = '\0'; // add the end string marker
  return dest; // return the copied instance
}

int indexOf(char c, const char* str){ 
  for(int i = 0; i < length(str); i++){ // iterates through each index of string
    if(str[i] == c){ // if the character at the index of i is equal to c
      return i; // return the index
    }
  }
  return -1; // if its never found, return -1
}

char* substring(int i, int j, const char* str){
  int strLength = length(str); 
  if(i < 0 || j < 0 || i > j || i >= strLength || j > strLength){ 
    return NULL; // if i or j is out of bounds of the string (smaller then 0, i>j or either are bigger)
  }
  
  int newLength = j - i; // new results length is the difference between the 2 
  char* result = new char[newLength + 1];   // answer array is initialized
  
  int index = 0; // index is declared
  for(int p = i; p < j; p++){ // iterate through from i to j
    result[index] = str[p]; // results index is the string of current p index (between i and j)
    index++; // results index increases
  }
  result[index] = '\0'; // append the end string character
  return result;
}

char* replace(char c, char p, const char* str){
  int strLength = length(str);
  char* result = new char[strLength + 1];  // result declared
  
  for(int i = 0; i < strLength; i++){ // iterate through the passed in string
    if(str[i] == c){ // if the character in input String is equals to c (toBeReplaced)
      result[i] = p; // set the result to then be p (toReplaceWith)
    } else {
      result[i] = str[i]; // otherwise, set the result to be the same as the string
    }
  }
  result[strLength] = '\0'; // append the end string character
  return result;
}

void length_test_case_1(){
  std::cout << "length_test_case_1: ";
  unsigned int result = length("string"); // standard string testcase

  unsigned int expected = 6;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

void length_test_case_2(){
  std::cout << "length_test_case_2: ";
  unsigned int result = length(""); // length of empty string

  unsigned int expected = 0;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

void length_test_case_3(){
  std::cout << "length_test_case_3: ";
  unsigned int result = length("a"); // length of 1 char

  unsigned int expected = 1;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

void length_test_case_4(){
  std::cout << "length_test_case_4: ";
  unsigned int result = length(NULL); // check what happens if null passed in

  unsigned int expected = 0;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

// HELPER FUNCTION SO I CAN COMPARE 2 STRINGS TO MAKE SURE THERE IDENTICAL

bool sameStringCheck(const char* source, const char* result){
  if(source == NULL || result == NULL){ // make sure we return if we find null, must be very carefull as allot of testing relies on nulls
    if(source == result){ // technically 2 nulls are the same
      return true;
    }
    return false;
  }
  
  int counter = 0;
  while( source[counter] != '\0' || result[counter] != '\0' ){ // iterate through both strings making sure were not finding a \0
    if( source[counter] != result[counter] ){ 
      return false;
    }
    counter += 1;
  }
  return true;
}

// COPY TEST CASES
void copy_test_case_1(){
  std::cout << "copy_test_case_1: ";
  char dest[10];
  char* source = "string"; // test case :copy "string" , standard case
  char* result = copy(dest, source);

  if(result != NULL){
    if( sameStringCheck(source, result) ){ std::cout << "CORRECT : " << source << std::endl;} 
    else {std::cout << "WRONG, EXPECTED "<< source << " GOT : " << dest << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
}

void copy_test_case_2(){
  std::cout << "copy_test_case_2: ";
  char dest[5];
  char* source = ""; // copy empty string
  char* result = copy(dest, source);

  if(result != NULL){
    if( sameStringCheck(source, result) ){ std::cout << "CORRECT : " << source << std::endl;} 
    else {std::cout << "WRONG, EXPECTED "<< source << " GOT : " << dest << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
}

void copy_test_case_3(){
  std::cout << "copy_test_case_3: ";
  char* result = copy(NULL, "test"); // copying a test into a null
  if(result == NULL){
    std::cout << "CORRECT AS NULL WORKED" << std::endl;
  } else {
    std::cout << "NOT NULL, FAIL" << std::endl;
  }
}

void copy_test_case_4(){
  std::cout << "copy_test_case_2: ";
  char dest[3];
  char* source = "HELLOWORLD"; // copy too big of a string
  char* result = copy(dest, source);

  if(result == NULL){
    std::cout << "CORRECT AS NULL WORKED" << std::endl;
  } else {
    std::cout << "NOT NULL, FAIL" << std::endl;
  }
}

// INDEXOF TESTS
void indexOf_test_case_1(){
  std::cout << "indexOf_test_case_1: ";
  char indexChar = 'i';
  const char* input = "string"; // index of standard string
  int result = indexOf(indexChar, input);
  int expected = 3;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

void indexOf_test_case_2(){
  std::cout << "indexOf_test_case_2: ";
  char indexChar = 'a';
  const char* input = "string"; // index of standard string
  int result = indexOf(indexChar, input);
  int expected = -1;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

void indexOf_test_case_3(){
  std::cout << "indexOf_test_case_3: ";
  char indexChar = 's';
  const char* input = "string"; // index of standard string
  int result = indexOf(indexChar, input);
  int expected = 0;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

void indexOf_test_case_4(){
  std::cout << "indexOf_test_case_4: ";
  char indexChar = 'g';
  const char* input = "string";// index of standard string
  int result = indexOf(indexChar, input);
  int expected = 5;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

void indexOf_test_case_5(){
  std::cout << "indexOf_test_case_5: ";
  char indexChar = 'x';
  const char* input = "";// index of char not in string
  int result = indexOf(indexChar, input);
  int expected = -1;
  if(result == expected){ std::cout << "CORRECT : " << expected << std::endl;} else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
}

// SUBSTRING TESTS
void substring_test_case_1(){
  std::cout << "substring_test_case_1: ";
  const char* source = "string";
  char* result = substring(0, 3, source);
  char* expected = "str"; // substr of standard string
  if(result != NULL){
    if( sameStringCheck(expected, result) ){ std::cout << "CORRECT : " << expected << std::endl;}
    else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
  delete[] result;
}

void substring_test_case_2(){
  std::cout << "substring_test_case_2: ";
  const char* source = "hello";
  char* result = substring(1, 5, source);
  char* expected = "ello"; // substr of standard string
  if(result != NULL){
    if( sameStringCheck(expected, result) ){ std::cout << "CORRECT : " << expected << std::endl;}
    else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
  delete[] result;
}

void substring_test_case_3(){
  std::cout << "substring_test_case_3: ";
  const char* source = "string";
  char* result = substring(-1, 3, source); // incorrect starting index
  if(result != NULL){
    std::cout << "WRONG, EXPECTED NULL ,gout: " << result << std::endl;
    delete[] result;
  }else{
    std::cout<<"NULL RETURNED SO CORRECT"<<std::endl;
  }
}

void substring_test_case_4(){
  std::cout << "substring_test_case_4: ";
  const char* source = "string";
  char* result = substring(3, 2, source); // incorrect indexes as end < start
  if(result != NULL){
    std::cout << "WRONG, EXPECTED NULL ,gout: " << result << std::endl;
    delete[] result;
  }else{
    std::cout<<"NULL RETURNED SO CORRECT"<<std::endl;
  }
}

void substring_test_case_5(){
  std::cout << "substring_test_case_5: ";
  const char* source = "string";
  char* result = substring(0, 10, source); // end index is too big for source string
  if(result != NULL){
    std::cout << "WRONG, EXPECTED NULL ,gout: " << result << std::endl;
    delete[] result;
  }else{
    std::cout<<"NULL RETURNED SO CORRECT"<<std::endl;
  }
}

void substring_test_case_6(){
  std::cout << "substring_test_case_6: ";
  const char* source = "string";
  char* result = substring(0, 6, source); // standard, should return entire string
  char* expected = "string";
  if(result != NULL){
    if( sameStringCheck(expected, result) ){ std::cout << "CORRECT : " << expected << std::endl;}
    else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
  delete[] result;
}

//  replacer TESTS
void replace_test_case_1(){
  std::cout << "replace_test_case_1: ";
  char replaceChar = 'i';
  char replaceWith = 'x';
  const char* source = "string"; // replace string with i for x 
  char* result = replace(replaceChar, replaceWith, source);
  char* expected = "strxng";
  if(result != NULL){
    if( sameStringCheck(expected, result) ){ std::cout << "CORRECT : " << expected << std::endl;}
    else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
  delete[] result;
}

void replace_test_case_2(){
  std::cout << "replace_test_case_2: ";
  char replaceChar = 'a';
  char replaceWith = 'x';
  const char* source = "string";// replace string with a for x 
  char* result = replace(replaceChar, replaceWith, source);
  char* expected = "string";
  if(result != NULL){
    if( sameStringCheck(expected, result) ){ std::cout << "CORRECT : " << expected << std::endl;}
    else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
  delete[] result;
}

void replace_test_case_3(){
  std::cout << "replace_test_case_3: ";
  char replaceChar = 'l';
  char replaceWith = 'x';
  const char* source = "hello";// replace string with l for x, test for replacing multiple characters 
  char* result = replace(replaceChar, replaceWith, source);
  char* expected = "hexxo";
  if(result != NULL){
    if( sameStringCheck(expected, result) ){ std::cout << "CORRECT : " << expected << std::endl;}
    else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
  delete[] result;
}

void replace_test_case_4(){
  std::cout << "replace_test_case_4: ";
  char replaceChar = 'h';
  char replaceWith = 'H';
  const char* source = "hello"; // capitalizes string
  char* result = replace(replaceChar, replaceWith, source);
  char* expected = "Hello";
  if(result != NULL){
    if( sameStringCheck(expected, result) ){ std::cout << "CORRECT : " << expected << std::endl;}
    else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
  delete[] result;
}

void replace_test_case_5(){
  std::cout << "replace_test_case_5: ";
  char replaceChar = 'x';
  char replaceWith = 'y';
  const char* source = ""; // empty string test case
  char* result = replace(replaceChar, replaceWith, source);
  char* expected = "";
  if(result != NULL){
    if( sameStringCheck(expected, result) ){ std::cout << "CORRECT : " << expected << std::endl;}
    else {std::cout << "WRONG, EXPECTED "<< expected << " GOT : " << result << std::endl;}
  }else{
    std::cout<<"NULL RETURNED"<<std::endl;
  }
  delete[] result;
}

int main(){
  std::cout << "========== LENGTH TEST ==========" << std::endl;
  length_test_case_1();
  length_test_case_2();
  length_test_case_3();
  length_test_case_4();
  
  std::cout << "\n========== COPY() TEST ==========" << std::endl;
  copy_test_case_1();
  copy_test_case_2();
  copy_test_case_3();
  copy_test_case_4();
  
  std::cout << "\n========== INDEXOF() TEST ==========" << std::endl;
  indexOf_test_case_1();
  indexOf_test_case_2();
  indexOf_test_case_3();
  indexOf_test_case_4();
  indexOf_test_case_5();
  
  std::cout << "\n========== SUBSTRING TEST ==========" << std::endl;
  substring_test_case_1();
  substring_test_case_2();
  substring_test_case_3();
  substring_test_case_4();
  substring_test_case_5();
  substring_test_case_6();
  
  std::cout << "\n========== REPLACING() TEST ==========" << std::endl;
  replace_test_case_1();
  replace_test_case_2();
  replace_test_case_3();
  replace_test_case_4();
  replace_test_case_5();
  
  
  return 0;
}
