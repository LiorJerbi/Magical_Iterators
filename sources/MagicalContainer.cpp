#include "MagicalContainer.hpp"
#include <vector>

using namespace ariel;
using namespace std;

MagicalContainer::MagicalContainer():_container(),_size(0){}
void MagicalContainer::addElement(int num){

}
void MagicalContainer::removeElement(int num){      //need to change imple for add and remove

}
int MagicalContainer::size() const{
    return _size;
}
std::vector<int>& MagicalContainer::getContainer(){
    return _container;
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : _container(other._container), _current_index(other._current_index) {}
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : _container(container), _current_index(0) {}
MagicalContainer::AscendingIterator::~AscendingIterator(){}
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : _container(other._container), _current_index(other._current_index) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : _container(container), _current_index(0) {}
MagicalContainer::SideCrossIterator::~SideCrossIterator(){}
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : _container(other._container), _current_index(other._current_index) {}
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : _container(container), _current_index(0) {}
MagicalContainer::PrimeIterator::~PrimeIterator(){}