//include any standard libraries needed
#include <iostream>
#include <fstream>
using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
   double sum = 0;
   for (int i = 0; i < arraySize; i++){
      sum += array[i];
   }
   return sum / arraySize;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
   //int lastIndex = arraySize;
   for (int i = index; i < arraySize; i++){
      if (i < arraySize - 1){
         array[i] = array[i +1];
         
      }
      if ( i == arraySize - 1){
         arraySize--;
      }
   }
   // if(array[arraySize -1] == array[lastIndex]){
   //    arraySize--;
   // }else{
   //    arraySize = lastIndex - 1;
   // }
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
   for(int i = 0; i < arraySize; i++){
      cout << array[i];
      if (i != arraySize - 1){
         cout << ", ";
      }
   }
}


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   // verify file name provided on command line
   if (argc < 2){
      return 1;
   }
   string filename = argv[1];

   // open file and verify it opened
   ifstream fin(filename);
   if (!fin.is_open()){
      cout << filename << " failed to open" << endl;
   }

   // Declare an array of doubles of size ARR_CAP.
   double array[ARR_CAP];

    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   double fileInput;
   int counter = 0;
   while(fin >> fileInput){
      array[counter] = fileInput;
      counter++;
   }
   


    
   // Call the mean function passing it this array and output the 
   // value returned.
   cout << "Mean: " << mean(array,counter) << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int index;
   cout << "Enter index of value to be removed (0 to " << counter - 1 << " ):" << endl;
   cin >> index;
	
   // Call the display function to output the array.
   cout << "Before removing value:";
   display(array,counter);
   cout << endl;

   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(array,counter,index);
  
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value:";
   display(array,counter);
   cout << endl;

   
   // Call the mean function again to get the new mean
   cout << "Mean:" << mean(array,counter) << endl;

   
	return 0;
}