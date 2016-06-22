//
//  TouchTest.cpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/22.
//
//

#include "TouchTest.h"
#include "HelloWorldScene.h"

CCScene* TouchTest::scene(){
    CCScene *ret = CCScene::create();
    
    TouchTest *layer = TouchTest::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool TouchTest::init(){
    Layer *layer1 = Layer::create();
    layer1->setColor(ccc3(rand()/256, rand()/256, rand()/256));
    layer1->setOpacity(255);
  
    Layer *layer2 = Layer::create();
    layer2->setColor(ccc3(rand()/256, rand()/256, rand()/256));
    layer2->setOpacity(255);
    
    Layer *layer3 = Layer::create();
    layer3->setColor(ccc3(rand()/256, rand()/256, rand()/256));
    layer3->setOpacity(255);
    
    this->addChild(layer1);
    this->addChild(layer2);
    this->addChild(layer3);

    layer1->setTouchEnabled(true);
    layer2->setTouchEnabled(true);
    layer3->setTouchEnabled(true);
//    layer1->setTouchMode(kCCTouchesOneByOne);
//    layer2->setTouchMode(kCCTouchesOneByOne);
//    layer3->setTouchMode(kCCTouchesOneByOne);
    
    return true;
}