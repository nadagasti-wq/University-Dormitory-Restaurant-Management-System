#ifndef UNIVERSITY_H
#define UNIVERSITY_H
using namespace std ;
#include <vector>
#include<string>
#include "Dormitory.h"
class University{
private:
vector<Dormitory> dormitories ;
string name ;
public:
University() ;
University(string n) ;
Dormitory getDormitory(int i) const;
vector<Dormitory> getDormitories() const;
bool addDormitory(Dormitory d);
Dormitory* findDormitory(int id) ;
int getDormitorycount() const;
bool saveToFile(string filename) const;
bool loadFromFile(string filename);
};
#endif