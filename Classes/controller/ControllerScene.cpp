//
//  ControllerScene.cpp
//  HelloCpp
//
//  Created by lewis on 16/6/19.
//
//

#include "ControllerScene.h"
#include "HelloWorldScene.h"

#define MENUBTN(actionname, menuaction, posy) \
label = CCLabelTTF::create(#actionname" test", "Arial", 24);\
item = CCMenuItemLabel::create(label, this, menu_selector(ControllerScene::menuaction));\
item->setPosition(ccp(320, posy));\
menu->addChild(item);

CCScene* ControllerScene::scene(){
    CCScene *ret = CCScene::create();
    
    ControllerScene *layer = ControllerScene::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool ControllerScene::init(){
    CCMenu *menu = CCMenu::create();
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    CCLabelTTF *label = CCLabelTTF::create("CCTextFieldTTF", "Arial", 24);
    CCMenuItemLabel *item = CCMenuItemLabel::create(label, this, menu_selector(ControllerScene::menuItemClick1));
    item->setPosition(ccp(320, 1100));
    menu->addChild(item);
    
    label = CCLabelTTF::create("确定", "Arial", 24);
    m_btn = CCMenuItemLabel::create(label, this, menu_selector(ControllerScene::btnOk));
    m_btn->setPosition(ccp(100, 850));
    menu->addChild(m_btn);
    
    m_texField = CCTextFieldTTF::textFieldWithPlaceHolder("input", CCSizeMake(200, 50), kCCTextAlignmentLeft, "Arial", 24);
    m_texField->setPosition(ccp(320, 300));
    this->addChild(m_texField);
    m_texField->attachWithIME();
    
    m_name = CCLabelTTF::create("name:", "Arial", 24);
    m_name->setPosition(ccp(100, 900));
    this->addChild(m_name);
    
    return true;
}

void ControllerScene::menuItemClick1(CCObject *pSender){
}

void ControllerScene::btnOk(CCObject *pSender){
    m_name->setString(m_texField->getString());
}