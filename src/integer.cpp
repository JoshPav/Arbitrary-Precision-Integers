#include "integer.h"
#include "negativenumbererror.h"
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
        return compare(other) == 0;
    };

    // !=
    bool Integer::Integer::operator!=(const Integer & other) const{
        return compare(other) != 0;
    };

    // <
    bool Integer::Integer::operator<(const Integer & other) const{
        return compare(other) < 0;
    };

    // <=
    bool Integer::Integer::operator<=(const Integer & other) const{
        return compare(other) <= 0;
    };

    // >
    bool Integer::Integer::operator>(const Integer & other) const{
        return compare(other) > 0;
    };

    // >=
    bool Integer::Integer::operator>=(const Integer & other) const{
        return compare(other) >= 0;
    };

    // ================================
    //      Stream Overloads
    // ================================

    std::ostream & operator<<(std::ostream & os, const Integer & I){
        os << I.toString();
        return os;
    }

    std::istream & operator>>(std::istream & is, Integer & I){

        std::string input;
        is >> input;

        I = Integer(input);
        return is;
    }
    // ================================
    //      Increment Operators
    // ================================
    
    // ++ Pre-increment
    Integer & Integer::operator++(){
        ++digits.back();
        normalise();
        return *this;
    }

    // Post-increment ++
    Integer Integer::operator++(int){
        Integer temp(toString());
        digits.back()++;
        normalise();
        return temp;
    } 

    // -- Pre-decrement
    Integer & Integer::operator--(){
        if(digits.size() == 1 && digits.back() == 0){
            throw NegativeNumberError();
        }
        else{
            --digits.back();
            normalise();
            return *this;
        }
    }  

    // Post-decrement --
    Integer Integer::operator--(int){
        if(digits.size() == 1 && digits.back() == 0){
            throw NegativeNumberError();
        }
        else{
            Integer temp(toString());
            digits.back()--;
            normalise();
            return temp;
        }
    } 


    // ================================
    //       Private Functions
    // ================================

    std::string Integer::toString() const{
        std::string S = "";
        for(Digit I : digits){
            S += std::to_string(I);
        }
        return S;
    }

    int Integer::compare(const Integer & other) const{
        if(digits.size() < other.digits.size()){
            return -1;
        }
        else if(digits.size() > other.digits.size()){
            return 1;
        }
        else{
            auto Pair = std::mismatch(digits.begin(),digits.end(),
                                other.digits.begin(),other.digits.end());
            return *Pair.first - *Pair.second;
        }
    }

    void Integer::normalise() {

        auto D = --digits.end();
        while(D!= digits.begin()){
            if(*D > 9){
                *D = 0;
                if(D == digits.begin()){
                    digits.push_front(1);
                    return;
                }
                else
                    (*--D)++;
            }
            else if(*D < 0){
                *D = 9;
                (*--D)--;
            }
            else
                --D;
        }
        if(*D == 0)
            digits.erase(D);
    }
}