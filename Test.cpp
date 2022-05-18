#include "doctest.h"
#include "sources/OrgChart.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace ariel;

TEST_CASE("20 Test"){

    

    for (size_t i = 0; i < 20; i++)
    {
        CHECK_EQ(i,i+1);
    }
    
}

TEST_CASE("Initiation"){
    OrgChart family_1;
    CHECK_THROWS(family_1.add_sub("none","Father"));
    CHECK_NOTHROW(family_1.add_root("Father"));
    CHECK_NOTHROW(family_1.add_sub("Father","Son_1"));
    CHECK_THROWS(family_1.add_sub("none","Son_2"));
    CHECK_NOTHROW(family_1.add_root("GrandFather"));
}

TEST_CASE("bad inputs")
{
    OrgChart family;
    family.add_root("Grandfather");
    family.add_sub("Grandfather","Father");
    family.add_sub("Father","Son_1");
    family.add_sub("Father","Son_2");
    family.add_sub("Father","Son_3");
    family.add_sub("Son_1","Grandson_1");
    family.add_sub("Son_2","Grandson_2");
    family.add_sub("Son_3","Grandson_3");

    SUBCASE("level order")
    {
        std::vector<std::string> test = {"Grandfather","Father",
                                        "Son_1","Son_2","Son_3",
                                        "Grandson_1","Grandson_2","Grandson_3"};

        for (auto it = family.begin_level_order(); it != family.end_level_order(); ++it){
            CHECK_EQ(*it,test.front());
            test.erase(test.begin());
        }
    }

    SUBCASE("reverse order")
    {
        std::vector<std::string> test = {"Grandson_1","Grandson_2","Grandson_3",
                                        "Son_1","Son_2","Son_3",
                                        "Grandfather","Father"};

        for (auto it = family.begin_level_order(); it != family.end_level_order(); ++it){
            CHECK_EQ(*it,test.front());
            test.erase(test.begin());
        }
    }

    SUBCASE("preorder")
    {
        std::vector<std::string> test = {"Grandfather","Father",
                                        "Son_1","Grandson_1",
                                        "Son_2","Grandson_2",
                                        "Son_3","Grandson_3"};

        for (auto it = family.begin_level_order(); it != family.end_level_order(); ++it){
            CHECK_EQ(*it,test.front());
            test.erase(test.begin());
        }
    }
}

