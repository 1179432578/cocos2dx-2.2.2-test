//
//  draw.hpp
//  HelloCpp
//
//  Created by lewis on 16/6/11.
//
//

#ifndef draw_hpp
#define draw_hpp

#include <stdio.h>

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class DrawScene : CCLayer{
public:
    static CCScene* scene();
    bool init();
};

#endif /* draw_hpp */
