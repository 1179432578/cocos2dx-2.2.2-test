//
//  BatchTest.cpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/7/5.
//
//

#include "BatchTest.h"
#include "HelloWorldScene.h"
#include <stdlib.h>

using namespace tinyxml2;

CCScene* BatchTest::scene(){
    CCScene *ret = CCScene::create();
    
    BatchTest *layer = BatchTest::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool BatchTest::init(){
    CCControlButton *btn = CCControlButton::create("add role", "Arial", 24);
    btn->setPosition(ccp(320, 1000));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(BatchTest::btnClick), CCControlEventTouchDown);
    
    btn = CCControlButton::create("add ui", "Arial", 24);
    btn->setPosition(ccp(320, 950));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(BatchTest::btnClick2), CCControlEventTouchDown);
    
    return true;
}

// 一组角色
void BatchTest::btnClick(CCObject* pSender, CCControlEvent event){
    CCSpriteBatchNode *batchNode = CCSpriteBatchNode::create("role-run2/AthenaAsamiya_by_SWP.png");//128x192
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            CCSprite  *child = CCSprite::create("role-run2/AthenaAsamiya_by_SWP.png", CCRectMake(j*32, i*48, 32, 48));
            int x = random() % 640;
            int y = random() % 1136;
            child->setPosition(ccp(x, y));
            batchNode->addChild(child);
        }
    }
    
    this->addChild(batchNode);
}

// 一组ui
void BatchTest::btnClick2(CCObject* pSender, CCControlEvent event){

}