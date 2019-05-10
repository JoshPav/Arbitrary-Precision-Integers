#include "integer.h"
<<<<<<< HEAD
=======
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
>>>>>>> development



<<<<<<< HEAD
//testing Git gui



//Constructors
namespace ExactArithmetic{
  Integer::Integer(){
      digits.push_back(0);
  }

  Integer::Integer(unsigned long long int i){
    std::string numeric = std::to_string(i);
    for(char c : numeric){
      digits.push_back(c-'0');
    }
  }

  Integer::Integer(const std::string & s) throw (std::invalid_argument){
    if(s.find_first_not_of("0123456789") == std::string::npos){
      for(auto charItr = s.begin(); charItr != s.end(); charItr++){
          if(digits.size() == 0 && *charItr == '0' && charItr != s.end()-1){
                continue;
          }
          digits.push_back(*charItr -'0');
      }
    }
    else{
        throw std::invalid_argument("Invalid syntax");
    }
  }


//Stream Operator
  std::ostream & operator<<(std::ostream & os, const Integer & i){
      return os << i.toString();
  }

//Comparison Operators
  bool Integer::operator<(const Integer & toCompare) const{
    return compare(toCompare) < 0;
  }
  bool Integer::operator>(const Integer & toCompare) const{
    return compare(toCompare) > 0;
  }
  bool Integer::operator<=(const Integer & toCompare) const{
    int i = compare(toCompare);
    return i < 0 || i == 0;
  }
  bool Integer::operator>=(const Integer & toCompare) const{
    int i = compare(toCompare);
    return i > 0 || i == 0;
  }
  bool Integer::operator==(const Integer & toCompare) const{
    return compare(toCompare) == 0;
  }
  bool Integer::operator!=(const Integer & toCompare) const{
    int i = compare(toCompare);
    return i > 0 || i < 0;
  }

  //Arithmetic Operators
  Integer Integer::operator+(const Integer & toAdd) const{
    Integer temp;
      if(digits.size() > toAdd.digits.size()){
        return additionHelper(*this, toAdd);
      }
      else{
         return additionHelper(toAdd, *this);
       }

  }

  Integer Integer::additionHelper(const Integer & larger, const Integer & smaller) const{
    Integer temp(larger.toString());
    auto toAddItr = smaller.digits.end();
    auto itr = temp.digits.end();
    do{
        toAddItr--;
        itr--;
        *itr += *toAddItr;
    }while(toAddItr != smaller.digits.begin());
    temp.normalise();
    return temp;
  }

  //Private Functions
  std::string Integer::toString() const {
    std::string numeric;

    for(short int i : digits){
        numeric += std::to_string(i);
    }

    return numeric;
  }

  int Integer::compare(const Integer & toCompare) const{
    if(digits.size() < toCompare.digits.size()){
      return -1;
    }
    else if(digits.size() > toCompare.digits.size()){
      return 1;
    }
    else{
        auto testPair = std::mismatch(digits.begin(), digits.end(), toCompare.digits.begin());
        return *(testPair).first - *(testPair).second;
    }
  }
}

namespace ExactArithmetic{


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

    void Integer::normalise() {

        auto digitsItr = --digits.end();
        while(digitsItr!= digits.begin()){
            if(*digitsItr > 9){
                *digitsItr = *digitsItr % 10;
                if(digitsItr == digits.begin()){
                    digits.push_front(1);
                    return;
                }
                else
                    (*--digitsItr)++;
            }
            else if(*digitsItr < 0){
                *digitsItr = *digitsItr + 10;
                (*--digitsItr)--;
            }
            else
                --digitsItr;
        }
        while(*digitsItr == 0 && digitsItr != --digits.end()){
                digits.erase(digitsItr++);
        }
    }
}
=======
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
>>>>>>> development
