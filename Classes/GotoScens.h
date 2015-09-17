//
//  GotoScens.h
//  tutian
//
//  Created by student on 15/8/22.
//
//

#ifndef __tutian__GotoScens__
#define __tutian__GotoScens__

#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "ui/CocosGUI.h"
#include "MainScene.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

using namespace timeline;
#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;




class GotoScens : public Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    
    virtual bool init();
    
    CREATE_FUNC(GotoScens);
    
    void copyFileToPath(std::string fileName);
    void   getMapdata(std::string fileName);
     void   getOtherdata(std::string fileName);
    
};



#endif /* defined(__tutian__GotoScens__) */
