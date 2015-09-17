//
//  GotoScens.cpp
//  tutian
//
//  Created by student on 15/8/22.
//
//

#include "GotoScens.h"
#include "GameData.h"
#include "GuanQia.h"

Scene* GotoScens::createScene()
{
    
    auto scene = Scene::create();
    
    
    auto layer = GotoScens::create();
    
    
    scene->addChild(layer);
    
    
    return scene;
}

bool GotoScens::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
   
        auto MainNode=CSLoader::createNode("GotoScene.csb");
        this->addChild(MainNode);
    
    //创建时间线动作
        auto time=CSLoader::createTimeline("GotoScene.csb");
    
       //从0-120帧，循环播放设计动画
       time->gotoFrameAndPlay(0, 120,false);
    
    //设置帧事件函数回调
    time->setFrameEventCallFunc([](Frame *frame){
    
        EventFrame *ev=dynamic_cast<EventFrame*>(frame);
        if (!ev)return;
        
        std::string str=ev->getEvent();
        
        if (str=="Goto") {
            auto main = MainScene::createScene();
            Director::getInstance()->replaceScene(main);
        }
    });
    
    auto dis=Director::getInstance()->getEventDispatcher();
    auto listener =EventListenerTouchOneByOne::create();
    listener->onTouchBegan=[](Touch *touch, Event *event)->bool{
        
        auto main = MainScene::createScene();
        Director::getInstance()->replaceScene(main);
        return true;
    };
     dis->addEventListenerWithSceneGraphPriority(listener, this);
    
       MainNode->runAction(time);
    this->getMapdata("GuanQia.xml");
    this->getOtherdata("Data.xml");
    
    return true;
}
void GotoScens::copyFileToPath(std::string fileName){
    
    FileUtils * fu=FileUtils::getInstance();
    
    //Documents //沙盒路径下的
    std::string wrPath = fu->getWritablePath();
    //拼接路径
    wrPath  += fileName;
    log("路径为：%s",wrPath.c_str());
    if(! fu->isFileExist(wrPath)){
        // 获取app里面的路径
        std::string dataPath = fu->fullPathForFilename(fileName);
        log("dataPath=%s",dataPath.c_str());
        
        //获取文件内容
        std::string pFileContent=fu->getStringFromFile(dataPath);
        CCLOG("%s",pFileContent.c_str());
        
        //将文件内容读出，写入到沙盒的wrPath
        FILE *file=fopen(wrPath.c_str(), "w");
        if (file) {
            fputs(pFileContent.c_str(), file);
            fclose(file);
        }
    }
}

void GotoScens::getMapdata(std::string fileName){
    
    copyFileToPath(fileName);
    std::string path = FileUtils::getInstance()->getWritablePath();
    std::string xmlfile = path + fileName;
    //加载文档
    XMLDocument *mydoc=new XMLDocument();
    XMLError errorid=mydoc->LoadFile(xmlfile.c_str());
    if (errorid !=0) {
        return;
    }
    
    XMLElement *Rootelement = mydoc->RootElement();
    XMLElement *element1 = Rootelement->FirstChildElement();
    XMLElement *nameelement = element1->FirstChildElement();
    XMLElement *numberelement = nameelement->NextSiblingElement();
    XMLElement *unlockedelement = numberelement->NextSiblingElement();
    GuanQia *temp=new GuanQia(nameelement->GetText(),atoi(numberelement->GetText()),atoi(unlockedelement->GetText()));
    
    XMLElement *blement=unlockedelement->NextSiblingElement();
    while (blement != NULL) {
        XMLElement * id = blement->FirstChildElement();
        XMLElement * level = id->NextSiblingElement();
        XMLElement *zhanli = level->NextSiblingElement();
        battle tempbattle={atoi(id->GetText()),atoi(level->GetText()),atoi(zhanli->GetText())};
        temp->batarray.push_back(tempbattle);
        blement=blement->NextSiblingElement();
    }
    GameData::getInstance()->GQ.push_back(temp);
    
    
    XMLElement *loopelement=element1->NextSiblingElement();
    while (loopelement != NULL) {
        XMLElement *nameelement = loopelement->FirstChildElement();
        XMLElement *numberelement = nameelement->NextSiblingElement();
        XMLElement *unlockedelement = numberelement->NextSiblingElement();
        GuanQia *temp=new GuanQia(nameelement->GetText(),atoi(numberelement->GetText()),atoi(unlockedelement->GetText()));
        
        XMLElement *blement=unlockedelement->NextSiblingElement();
        while (blement != NULL) {
            XMLElement * id = blement->FirstChildElement();
            XMLElement * level = id->NextSiblingElement();
            XMLElement *zhanli = level->NextSiblingElement();
            battle tempbattle={atoi(id->GetText()),atoi(level->GetText()),atoi(zhanli->GetText())};
            temp->batarray.push_back(tempbattle);
            blement=blement->NextSiblingElement();
        }
        GameData::getInstance()->GQ.push_back(temp);
        
        loopelement=loopelement->NextSiblingElement();
    }
    
}

void   GotoScens::getOtherdata(std::string fileName){
    copyFileToPath(fileName);
    std::string path = FileUtils::getInstance()->getWritablePath();
    std::string xmlfile = path + fileName;
    //加载文档
    XMLDocument *mydoc=new XMLDocument();
    XMLError errorid=mydoc->LoadFile(xmlfile.c_str());
    if (errorid !=0) {
        return;
    }
    
    std::vector<int> strArray;
    XMLElement *Rootelement = mydoc->RootElement();
    XMLElement *temp=Rootelement->FirstChildElement();
    while (temp!=NULL) {
          strArray.push_back(atoi(temp->GetText()));
          temp = temp->NextSiblingElement();
    }
    
    auto gamedate = GameData::getInstance();
    gamedate->hero_LV=strArray.at(0);
    gamedate->hero_Exp=strArray.at(1);
     gamedate->CurExp=strArray.at(2);
    gamedate->Hp=strArray.at(3);
    gamedate->CurHp=strArray.at(4);
    gamedate->Hurt=strArray.at(5);
    gamedate->protection=strArray.at(6);
    gamedate->date=strArray.at(7);
       
}

