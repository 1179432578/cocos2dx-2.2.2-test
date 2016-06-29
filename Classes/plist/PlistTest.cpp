//
//  PlistTest.cpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/27.
//
//

#include "PlistTest.h"
#include "HelloWorldScene.h"

using namespace tinyxml2;

CCScene* PlistTest::scene(){
    CCScene *ret = CCScene::create();
    
    PlistTest *layer = PlistTest::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool PlistTest::init(){
    CCControlButton *btn = CCControlButton::create("parse plist", "Arial", 24);
    btn->setPosition(ccp(320, 1000));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(PlistTest::btnClick), CCControlEventTouchDown);
    
    btn = CCControlButton::create("create sprite\nby spriteframe", "Arial", 24);
    btn->setPosition(ccp(320, 900));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(PlistTest::btnClickCreateSpriteBySpriteFrame), CCControlEventTouchDown);
    
    btn = CCControlButton::create("test CCDictionary\nwritetofile", "Arial", 24);
    btn->setPosition(ccp(320, 800));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(PlistTest::btnClickUseDictionary), CCControlEventTouchDown);
    
    btn = CCControlButton::create("test reference count", "Arial", 24);
    btn->setPosition(ccp(320, 700));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(PlistTest::btnClickTestRC), CCControlEventTouchDown);
    btn = CCControlButton::create("test CCSpriteFrame", "Arial", 24);
    btn->setPosition(ccp(320, 600));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(PlistTest::btnClickTestSpriteFrame), CCControlEventTouchDown);

    
    return true;
}

void PlistTest::btnClick(CCObject* pSender, CCControlEvent event){
    string filename = CCFileUtils::sharedFileUtils()->fullPathForFilename("shoe.plist");
    XMLDocument doc;
    doc.LoadFile(filename.c_str());
    
    XMLElement *rootElement = doc.FirstChildElement();//root plist element
    XMLElement *dicts = rootElement->FirstChildElement("dict")->FirstChildElement("dict");
    XMLElement *child = dicts->FirstChildElement("dict")->FirstChildElement();
    while (child) {
        printf("%s\n", child->GetText());
        child = child->NextSiblingElement();
    }
}

void PlistTest::btnClickCreateSpriteBySpriteFrame(CCObject* pSender, CCControlEvent event){
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("shoe.plist");
    CCSprite *sp = CCSprite::createWithSpriteFrameName("1.png");
    sp->setPosition(ccp(320, 500));
    this->addChild(sp);
}

void PlistTest::btnClickUseDictionary(CCObject* pSender, CCControlEvent event){
    CCDictionary *dict = CCDictionary::create();
    dict->setObject(new CCString("12"), "integer");
    dict->setObject(new CCString("21.34"), "float");
    dict->setObject(new CCString("true"), "bool");
    dict->setObject(new CCString("hello world"), "string");
    string path =  CCFileUtils::sharedFileUtils()->getWritablePath();
    printf("%s", path.c_str());
    path += "test.xml";
    dict->writeToFile(path.c_str());
}

//测试引用计数
void PlistTest::btnClickTestRC(CCObject* pSender, CCControlEvent event){
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("shoe.plist");
    CCSprite *sp = CCSprite::createWithSpriteFrameName("1.png");
    
    CCTexture2D *tex  = sp->getTexture();
    printf("tex ref count:%d", tex->retainCount());
}

//优化精灵的创建
void PlistTest::btnClickTestSpriteFrame(CCObject* pSender, CCControlEvent event){
    //直接原图创建精灵
    CCSprite *sp = CCSprite::create("11.png");
    sp->setPosition(ccp(320, 500));
    this->addChild(sp);
    
    //由裁剪过的图片创建精灵帧，再创建精灵
    CCSpriteFrame *sf = CCSpriteFrame::create("111.png", CCRectMake(2, 2, 221, 380), false, CCPointMake(10, 171), CCSizeMake(343, 762));
    CCSprite *sp2 = CCSprite::createWithSpriteFrame(sf);
    sp2->setPosition(ccp(320, 500));
    this->addChild(sp2);
}