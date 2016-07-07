//
//  CurlTest.hpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/7/7.
//
//

#ifndef CurlTest_hpp
#define CurlTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CurlTest : public CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(CurlTest);
    
    bool init();
    
    void btnClick(CCObject* pSender, CCControlEvent event);
    void btnClick2(CCObject* pSender, CCControlEvent event);
};


#endif /* CurlTest_hpp */
