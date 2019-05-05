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

  void Integer::normalise(){
    int carryBit = 0;
    auto itr = --digits.end();
    for(int i =0; i < digits.size(); i++){

        *itr += carryBit;
        if(*itr < 0){
            *itr += 10;
            carryBit = -1;
        }
        else if(*itr > 9){
            *itr -= 10;
            carryBit = 1;
        }
        else{
            carryBit = 0;
        }
        itr--;
    }
    if(carryBit == -1){
      //if theres still a negative carry bit at the end throw error as resulting number is less than 0
      throw NegativeNumberError();
    }
    else if(carryBit == 1){
      digits.push_front(1);
    }

    //remove leading zeros
  }
}
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
                *D = *D % 10;
                if(D == digits.begin()){
                    digits.push_front(1);
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
        }
        }
        while(*D == 0 && D != --digits.end()){
                digits.erase(D++);
        }
    }
}
