//
//  action2.cpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/21.
//
//

#include "action2.h"
#include "HelloWorldScene.h"

#define MENUBTN(actionname, menuaction, posy) \
label = CCLabelTTF::create(#actionname" test", "Arial", 24);\
item = CCMenuItemLabel::create(label, this, menu_selector(ActionScene2::menuaction));\
item->setPosition(ccp(320, posy));\
menu->addChild(item);

CCScene* ActionScene2::scene(){
    CCScene *scene = CCScene::create();
    
    ActionScene2 *layer = ActionScene2::create();
    scene->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(scene);
    
    return scene;
}

bool ActionScene2::init(){
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("grossini.plist");
    m_sp1 = CCSprite::createWithSpriteFrameName("grossini_dance_05.png");
    m_sp1->setPosition(ccp(320, 100));
    this->addChild(m_sp1, 2);
    
    CCMenu *menu = CCMenu::create();
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    //rest button
    CCMenuItemImage *img = CCMenuItemImage::create("reset.png", "reset.png");
    img->setTarget(this, menu_selector(ActionScene2::reset));
    img->setPosition(ccp(50, 1100));
    menu->addChild(img);
    
    m_label = CCLabelTTF::create("touch me\nchange action\nCCMoveBy", "Arial", 24);
    CCMenuItemLabel *changeBtn = CCMenuItemLabel::create(m_label, this, menu_selector(ActionScene2::changeActionState));
    changeBtn->setPosition(ccp(100, 1000));
    menu->addChild(changeBtn);
    
    CCLabelTTF *label = CCLabelTTF::create("CCActionEase", "Arial", 24);
    CCMenuItemLabel *item = CCMenuItemLabel::create(label, this, menu_selector(ActionScene2::menuaction1));
    item->setPosition(ccp(320, 1100));
    menu->addChild(item);
    
    MENUBTN(CCEaseRateAction, menuaction2, 1050);
    MENUBTN(CCEaseIn, menuaction3, 1020);
    MENUBTN(CCEaseOut, menuaction4, 990);
    MENUBTN(CCEaseInOut, menuaction5, 960);
    MENUBTN(CCEaseExponentialIn, menuaction6, 930);
    MENUBTN(CCEaseExponentialOut, menuaction7, 900);
    MENUBTN(CCEaseExponentialInOut, menuaction8, 870);
    MENUBTN(CCEaseSineIn, menuaction9, 840);
    MENUBTN(CCEaseSineOut, menuaction10, 810);
    MENUBTN(CCEaseSineInOut, menuaction11, 780);
    MENUBTN(CCEaseElastic, menuaction12, 750);
    MENUBTN(CCEaseElasticIn, menuaction13, 720);
    MENUBTN(CCEaseElasticOut, menuaction14, 690);
    MENUBTN(CCEaseElasticInOut, menuaction15, 660);
    MENUBTN(CCEaseBounce, menuaction16, 540);
    MENUBTN(CCEaseBounceIn, menuaction17, 510);
    MENUBTN(CCEaseBounceOut, menuaction18, 480);
    MENUBTN(CCEaseBounceInOut, menuaction19, 450);
    MENUBTN(CCEaseBackIn, menuaction20, 420);
    MENUBTN(CCEaseBackOut, menuaction21, 390);
    MENUBTN(CCEaseBackInOut, menuaction22, 360);
    return true;
}

void ActionScene2::changeActionState(CCObject *pSender){
    m_action = (ActionState)((m_action + 1) % 3);
    
    switch (m_action) {
        case MOVE:
            m_label->setString("touch me\nchange action\nCCMoveBy");
            break;
        case ROTATION:
             m_label->setString("touch me\nchange action\nCCRotationTo");
            break;
        case SCALE:
            m_label->setString("touch me\nchange action\nCCScaleTo");
            break;
        default:
            break;
    }
}

void ActionScene2::reset(){
    m_sp1->removeFromParent();
    m_sp1 = CCSprite::createWithSpriteFrameName("grossini_dance_05.png");
    m_sp1->setPosition(ccp(320, 100));
    this->addChild(m_sp1);
}

//CCActionEase\CCEaseRateAction\CCEaseIn\CCEaseOut\CCEaseInOut
//CCEaseExponentialIn\CCEaseExponentialOut\CCEaseExponentialInOut
//CCEaseSineIn\CCEaseSineOut\CCEaseSineInOut\CCEaseElastic
//CCEaseElasticIn\CCEaseElasticOut\CCEaseElasticInOut
//CCEaseBounce\CCEaseBounceIn\CCEaseBounceOut\CCEaseBounceInOut
//CCEaseBackIn\CCEaseBackOut\CCEaseBackInOut

void ActionScene2::menuaction1(CCObject *pSender){
    CCActionEase *act = CCActionEase::create(getAction());
                                             
    m_sp1->runAction(act);
}
void ActionScene2::menuaction2(CCObject *pSender){
    CCEaseRateAction *act = CCEaseRateAction::create(getAction(), 50);
    
    m_sp1->runAction(act);
}

void ActionScene2::menuaction3(CCObject *pSender){
    CCEaseIn *act = CCEaseIn::create(getAction(), 3);
    m_sp1->runAction(act);
}
void ActionScene2::menuaction4(CCObject *pSender){
    CCEaseOut *act = CCEaseOut::create(getAction(), 3);
    m_sp1->runAction(act);
}
void ActionScene2::menuaction5(CCObject *pSender){
    CCEaseInOut *act = CCEaseInOut::create(getAction(), 3);
    m_sp1->runAction(act);
}
void ActionScene2::menuaction6(CCObject *pSender){
    CCEaseExponentialIn *act = CCEaseExponentialIn::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction7(CCObject *pSender){
    CCEaseExponentialOut *act = CCEaseExponentialOut::create(getAction());
    m_sp1->runAction(act);
}

void ActionScene2::menuaction8(CCObject *pSender){
    CCEaseExponentialInOut *act = CCEaseExponentialInOut::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction9(CCObject *pSender){
    CCEaseSineIn *act = CCEaseSineIn::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction10(CCObject *pSender){
    CCEaseSineOut *act = CCEaseSineOut::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction11(CCObject *pSender){
    CCEaseSineInOut *act = CCEaseSineInOut::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction12(CCObject *pSender){
    CCEaseElastic *act = CCEaseElastic::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction13(CCObject *pSender){
    CCEaseElasticIn *act = CCEaseElasticIn::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction14(CCObject *pSender){
    CCEaseElasticOut *act = CCEaseElasticOut::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction15(CCObject *pSender){
    CCEaseElasticInOut *act = CCEaseElasticInOut::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction16(CCObject *pSender){
    CCEaseBounce *act = CCEaseBounce::create(getAction());
    m_sp1->runAction(act);
}

void ActionScene2::menuaction17(CCObject *pSender){
    CCEaseBounceIn *act = CCEaseBounceIn::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction18(CCObject *pSender){
    CCEaseBounceOut *act = CCEaseBounceOut::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction19(CCObject *pSender){
    CCEaseBounceInOut *act = CCEaseBounceInOut::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction20(CCObject *pSender){
    CCEaseBackIn *act = CCEaseBackIn::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction21(CCObject *pSender){
    CCEaseBackOut *act = CCEaseBackOut::create(getAction());
    m_sp1->runAction(act);
}
void ActionScene2::menuaction22(CCObject *pSender){
    CCEaseBackInOut *act = CCEaseBackInOut::create(getAction());
    m_sp1->runAction(act);
}
