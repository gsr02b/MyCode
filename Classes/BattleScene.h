//
//  BattleScene.h
//  tutian
//
//  Created by student on 15/8/22.
//
//

#ifndef __tutian__BattleScene__
#define __tutian__BattleScene__

#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

using namespace timeline;




class BattleScene: public Layer
{
public:
    
    static Scene* createScene();
    
    
    virtual bool init();
    
    CREATE_FUNC(BattleScene);
    
    Sprite *movebtn;
    Sprite *movesize;
    Sprite *hero;
    Button *gongjibtn;
    
    int touchCounts;
    void updateSingleDelay(float dt);
    void updateDoubleDelay(float dt);
   
};


#endif 
