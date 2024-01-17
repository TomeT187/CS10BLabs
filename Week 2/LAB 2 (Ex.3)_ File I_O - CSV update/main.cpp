#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream fin(inputFile);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!fin.is_open()){
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   
   // Read in integers from input file to vector.
   int temp;
   char commaSkipper;
   vector<int> myVec;
   while (fin >> temp){
      myVec.push_back(temp);
      cout << temp;
      fin >> commaSkipper;
   }
   
   // Close input stream.
   fin.close();
   
   // Get integer average of all values read in.
   int sum = 0;
   for (unsigned int i = 0; i < myVec.size(); i++){
      sum += myVec[i];
   }
   int average = sum / int(myVec.size());
   
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < myVec.size(); i++){
      myVec[i] = myVec[i] - average;
   }
   
   // Create output stream and open/create output csv file.
   ofstream fout(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
      if (!fout.is_open()){
      cout << "Error opening " << outputFile << endl;
      return 1;
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < myVec.size(); i++){
      fout << myVec[i];
      if (i != myVec.size() - 1){
         fout << ",";
      }
   }
   
   // Close output stream.
   fout.close();
   
   return 0;
}