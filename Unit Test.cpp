// Author: Yousif Jabbo

#include "array.h"
#include "acutest.h"
#include <stdexcept>

/**
 * @brief testInitialization - tests if the array is created with size 0
 */
void testInitialization(void){
    Array arr;
    TEST_CHECK(arr.getSize() == 0);
}


/**
 * @brief testAddAndGet - tests if the array is initialized and working with add and get
 */
void testAddAndGet(void){
    Array arr;
    arr.add(1);    
    arr.add(2);    
    arr.add(3);
    arr.add(4);
    TEST_CHECK(arr.get(0)==1);
    TEST_CHECK(arr.get(1)==2);
    TEST_CHECK(arr.get(2)==3);
    TEST_CHECK(arr.get(3)==4);
}

/**
 * @brief testAddAndGetOperators - tests overloaded operators
 */
void testAddAndGetOperators(void){
    Array arr;
    arr += 4;
    arr += 5;
    arr += 1;
    arr += 9;
    TEST_CHECK(arr[0]==4);
    TEST_CHECK(arr[1]==5);
    TEST_CHECK(arr[2]==1);
    TEST_CHECK(arr[3]==9);
}
/**
 * @brief testRemove - tests if removing elements works as expected
 */
void testRemove(void){
    Array arr;
    arr += 4;
    arr += 5;
    arr += 57;
    arr += 99;
    //Test for removing elements that do not exist
    TEST_CHECK(arr.removeElement(11)==false);
    TEST_CHECK(arr.removeIndex(11)==false);

    //Test removeing first element
    TEST_CHECK(arr.getSize()==4);
    TEST_CHECK(arr.removeIndex(0)==true);
    TEST_CHECK(arr.getSize()==3);
    //Test if the second element is now the first since first was removed
    TEST_CHECK(arr[0]==5);
    //Remove 57 by element
    TEST_CHECK(arr[1]==57);
    TEST_CHECK(arr.removeElement(57));
    TEST_CHECK(arr[1]!=57);
}

/**
 * @brief testOutOfBond - tests if the array is initialized and working with add and get
 */
void testOutOfBond(void){
    Array arr;
    // Test on an empty array size since no element it should throw out of range
    TEST_EXCEPTION(arr.get(0), std::out_of_range);
    arr.add(1);
    TEST_EXCEPTION(arr.get(1), std::out_of_range);
}

/**
 * @brief testSort1 - tests if the array is sorted
 */
void testSort1(void){
    const int testSize =6;
    Array arr;
    arr += 5;
    arr += 2;
    arr += 1;
    arr += 0;
    arr += 3;
    arr += 4;
    arr.sort();
    int expected[testSize] = {0,1,2,3,4,5};
    for(int i=0; i < testSize ;i++){
        TEST_CHECK(arr[i]==expected[i]);
    }
}

/**
 * @brief testSort2 - tests if the array is sorted with 1000 elements
 */
void testSort2(void){
    Array arr;
    // Add 1000 elements in the decending order to the array 999 to 0
    for (int i = 999; i >= 0; i--){
        arr.add(i);
    }
    // Test if the are not sorted (expected)
    for(int i = 0; i < 1000;i++){
        TEST_CHECK(i != arr[i]);
    }
    // Sort the array 
    arr.sort();
    // Test again on the sorted array
    for(int i = 0; i < 1000;i++){
        TEST_CHECK(i == arr[i]);
    }
}



TEST_LIST = {
   { "Initialization", testInitialization },
   { "Insert and Get", testAddAndGet },
   { "Insert and Get Operators", testAddAndGetOperators },
   { "Index out of bond", testOutOfBond },
   { "Test Remove", testRemove },
   { "Test sort 1", testSort1 },
   { "Test sort 2", testSort2 },

   { NULL, NULL }     /* zeroed record marking the end of the list */
};