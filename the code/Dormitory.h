#ifndef DORMITORY_H
#define DORMITORY_H
#include<vector>
#include "Restaurant.h"
#include "Room.h"
#include<string>
using namespace std ;
class Dormitory{
private :
string name ;
int id ;
int capacity ;
vector<Room> rooms ;
Restaurant restaurant ;
public:
Dormitory() ;
Dormitory(string n,int id,int c,Restaurant r);
string getName() const;
int getId() const;
int getCapacity() const;
vector<Room> getRooms() const;
Room getRoom(int i) const;
Restaurant getRestaurant() const;
bool addRoom(Room r) ;
Room* findRoom(int num);
int gettotalOccupency() const;
void setName(string n) ;
void setId(int a);
void setCapacity(int c) ;
void setRestaurant(Restaurant r) ;
};
#endif
