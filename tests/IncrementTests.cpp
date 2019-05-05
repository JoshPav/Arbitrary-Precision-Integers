#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"

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