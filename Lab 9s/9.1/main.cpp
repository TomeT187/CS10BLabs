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
   
   cout << "going" << endl;
   string temp = s.substr(1,s.size() - 1);
   flipString(temp);
   cout << temp <<"here" <<  s.at(0) << endl;
   s = temp + s.at(0);
   
   
   // flipString(s);
}
