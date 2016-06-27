//
//  PlistTest.hpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/27.
//
//

#ifndef PlistTest_hpp
#define PlistTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class PlistTest : public CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(PlistTest);
    
    bool init();
    
    void btnClick(CCObject* pSender, CCControlEvent event);
private:
};

#endif /* PlistTest_hpp */
