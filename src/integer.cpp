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
