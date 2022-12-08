#include <iostream>
#include <iterator>


using namespace std;

template <typename T, size_t size>

class AAVector 
{
private:
  T* vecPtr = new T[size];
public:

    // Constructors and Big 4 
    AAVector (int capacity = 0);			// Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    AAVector (T* arr, int nitems);		// Initialize by n items from array 
    AAVector (const AAVector& anotherVec);	// Initialize with a copy
    ~AAVector();			// Delete allocated memory
    AAVector &operator=(const AAVector& anotherVec);  // Copy assignment  
    AAVector &operator=(const AAVector&& anotherVec); // Move assignment 

    // Access operations 
    T& operator[](int index); // Access item by reference 
    // Throw an exception if out of range 

    // Modifying operations 
    int push_back(T item); // Add item to end of vec & return # of items 
            // Increase capacity of needed
    T pop_back();     // Remove and return last element in vec 
    void erase(iterator it);        // Remove item at iterator
                // Throw exception if invalid iter 
    void erase(iterator it1, iterator it2); // Remove items between 
    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range
    void clear();     // Delete all vector content
    void insert(iterator it, T item);       // Insert item at iterator 
    // Throw exception if invalid 

    // Iterators 		// Supports *, + and ++ operations at least
    // Can use: typedef T* iterator 
    // Or u can use std::iterator so you can 
    // apply STL algorithms on AAVector
    iterator begin();	// Return an iterator (T*) 
    iterator end();	// Return an iterator (T*) 

    // Comparison operations 
    bool operator==(const AAVector<T>&); // Return true if ==  
    bool operator< (const AAVector<T>&); // Compares item by item // Return true if first different item in this is < in other

    // Capacity operations 
    int size(); const     // Return current size of vec
    int capacity(); const // Return size of current allocated array  
    int resize();         // Relocate to bigger space
    bool empty();         // Return true if size is 0

    // Friends 
    friend ostream& operator << (ostream& out, AAvector<T>)

};
