#include "integer.h"


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
