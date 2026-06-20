#ifndef MENU_H
#define MENU_H
#include<string>
using namespace std ;
class Menu{
private:
string breakfast ;
string lunch ;
string dinner ;
string date ;
public:
Menu() ;
Menu(string b,string l, string di,string d) ;
string getBreakfast() const ;
string getLunch() const ;
string getDinner() const  ;
string getDate() const  ;
void setBreakfast(string s) ;
void setLunch(string s) ;
void setDinner(string s);
void setDate(string s) ;
};
#endif