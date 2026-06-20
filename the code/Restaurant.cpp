#include "Restaurant.h"
#include<iostream>

using namespace std ;
Restaurant::Restaurant()=default ;
 vector<Menu> Restaurant::getMenus() const{
     return menus ;
 }
    bool Restaurant::addMenu(Menu m){
        for(auto i: menus){
            if(i.getDate() == m.getDate()){
                cout<<"menu already exists"<<endl ;
                return false ;
            }
        }
        menus.push_back(m) ;
        return true ;
    }        
    Menu* Restaurant::findMenuByDate(string date){
        for(auto& i: menus){
            if(i.getDate()== date){
                return &i ;
            }
        }
        return nullptr ;
    }
    