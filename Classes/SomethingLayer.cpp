//
//  SomethingLayer.cpp
//  tutian
//
//  Created by student on 15/8/22.
//
//

#include "SomethingLayer.h"
SomethingLayer* SomethingLayer::createWithTag(int tag){
    auto layer = new  (std::nothrow) SomethingLayer;
    if (layer && layer->initWithTag(tag)) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}
bool SomethingLayer::initWithTag(int tag){
    if (!LayerColor::initWithColor(Color4B::BLACK)) {
        return false;
    }
    visi=Director::getInstance()->getVisibleSize();
    this->setOpacity(100);
    auto dis = Director::getInstance()->getEventDispatcher();
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [](Touch *touch, Event *unused_event)->bool{
        return true;
    };
    dis->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto closebtn =Button::create();
    closebtn->loadTextureNormal("btn_clouse_1.png");
    closebtn->loadTexturePressed("btn_clouse_2.png");
    closebtn->setContentSize(Size(50,50));
    closebtn->setPosition(Size(visi.width-100,visi.height-100));
    closebtn->addClickEventListener([this](Ref* ref){
        this->removeFromParent();
    });
    addChild(closebtn);

    
    switch (tag) {
        case 2:
        {
        
        
        
        }
            break;
            
        case 3:
            log("布阵");
            break;
        case 4:
            log("佣兵屋");
            break;
        case 5:
            log("成就");
            break;
        case 6:
            log("商店");
            break;
        case 8:
        { //返回
           
            break;
        }
        case 9:
        {//至尊礼包
            auto sp=Sprite::create("shop_goods_15_2.png");
            sp->setAnchorPoint(Vec2(1,1));
            sp->setPosition(Vec2(visi.width-100, visi.height-100));
            sp->setScale(1);
            addChild(sp);
            
            auto buybtn =Button::create();
            buybtn->loadTextureNormal("box_btn_lingqu_0.png");
            buybtn->loadTexturePressed("box_btn_lingqu_1.png");
            buybtn->setContentSize(Size(100,50));
            buybtn->setScale(0.5);
            buybtn->setPosition(Vec2(visi.width/2.0,100));
            buybtn->addClickEventListener([this](Ref* ref){
                
            });
            addChild(buybtn);
        
        }
            break;
        case 10:
            //公告
            this->initGongGao();
            break;
        case 11:
            log("社区");
            break;
        case 12:
            log("VIP");
            break;
        case 13:
            log("史诗套装");
            break;
        case 14:
            log("终极佣兵");
            break;
        case 15:
            log("兑换");
            break;
        case 16:
            log("购买金币");
            break;

    }
    
    return true;
}
void SomethingLayer::initGongGao()
{
    auto sp=Sprite::create("town_bg_5.png");
    sp->setAnchorPoint(Vec2(1,1));
    sp->setPosition(Vec2(visi.width-100, visi.height-100));
    addChild(sp);
    
    auto buybtn =Button::create();
    buybtn->loadTextureNormal("shop_bg_2.png");
    buybtn->loadTexturePressed("shop_bg_3.png");
    buybtn->setContentSize(Size(100,50));
    buybtn->setScale(0.8);
    buybtn->setPosition(Vec2(visi.width/2.0,100));
    buybtn->addClickEventListener([this](Ref* ref){
        
    });
    addChild(buybtn);
   
}