//
//  BattleScene.cpp
//  tutian
//
//  Created by student on 15/8/22.
//
//

#include "BattleScene.h"
#include "Tools.h"
Scene* BattleScene::createScene()
{
    
    auto scene = Scene::create();
    
    
    auto layer = BattleScene::create();
    
    
    scene->addChild(layer);
    
    
    return scene;
}

bool BattleScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
   
    //人物
    
     hero=Sprite::create("aa.png");
    hero->setPosition(200,350);
    this->addChild(hero);
    
    
    
    auto battlenode=CSLoader::createNode("BattleScene.csb");
    this->addChild(battlenode);
    
    movebtn = battlenode->getChildByName<Sprite*>("img_joystick_2");
    movesize = battlenode->getChildByName<Sprite*>("Sprite_1");
    gongjibtn =battlenode->getChildByName<Button*>("Button_1");

    auto dis = Director::getInstance()->getEventDispatcher();
    auto listener=EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [](Touch *touch, Event *event)->bool{
    auto target =(Sprite *)event->getCurrentTarget();
       //触摸
    Point localinode =  target->convertToNodeSpace(touch->getLocation());
    Size targetsize = target->getContentSize();
    Rect rect = Rect(0, 0, targetsize.width, targetsize.height);
    if (rect.containsPoint(localinode)) {return  true;}else{return false;}

    };
    listener->onTouchMoved = [this](Touch *touch, Event *event){
        //移动
        auto target =(Sprite *)event->getCurrentTarget();
        target->setPosition(Point(touch->getLocation()));
        target->setPosition(Point(target->getPosition()+touch->getDelta()));
        
        double dis=Tools::DistanceForPoint(target->getPosition(), movesize->getPosition());
        if (dis >= 100){
            movebtn->setPosition(movesize->getPosition());
        }
        
        Point localinode = movesize->convertToNodeSpace(target->getPosition());
        log("%f-----%f",localinode.x,localinode.y);
        
    };
    listener->onTouchEnded = [this](Touch *touch, Event *event){
        
        movebtn->setPosition(movesize->getPosition());

    };
    
    
    dis->addEventListenerWithSceneGraphPriority(listener, movebtn);
    
    //攻击按钮
    gongjibtn->addClickEventListener([this](Ref* ref){
        
        if (touchCounts == 2) {
            log("三击");
            touchCounts=0;
        }
        else if (touchCounts == 1) {
            log("二击");
            this->scheduleOnce(schedule_selector( BattleScene::updateDoubleDelay), 05);
            touchCounts++;
        }
        else if (touchCounts == 0) {
            log("一击");
            this->scheduleOnce(schedule_selector(BattleScene::updateSingleDelay),0.5);
            touchCounts++;
        }


    });
    
    return true;
}
void BattleScene::updateSingleDelay(float dt){
    if (touchCounts == 1) {
        touchCounts=0;
    }


}
void BattleScene::updateDoubleDelay(float dt){
    if (touchCounts == 2 )
    {
        touchCounts=0;
    }
}

