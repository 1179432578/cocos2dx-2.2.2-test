//
//  ParticleTest.hpp
//  HelloCpp
//
//  Created by lewis on 16/7/4.
//
//

#ifndef ParticleTest_hpp
#define ParticleTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ParticleTest : public CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(ParticleTest);
    
    bool init();
    
    void btnClick(CCObject* pSender, CCControlEvent event);
    
};

#endif /* ParticleTest_hpp */
