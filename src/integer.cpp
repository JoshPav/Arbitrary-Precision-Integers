#include "integer.h"

namespace ExactArithmetic{

// ================================
//          Constructors
// ================================

    Integer::Integer(){
        digits.push_back(0);
    }

    Integer::Integer(unsigned long long int I){
        for(char c : std::to_string(I)){
            digits.push_back(c-'0');
        }
    }

    Integer::Integer(const std::string &S){
        // Check if first symbol is valid
        for(auto cit = S.begin(); cit != S.end(); cit++){
            if(48 <= *cit && *cit<= 57){
                if(*cit == 48){
                    if((digits.size() == 0) && cit != S.end()-1){
                        continue;
                    }
                }
                digits.push_back(*cit-'0');
            }
            else{
                throw std::invalid_argument("Invalid Input");
            }
        }
    }

    // ================================
    //      Comparison Operators
    // ================================

    // ==
    bool Integer::Integer::operator==(const Integer & other) const{
        
        if(digits.size() == other.digits.size()){
            auto thisIt = digits.begin();
            auto otherIt = other.digits.begin();
            while(thisIt != digits.end() && otherIt != other.digits.end()){
                if(*thisIt == *otherIt){
                    thisIt++;
                    otherIt++;
                }
                else
                    return false; 
            }
            return true;
        }
        else
            return false;
    };

    // !=
    bool Integer::Integer::operator!=(const Integer & other) const{

        if(digits.size() == other.digits.size()){
            auto thisIt = digits.begin();
            auto otherIt = other.digits.begin();
            while(thisIt != digits.end() && otherIt != other.digits.end()){
                if(*thisIt != *otherIt){
                    thisIt++;
                    otherIt++;
                }
                else
                    return false; 
            }
            return true;
        }
        else
            return true;
    };

    // <
    bool Integer::Integer::operator<(const Integer & other) const{
        if(digits.size() < other.digits.size()){
            return true;
        }
        else if(digits.size() > other.digits.size()){
            return false;
        }
        else{
            auto Pair = std::mismatch(digits.begin(),digits.end(),
                                other.digits.begin(),other.digits.end());
            return *Pair.first < *Pair.second;
        }
    };

    // <=
    bool Integer::Integer::operator<=(const Integer &) const{

        return true;        
    };

    // >
    bool Integer::Integer::operator>(const Integer & other) const{
        return other < *this;
    };

    // >=
    bool Integer::Integer::operator>=(const Integer &) const{

        return true;
    };


    // ================================
    //      Friend Declarations
    // ================================

    std::ostream & operator<<(std::ostream & os, const Integer & I){
        os << I.toString();
        return os;
    }


    std::string Integer::toString() const{
        // Loop through list appending digit to string
        std::string S = "";
        for(short int I : digits){
            S += std::to_string(I);
        }
        return S;
    }

}