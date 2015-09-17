//
//  GameData.cpp
//  SingleObj
//
//  Created by student on 15/8/21.
//
//

#include "GameData.h"
static GameData * instance = nullptr;
GameData* GameData::getInstance(){
    if (instance==nullptr) {
        instance = new GameData();
        
        return instance;
    }
    return instance;

}

void GameData::purgeInstance(){
    if (instance) {
        delete instance;
        instance=nullptr;
    }

}
GameData::GameData(){

}
GameData::~GameData(){

}
