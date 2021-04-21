#include <stdio.h>
#include <fstream>
#include <sstream>
#include "NumberWithUnits.hpp"
#include "doctest.h"
using namespace ariel;
using namespace std;

ifstream units_file{"units.txt"};

TEST_CASE("Operator Overloading test:")
{
    NumberWithUnits::read_units(units_file);
    NumberWithUnits km{1, "km"};
    NumberWithUnits m{10, "m"};
    NumberWithUnits cm{30, "cm"};
    NumberWithUnits kg{3, "kg"};
    NumberWithUnits g{10, "g"};
    CHECK_EQ(km + m, NumberWithUnits{1010, "m"});
    CHECK_EQ(km - m, NumberWithUnits{990, "m"});
    CHECK_EQ(m += km, NumberWithUnits{1010, "m"});
    CHECK_EQ(m + cm, NumberWithUnits{10.3, "m"});
    CHECK_EQ(cm += m, NumberWithUnits{1030, "cm"});
    CHECK_EQ(m -= cm, NumberWithUnits{970, "m"});
    CHECK_EQ(kg + g, NumberWithUnits{3.010, "kg"});
    CHECK_EQ(g += kg, NumberWithUnits{3010, "g"});
    CHECK_EQ(kg -= g, NumberWithUnits{3, "kg"});

    NumberWithUnits::read_units(units_file);
    NumberWithUnits ton{5, "ton"};
    NumberWithUnits kg2{5000, "kg"};
    CHECK(ton >= kg2);
    kg2 = {5001, "kg"};
    CHECK(ton < kg2);
    ton++;
    CHECK(ton > kg2);
    CHECK(kg2 <= kg2);

    NumberWithUnits::read_units(units_file);
    NumberWithUnits hour{22, "hour"};
    NumberWithUnits hour2{24, "hour"};
    NumberWithUnits min{15, "min"};
    NumberWithUnits min2{30, "min"};
    NumberWithUnits sec{10, "sec"};
    CHECK_EQ(++hour, NumberWithUnits{21, "hour"});
    hour++;
    CHECK_EQ(hour, NumberWithUnits{23, "hour"});
    hour++;
    CHECK(hour == hour2);
    CHECK(min == NumberWithUnits{15, "min"});
    CHECK(min != min2);
    CHECK(--sec == (NumberWithUnits{9, "sec"}));
    CHECK_EQ(sec, NumberWithUnits{9, "sec"});
    CHECK(sec != (NumberWithUnits{12, "sec"}));
}


