#include <iostream>
#include <cstring>
#include <bits/stdc++.h> //from https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
#include "Node.h"
#include "Student.h"

using namespace std;

void ADD(Node* &current, Node* head, Student* addStud);
void PRINT(Node* head);
void DELETE(int rmID, Node* &current, Node* head);
void AVERAGE(float gpa, int count, Node* current);

int main() {
  Node* head = NULL;
  bool running = true;
  
  while (running) {
    cout << "Enter ADD, PRINT, DELETE, AVERAGE, or QUIT" << endl << "> ";
    char input[10];
    cin.get(input, 11);
    cin.get();
    if (strcmp(input, "ADD") == 0) { //create node and add to head
      Student* addStud = new Student();
      //ask for student details
      cout << "Last Name: ";
      cin.get(addStud->last, 51);
      cin.get();
      cout << "First name: ";
      cin.get(addStud->first, 51);
      cin.get();
      cout << "Student ID: ";
      cin >> addStud->id;
      cin.ignore();
      cout << "Student GPA: ";
      cin >> addStud->gpa;
      cin.ignore();
      ADD(head, head, addStud);
    } else if (strcmp(input, "PRINT") == 0) {
      PRINT(head);
    } else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter the ID you want to delete" << endl << "> ";
      int rmID = 0;
      cin >> rmID;
      cin.ignore();
      DELETE(rmID, head, head);
    } else if (strcmp(input, "AVERAGE") == 0) {
      //use recursion
      AVERAGE(0, 0, head);
    } else if (strcmp(input, "QUIT") == 0) {
      //end program
      cout << "Ending program";
      running = false;
    } else {
      cout << "Check capitalization or spelling" << endl << endl;
    }
  }
  return 0;
}

void ADD(Node* &current, Node* head, Student* addStud) { //insert node according to student id  
  if (current == NULL) { //if head is empty
    current = new Node(addStud);
    current->setNext(NULL);
    return;
  }
  if (addStud->id <= current->getStudent()->id) { //added student has a lower/same id
    Node* temp = current;
    current = new Node(addStud);
    current->setNext(temp);
  } else if (current->getStudent()->id < addStud->id) { //new stud has larger id
    if (current->getNext() != NULL && current->getNext()->getStudent()->id < addStud->id) { //new stud has larger id than next
      Node* next = current->getNext();
      ADD(next, head, addStud);
    } else { //new stud is larger than current but smaller than next
      Node* insert = new Node(addStud);
      insert->setNext(current->getNext());
      current->setNext(insert);
    }
  }
}

void PRINT(Node* head) {
  if (head != NULL) { //make sure not empty
    cout << head->getStudent()->first << " " << head->getStudent()->last << ", " << head->getStudent()->id << ", " << fixed << setprecision(2) << head->getStudent()->gpa << endl;
    if (head->getNext() != NULL) {
      PRINT(head->getNext()); //recursion!
    }
  }
}

void DELETE(int rmID, Node* &current, Node* head) {
  //first node stuff
  if (current == head && current->getStudent()->id == rmID) {
    if (current->getNext() == NULL) {
      delete current;
      current = NULL;
    } else {
      Node* temp = current;
      current = current->getNext();
      delete temp;
    }
  }
  if (current->getNext() != NULL) {
    if (current->getNext()->getStudent()->id == rmID) {
      Node* temp = current->getNext();
      current->setNext(current->getNext()->getNext()); //set the next to next's next
      delete temp;
    } else {
      Node* next = current->getNext();
      DELETE(rmID, next, head);
    }
  }
}

void AVERAGE(float gpa, int count, Node* current) {
  if (current != NULL) {
    gpa += current->getStudent()->gpa;
    count++;
    Node* next = current->getNext();
    AVERAGE(gpa, count, next); //go again and keep adding to gpa until end of list
  } else {
    cout << "AVERAGE GPA: " << fixed << setprecision(2) << gpa / count << endl;
  }
}
