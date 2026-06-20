#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <vector>
#include "Menu.h"
using namespace std;
class Restaurant {
private:
    vector<Menu> menus;
public:
    Restaurant();
    vector<Menu> getMenus() const;
    bool addMenu(Menu m);           
    Menu* findMenuByDate(string date); 
      
};

#endif