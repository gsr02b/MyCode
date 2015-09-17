//
//  FightingScene.cpp
//  tutian
//
//  Created by student on 15/8/22.
//
//

#include "FightingScene.h"
#include "MainScene.h"
#include "GameData.h"

Scene* FightingScene::createScene()
{
    
    auto scene = Scene::create();
    
    
    auto layer = FightingScene::create();
    
    
    scene->addChild(layer);
    
    
    return scene;
}

bool FightingScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    log("%d",GameData::getInstance()->date);
    GameData::getInstance()->date=700;
    

    auto fightnode=CSLoader::createNode("fightScene.csb");
    this->addChild(fightnode);
    
    auto node = fightnode->getChildByName<Node*>("ProjectNode_7");
    auto PV= node->getChildByName<PageView*>("PageView_1");

    auto LeftB = fightnode->getChildByName<Button*>("Button_4");
    auto RightB = fightnode->getChildByName<Button*>("Button_5");
    LeftB->setVisible(false);
    
    LeftB->addClickEventListener([PV,LeftB,RightB](Ref* ref){
        auto index=PV->getCurPageIndex();
        if (index==0) {
            LeftB->setVisible(false);
            return ;
        }
        index--;
        RightB->setVisible(true);
        PV->scrollToPage(index);
    });
    
    RightB->addClickEventListener([PV,LeftB,RightB](Ref* ref){
        
        auto index=PV->getCurPageIndex();
        log("%ld",index);
        index++;
        if (index==5) {
            RightB->setVisible(false);
            return ;
        }
        LeftB->setVisible(true);
        PV->scrollToPage(index);
        
    });
    
    auto returnbtn = fightnode->getChildByName<Button*>("Button_1");
    returnbtn->addClickEventListener([](Ref *ref){
        auto main=MainScene::createScene();
        Director::getInstance()->replaceScene(main);
    });
    
    return true;
}