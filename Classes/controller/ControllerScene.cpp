//
//  ControllerScene.cpp
//  HelloCpp
//
//  Created by lewis on 16/6/19.
//
//

#include "ControllerScene.h"
#include "HelloWorldScene.h"

CCScene* ControllerScene::scene(){
    CCScene *ret = CCScene::create();
    
    ControllerScene *layer = new ControllerScene;
    layer->init();
    layer->autorelease();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool ControllerScene::init(){

}

