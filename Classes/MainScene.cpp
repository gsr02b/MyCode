

#include "MainScene.h"
#include "LoginScene.h"
#include "SomethingLayer.h"
#include "FightingScene.h"

Scene* MainScene::createScene()
{
   
    auto scene = Scene::create();
    
   
    auto layer = MainScene::create();
    
   
    scene->addChild(layer);
    

    return scene;
}

bool MainScene::init()
{
   
    if ( !Layer::init() )
    {
        return false;
    }
    
    Director::getInstance()->getTextureCache()->addImageAsync("Main.png", [this](Texture2D *texture){
        
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Main.plist");
        
         MainNode=CSLoader::createNode("MainScene.csb");
        this->addChild(MainNode);
        
      Vector<Node*> allnode =  MainNode->getChildren();

        for (auto item : allnode) {
           
            if (item->getTag()>=2 && item->getTag()<=16) {
               Button* btn = dynamic_cast<Button*>(item);
                btn->addClickEventListener(CC_CALLBACK_1(MainScene::chose, this));
            }
            
        }
     
    });

    return true;
}

void  MainScene::chose(Ref *ref){
    Button* btn = dynamic_cast<Button*>(ref);
    switch (btn->getTag()) {
        case 3:
            log("布阵");
            break;
        case 7:
        {//战斗
            auto fightScene=FightingScene::createScene();
            Director::getInstance()->replaceScene(fightScene);
            
        }
            break;
        case 8:
        { //返回
    auto login = LoginScene::createScene();
    Director::getInstance()->replaceScene(login);
        }
    break;
        default:
            SomethingLayer *some = SomethingLayer::createWithTag(btn->getTag());
            this->addChild(some);
         break;

            
    }
//        case 2:
//            log("英雄殿堂");
//            break;
//            
//        case 3:
//            log("布阵");
//            break;
//        case 4:
//            log("佣兵屋");
//            break;
//        case 5:
//            log("成就");
//            break;
//        case 6:
//            log("商店");
//            break;
//        case 7:
//            log("战斗");
//            break;
//        case 8:
//        { //返回
//            auto login = LoginScene::createScene();
//            Director::getInstance()->replaceScene(login);
//            break;
//        }
//        case 9:
//            log("至尊礼包");
//            break;
//        case 10:
//        { //公告
//            SomethingLayer *some = SomethingLayer::createWithTag(btn->getTag());
//          
//            this->addChild(some);
//        }
//            break;
//        case 11:
//            log("社区");
//            break;
//        case 12:
//            log("VIP");
//            break;
//        case 13:
//            log("史诗套装");
//            break;
//        case 14:
//            log("终极佣兵");
//            break;
//        case 15:
//            log("兑换");
//            break;
//        case 16:
//            log("购买金币");
//            break;
//    }
    
    
}

