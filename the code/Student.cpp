#include "Student.h" 
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std ;
Student::Student():Person(){
    id=0;
    year=0;
}
Student::Student(string n,int i,int y):Person(n){
    if(i<0 || y<0){
        throw(invalid_argument("you gave invalid arguments"));
    }
    else{
        id=i ;
        year=y ;
    }
}
int Student::getId() const {
    return id ;
}
int Student::getYear() const {
    return year ;
}
 void Student::displayInfo() const {
    this->Person::displayInfo();
    cout<<"the id : "<<id<<endl ;
    cout<<"the year : "<<year<<endl ;
 }
 void Student::setId(int i){
    if(i<0){
        throw(invalid_argument("you id is less then 0"));
    }
    else{
        id=i ;
    }
 }
void Student::setYear(int y){
    if(y<0){
        throw(invalid_argument("your year is negative")) ;
    }
    else{
        year=y ;
    }
}
