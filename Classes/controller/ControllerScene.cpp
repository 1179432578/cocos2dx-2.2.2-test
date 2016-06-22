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
    m_btn->setPosition(ccp(400, 1050));
    menu->addChild(m_btn);
    
    m_texField = CCTextFieldTTF::textFieldWithPlaceHolder("input", CCSizeMake(200, 50), kCCTextAlignmentLeft, "Arial", 24);
    m_texField->setPosition(ccp(320, 1050));
    this->addChild(m_texField);
    m_texField->attachWithIME();
    
    m_name = CCLabelTTF::create("show info", "Arial", 24);
    m_name->setPosition(ccp(100, 1100));
    this->addChild(m_name);
    
    //CCControlButton label+s9
    label = CCLabelTTF::create("BUTTON", "Arial", 24);
    CCControlButton *btn = CCControlButton::create(label , CCScale9Sprite::create("start.png"));
    btn->setPreferredSize(CCSizeMake(228, 81));
    btn->setLabelAnchorPoint(ccp(0.5, 2));
    btn->setPosition(ccp(320, 1000));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControllerScene::btnClick), CCControlEventTouchDown);
    
    //CCControlButton s9
    CCScale9Sprite *s9 = CCScale9Sprite::create("start.png");
    btn = CCControlButton::create(s9);
    btn->setPosition(ccp(320, 900));
    btn->setPreferredSize(CCSizeMake(228, 81));
    this->addChild(btn);
    
    //CCControlButton title
    btn = CCControlButton::create("CCControlButton", "Arial", 24);
    btn->setPosition(ccp(320, 800));
    this->addChild(btn);
    
    //s9
//    s9 = CCScale9Sprite::create("home.png");
//    s9->setPosition(ccp(100, 800));
//    this->addChild(s9);
    
    //CCControlColourPicker not useful
    CCControlColourPicker *cp = CCControlColourPicker::create();
    cp->setPosition(ccp(320, 750));
    this->addChild(cp);
    
    //CCControlPotentiometer
    CCControlPotentiometer *pot = CCControlPotentiometer::create("potentiometerTrack.png", "potentiometerProgress.png", "potentiometerButton.png");
    pot->setPosition(ccp(100, 750));
    this->addChild(pot);
    pot->setValue(90);
    
    //CCControlSlider
    CCControlSlider *slider = CCControlSlider::create("sliderTrack.png", "sliderProgress.png", "sliderThumb.png");
    slider->setPosition(ccp(150, 600));
    slider->setMinimumValue(0);
    slider->setMaximumValue(100);
    this->addChild(slider);
    slider->addTargetWithActionForControlEvents(this, cccontrol_selector(ControllerScene::valueChanged), CCControlEventValueChanged);
    
    //CCControlStepper
    CCControlStepper *ste = CCControlStepper::create(CCSprite::create("stepper-minus.png"), CCSprite::create("stepper-plus.png"));
    ste->setPosition(ccp(320, 600));
    this->addChild(ste);
    
    //CCControlSwitch
    CCControlSwitch *swi = CCControlSwitch::create(CCSprite::create("switch-mask.png"), CCSprite::create("switch-on.png"), CCSprite::create("switch-off.png"), CCSprite::create("switch-thumb.png"), CCLabelTTF::create("on", "Arial", 24), CCLabelTTF::create("off", "Arial", 24));
    swi->setPosition(ccp(500, 600));
    this->addChild(swi);

    //
    CCEditBox *edi = CCEditBox::create(CCSizeMake(200, 50), CCScale9Sprite::create("start.png"));
    edi->setPosition(ccp(150, 500));
    this->addChild(edi);
    
    return true;
}

void ControllerScene::menuItemClick1(CCObject *pSender){
}

void ControllerScene::btnOk(CCObject *pSender){
    m_name->setString(m_texField->getString());
}

void ControllerScene::btnClick(CCObject*, CCControlEvent eventID){
    char buf[64];
    sprintf(buf, "CCControlEvent:%d", eventID);
    m_name->setString(buf);
}

void ControllerScene::valueChanged(CCObject* pSender, CCControlEvent eventID){
    auto slider = (CCControlSlider*)pSender;
    float val = slider->getValue();
    
    CCString *str = CCString::createWithFormat("CCControlSlider.value=%f", val);
    m_name->setString(str->getCString());
}