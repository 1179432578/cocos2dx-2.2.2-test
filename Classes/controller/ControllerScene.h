//
//  ControllerScene.hpp
//  HelloCpp
//
//  Created by lewis on 16/6/19.
//
//

#ifndef ControllerScene_hpp
#define ControllerScene_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class ControllerScene : public CCLayer{
public:
    static CCScene* scene();
    bool init();
};

#endif /* ControllerScene_hpp */
