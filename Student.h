#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {
 public:
  Student();
  ~Student();
  char* first;
  char* last;
  int id;
  float gpa;
 private:
};

#endif