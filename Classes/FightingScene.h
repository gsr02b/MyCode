//
//  FightingScene.h
//  tutian
//
//  Created by student on 15/8/22.
//
//

#ifndef __tutian__FightingScene__
#define __tutian__FightingScene__

#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

using namespace timeline;




class FightingScene: public Layer
{
public:
    
    static Scene* createScene();
    
    
    virtual bool init();
    
    CREATE_FUNC(FightingScene);
    
};

#endif 