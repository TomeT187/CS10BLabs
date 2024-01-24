#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string filename,char ch){
   int count = 0;
   ifstream fin;
   fin.open(filename);
   //char temp;
   if (!fin.is_open()){
      cout << "Error opening " << filename << endl;
      exit(EXIT_FAILURE);
      return 1;
   }
   string input;
   // while(getline(fin,input)){
      
   //    for (unsigned i = 0; i < input.size(); i++){
   //       if (input[i] == ch){
   //          count++;
   //         }
   //    }
   // }
   char temp;
   while (fin.get(temp)){
      if (temp == ch){
         count++;
      }
   }


   return count;
}


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
