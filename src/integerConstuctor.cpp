#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE IntegerTests
#include <boost/test/unit_test.hpp>

#include "integer.h"
#include <stdexcept>

using namespace ExactArithmetic;

BOOST_AUTO_TEST_SUITE(constructorTests)

BOOST_AUTO_TEST_CASE(useDefaultConstructor){
  Integer newInt;
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "0");
}

BOOST_AUTO_TEST_CASE(minumum){
  Integer newInt(0);
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "0");
}

BOOST_AUTO_TEST_CASE(maximum){
  Integer newInt(18446744073709551);
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "18446744073709551");
}
BOOST_AUTO_TEST_CASE(lessThanMinumum){
  BOOST_CHECK_THROW(Integer(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(greaterThanMaximum){
  BOOST_CHECK_THROW(Integer(18446744073709552), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
