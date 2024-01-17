#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename){
   int sum;
   int temp;
   ifstream fin;
   fin.open(filename);
   if (!fin.is_open()){
      cout << "Error opening " << filename << endl;
      exit(EXIT_FAILURE);
   }
   while (fin >> temp){
      sum += temp;
   }

   return sum;
}

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here