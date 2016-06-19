//
//  scissor.h
//  HelloCpp
//
//  Created by lewis on 16/6/19.
//
//

#ifndef scissor_h
#define scissor_h
#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class ScissorScene : public CCLayer{
public:
    static CCScene* scene();
    bool init();
    
    void virtual visit();
};

#endif /* scissor_h */
