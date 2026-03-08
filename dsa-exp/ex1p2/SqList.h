#ifndef SEQUENCEDLIST_H  
#define SEQUENCEDLIST_H  

#include <vector>
#include <stdexcept>

template <typename T>
class SequencedList {
private:
    std::vector<T> elements;

public:
    SequencedList();
    ~SequencedList();

    void push_back(const T& element);
    void insert(size_t index, const T& element);
    T& at(size_t index);
    const T& at(size_t index) const;
    size_t size() const;
    bool empty() const;
    void clear();
};

template <typename T>
SequencedList<T>::SequencedList()
{
    // Constructor implementation  
}

template <typename T>
SequencedList<T>::~SequencedList()
{
    // Destructor implementation  
}

template <typename T>
void SequencedList<T>::push_back(const T& element)
{
    elements.push_back(element);
}

template <typename T>
void SequencedList<T>::insert(size_t index, const T& element)
{
    if (index > elements.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    elements.insert(elements.begin() + index, element);
}

template <typename T>
T& SequencedList<T>::at(size_t index)
{
    if (index >= elements.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

template <typename T>
const T& SequencedList<T>::at(size_t index) const
{
    if (index >= elements.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

template <typename T>
size_t SequencedList<T>::size() const
{
    return elements.size();
}

template <typename T>
bool SequencedList<T>::empty() const
{
    return elements.empty();
}

template <typename T>
void SequencedList<T>::clear()
{
    elements.clear();
}

#include "SqList.cpp"  

#endif // SEQUENCEDLIST_H