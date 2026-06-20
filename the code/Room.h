#ifndef ROOM_H
#define ROOM_H
#include<string>
#include<vector>
#include "Student.h"
using namespace std ;
class Room{
    private:
    int number ;
    int capacity ;
    vector<Student> students ;
    public:
    Room();
    Room(int n,int c,vector<Student> s);
    int getNumber() const;
    int getCapacity() const ;
    void setNumber(int i) ;
    void setCapacity(int i) ;
    vector<Student> getStudents() const;
    Student getStudent(int i) const;
    bool isFull() const;
    int getOccupency() const;
    bool addStudent(Student s);
    bool removeStudent(int id) ;
};
#endif