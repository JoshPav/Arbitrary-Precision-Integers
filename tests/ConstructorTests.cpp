#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"

using namespace ExactArithmetic;

BOOST_AUTO_TEST_SUITE(ConstructorTests)

    BOOST_AUTO_TEST_CASE( CheckDefualtConstructor )
    {
        Integer I;
        BOOST_CHECK_EQUAL( "0", I.toString() );
    }

    BOOST_AUTO_TEST_CASE (CheckLowestInt)
    {
        unsigned long long int lInt = 0;

        Integer aInt(lInt);
        
        BOOST_CHECK_EQUAL(std::to_string(lInt), aInt.toString());

    }

    BOOST_AUTO_TEST_CASE( CheckLongInt)
    {
        unsigned long long int lInt = 18446744073709551615U;

        Integer aInt(lInt);

        BOOST_CHECK_EQUAL(std::to_string(lInt), aInt.toString());
    }

    BOOST_AUTO_TEST_CASE ( StringZeroTest)
    {
        std::string myString = "0";

        Integer aInt(myString);

        BOOST_CHECK_EQUAL("0", aInt.toString());
    }

    BOOST_AUTO_TEST_CASE( CheckString)
    {
        std::string myString = "184467440737095533123123242316131231923719235";

        Integer aInt(myString);

        BOOST_CHECK_EQUAL(myString, aInt.toString());
    }

    BOOST_AUTO_TEST_CASE( ZeroLeadingString)
    {
        std::string myString = "00000000000000006225315";

        Integer aInt(myString);

        BOOST_CHECK_EQUAL("6225315", aInt.toString());
    }

    BOOST_AUTO_TEST_CASE( SymbolInMiddle)
    {
        BOOST_CHECK_THROW(Integer("23123??23123"),std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE( CheckInvalidString )
    {
        BOOST_CHECK_THROW(Integer("as"),std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE( CheckNegative )
    {
        BOOST_CHECK_THROW(Integer("-1"),std::invalid_argument);
    }


BOOST_AUTO_TEST_SUITE_END()