#include <iostream>
#include <string>
#include "sources/MagicalContainer.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_SUITE("Magical Container Methods:"){
    MagicalContainer container;

    TEST_CASE("add/remove/size methods"){
        CHECK(container.size() == 0);
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
    TEST_CASE("AscendingIterator:"){
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        container.addElement(1);
        container.addElement(14);
        MagicalContainer::AscendingIterator asIt(container);
        auto it = asIt.begin();
        CHECK_EQ(*it,1);
        CHECK_NOTHROW(++it); 
        auto it1 = ++it;        //should be 2
        CHECK_EQ(*it1,2);
        ++it1,++it;
        CHECK(it1>it);      // 5>2
        CHECK_NE(it,asIt.end());
        
        string ans;
        MagicalContainer::AscendingIterator itr =asIt.begin();
        for(;itr != asIt.end();++itr){
            ans += *itr + ' ';
        }
        CHECK_EQ(ans,"1 2 4 5 14 ");

        CHECK_NOTHROW(asIt = ++it1);
        CHECK_EQ(asIt.begin(),it.begin());
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
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        container.addElement(1);
        container.addElement(14);
        MagicalContainer::SideCrossIterator scIt(container);
        auto it = scIt.begin();
        CHECK_EQ(*it,1);
        CHECK_NOTHROW(++it);
        auto it1 = ++it;    //should be 14
        CHECK_EQ(*it1,14);
        string ans;
        MagicalContainer::SideCrossIterator itr = scIt.begin();
        for(;itr != scIt.end();++itr){
            ans += *itr + ' ';
        }
        CHECK_EQ(ans,"1 14 2 5 4 ");
        CHECK_NOTHROW(scIt = ++it);
        CHECK_EQ(scIt.begin(),it.begin());

        container.addElement(7);
        CHECK_EQ(6,container.size());
        scIt.setIndex(4);
        CHECK_EQ(*scIt,5);

        container.removeElement(1);
        CHECK_EQ(5,container.size());
    }
    TEST_CASE("PrimeIterator:"){
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(4);
        container.addElement(1);
        container.addElement(14);
        MagicalContainer::PrimeIterator prIt(container);
        auto it = prIt.begin();
        CHECK_EQ(*it,2);
        CHECK_NOTHROW(++it);
        auto it1 = ++it;        //should be 5
        CHECK(it1>it);      // 5>2
        CHECK_NE(it,prIt.end());

        string ans;
        MagicalContainer::PrimeIterator itr = prIt.begin();
        for(;itr != prIt.end();++itr){
            ans += *itr + ' ';
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
