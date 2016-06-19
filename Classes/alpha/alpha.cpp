//
//  alpha.cpp
//  HelloCpp
//
//  Created by lewis on 16/6/11.
//
//

#include "alpha.h"

CCScene* AlphaScene::scene(){
    CCScene *ret = CCScene::create();
    
    AlphaScene *layer = new AlphaScene;
    layer->init();
    layer->autorelease();
    ret->addChild(layer);
    
    return ret;
}

bool AlphaScene::init(){
    CCLabelTTF *lab = CCLabelTTF::create("Alpha test", "Arial", 24);
    lab->setPosition(ccp(320, 1000));
    addChild(lab);
    
    /*创建两个精灵进行混合*/
    CCSprite *sp1 = CCSprite::create("Icon-144.png");
    CCSprite *sp2 = CCSprite::create("Icon-72@2x.png");
    sp1->setPosition(ccp(320, 500));
    sp2->setPosition(ccp(320, 550));
    addChild(sp1, 2);
    addChild(sp2, 1);
    
    ccBlendFunc blend = {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA};
    sp1->setOpacity(128);
    sp1->setBlendFunc(blend);
}