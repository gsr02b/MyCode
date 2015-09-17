//
//  LoginScene.h
//  tutian
//
//  Created by student on 15/8/21.
//
//

#ifndef __tutian__LoginScene__
#define __tutian__LoginScene__

#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"

#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;
USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

using namespace timeline;




class LoginScene: public Layer
{
public:
    
    static Scene* createScene();
    
    
    virtual bool init();
    
    CREATE_FUNC(LoginScene);
  
};


#endif
