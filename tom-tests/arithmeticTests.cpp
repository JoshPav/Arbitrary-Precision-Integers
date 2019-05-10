#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE IntegerTests
#include <boost/test/unit_test.hpp>

#include "integer.h"
#include <stdexcept>

using namespace ExactArithmetic;


BOOST_AUTO_TEST_SUITE(ArithmeticTests)

  BOOST_AUTO_TEST_SUITE(additionTests)

    BOOST_AUTO_TEST_CASE(addSimplestCase){
    Integer newInt(0);
    Integer newInt2(0);
    Integer newInt3 = newInt + newInt2;

    BOOST_CHECK_EQUAL(newInt3 , Integer("0"));
    }

    BOOST_AUTO_TEST_CASE(NzeroIsN){
    Integer newInt(0);
    Integer newInt2(3);
    Integer newInt3 = newInt + newInt2;

    BOOST_CHECK_EQUAL(newInt3 , Integer("3"));
    }

    BOOST_AUTO_TEST_CASE(addSimpleCase){
    Integer newInt(3);
    Integer newInt2(2);
    Integer newInt3 = newInt + newInt2;

    BOOST_CHECK_EQUAL(newInt3 , Integer("5"));
    }

    BOOST_AUTO_TEST_CASE(addFrontAppend){
    Integer newInt(5);
    Integer newInt2(5);
    Integer newInt3 = newInt + newInt2;

    BOOST_CHECK_EQUAL(newInt3 , Integer("10"));
    }

    BOOST_AUTO_TEST_CASE(addOverflow){
    Integer newInt(9);
    Integer newInt2(9);
    Integer newInt3 = newInt + newInt2;

    BOOST_CHECK_EQUAL(newInt3 , Integer("18"));
    }

    BOOST_AUTO_TEST_CASE(addMulyipleOVerflow){
    Integer newInt(16849);
    Integer newInt2(7238);
    Integer newInt3 = newInt + newInt2;

    BOOST_CHECK_EQUAL(newInt3 ,Integer("24087");
    }

    BOOST_AUTO_TEST_CASE(addMulyipleOverflowAndFrontAppend){
    Integer newInt(16849);
    Integer newInt2(97238);
    Integer newInt3 = newInt + newInt2;

    BOOST_CHECK_EQUAL(newInt3.toString() ,Integer("114087");
    }
    BOOST_AUTO_TEST_CASE(>MAXINT){
    Integer newInt(18446744073709551615);
    Integer newInt2(2);
    Integer newInt3 = newInt + newInt2;

    BOOST_CHECK_EQUAL(newInt3.toString() ,Integer("18446744073709551617");
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(subtractionTests)

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(multiplicationTests)
    BOOST_AUTO_TEST_CASE(zeroTimesZero){

    }
  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(divisionTests)

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
