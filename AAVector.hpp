#ifndef AAVECTOR_HPP
#define AAVECTOR_HPP

#include <iostream>
#include <iterator>

using namespace std;


template <typename T>
class AAVector 
{
private:
  int size, capacity;
  T* vecPtr;
public:
  struct Iterator 
  {
  public:

    using iterator_category = random_access_iterator_tag;
    using difference_type   = ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;  

    //Constructor
    Iterator(pointer p): ptr(p){}

    Iterator& operator=(Iterator& it)
    {
      this->ptr = it.ptr;
      return *this;
    }

    Iterator& operator=(pointer& p)
    {
      ptr = p;
      return *this;
    }
    
    reference operator*() const {return *ptr;}
    pointer operator->() {return ptr;}
    //++it;
    Iterator& operator++(){ptr++; return *this;}
    //it++;
    Iterator operator++(int) 
    {
      auto oldit = *this;
      ++(*this);
      return oldit;
    }
    //--it;
    Iterator& operator--(){ptr--; return *this;}
    //it--;
    Iterator operator--(int) 
    {
      auto tmp = *this;
      --(*this);
      return tmp;
    }
    
    bool operator< (Iterator& it2) const {return (ptr < it2.ptr);}
    bool operator<= (Iterator& it2) const {return (ptr <= it2.ptr);}

    bool operator> (Iterator& it2) const  {return (ptr > it2.ptr);}
    bool operator>= (Iterator& it2) const {return (ptr >= it2.ptr);}

    Iterator operator+(const int& n) const {return Iterator(ptr + n);}
    Iterator operator+=(const int& n) {ptr += n; return *this;}

    Iterator operator-(const int& n) const {return Iterator(ptr - n);}
    Iterator operator-=(const int& n) {ptr -= n; return *this;}

    friend bool operator== (const Iterator& p1, const Iterator& p2) { return p1.ptr == p2.ptr; };
    friend bool operator!= (const Iterator& p1, const Iterator& p2) { return p1.ptr != p2.ptr; };

  private:
    pointer ptr;
  };
  // Constructors and Big 4 
  AAVector (int capacity = 0);
  // Initialize by specific capacity
  // No content is added, size = 0
  // Assign a default size value
  AAVector (T* arr, int nitems);		// Initialize by n items from array 
  AAVector (const AAVector& anotherVec);	// Initialize with a copy
  AAVector (AAVector&& anotherVec);
  ~AAVector();			// Delete allocated memory
  AAVector &operator=(const AAVector& anotherVec); // Copy assignment  
  AAVector &operator=(AAVector&& anotherVec); // Move assignment 

  // Access operations 
  T& operator[](int index); // Access item by reference 
  // Throw an exception if out of range 

  // Modifying operations 
  int push_back(T item); // Add item to end of vec & return # of items 
                        // Increase capacity of needed
  T pop_back(); // Remove and return last element in vec 
  void erase(Iterator it);  // Remove item at iterator
  // Throw exception if invalid iter 
  void erase(Iterator it1, Iterator it2); // Remove items between 
  // iterator 1 <= iterator 2 otherwise do nothing
  // Throw exception if any iterator outside range
  void clear();     // Delete all vector content
  void insert(Iterator it, T item);       // Insert item at iterator 
  // Throw exception if invalid 

  // Iterators 		// Supports *, + and ++ operations at least
  // Can use: typedef T* iterator 
  // Or u can use std::iterator so you can 
  // apply STL algorithms on AAVector
  Iterator begin() const {AAVector<T>::Iterator it (vecPtr); return it;}	// Return an iterator (T*) 
  Iterator end() const {AAVector<T>::Iterator it (vecPtr + size); return it;}	// Return an iterator (T*) 

  // Comparison operations 
  bool operator==(const AAVector<T>& vec2); // Return true if ==  
  bool operator< (const AAVector<T>& vec2); // Compares item by item // Return true if first different item in this is < in other

  // Capacity operations 
  int Size() const {return size;}    // Return current size of vec
  int Capacity() const {return capacity;} // Return size of current allocated array  
  void resize(int newSize);         // Relocate to bigger space
  bool empty();         // Return true if size is 0

  // Friends
  friend ostream& operator<<(ostream& out, const AAVector<T>& vec)
  {
    out << '{';
    for (int i = 0; i < vec.size; i++)
    {
      if (i == vec.size - 1)
      {
        out << vec.vecPtr[i] << '}' << endl;
        break;
      }
      out << vec.vecPtr[i] << ", ";
    }
    return out;
  }
};

#endif