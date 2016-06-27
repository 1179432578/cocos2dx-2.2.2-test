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