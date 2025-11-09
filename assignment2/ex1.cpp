#include <iostream>

unsigned int length(const char* str){

    //basically , c++ strings end with a \0, since thats how assembly does it 
    //so, if we keep iterating through this char* like an array until we hit the \o
    // we will get the length

    int counter = 0; // init the counter that will find our length
    while(str[counter] != '\0'){ // iterate through array until we hit the \0
        counter+=1; // add as we have not hit \0 yet
    }

    return counter; // at this point \0s been hit, return length

}

char* copy (char* dest, const char* src){
    //first we need to check if the destination is bigger or equal to source
    int destLength = length(dest);
    int sourceLength = length(src);

    std::cout<<sourceLength<<std::endl;

    if(destLength < sourceLength){ // if dest is smaller then source, it cant fit
        return NULL;
    }

    for(int i = 0; i <sourceLength; i++){
        dest[i] = src[i];
    }

    dest[destLength+1] = '\0'; // still need to assign the \0

    return dest;

}


int main(){

    const char* str = "string";
    char newStr[8]{};

    int len = length(newStr);

    std::cout<<copy(newStr , str);

    return 0;
}