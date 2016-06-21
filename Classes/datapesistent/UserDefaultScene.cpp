//
//  UserDefaultScene.cpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/21.
//
//

#include "UserDefaultScene.h"
#define KEEP_COMPATABILITY
extern
//ios:NSUserDefault android:... both of them use tinyXML keep COMPATABILITY

void testUserDefault(){
    CCUserDefault *ud = CCUserDefault::sharedUserDefault();
    const std::string path = ud->getXMLFilePath();
    printf("UserDefault path:%s\n", path.c_str());
    
    //check is exist
    bool isExist = ud->isXMLFileExist();
    printf("isExist :%s\n", isExist ? "true" : "false");
    
    ud->setBoolForKey("bool", true);
    ud->setDoubleForKey("double", 2.3);
    ud->setFloatForKey("float", 1.0f);
    ud->setIntegerForKey("int", 20);
    ud->setStringForKey("string", "hello world");
    
    //a node information, storage as: ["dress":24] ...
    ud->setIntegerForKey("dress", 16);
    ud->setIntegerForKey("shoe", 12);

    printf("dress:%d\n", ud->getIntegerForKey("dress"));
    printf("shoe:%d\n", ud->getIntegerForKey("shoe"));
}