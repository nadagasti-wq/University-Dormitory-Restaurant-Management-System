#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include "Room.h"
using namespace std ;
 Room::Room(){
    number=0;
    capacity=0;
 }
    Room::Room(int n,int c,vector<Student> s){
        number=n ;
        capacity=c ;
        students=s ;
    }
    int Room::getNumber() const{
        return number;
    }
    int Room:: getCapacity() const {
        return capacity ;
    }
    vector<Student> Room::getStudents() const{
        return students ;
    }
    Student Room::getStudent(int i) const{
        if(i<0 || i>=students.size()){
            throw(out_of_range("your index is out of range"));
        }
        else{
            return students[i] ;
        }
    }
    bool Room::isFull() const{
        return(students.size() == capacity);
    }
    int Room::getOccupency() const{
        return students.size() ;
    }
    bool Room::addStudent(Student s){
        if(this->isFull()){
            throw(out_of_range("the room is full"));
        }
        for( auto i: students){
            if(i.getId() == s.getId()){
                cout<<"student already exist"<<endl ;
                return false ;
            }
        }
        students.push_back(s) ;
        return true ;
        
    }
    bool Room::removeStudent(int id) {
         for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getId() == id)
        {
            students.erase(students.begin() + i);
            return true;
        }
    }
        return false ;
    }
     
void Room::setNumber(int n){
    if(n<0){
        throw(invalid_argument("room number cannot be negative"));
    }
    else{
        number=n ;
    }
}
void Room::setCapacity(int c){
    if(c<0){
        throw(invalid_argument("capacity cannot be negative"));
    }
    else if(c < (int)students.size()){
        throw(invalid_argument("new capacity is smaller than current occupancy"));
    }
    else{
        capacity=c ;
    }
}