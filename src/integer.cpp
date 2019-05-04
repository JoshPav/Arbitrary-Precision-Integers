#include "integer.h"


namespace ExactArithmetic{
  Integer::Integer(){
      digits.push_back(0);
  }

  Integer::Integer(unsigned long long int){

  }

    Integer::Integer(const std::string &){

  }

  std::string Integer::toString() const{
    std::string numeric;

    for(short int i : digits){
        numeric += std::to_string(i);
    }

    return numeric;
  }
}
