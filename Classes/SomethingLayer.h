//
//  SomethingLayer.h
//  tutian
//
//  Created by student on 15/8/22.
//
//

#ifndef __tutian__SomethingLayer__
#define __tutian__SomethingLayer__

#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
USING_NS_CC;

class SomethingLayer:public LayerColor{

public:
    //virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    static SomethingLayer* createWithTag(int tag);
    bool initWithTag(int tag);
    Size visi;
    
    void initGongGao();
};
#endif 
