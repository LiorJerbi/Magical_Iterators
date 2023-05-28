#pragma once

#include <vector>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> _container;
        int _size;

    public:
        MagicalContainer();
        ~MagicalContainer(){}

        void addElement(int num);
        void removeElement(int num);
        int size() const;
        std::vector<int>& getContainer();
    public:
        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;

    };
    class AscendingIterator {
    private:
        MagicalContainer& _container;
        int _current_index;

    public:
        AscendingIterator(const AscendingIterator& other);
        AscendingIterator(MagicalContainer& container);
        ~AscendingIterator();
        AscendingIterator& operator=(const AscendingIterator& other) {
            _container = other._container;
            _current_index = other._current_index;
            return *this;
        }

        bool operator==(const AscendingIterator& other) const {
            return _current_index == other._current_index;
        }

        bool operator!=(const AscendingIterator& other) const {
            return !(*this == other);
        }

        bool operator>(const AscendingIterator& other) const {
            return _current_index > other._current_index;
        }

        bool operator<(const AscendingIterator& other) const {
            return _current_index < other._current_index;
        }

        int& operator*() const {
            return _container.getContainer().at(static_cast<std::vector<int>::size_type>(_current_index));
        }

        AscendingIterator& operator++() {
            ++_current_index;
            return *this;
        }

        AscendingIterator begin() {
            return AscendingIterator(_container);
        }

        AscendingIterator end() {
            AscendingIterator it(_container);
            it._current_index = _container.getContainer().size();
            return it;
        }
};

class SideCrossIterator {

    private:
        MagicalContainer& _container;
        int _current_index;

    public:
        SideCrossIterator(const SideCrossIterator& other);
        SideCrossIterator(MagicalContainer& container);
        ~SideCrossIterator();
        SideCrossIterator& operator=(const SideCrossIterator& other) {
            _container = other._container;
            _current_index = other._current_index;
            return *this;
        }

        bool operator==(const SideCrossIterator& other) const {
            return _current_index == other._current_index;
        }

        bool operator!=(const SideCrossIterator& other) const {
            return !(*this == other);
        }

        bool operator>(const SideCrossIterator& other) const {
            //need to change implementation
            return _current_index > other._current_index;
        }

        bool operator<(const SideCrossIterator& other) const {
            //need to change implementation
            return _current_index < other._current_index;
        }

        int& operator*() const {
            return _container.getContainer().at(static_cast<std::vector<int>::size_type>(_current_index));
        }

        SideCrossIterator& operator++() {
            ++_current_index;
            return *this;
        }

        SideCrossIterator begin() {
            return SideCrossIterator(_container);
        }

        SideCrossIterator end() {
            SideCrossIterator it(_container);
            //need to implement the inside
            return it;
        }
};

class PrimeIterator {
    private:
        MagicalContainer& _container;
        int _current_index;

    public:
        PrimeIterator(const PrimeIterator& other);
        PrimeIterator(MagicalContainer& container);
        ~PrimeIterator();
        PrimeIterator& operator=(const PrimeIterator& other) {
            _container = other._container;
            _current_index = other._current_index;
            return *this;
        }

        bool operator==(const PrimeIterator& other) const {
            return _current_index == other._current_index;
        }

        bool operator!=(const PrimeIterator& other) const {
            return !(*this == other);
        }

        bool operator>(const PrimeIterator& other) const {
            //need to change implementation
            return _current_index > other._current_index;
        }

        bool operator<(const PrimeIterator& other) const {
            //need to change implementation
            return _current_index < other._current_index;
        }

        int& operator*() const {
            return _container.getContainer().at(static_cast<std::vector<int>::size_type>(_current_index));
        }

        PrimeIterator& operator++() {
            ++_current_index;
            return *this;
        }

        PrimeIterator begin() {
            return PrimeIterator(_container);
        }

        PrimeIterator end() {
            PrimeIterator it(_container);
            //need to implement the inside
            return it;
        }
};
}
