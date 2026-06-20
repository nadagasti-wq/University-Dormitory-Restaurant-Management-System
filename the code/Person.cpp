#include<iostream>
#include "Person.h"
Person::Person() {
    name=" ";
}
Person::Person(string n){
    name=n ;
}
string Person::getName() const {
    return name ;
}
 void Person::displayInfo() const {
   cout<<"the name : "<<name<<endl ;
 }
Person::~Person() {
}

