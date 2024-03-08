#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;
   return 0;
}

//Implement the flipString function here

void flipString(string &s){
   if(s.size() <= 0 ){
      return; // end recursion if s is empty
   }else{
      string temp = s.substr(1,s.size() - 1); //temp = string without last index
      flipString(temp);                       //flip temp // temp is now shorter by 1 
      s = temp + s.at(0);                     // s = temp + last index // 
   }
   
   
}
