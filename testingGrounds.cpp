
#include <iostream>
#include <string>
using namespace std;

class Students {
   public:
      Students();
      Students(int);
      int GetTotal() const { return  numStudents; }

   private:
      int numStudents;
};

Students::Students() : numStudents(0) {}
Students::Students(int num) : numStudents(num) {}

class Tutor {
   public:
      Tutor(string);
      Tutor(string, int);
      void Print() const;

   private:
      string name;
      Students students;
};

Tutor::Tutor(string tutorName) : name(tutorName) {}
Tutor::Tutor(string tutorName, int numStudents) : name(tutorName), students(numStudents) {}

void Tutor::Print() const {
   if (students.GetTotal() == 0){
      cout << name << " is alone" << endl;
   }
   else {
      cout << name << " has " << students.GetTotal() << " students" << endl;
   }
}

int main() {
   Tutor myTutor("May");
   Tutor yourTutor("Eve", 2);

   yourTutor.Print();
   myTutor.Print();

   return 0;
}