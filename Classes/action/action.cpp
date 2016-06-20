//
//  action.cpp
//  HelloCpp
//
//  Created by lewis on 16/6/20.
//
//

#include "action.h"
#include "HelloWorldScene.h"

#define MENUBTN(actionname, menuaction, posy) \
label = CCLabelTTF::create(#actionname" test", "Arial", 24);\
item = CCMenuItemLabel::create(label, this, menu_selector(ActionScene::menuaction));\
item->setPosition(ccp(320, posy));\
menu->addChild(item);

CCScene* ActionScene::scene(){
    CCScene *scene = CCScene::create();
    
    ActionScene *layer = ActionScene::create();
    scene->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(scene);
    return scene;
}

bool ActionScene::init(){
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("grossini.plist");
    m_sp1 = CCSprite::createWithSpriteFrameName("grossini_dance_05.png");
    m_sp1->setPosition(ccp(320, 100));
    this->addChild(m_sp1);
    m_sp2 = CCSprite::createWithSpriteFrameName("grossini_dance_02.png");
    m_sp2->retain();
    
    CCMenu *menu = CCMenu::create();
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    CCMenuItemImage *img = CCMenuItemImage::create("reset.png", "reset.png");
    img->setTarget(this, menu_selector(ActionScene::reset));
    img->setPosition(ccp(50, 1000));
    menu->addChild(img);
    
    //add split symbol
    CCLabelTTF *split = CCLabelTTF::create("--------------------------------------------------------------------------", "Arial", 25);
    split->setPosition(ccp(320, 650));
    this->addChild(split);
    
    CCLabelTTF *label = CCLabelTTF::create("CCSequence test", "Arial", 24);
    CCMenuItemLabel *item = CCMenuItemLabel::create(label, this, menu_selector(ActionScene::menuAction1));
    item->setPosition(ccp(320, 1100));
    menu->addChild(item);
    
    MENUBTN(CCRepeat, menuAction2, 1050);
    MENUBTN(CCSpawn, menuAction3, 1000);
    MENUBTN(CCSkewTo, menuAction4, 950);
    MENUBTN(CCBlink, menuAction5, 900);
    MENUBTN(CCFadeIn, menuAction6, 850);
    MENUBTN(CCFadeTo, menuAction7, 800);
    MENUBTN(CCTintTo, menuAction8, 750);
    MENUBTN(CCBezierBy, menuAction9, 700);
 
}

void ActionScene::reset(){
    m_sp1->removeFromParentAndCleanup(true);
    m_sp1 = CCSprite::createWithSpriteFrameName("grossini_dance_05.png");
    m_sp1->setPosition(ccp(320, 100));
    this->addChild(m_sp1);
}

void ActionScene::menuAction1(CCObject *pSender){
    CCSequence *seq = CCSequence::create(CCMoveBy::create(2, ccp(100,0)), CCJumpBy::create(2, ccp(0, 0), 50, 3), CCMoveBy::create(2, ccp(-100,0)), NULL);
    
    m_sp1->runAction(seq);
}

void ActionScene::menuAction2(CCObject *pSender){
    CCRepeat *rep = CCRepeat::create(CCJumpBy::create(2, ccp(0,0), 50, 1), 4);
     m_sp1->runAction(rep);
}

void ActionScene::menuAction3(CCObject *pSender){
    CCSpawn *spa = CCSpawn::create(CCJumpBy::create(5, ccp(0, 0), 50, 5), CCRotateBy::create(5, 360), NULL);
    m_sp1->runAction(spa);
}

//CCRotateTo\CCRotateBy\CCMoveBy\CCMoveTo\CCSkewTo\CCSkewBy\CCJumpBy\CCJumpTo
//CCBezierBy\CCBezierTo\CCScaleTo\CCScaleBy\CCBlink\CCFadeIn\CCFadeOut\CCFadeTo
//CCTintTo\CCTintBy\CCDelayTime\CCReverseTime\CCAnimate\CCTargetedAction


void ActionScene::menuAction4(CCObject *pSender){
    CCSkewTo *ske = CCSkewTo::create(2, 20, 0);
    m_sp1->runAction(ske);
}

void ActionScene::menuAction5(CCObject *pSender){
    CCBlink *bli = CCBlink::create(2, 5);
    m_sp1->runAction(bli);
}

void ActionScene::menuAction6(CCObject *pSender){
    CCFadeIn *fin = CCFadeIn::create(2);
    m_sp1->runAction(fin);
}

void ActionScene::menuAction7(CCObject *pSender){
    CCFadeTo *fto = CCFadeTo::create(5, 128);
    m_sp1->runAction(fto);
}

void ActionScene::menuAction8(CCObject *pSender){
    CCTintTo *tto = CCTintTo::create(2, 255, 255, 0);
    m_sp1->runAction(tto);
}

void ActionScene::menuAction9(CCObject *pSender){
    ccBezierConfig cfg = {ccp(320, 400), ccp(200, 200), ccp(300, 300)};
    CCBezierBy *bby = CCBezierBy::create(2, cfg);
    m_sp1->runAction(bby);
}

void ActionScene::menuAction10(CCObject *pSender){
    //CCReverseTime\CCDelayTime
}

void ActionScene::menuAction11(CCObject *pSender){
    //CCTargetedAction

}

//void ActionScene::menuAction12(CCObject *pSender){
//    
//}
