//
//  GuanQia.cpp
//  tutian
//
//  Created by student on 15/8/23.
//
//

#include "GuanQia.h"
GuanQia::GuanQia(){}
GuanQia::GuanQia(std::string name, int number, int unlocked){
    _name = name;
 
    _number = number;
    _unlocked = unlocked;
}

GuanQia::GuanQia(std::string name, int number, int unlocked, battle bat){
    _name = name;
    _number = number;
    _unlocked = unlocked;
    _bat._id = bat._id;
    _bat._levelnum = bat._levelnum;
    _bat._zhanli = bat._zhanli;

}
GuanQia::GuanQia(const GuanQia &it){
    _name = it._name;
    _number = it._number;
    _unlocked = it._unlocked;
    _bat._id = it._bat._id;
    _bat._levelnum = it._bat._levelnum;
    _bat._zhanli = it._bat._zhanli;
  
}

battle GuanQia::getBat(){
    return _bat;
}
void GuanQia::setBat(battle bat){
    _bat._id =  bat._id;
    _bat._levelnum =  bat._levelnum;
    _bat._zhanli = bat._zhanli;
}
