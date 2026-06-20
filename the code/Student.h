#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include "Person.h"
using namespace std ;
class Student: public Person{
private:
int id ;
int year ;
public:
Student() ;
Student(string n,int i,int y);
int getId() const ;
int getYear() const ;
void setId(int i);
void setYear(int y) ;
virtual void displayInfo() const ;
};
#endif