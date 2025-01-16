#include "Student.h"

using namespace std;

Student::Student() {
  first = new char[50];
  last = new char[50];
  id = 0;
  gpa = 0;
}

Student::~Student() {
  delete first;
  delete last;
}
