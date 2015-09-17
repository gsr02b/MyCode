//
//  Hero.h
//  tutian
//
//  Created by student on 15/8/23.
//
//

#ifndef __tutian__Hero__
#define __tutian__Hero__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class Hero:public Sprite{

public:
    int hero_LV;
    int hero_Exp;
    int CurExp;
    int Hp;
    int CurHp;
    int Hurt;
    int protection;
    

};


#endif
