//
//  ParticleTest.cpp
//  HelloCpp
//
//  Created by lewis on 16/7/4.
//
//

#include "ParticleTest.h"
#include "HelloWorldScene.h"

using namespace tinyxml2;

CCScene* ParticleTest::scene(){
    CCScene *ret = CCScene::create();
    
    ParticleTest *layer = ParticleTest::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool ParticleTest::init(){
    CCControlButton *btn = CCControlButton::create("particle ", "Arial", 24);
    btn->setPosition(ccp(320, 1000));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(ParticleTest::btnClick), CCControlEventTouchDown);
    
    
    return true;
}
void ParticleTest::btnClick(CCObject* pSender, CCControlEvent event){
//    CCParticleBatchNode
//    CCParticleSystemQuad *particle = =CCParticleSystemQuad::create("");
    
    CCParticleFire *fire = CCParticleFire::create();
    fire->setPosition(ccp(320, 500));
    this->addChild(fire);
}