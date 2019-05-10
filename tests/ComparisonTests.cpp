#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"

using namespace ExactArithmetic;

BOOST_AUTO_TEST_SUITE ( ComparisonTests)

    BOOST_AUTO_TEST_CASE(  EqualTrue  )
    {
        Integer aInt1("461651252542");
        Integer aInt2("461651252542");

        BOOST_CHECK ( aInt1 == aInt2);
    }

    BOOST_AUTO_TEST_CASE( EqualFalse )
    {
        Integer aInt1("461651252542");
        Integer aInt2("4551541");

        BOOST_CHECK ( (aInt1 == aInt2) == false);
    }

    BOOST_AUTO_TEST_CASE( NotEqualTrue )
    {
        Integer aInt1("462542");
        Integer aInt2("461651252542");

        BOOST_CHECK ( aInt1 != aInt2);
    }

    BOOST_AUTO_TEST_CASE( NotEqualFalse )
    {
        Integer aInt1("7826978");
        Integer aInt2("7826978");

        BOOST_CHECK ( (aInt1 != aInt2) == false);
    }
    
    BOOST_AUTO_TEST_CASE( LessThanTrue )
    {
        Integer aInt1("234");
        Integer aInt2("7826978");

        BOOST_CHECK_LT ( aInt1 ,aInt2);
    }
    
    BOOST_AUTO_TEST_CASE( LessThanSameSize )
    {
        Integer aInt1("7826977");
        Integer aInt2("7826978");

        BOOST_CHECK_LT ( aInt1 ,aInt2);
    }

    BOOST_AUTO_TEST_CASE( LessThanFalse )
    {
        Integer aInt1("7826978");
        Integer aInt2("726266");

        BOOST_CHECK ( (aInt1  < aInt2) == false );
    }

    BOOST_AUTO_TEST_CASE( LessThanSameNumber )
    {
        Integer aInt1("7826978");
        Integer aInt2("7826978");

        BOOST_CHECK ( (aInt1  < aInt2) == false );
    }    
    
    BOOST_AUTO_TEST_CASE( GreaterThanTrue )
    {
        Integer aInt1("2562156515415");
        Integer aInt2("562156");

        BOOST_CHECK_GT ( aInt1,  aInt2);
    }

    BOOST_AUTO_TEST_CASE( GreaterThanFalse )
    {
        Integer aInt1("15225");
        Integer aInt2("4522542525");

        BOOST_CHECK ( (aInt1  > aInt2) == false );
    }

    BOOST_AUTO_TEST_CASE( GreaterThanSameNumber )
    {
        Integer aInt1("4525515625525");
        Integer aInt2("4525515625525");

        BOOST_CHECK ( (aInt1  > aInt2) == false );
    }  

    BOOST_AUTO_TEST_CASE( GreaterThanSameSize )
    {
        Integer aInt1("12552174551");
        Integer aInt2("12552167451");

        BOOST_CHECK_GT ( aInt1,  aInt2);
    }  
    
    BOOST_AUTO_TEST_CASE( LessThanEqualTrue )
    {
        Integer aInt1("456163522");
        Integer aInt2("4525515625525");

        BOOST_CHECK_LE ( aInt1 , aInt2 );
    }

    BOOST_AUTO_TEST_CASE( LessThanEqualFalse )
    {
        Integer aInt1("162263226");
        Integer aInt2("2554866");

        BOOST_CHECK ( (aInt1  <= aInt2) == false );
    }

    BOOST_AUTO_TEST_CASE( LessThanEqualSame )
    {
        Integer aInt1("4636630566");
        Integer aInt2("4636630566");

        BOOST_CHECK_LE ( aInt1 , aInt2 );
    }

    BOOST_AUTO_TEST_CASE( GreaterThanEqualTrue )
    {
        Integer aInt1("62222222244843229");
        Integer aInt2("4525515625525");

        BOOST_CHECK_GE ( aInt1 , aInt2 );
    }

    BOOST_AUTO_TEST_CASE( GreaterThanEqualFalse )
    {
        Integer aInt1("1231235");
        Integer aInt2("23749237682");

        BOOST_CHECK ( (aInt1  >= aInt2) == false );
    }

    BOOST_AUTO_TEST_CASE( GreaterThanEqualSame )
    {
        Integer aInt1("123652378230");
        Integer aInt2("123652378230");

        BOOST_CHECK_GE ( aInt1 , aInt2 );
    }
    
BOOST_AUTO_TEST_SUITE_END()