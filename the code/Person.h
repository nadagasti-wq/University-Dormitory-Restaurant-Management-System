#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std ;
class Person{
private:
string name ;
public :
Person() ;
Person(string n);
virtual ~Person() ;
virtual string getName() const ;
virtual void displayInfo() const ;
};


#endif