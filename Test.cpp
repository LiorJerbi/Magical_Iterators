#include <iostream>
#include <string>
#include "sources/MagicalContainer.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_SUITE("Magical Container Methods:"){
    MagicalContainer container;

    TEST_CASE("add/remove/size methods"){
        CHECK_THROWS_AS(container.removeElement(2),runtime_error);  //can't remove from empty container
        container.addElement(1);
        container.addElement(7);
        container.addElement(5);
        CHECK_EQ(container.size(),3);

        CHECK_NOTHROW(container.removeElement(1));
        container.removeElement(1);
        CHECK_EQ(container.size(),2);
        
        CHECK_THROWS(container.removeElement(1)); // removing elemnt not exsist       
        
    }

}
TEST_SUITE("Iterators Methods:"){
    MagicalContainer container;
    TEST_CASE("AscendingIterator:"){
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        container.addElement(1);
        container.addElement(14);
        MagicalContainer::AscendingIterator asIt(container);
        auto it = asIt.begin();
        CHECK_EQ(*it,1);
        auto it1 = ++it;        //should be 2
        CHECK_NOTHROW(++it1);   
        ++it1;
        CHECK(it1>it);      // 5>2
        CHECK_NE(it,asIt.end());
        string ans;
        for(;it != asIt.end();++it){
            ans += *it + ' ';
        }
        CHECK_EQ(ans,"1 2 4 5 14 ");
        CHECK_NOTHROW(asIt = ++it1);
        CHECK_EQ(asIt.begin(),it);
        ++it1;
        CHECK(asIt.begin()<it1);    //1<14

        container.addElement(7);
        CHECK_EQ(6,container.size());
        asIt.setIndex(4);
        CHECK_EQ(*asIt,7);

        container.removeElement(1);
        CHECK_EQ(5,container.size());
    }   
    TEST_CASE("SideCrossIterator:"){
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        container.addElement(1);
        container.addElement(14);
        MagicalContainer::SideCrossIterator scIt(container);
        auto it = scIt.begin();
        CHECK_EQ(*it,1);
        CHECK_NOTHROW(++it);
        string ans;
        for(;it != scIt.end();++it){
            ans += *it + ' ';
        }
        CHECK_EQ(ans,"1 14 2 5 4 ");
        CHECK_NOTHROW(scIt = ++it);
        CHECK_EQ(scIt.begin(),it);

        container.addElement(7);
        CHECK_EQ(6,container.size());
        scIt.setIndex(4);
        CHECK_EQ(*scIt,5);

        container.removeElement(1);
        CHECK_EQ(5,container.size());
    }
    TEST_CASE("PrimeIterator:"){
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        container.addElement(1);
        container.addElement(14);
        MagicalContainer::PrimeIterator prIt(container);
        auto it = prIt.begin();
        CHECK_EQ(*it,2);
        auto it1 = ++it;        //should be 5
        CHECK_NOTHROW(++it1);   
        CHECK(it1>it);      // 5>2
        CHECK_NE(it,prIt.end());

        string ans;
        for(;it != prIt.end();++it){
            ans += *it + ' ';
        }
        CHECK_EQ(ans,"2 5 ");

        container.addElement(7);
        CHECK_EQ(6,container.size());
        prIt.setIndex(2);
        CHECK_EQ(*prIt,7);

        container.removeElement(1);
        CHECK_EQ(5,container.size());
    }    
}
