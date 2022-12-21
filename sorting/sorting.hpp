#include <stdio.h>
#include <stdlib.h>
#include <vector> 
#include <string> 
#include <iostream> 

/*
 * We are essentially going to implement multple different sorting algorithms. 
 *
 * Here are the list of sorting algorithms that are mentioned below: 
 *
 * - Merge Sort
 *
 * Merge Sort begins by taking the midpoint of the entire function and then recursively calling mergeSort()
 * on each of the two halves. 
 *
 * We are only concerned about holding the indices of each half, delegating a right and left index. 
 *
 * Thus, the recursive call should look like...
 *
 *      mergeSort(A, left-end, mid);
 *      mergeSort(A, mid+1, right-end); 
 *
 *
 *
 *
 *
 * - Quick Sort
 *
 * - Bubble Sort
 *
 * - Insertion Sort
 *
 *
 *
 *
 *
 *
 *
 */


void printVector(std::vector<int> printing) {
    for (int i = 0; i < printing.size(); i++) 
        printf("\n%d\n", printing[i]);
}





void merge(std::vector<int>& sorting, int left, int right, int mid) {
    std::vector<int> subOne;
    std::vector<int> subTwo; 
    printf("\n\n-------------------BEGINNING OF FULL ARRAY MERGING--------------------\n");
    printf("\n\nLeft: %d\nRight: %d\nMid: %d\n\n", left, right, mid);
    for (int i = left; i < mid+1; i++) 
        subOne.push_back(sorting[i]);
   
    printVector(subOne);
    std::cout << "PRINTED SUBONE ^\n\n\n" << std::endl;
    
    for (int i = mid+1; i <= right; i++) 
        subTwo.push_back(sorting[i]);
    
    printVector(subTwo);
    std::cout << "PRINTED SUBTWO ^\n\n\n" << std::endl; 

    int x = 0;
    int y = 0; 
    while (x < subOne.size() && y < subTwo.size()) {
        if (subOne[x] >= subTwo[y]) {
            sorting[left+x+y] = subTwo[y];
            y++;
       } else {
            sorting[left+x+y] = subOne[x];
            x++;
     }
    }

    while (x < subOne.size()) {
        sorting[left+x+y] = subOne[x]; 
        x++;
    }
    
    while (y < subTwo.size()) {
        sorting[left+x+y] = subTwo[y]; 
        y++;
    }

    printf("\n\nPRINTING FULL ARRAY:\n\n");
    printVector(sorting);
    printf("\n\n\n-------------DONE WITH FULL ARRAY--------------\n");
}




// WORKING EXAMPLE, JUST NEED TO RECONFIGURE SOME THINGS! Try making this bottom function run! Good practice. 

/*
void merge(std::vector<int> sorting, int left, int right, int mid) {
    std::vector<int> sortedArray; // Temporary array to hold the sorted variables 
    int lpos = left; 
    int rpos = mid+1;

    //left max is mid
    //right max is right
    
    int lsize = (mid - left) + 1;
    int rsize = (right - mid); 
    int x = 0; 
    int y = 0; 
    while (x < lsize && y < rsize) { 
        if (sorting[lpos+x] <= sorting[rpos+y]) {
            sortedArray.push_back(sorting[lpos+x]);
            x++; 
        } else {
            sortedArray.push_back(sorting[rpos+y]);
            y++;
        }
    }

     while (x < lsize) {
         sortedArray.push_back(sorting[lpos + x]);
         x++;
     }

     while (y < rsize) {
         sortedArray.push_back(sorting[rpos+y]);
         y++;
     }
  
    for (int i = left; i < sortedArray.size(); i++) 
        sorting[i] = sortedArray[i]; 
    
}
*/


void mergeSort(std::vector<int>& unsorted, int left, int right) {
    if (left >= right) // If the left index is greater, then size is less than 1. 
        return; 
    
    int mid = left + ((right - left) / 2); // The midpoint of the array based on the indices of left and right  
    
    mergeSort(unsorted, left, mid); // Recursively call mergeSort on the array and the left and midpoint indices 
    mergeSort(unsorted, mid+1, right); // Recursively call mergeSort on the array and midpoint + 1 and the right indices 
    merge(unsorted, left, right, mid); // Call merge on the entire array so that you can combine the two halves into the correct position
}


