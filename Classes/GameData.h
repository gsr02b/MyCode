//
//  GameData.h
//  SingleObj
//
//  Created by student on 15/8/21.
//
//

#ifndef __SingleObj__GameData__
#define __SingleObj__GameData__

#include <stdio.h>
#include "GuanQia.h"

class GameData{

public:
    static GameData *getInstance();
    static void purgeInstance();
    std::vector<GuanQia*> GQ;
    GameData();
    ~GameData();
    int currentQia;
    int hero_LV;
    int hero_Exp;
    int CurExp;
    int Hp;
    int CurHp;
    int Hurt;
    int protection;
    int date;

};

#endif /* defined(__SingleObj__GameData__) */
