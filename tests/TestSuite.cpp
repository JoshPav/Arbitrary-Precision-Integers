#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ArbitraryIntegers
#include <boost/test/unit_test.hpp>
#include "integer.h"


BOOST_AUTO_TEST_SUITE(ConstructorTests)

    BOOST_AUTO_TEST_CASE( CheckDefualtConstructor )
    {
        ExactArithmetic::Integer I;
        BOOST_CHECK_EQUAL( "0", I.toString() );
    }

    BOOST_AUTO_TEST_CASE (CheckLowestInt)
    {
        unsigned long long int lInt = 0;

        ExactArithmetic::Integer aInt(lInt);
        
        BOOST_CHECK_EQUAL(std::to_string(lInt), aInt.toString());

    }

    BOOST_AUTO_TEST_CASE( CheckLongInt)
    {
        unsigned long long int lInt = 18446744073709551615U;

        ExactArithmetic::Integer aInt(lInt);

        BOOST_CHECK_EQUAL(std::to_string(lInt), aInt.toString());
    }

    BOOST_AUTO_TEST_CASE( CheckString)
    {
        std::string myString = "184467440737095533123123242316131231923719235";

        ExactArithmetic::Integer aInt(myString);

        BOOST_CHECK_EQUAL(myString, aInt.toString());
    }

    BOOST_AUTO_TEST_CASE( CheckInvalidString )
    {
        BOOST_CHECK_THROW(ExactArithmetic::Integer("as"),std::invalid_argument);
    }

BOOST_AUTO_TEST_SUITE_END()