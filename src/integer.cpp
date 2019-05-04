#include "integer.h"


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

  std::string Integer::toString() const {
    std::string numeric;

    for(short int i : digits){
        numeric += std::to_string(i);
    }

    return numeric;
  }
}
