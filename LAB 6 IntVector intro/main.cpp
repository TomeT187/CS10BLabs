#include "IntVector.h"
#include <iostream>
using namespace std;


int main(){
    int size = 10;
    int values = 10;
    IntVector test(size,values);
    cout << "Test size: " << test.size() << endl;
    cout << "Test capacity: " << test.capacity() << endl;

    IntVector emptyTest(0,5);
    cout << "Test is not empty if 0 = " << test.empty() << endl;
    cout << "Test is  empty if 1 = " << emptyTest.empty() << endl;

    int index = 3;
    cout << "Value at index " << index << ": " << test.at(index) << endl;

    cout << "Value at Front: " << test.front() << endl;
    cout << "Value at Back: " << test.back() << endl;

    //will abort the program after this test is ran
    int outOfBonds = 999;
    cout << "Value out of Bounds: " << test.at(outOfBonds);

    

    
    return 0;
}