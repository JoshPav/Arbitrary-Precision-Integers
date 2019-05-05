#include "integer.h"
#include "negativenumbererror.h"
#include "dividebyzeroerror.h"
#include <math.h>
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
    //       Arithmetic Operators
    // ================================

    Integer Integer::operator-(const Integer & I) const{
        if(digits.size() < I.digits.size()){
            throw NegativeNumberError();
        }
        else{
            Integer temp1(toString());

            auto it1 = temp1.digits.end();
            auto it2 = I.digits.end();

            do{
                it1--;
                it2--;
                *it1 = *it1 - *it2;
            }while(it2 != I.digits.begin());

            temp1.normalise();
            return temp1;
        }
    }

    Integer Integer::operator/(const Integer & I) const{
        if(I == Integer(0)){
            throw DivideByZeroError();
        }
        else{
            Integer Temp(toString());
            Integer Count;
            while(Temp >= 0){
                try
                { 
                    Temp -= I;
                    Count++;
                }
                catch(ExactArithmetic::NegativeNumberError)
                {
                    Count.normalise();
                    return Count;
                }
                catch(std::invalid_argument)
                {
                    Count.normalise();
                    return Count;
                }
            }
        return Count;
        }
    } // Throws a DivideByZeroError for a 0 divisor.


    // ================================
    //       Compound Operators
    // ================================

    Integer & Integer::operator-=(const Integer & I){
        if(digits.size() < I.digits.size()){
            throw NegativeNumberError();
        }
        else{
            auto it1 = digits.end();
            auto it2 = I.digits.end();

            do{
                it1--;
                it2--;
                *it1 = *it1 - *it2;
            }while(it2 != I.digits.begin());

            normalise();
            return *this;
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

    void Integer::removeLeadingZeros(){
        auto D = digits.begin();
        while(*D == 0 && D != --digits.end()){
                digits.erase(D++);
        }
    }

    void Integer::normalise() {

        auto D = --digits.end();
        do{
            if(*D > 9){
                *D = *D % 10;
                if(D == digits.begin()){
                    digits.push_front(floor(*D / 10));
                    return;
                }
                else
                    (*--D)++;
            }
            else if(*D < 0){
                *D = *D + 10;
                (*--D)--;
            }
            else
                --D;
        }while(D!= digits.begin());

        removeLeadingZeros();
    }
}