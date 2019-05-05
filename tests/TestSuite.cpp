#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ArbitraryIntegers
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"

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

BOOST_AUTO_TEST_SUITE ( IncrementTests)

    BOOST_AUTO_TEST_CASE ( PostIncrementCheckIncrement )
    {
        ExactArithmetic::Integer I("462394910834");

        I++;

        BOOST_CHECK_EQUAL(I.toString(),"462394910835");
    }

    BOOST_AUTO_TEST_CASE ( PostIncrementCheckPost )
    {
        ExactArithmetic::Integer I("1234");

        BOOST_CHECK_EQUAL((I++).toString(),"1234");
    }

    BOOST_AUTO_TEST_CASE ( PostIncrementCheckCarry )
    {
        ExactArithmetic::Integer I("745999999999999999999");
        I++;
        BOOST_CHECK_EQUAL(I.toString(),"746000000000000000000");
    }

    BOOST_AUTO_TEST_CASE ( PostIncrementCheckAddDigit )
    {
        ExactArithmetic::Integer I("999");
        I++;
        BOOST_CHECK_EQUAL(I.toString(),"1000");
    }

    BOOST_AUTO_TEST_CASE ( PreIncrementCheckIncrement )
    {
        ExactArithmetic::Integer I("342432256");
        ++I;
        BOOST_CHECK_EQUAL(I.toString(),"342432257");
    }

    BOOST_AUTO_TEST_CASE ( PreIncrementCheckPre )
    {
        ExactArithmetic::Integer I("13262621652");

        BOOST_CHECK_EQUAL((++I).toString(),"13262621653");
    }

    BOOST_AUTO_TEST_CASE ( PreIncrementCheckCarry )
    {
        ExactArithmetic::Integer I("621515699999999999");
        ++I;
        BOOST_CHECK_EQUAL(I.toString(),"621515700000000000");
    }

    BOOST_AUTO_TEST_CASE ( PreIncrementCheckAddDigit )
    {
        ExactArithmetic::Integer I("999");
        ++I;
        BOOST_CHECK_EQUAL(I.toString(),"1000");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementCheckDecrement )
    {
        ExactArithmetic::Integer I("615614541");

        I--;

        BOOST_CHECK_EQUAL(I.toString(),"615614540");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementCheckPost )
    {
        ExactArithmetic::Integer I("1234");

        BOOST_CHECK_EQUAL((I--).toString(),"1234");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementCheckCarry )
    {
        ExactArithmetic::Integer I("746000000000000000000");
        I--;
        BOOST_CHECK_EQUAL(I.toString(),"745999999999999999999");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementCheckRemoveDigit )
    {
        ExactArithmetic::Integer I("1000");
        I--;
        BOOST_CHECK_EQUAL(I.toString(),"999");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementZeroCheck)
    {
        ExactArithmetic::Integer I("0");
        BOOST_CHECK_THROW (I-- , ExactArithmetic::NegativeNumberError);
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementCheckDecrement )
    {
        ExactArithmetic::Integer I("342432256");
        --I;
        BOOST_CHECK_EQUAL(I.toString(),"342432255");
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementCheckPre )
    {
        ExactArithmetic::Integer I("13262621652");

        BOOST_CHECK_EQUAL((--I).toString(),"13262621651");
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementCheckCarry )
    {
        ExactArithmetic::Integer I("621515700000000000");
        --I;
        BOOST_CHECK_EQUAL(I.toString(),"621515699999999999");
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementCheckRemoveDigit )
    {
        ExactArithmetic::Integer I("1000");
        --I;
        BOOST_CHECK_EQUAL(I.toString(),"999");
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementZeroCheck)
    {
        ExactArithmetic::Integer I("0");
        BOOST_CHECK_THROW (--I , ExactArithmetic::NegativeNumberError);
    }

BOOST_AUTO_TEST_SUITE_END()