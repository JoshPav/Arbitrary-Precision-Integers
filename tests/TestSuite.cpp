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

    BOOST_AUTO_TEST_CASE ( StringZeroTest)
    {
        std::string myString = "0";

        ExactArithmetic::Integer aInt(myString);

        BOOST_CHECK_EQUAL("0", aInt.toString());
    }

    BOOST_AUTO_TEST_CASE( CheckString)
    {
        std::string myString = "184467440737095533123123242316131231923719235";

        ExactArithmetic::Integer aInt(myString);

        BOOST_CHECK_EQUAL(myString, aInt.toString());
    }

    BOOST_AUTO_TEST_CASE( ZeroLeadingString)
    {
        std::string myString = "00000000000000006225315";

        ExactArithmetic::Integer aInt(myString);

        BOOST_CHECK_EQUAL("6225315", aInt.toString());
    }

    BOOST_AUTO_TEST_CASE( SymbolInMiddle)
    {
        BOOST_CHECK_THROW(ExactArithmetic::Integer("23123??23123"),std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE( CheckInvalidString )
    {
        BOOST_CHECK_THROW(ExactArithmetic::Integer("as"),std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE( CheckNegative )
    {
        BOOST_CHECK_THROW(ExactArithmetic::Integer("-1"),std::invalid_argument);
    }


BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE ( ComparisonTests)

    BOOST_AUTO_TEST_CASE(  EqualTrue  )
    {
        ExactArithmetic::Integer aInt1("461651252542");
        ExactArithmetic::Integer aInt2("461651252542");

        BOOST_CHECK ( aInt1 == aInt2);
    }

    BOOST_AUTO_TEST_CASE( EqualFalse )
    {
        ExactArithmetic::Integer aInt1("461651252542");
        ExactArithmetic::Integer aInt2("4551541");

        BOOST_CHECK ( (aInt1 == aInt2) == false);
    }

    BOOST_AUTO_TEST_CASE( NotEqualTrue )
    {
        ExactArithmetic::Integer aInt1("462542");
        ExactArithmetic::Integer aInt2("461651252542");

        BOOST_CHECK ( aInt1 != aInt2);
    }

    BOOST_AUTO_TEST_CASE( NotEqualFalse )
    {
        ExactArithmetic::Integer aInt1("7826978");
        ExactArithmetic::Integer aInt2("7826978");

        BOOST_CHECK ( (aInt1 != aInt2) == false);
    }
    
    BOOST_AUTO_TEST_CASE( LessThanTrue )
    {
        ExactArithmetic::Integer aInt1("234");
        ExactArithmetic::Integer aInt2("7826978");

        BOOST_CHECK_LT ( aInt1 ,aInt2);
    }
    
    BOOST_AUTO_TEST_CASE( LessThanSameSize )
    {
        ExactArithmetic::Integer aInt1("7826977");
        ExactArithmetic::Integer aInt2("7826978");

        BOOST_CHECK_LT ( aInt1 ,aInt2);
    }

    BOOST_AUTO_TEST_CASE( LessThanFalse )
    {
        ExactArithmetic::Integer aInt1("7826978");
        ExactArithmetic::Integer aInt2("726266");

        BOOST_CHECK ( (aInt1  < aInt2) == false );
    }

    BOOST_AUTO_TEST_CASE( LessThanSameNumber )
    {
        ExactArithmetic::Integer aInt1("7826978");
        ExactArithmetic::Integer aInt2("7826978");

        BOOST_CHECK ( (aInt1  < aInt2) == false );
    }    
    
    BOOST_AUTO_TEST_CASE( GreaterThanTrue )
    {
        ExactArithmetic::Integer aInt1("2562156515415");
        ExactArithmetic::Integer aInt2("562156");

        BOOST_CHECK_GT ( aInt1,  aInt2);
    }

    BOOST_AUTO_TEST_CASE( GreaterThanFalse )
    {
        ExactArithmetic::Integer aInt1("15225");
        ExactArithmetic::Integer aInt2("4522542525");

        BOOST_CHECK ( (aInt1  > aInt2) == false );
    }

    BOOST_AUTO_TEST_CASE( GreaterThanSameNumber )
    {
        ExactArithmetic::Integer aInt1("4525515625525");
        ExactArithmetic::Integer aInt2("4525515625525");

        BOOST_CHECK ( (aInt1  > aInt2) == false );
    }  

    BOOST_AUTO_TEST_CASE( GreaterThanSameSize )
    {
        ExactArithmetic::Integer aInt1("12552174551");
        ExactArithmetic::Integer aInt2("12552167451");

        BOOST_CHECK_GT ( aInt1,  aInt2);
    }  
    
    BOOST_AUTO_TEST_CASE( LessThanEqualTrue )
    {
        ExactArithmetic::Integer aInt1("456163522");
        ExactArithmetic::Integer aInt2("4525515625525");

        BOOST_CHECK_LE ( aInt1 , aInt2 );
    }

    BOOST_AUTO_TEST_CASE( LessThanEqualFalse )
    {
        ExactArithmetic::Integer aInt1("162263226");
        ExactArithmetic::Integer aInt2("2554866");

        BOOST_CHECK ( (aInt1  <= aInt2) == false );
    }

    BOOST_AUTO_TEST_CASE( LessThanEqualSame )
    {
        ExactArithmetic::Integer aInt1("4636630566");
        ExactArithmetic::Integer aInt2("4636630566");

        BOOST_CHECK_LE ( aInt1 , aInt2 );
    }

    BOOST_AUTO_TEST_CASE( GreaterThanEqualTrue )
    {
        ExactArithmetic::Integer aInt1("62222222244843229");
        ExactArithmetic::Integer aInt2("4525515625525");

        BOOST_CHECK_GE ( aInt1 , aInt2 );
    }

    BOOST_AUTO_TEST_CASE( GreaterThanEqualFalse )
    {
        ExactArithmetic::Integer aInt1("1231235");
        ExactArithmetic::Integer aInt2("23749237682");

        BOOST_CHECK ( (aInt1  >= aInt2) == false );
    }

    BOOST_AUTO_TEST_CASE( GreaterThanEqualSame )
    {
        ExactArithmetic::Integer aInt1("123652378230");
        ExactArithmetic::Integer aInt2("123652378230");

        BOOST_CHECK_GE ( aInt1 , aInt2 );
    }
    
BOOST_AUTO_TEST_SUITE_END()