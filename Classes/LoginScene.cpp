//
//  LoginScene.cpp
//  tutian
//
//  Created by student on 15/8/21.
//
//

#include "LoginScene.h"
#include "GotoScens.h"
#include "GuanQia.h"
#include "GameData.h"
Scene* LoginScene::createScene()
{
    
    auto scene = Scene::create();
    
    
    auto layer = LoginScene::create();
    
    
    scene->addChild(layer);
    
    
    return scene;
}

bool LoginScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visi =  Director::getInstance()->getVisibleSize();
    
    auto SYitem1 = MenuItemImage::create("btn_shengyin_0.png", "btn_shengyin_0.png");
    auto SYitem2 = MenuItemImage::create("btn_shengyin_1.png", "btn_shengyin_1.png");
    auto SY1 = MenuItemToggle::createWithCallback([](Ref *ref){
        
        //开关声音
    
    }, SYitem1,SYitem2, NULL);
    
    auto YYitem1 = MenuItemImage::create("btn_yinyue_0.png", "btn_yinyue_0.png");
    auto YYitem2 = MenuItemImage::create("btn_yinyue_1.png", "btn_yinyue_1.png");
    auto YY1 = MenuItemToggle::createWithCallback([](Ref *ref){
        
        //开关音乐
        
    }, YYitem1,YYitem2, NULL);
    
    auto SYYYMenu=Menu::create(SY1,YY1,NULL);
    SYYYMenu->setPosition(visi.width/8, visi.height/15);
    SYYYMenu->alignItemsHorizontallyWithPadding(60);
    this->addChild(SYYYMenu,3);
    
    
    
    Director::getInstance()->getTextureCache()->addImageAsync("Login.png", [this](Texture2D *texture){
        
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Login.plist");
        
        auto MainNode=CSLoader::createNode("LoginScene.csb");
        this->addChild(MainNode);
        
        auto startbtn=MainNode->getChildByName<Button*>("Button_1");
        startbtn->addClickEventListener([startbtn,this](Ref *ref){
            
            startbtn->removeFromParent();

            auto CunDang1=MenuItemImage::create("btn_cundang_0.png", "btn_cundang_0.png",[](Ref *ref){
                
                auto Goto = GotoScens::createScene();
                Director::getInstance()->replaceScene(Goto);
                
            });
            CunDang1->setPosition(0, 50);
            
            
            
            auto CunDang2=MenuItemImage::create("btn_cundang_1.png", "btn_cundang_1.png",[](Ref *ref){
        
            
            });
            CunDang2->setPosition(0, -50);
            auto CunDang=Menu::create(CunDang1,CunDang2, NULL);
            CunDang->setPosition(startbtn->getPosition());
            this->addChild(CunDang);
            
        });
        
        auto eixtbtn=MainNode->getChildByName<Button*>("Button_2");
        eixtbtn->addClickEventListener([](Ref *ref){
           //退出游戏
        
        });
        
    });
    
    return true;
}