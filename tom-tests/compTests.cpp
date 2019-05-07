#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "integer.h"
#include <stdexcept>

using namespace ExactArithmetic;


BOOST_AUTO_TEST_SUITE(constructorTests)

// ==

BOOST_AUTO_TEST_CASE(smallNumEqual){
  Integer newInt(0);
  Integer newInt2(0);

  BOOST_CHECK_EQUAL(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(bigNumEqual){
  Integer newInt(345639);
  Integer newInt2(345639);

  BOOST_CHECK_EQUAL(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(equalFasle){
  Integer newInt(345638);
  Integer newInt2(345639);

  BOOST_CHECK((newInt == newInt2) == false);
}
//!=
BOOST_AUTO_TEST_CASE(smallNumNotEqual){
  Integer newInt(0);
  Integer newInt2(1);

  BOOST_CHECK(newInt != newInt2);
}
BOOST_AUTO_TEST_CASE(bigNumNotEqual){
  Integer newInt(34897924);
  Integer newInt2(42792834);

  BOOST_CHECK(newInt != newInt2);
}
BOOST_AUTO_TEST_CASE(EqualDifferentLengths){
  Integer newInt(0);
  Integer newInt2(10);

  BOOST_CHECK(newInt != newInt2);
}
BOOST_AUTO_TEST_CASE(notEqualFalse){
  Integer newInt(345639);
  Integer newInt2(345639);

  BOOST_CHECK((newInt != newInt2) == false);
}
// >
BOOST_AUTO_TEST_CASE(smallNumGreater){
  Integer newInt(1);
  Integer newInt2(0);

  BOOST_CHECK_GT(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(bigNumGreater){
  Integer newInt(54897924);
  Integer newInt2(42792834);

  BOOST_CHECK_GT(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(DifferentLengthsGreater){
  Integer newInt(10);
  Integer newInt2(1);

  BOOST_CHECK_GT(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(greaterFalse){
  Integer newInt(1);
  Integer newInt2(10);

  BOOST_CHECK((newInt > newInt2) == false);
}

// <

BOOST_AUTO_TEST_CASE(smallNumLess){
  Integer newInt(0);
  Integer newInt2(1);

  BOOST_CHECK_LT(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(bigNumLess){
  Integer newInt(34897924);
  Integer newInt2(42792834);

  BOOST_CHECK_LT(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(DifferentLengthsLess){
  Integer newInt(1);
  Integer newInt2(10);

  BOOST_CHECK_LT(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(lessFalse){
  Integer newInt(10);
  Integer newInt2(1);

  BOOST_CHECK((newInt < newInt2) == false);
}

// >=
BOOST_AUTO_TEST_CASE(smallNumGreaterEqual){
  Integer newInt(1);
  Integer newInt2(0);

  BOOST_CHECK_GE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(bigNumGreaterEqual){
  Integer newInt(54897924);
  Integer newInt2(42792834);

  BOOST_CHECK_GE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(DifferentLengthsGreaterEqual){
  Integer newInt(10);
  Integer newInt2(1);

  BOOST_CHECK_GE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(smallNumEqualGreater){
  Integer newInt(0);
  Integer newInt2(0);

  BOOST_CHECK_GE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(bigNumEqualGreater){
  Integer newInt(345639);
  Integer newInt2(345639);

  BOOST_CHECK_GE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(greaterEqualFalse){
  Integer newInt(1);
  Integer newInt2(10);

  BOOST_CHECK((newInt >= newInt2) == false);
}

// <=
BOOST_AUTO_TEST_CASE(smallNumLessEqual){
  Integer newInt(0);
  Integer newInt2(1);

  BOOST_CHECK_LE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(bigNumLessEqual){
  Integer newInt(34897924);
  Integer newInt2(42792834);

  BOOST_CHECK_LE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(DifferentLengthsLessEqual){
  Integer newInt(1);
  Integer newInt2(10);

  BOOST_CHECK_LE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(smallNumEqualLess){
  Integer newInt(0);
  Integer newInt2(0);

  BOOST_CHECK_LE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(bigNumEqualLess){
  Integer newInt(345639);
  Integer newInt2(345639);

  BOOST_CHECK_LE(newInt , newInt2);
}
BOOST_AUTO_TEST_CASE(lessEqualFalse){
  Integer newInt(10);
  Integer newInt2(1);

  BOOST_CHECK((newInt <= newInt2) == false);
}

BOOST_AUTO_TEST_SUITE_END()
