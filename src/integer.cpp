#include "integer.h"

ExactArithmetic::Integer::Integer(){
    digits.push_back(0);
}

ExactArithmetic::Integer::Integer(unsigned long long int I){
    for(char c : std::to_string(I)){
        digits.push_back(c-'0');
    }
}

ExactArithmetic::Integer::Integer(const std::string &S){
    // Check if first symbol is valid
    for(char c : S){
        if(48 <= c && c<= 57){
            digits.push_back(c-'0');
        }
        else{
            throw std::invalid_argument("Invalid Input");
        }
    }
}

std::string ExactArithmetic::Integer::toString() const{
    // Loop through list appending digit to string
    std::string S = "";
    for(short int I : digits){
        S += std::to_string(I);
    }
    return S;
}
