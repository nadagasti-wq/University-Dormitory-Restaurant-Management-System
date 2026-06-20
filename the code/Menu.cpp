#include "Menu.h"
#include<string>
using namespace std ;
Menu::Menu(){
    breakfast="not set" ;
    lunch="not set" ;
    dinner= "not set" ;
    date = "not set" ;
}
Menu::Menu(string b,string l, string di,string d) {
    breakfast =b;
    lunch=l;
    dinner=di ;
    date= d ;
}
string Menu::getBreakfast() const{
    return breakfast;
}
string Menu::getLunch() const {
    return lunch ;
}
string Menu::getDinner() const {
    return dinner ;
}
string Menu::getDate() const{
    return date ;
}
void Menu::setBreakfast(string s) {
    breakfast=s ;
}
void Menu::setLunch(string s) {
    lunch=s ;
}
void Menu::setDinner(string s){
    dinner=s ;
}
void Menu::setDate(string s) {
    date= s ;
}