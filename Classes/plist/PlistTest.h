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

USING_NS_CC;

class PlistTest : public CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(PlistTest);
    
    bool init();
    
private:
};

#endif /* PlistTest_hpp */
