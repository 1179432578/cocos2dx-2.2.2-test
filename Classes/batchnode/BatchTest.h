//
//  BatchTest.hpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/7/5.
//
//

#ifndef BatchTest_hpp
#define BatchTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class BatchTest : public CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(BatchTest);
    
    bool init();
    
    void btnClick(CCObject* pSender, CCControlEvent event);
    void btnClick2(CCObject* pSender, CCControlEvent event);
};

#endif /* BatchTest_hpp */
