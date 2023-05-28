#include "MagicalContainer.hpp"
#include <vector>

using namespace ariel;
using namespace std;

MagicalContainer::MagicalContainer():_container(),_size(0){}
void MagicalContainer::addElement(int num){
    _container.push_back(num);
    _size++;
}
void MagicalContainer::removeElement(int num){      //need to change imple for add and remove
    _container.pop_back();
    _size--;
}
int MagicalContainer::size() const{
    return _size;
}
std::vector<int>& MagicalContainer::getContainer(){
    return _container;
}

AscendingIterator::AscendingIterator(const AscendingIterator& other) : _container(other._container), _current_index(other._current_index) {}
AscendingIterator::AscendingIterator(MagicalContainer& container) : _container(container), _current_index(0) {}
AscendingIterator::~AscendingIterator(){}
SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : _container(other._container), _current_index(other._current_index) {}
SideCrossIterator::SideCrossIterator(MagicalContainer& container) : _container(container), _current_index(0) {}
SideCrossIterator::~SideCrossIterator(){}
PrimeIterator::PrimeIterator(const PrimeIterator& other) : _container(other._container), _current_index(other._current_index) {}
PrimeIterator::PrimeIterator(MagicalContainer& container) : _container(container), _current_index(0) {}
PrimeIterator::~PrimeIterator(){}