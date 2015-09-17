//
//  GuanQia.h
//  tutian
//
//  Created by student on 15/8/23.
//
//

#ifndef __tutian__GuanQia__
#define __tutian__GuanQia__

#include <iostream>
using namespace std;

struct battle{
    int _id;
    int _levelnum;
    int _zhanli;
};

class GuanQia{
private:
       battle _bat;
public:
    GuanQia();
    GuanQia(std::string name, int number, int unlocked, battle bat);
    GuanQia(std::string name, int number, int unlocked);
    GuanQia(const GuanQia &it);
  
    CC_SYNTHESIZE(std::string,_name, Name);
    CC_SYNTHESIZE(int, _number,Number);
    CC_SYNTHESIZE(int, _unlocked, Unlocked);
  
   vector<battle> batarray;
    battle getBat();
    void setBat(battle bat);
    
};

#endif
