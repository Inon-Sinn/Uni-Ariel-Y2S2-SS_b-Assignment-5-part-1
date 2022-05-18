#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;


TEST_CASE("20 Test"){

    for (size_t i = 0; i < 20; i++)
    {
        CHECK_EQ(i,i+1);
    }
    
}