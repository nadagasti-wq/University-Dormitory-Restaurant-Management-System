#include "University.h"
#include<string>
#include<vector>
#include<stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Room.h"
#include "Student.h"
#include "Menu.h"
using namespace std ;
University::University()=default ;
University::University(string n){
    name=n ;
}
Dormitory University::getDormitory(int i) const{
   if(i<0 || i>=(int)dormitories.size()){
    throw out_of_range("your index is out of range");
   }
   else{
       return dormitories[i] ;
   }
}
bool University::addDormitory(Dormitory d){
    for(auto i:dormitories){
        if(i.getId() ==d.getId()){
            cout<<"object Dormitory aready exist"<<endl ;
            return false ;
        }
    }
    dormitories.push_back(d);
    return true ;
    
}
vector<Dormitory> University::getDormitories() const{
    return dormitories ;
}
Dormitory* University::findDormitory(int id) {
    for(auto& i:dormitories){
        if(i.getId() == id){
            return &i ;
        }
    }
    return nullptr ;
}
int University::getDormitorycount() const{
    return dormitories.size() ;
}

bool University::saveToFile(string filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file for saving: " << filename << endl;
        return false;
    }

    for (const Dormitory& d : dormitories) {
        file << "DORM|" << d.getName() << "|" << d.getId() << "|" << d.getCapacity() << endl;

        for (const Menu& m : d.getRestaurant().getMenus()) {
            file << "MENU|" << m.getDate() << "|" << m.getBreakfast() << "|"
                 << m.getLunch() << "|" << m.getDinner() << endl;
        }

        for (const Room& r : d.getRooms()) {
            file << "ROOM|" << r.getNumber() << "|" << r.getCapacity() << endl;

            for (const Student& s : r.getStudents()) {
                file << "STUDENT|" << s.getId() << "|" << s.getName() << "|" << s.getYear() << endl;
            }
        }
    }

    file.close();
    cout << "Data saved to " << filename << endl;
    return true;
}

bool University::loadFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file for loading: " << filename << endl;
        return false;
    }

    dormitories.clear(); // start fresh so we don't duplicate existing data

    Dormitory* currentDorm = nullptr;
    Room* currentRoom = nullptr;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string tag;
        getline(ss, tag, '|');

        if (tag == "DORM") {
            string name, idStr, capStr;
            getline(ss, name, '|');
            getline(ss, idStr, '|');
            getline(ss, capStr, '|');

            Restaurant emptyRestaurant;
            Dormitory d(name, stoi(idStr), stoi(capStr), emptyRestaurant);
            dormitories.push_back(d);
            currentDorm = &dormitories.back();
            currentRoom = nullptr; // reset, we're in a new dormitory now
        }
        else if (tag == "MENU" && currentDorm != nullptr) {
            string date, breakfast, lunch, dinner;
            getline(ss, date, '|');
            getline(ss, breakfast, '|');
            getline(ss, lunch, '|');
            getline(ss, dinner, '|');

            Menu m(breakfast, lunch, dinner, date);
            Restaurant r = currentDorm->getRestaurant();
            r.addMenu(m);
            currentDorm->setRestaurant(r);
        }
        else if (tag == "ROOM" && currentDorm != nullptr) {
            string numStr, capStr;
            getline(ss, numStr, '|');
            getline(ss, capStr, '|');

            Room r(stoi(numStr), stoi(capStr), {});
            currentDorm->addRoom(r);
            currentRoom = currentDorm->findRoom(stoi(numStr));
        }
        else if (tag == "STUDENT" && currentRoom != nullptr) {
            string idStr, name, yearStr;
            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, yearStr, '|');

            Student s(name, stoi(idStr), stoi(yearStr));
            currentRoom->addStudent(s);
        }
    }

    file.close();
    cout << "Data loaded from " << filename << endl;
    return true;
}