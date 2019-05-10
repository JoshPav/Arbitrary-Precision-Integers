#include "integer.h"
#include "negativenumbererror.h"
#include "dividebyzeroerror.h"
#include <math.h>
#include <list>
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

    Integer::Integer( const Integer & I){
        for(Digit d : I.digits){
            digits.push_back(d);
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
                std::cout << S;
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
        Integer temp(*this);
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
            Integer temp(*this);
            digits.back()--;
            normalise();
            return temp;
        }
    }

    // ================================
    //       Arithmetic Operators
    // ================================

    Integer Integer::operator+(const Integer & I) const{
        return Integer(*this) += I;
    }

    Integer Integer::operator-(const Integer & I) const{
        return Integer(*this) -= I;
    }

    Integer Integer::operator*(const Integer & I) const{
        return Integer(*this) *= I;
    }


    Integer Integer::operator/(const Integer & I) const{
        return Integer(*this)/=I;
    }

    Integer Integer::operator%(const Integer & I) const{
        return Integer(*this)%=I;
    }

    // ================================
    //       Compound Operators
    // ================================

    Integer & Integer::operator+=(const Integer & I){
        if(digits.size() >= I.digits.size()){
            Integer temp(*this);

            auto it1 = digits.end();
            auto it2 = I.digits.end();

            do{
                it1--;
                it2--;
                *it1 += *it2;
            }while(it2 != I.digits.begin());
            normalise();
            return *this;
        }
        else
            return *this = (I + *this);
    }

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

    Integer & Integer::operator*=(const Integer & I){
        // Algorithm found at: https://silentmatt.com/blog/2011/10/how-bigintegers-work-part-2-multiplication/

       if(I.digits.size() <= digits.size()){

            auto bottomItr = I.digits.end();
            std::list<Integer> intToAdd;
            Integer Count, Total;

            do{
                --bottomItr;

               Integer temp(*this);

               //appending zeros to simulate long multiplication
               for(Integer countI; countI < Count; countI++)
                {
                   temp.digits.push_back(0);
                }

               for(auto topItr= temp.digits.end(); topItr != temp.digits.begin();){
                   --topItr;
                    *topItr = *topItr * *bottomItr;
                }

                Count++;
                temp.normalise();
                Total += temp;

            }while(bottomItr != I.digits.begin());

            return *this= Total;
        }
        else{
           return *this = (I * *this);
       }
    }

    Integer & Integer::operator/=(const Integer & I){
        if(I == Integer(0)){
            throw DivideByZeroError();
        }
        else{
            Integer Temp(*this);
            Integer Count;
            while(Temp >= Integer(0)){
                try
                {
                    Temp -= I;
                    if(Temp >= Integer(0))
                        Count++;
                }
                catch(ExactArithmetic::NegativeNumberError)
                {
                    Count.normalise();
                    return *this = Count;
                }
            }
        return *this = Count;
        }
    }

    Integer & Integer::operator%=(const Integer & I){
        if(I == Integer()){
            throw ExactArithmetic::DivideByZeroError();
        }
        else if(I >= *this || I == Integer("1")){
            return *this = Integer();
        }
        else{
            Integer Temp(*this);
            Integer Count;
            while(Temp >= I){
                try
                {
                    Temp -= I;
                }
                catch(ExactArithmetic::NegativeNumberError)
                {
                    Temp.normalise();
                    return *this = Temp;
                }
            }
        return *this = Temp;
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
        for(auto D = digits.end(); D != digits.begin();)
        {
            --D;
            if((*D) > 9){
                Digit toPush = floor(*D/10);
                *D %= 10;

                if(D == digits.begin()){
                    digits.push_front(toPush);
                    return;
                }
                else{
                    auto Dcopy = D;
                    (*--Dcopy)+= toPush;
                }
            }
            else if(*D < 0){
                auto Dcpy = D;
                *D += 10;
                (*--Dcpy)--;
            }
        }
        removeLeadingZeros();
    }

}
