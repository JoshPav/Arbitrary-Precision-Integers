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

BOOST_AUTO_TEST_CASE(smallNum){
  Integer newInt(0);
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "0");
}

BOOST_AUTO_TEST_CASE(bigNum){
  Integer newInt(18446744073709551615);
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "18446744073709551615");
}

BOOST_AUTO_TEST_CASE(stringSimpleValue){
  Integer newInt("00");
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "0");
}

BOOST_AUTO_TEST_CASE(stringLongValue){
  Integer newInt("94374023974587495302570234587490573458758390");
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "94374023974587495302570234587490573458758390");
}

BOOST_AUTO_TEST_CASE(stringLeadingZeros){
  Integer newInt("0000000001");
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "1");
}
BOOST_AUTO_TEST_CASE(stringInvalidInput){
  BOOST_CHECK_THROW(Integer("02914-0970974021%%"), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
