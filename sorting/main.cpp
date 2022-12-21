#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h> 
#include "sorting.hpp" 



int main() { 
    std::vector<int> regArray; 

    regArray.push_back(10);
    regArray.push_back(3);
    regArray.push_back(7);
    regArray.push_back(12);
    regArray.push_back(1);
    regArray.push_back(15);
    regArray.push_back(67);
    regArray.push_back(35);
    regArray.push_back(65);
    regArray.push_back(90);
    regArray.push_back(12);
    regArray.push_back(5);
    regArray.push_back(6);
    regArray.push_back(8);
    regArray.push_back(16);
    regArray.push_back(54);
    regArray.push_back(29);
    regArray.push_back(72);
    regArray.push_back(88);
    regArray.push_back(61);
    regArray.push_back(51);

    mergeSort(regArray, 0, regArray.size()-1);


    for (int i = 0; i < regArray.size(); i++) 
        printf("\n%d\n", regArray[i]); 










    
}
