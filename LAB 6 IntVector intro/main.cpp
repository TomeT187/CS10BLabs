#include "IntVector.h"
#include <iostream>
using namespace std;


int main(){

    //vector with size and capacity 10 filled with 10

    int size;
    int value;
    cout << "Enter vector size" << endl;
    cin >> size;
    cout << "Enter the value for all indices" << endl;
    cin >> value;
    IntVector test(size,value);

    cout << "Should output " << size << " for both" << endl;
    cout << "Test size: " << test.size() << endl;
    cout << "Test capacity: " << test.capacity() << endl << endl;

    cout << "Should output " << false << endl;
    cout << "Test is not empty " << test.empty() << endl << endl;
    
    int index;
    cout << "Enter an index to check" << endl;
    cin >> index;
    cout << "If index is out of bounds, program will abort" << endl;
    cout << "Should output " <<  value <<" at index " << index << endl;
    cout << "Value at index " << index << ": " << test.at(index) << endl << endl;

    cout << "Should output " << value << " for both front and back" << endl;
    cout << "Value at Front: " << test.front() << endl;
    cout << "Value at Back: " << test.back() << endl << endl;

    //test with an empty vector
    IntVector emptyTest(0,5);
    cout << "Should output " << true << endl;
    cout << "Test is  empty " << emptyTest.empty()  << endl << endl;


    cout << "Will abort the program after this test is ran and display error message" << endl;
    int outOfBonds = 999;
    cout << "Value out of Bounds: " << emptyTest.at(outOfBonds);

    

    
    return 0;
}