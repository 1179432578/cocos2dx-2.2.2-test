//
//  PlistTest.cpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/27.
//
//

#include "PlistTest.h"
#include "HelloWorldScene.h"

CCScene* PlistTest::scene(){
    CCScene *ret = CCScene::create();
    
    PlistTest *layer = PlistTest::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}
