#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize <= 0){
        return nullptr;
    }
    if(arrSize == 1){
        return arr;
    }else{
        const int* temp = (min(arr + 1,arrSize-1));
        if(arr[0] > *temp){ // if (first > min(arr + 1,arrSize-1))
            return temp;    // return min(arr + 1,arrSize-1)
        }else{
            return arr;//returns first element if its smallest
        }

        //same thing in different order
        // if (arr[arrSize - 1] > *(min(arr,arrSize-1)) ){
        //     return min(arr,arrSize - 1);
        // }else{
        //     return (arr + arrSize - 1);
        // }
        
    }
}