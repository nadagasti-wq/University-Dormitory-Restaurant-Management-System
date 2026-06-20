#include "Dormitory.h"
#include<stdexcept>
#include <iostream>
#include <vector>
#include <string>
using namespace std ;
Dormitory::Dormitory() {
    name=" ";
    id=0 ;
    capacity=0;
}
Dormitory::Dormitory(string n,int id,int c,Restaurant r){
    name=n;
    this->id=id ;
    capacity=c ;
    restaurant=r ;
}
string Dormitory::getName() const{
    return name ;
}
int Dormitory::getId() const{
    return id ;
}
int Dormitory::getCapacity() const{
    return capacity ;
}
vector<Room> Dormitory::getRooms() const{
    return rooms ;
}
Room Dormitory::getRoom(int i) const{
    if(i<0 || i> rooms.size()){
        throw(out_of_range("you index is out of range"));
    }
    else{
        return rooms[i] ;
    }
}
Restaurant Dormitory::getRestaurant() const{
    return restaurant ;
}
bool Dormitory::addRoom(Room r) {
    for(auto i:rooms){
        if(i.getNumber() ==r.getNumber()){
            cout<<"the room already exists "<<endl ;
            return false ;
        }
    }
    rooms.push_back(r);
    return true ;
}
Room* Dormitory::findRoom(int num){
    for(auto& i: rooms){
        if(i.getNumber() == num){
            return &i ;
        }
    }
    return nullptr ;
}
int Dormitory::gettotalOccupency() const{
    int total=0 ;
    for(auto i: rooms){
        total += i.getOccupency() ;
    }
    return total ;
}
void Dormitory::setName(string n){
    name=n; 
}
void Dormitory::setId(int a){
    if(a<0){
        throw( invalid_argument("your id is an invalid argument"));
    }
    else{
        id=a ;
    }
}
void Dormitory::setCapacity(int c) {
    if(c<0){
        throw(invalid_argument("your capacity is an invalid argument"));
    }
    else{
        capacity=c ;
    }
}
void Dormitory::setRestaurant(Restaurant r) {
    restaurant=r ;
}