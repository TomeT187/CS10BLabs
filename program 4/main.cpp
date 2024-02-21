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
    int outOfBonds = size + 1;
    cout << "Value out of Bounds: " << emptyTest.at(outOfBonds);


    IntVector test(5,5);
    test.at(0) = 10;
    cout << test.at(0) << endl;
    
    // not real functions
    // cout << test.capacity() << endl << "expansion:" << endl;;
    // test.expand();
    // cout << test.capacity() << endl;
    

    // test.at(9) = 999;
    // cout << test.at(9) << endl;
    // test.testExpand();

    
    cout << "Original Front: " << test.front() << endl;
    test.front() = 88;
    cout << "New Front: " << test.front() << endl;


    cout << "Original back: " << test.back() << endl;
    test.back() = 77;
    cout << "New back: " << test.back() << endl;

    cout << "pushing back" << endl;
    test.push_back(55);
    cout << test.back() << endl;

    cout << "popping back" << endl;
    test.pop_back();
    cout << test.back() << endl;
    
    cout << "Before Insert" << endl;
   for (unsigned i = 0; i < test.size(); i++){
    cout << test.at(i);
   }
   cout << endl;
   test.insert(3,2);
   cout << "after insert" << endl;
   for (unsigned i = 0; i < test.size(); i++){
    cout << test.at(i);
   }
   cout << endl;
   test.erase(3);
   cout << "after erase" << endl;
   for (unsigned i = 0; i < test.size(); i++){
    
    cout << test.at(i);
   }
  
   cout << "Before assign" << endl;
   for (unsigned i = 0; i < test.size(); i++){
    cout << test.at(i);
   }
   cout << endl << "after assign";
   test.assign(4,4);
   for (unsigned i = 0; i < test.size(); i++){
    cout << test.at(i);
   }
   cout << endl;
    
   test.resize(4);
   for (unsigned i = 0; i < test.size(); i++){
    cout << test.at(i);
   }
   cout << endl;

   test.resize(8);
   for (unsigned i = 0; i < test.size(); i++){
    cout << test.at(i);
   }
   cout << endl;

   test.resize(10,7);
   for (unsigned i = 0; i < test.size(); i++){
    cout << test.at(i);
   }
   cout << endl;
   
   cout << "Original capacity" << endl;
   cout << test.capacity() << endl;
   test.reserve( 10);
   cout << "New capacity" << endl;
   cout << test.capacity() << endl;
   cout << "with lower reserve" << endl;
   test.reserve( 5);
   cout << test.capacity() << endl;
   IntVector temp;
    cout << "start";
    temp.push_back(5);
    cout << "pushed";
    cout << temp.at(0);
    IntVector* ptr = new IntVector;
    delete ptr;
    cout << "deleted2";
    IntVector test;
    test.insert(1,100);
    for (unsigned i = 0; i < test.size(); i++){
        cout << test.at(i);
    }


    
    return 0;
}