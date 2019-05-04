#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE IntegerTests
#include <boost/test/unit_test.hpp>

#include "integer.h"

using namespace ExactArithmetic;

BOOST_AUTO_TEST_SUITE(constructorTests)

BOOST_AUTO_TEST_CASE(useDefaultConstructor){
  Integer newInt;
  std::string s = newInt.toString();
  BOOST_CHECK_EQUAL(s, "0");
}

BOOST_AUTO_TEST_SUITE_END()
