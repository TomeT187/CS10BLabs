
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
   void SetName(string employeeName) {
      name = employeeName;
   }

   virtual void PrintInfo() {
      cout << name << endl;
   }

protected:
   string name;
};

class Author : public Employee {
public:
   void SetGenre(string setGenre) {
      genre = setGenre;
   }

   void PrintInfo() {
      cout << name << " writes " << genre << endl;
   }

private:
   string genre;
};

class Designer : public Employee {
public:
   void SetObject(string setObject) {
      object = setObject;
   }

   void PrintInfo() {
      cout << name << " designs " << object << endl;
   }

private:
   string object;
};

int main() {
   Employee* person1;
   Author* person2;
   Designer* person3;

   vector<Employee*> personList;
   unsigned int i;

   person1 = new Employee();
   person1->SetName("Amy");

   person2 = new Author();
   person2->SetName("Bill");
   person2->SetGenre("mysteries");

   person3 = new Designer();
   person3->SetName("Mia");
   person3->SetObject("clothes");

   personList.push_back(person1);
   personList.push_back(person3);
   personList.push_back(person2);

   for (i = 0; i < personList.size(); ++i) {
      personList.at(i)->PrintInfo();
   }
   
   return 0;
}