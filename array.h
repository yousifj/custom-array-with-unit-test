/**
 * Author: Yousif Jabbo
 * Simple Array class
 */

#ifndef ARRAY_H
#define ARRAY_H

#define BUFFERSIZE 4 


class Array{
public:
    /**
     * @brief Default constructor.
     *
     * Initialize an empty array and member variables
     *
     */
    Array();
    /**
     * @brief Array destructor.
     *
     * Removes the array to avoid memeory leak
     *
     */
    ~Array();
    /**
     * @brief overload the += operator to insert operator a number into the array
     * internally it uses the add function
     * 
     * @param i: The number to insert
     * 
     * @return refernce to the current object, for chained operations.
    */
    Array& operator +=(int);
    /**
     * add - inserts element in the array.
     * If the array is at full capacity, the capacity is increased before
     * inserting the new element.
     *
     * @param  i: The number to insert.
     *
     */
    void add(int);
    /**
     * @brief overload the [] operator to allow acess to the element of the array using array syntax
     *  internally uses get function
     * 
     * @param index: index of element to return
     * 
     * @return value of the given index
     */
    int& operator [](int);
    /**
     * @brief get - retreve element by index
     * Check if index is inbound otherwise thows out of range exeption.
     * 
     * 
     * @param index: index of element to return
     * 
     * @return refernce to the element in the array
     */
    int& get(int);
    /**
     * @brief remove - Removes element in the array by value.
     * 
     *
     * @param  item: The item to remove.
     *
     * @return: true if element is remove, false otherwise
     */
    bool removeElement(int);
    /**
     * @brief removeIndex - Removes element in the array by index.
     * 
     *
     * @param  item: The item index to remove.
     *
     * @return: true if element is remove, false otherwise
     */
    bool removeIndex(int);
    /**
     * @brief sort - sorts the array inorder smallers to biggest
     * uses quick sort best time run time complexity  of o log n, worst time n^2
     * 
     */
    void sort();
    /**
     * @brief print - loops over the array to print current elements
     */
    void print();
    /**
     * @brief getSize - getter for the size of the array
     * 
     * @return size of the array
     */
    inline int getSize()const{return size;}

private:
    //member variables
    int * data;
    int size;
    int capacity;
    /**
     * @brief findIndex - helper to find the index of an element
     * 
     * @parma element to search in the array
     * 
     * @return -1 if element does not exists, index of element if it exists
     */
    int findIndex(int);
    /**
     * @brief increaseCapacity - Doubles the current capacity of the array
     * copies over all current element to a new array of bigger size
     * removes the old array to avoid memory leak
     * 
     */
    void increaseCapacity();
    /**
     * @brief quickSort- algorthim to sort an array
     * 
     * This is a recursive algorithm that sorts the array by selecting a pivot element
     * and then moving all elements smaller than the pivot to the left, and all elements
     * greater than the pivot to the right. The pivot then fits in its correct position.
     * The process continues recursively on the subarrays until the entire array is sorted.
     * The subarrays do no need to be compared to each other so this saves time.
     * 
     * 
     * @param data: pointer to the array to sort
     * @param left: index to start element to sort
     * @param right: index to the last element to sort
     * 
     */
    void quickSort(int* ,int,int);
};

#endif // ARRAY_H