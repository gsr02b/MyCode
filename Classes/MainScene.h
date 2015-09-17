//
//  MainScene.h
//  tutian
//
//  Created by student on 15/8/21.
//
//

#ifndef __tutian__MainScene__
#define __tutian__MainScene__


#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

using namespace timeline;




class MainScene : public Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    void  chose(Ref* ref);
    
    CREATE_FUNC(MainScene);
    
    Node* MainNode;
    
};



#endif
