//
//  TouchTest.cpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/22.
//
//

#include "TouchTest.h"
#include "HelloWorldScene.h"

Layer* Layer::create(const CCRect &rt, const char *name){
    Layer *ret = new Layer;
    ret->init();
    ret->autorelease();
    ret->setContentSize(rt.size);
    ret->setPosition(rt.origin);
    ret->name = name;
    
    return ret;
}

CCScene* TouchTest::scene(){
    CCScene *ret = CCScene::create();
    
    TouchTest *layer = TouchTest::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool TouchTest::init(){
    Layer *layer1 = Layer::create(CCRectMake(0, 0, 200, 200), "layer1");
    layer1->setOpacity(255);
    layer1->setColor(ccc3(rand()/256, rand()/256, rand()/256));
  
    Layer *layer2 = Layer::create(CCRectMake(100, 100, 100, 100), "layer2");
    layer2->setOpacity(255);
    layer2->setColor(ccc3(rand()/256, rand()/256, rand()/256));
    
    Layer *layer3 = Layer::create(CCRectMake(100, 100, 50, 50), "layer3");
    layer3->setOpacity(255);
    layer3->setColor(ccc3(rand()/256, rand()/256, rand()/256));
    
    this->addChild(layer1);
    this->addChild(layer2);
    this->addChild(layer3);

    layer1->setTouchEnabled(true);
    layer2->setTouchEnabled(true);
    layer3->setTouchEnabled(true);
    layer1->setTouchMode(kCCTouchesOneByOne);
    layer2->setTouchMode(kCCTouchesOneByOne);
    layer3->setTouchMode(kCCTouchesOneByOne);
    
    //改变触摸优先级，越大越后处理
    layer1->setTouchPriority(10);
    layer2->setTouchPriority(20);
    layer3->setTouchPriority(30);
    
    return true;
}