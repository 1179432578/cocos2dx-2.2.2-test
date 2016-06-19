//
//  SpriteScene.hpp
//  cocos2dx
//
//  Created by lewis on 16/6/11.
//
//

#ifndef SpriteScene_hpp
#define SpriteScene_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class SpriteScene : public CCLayer{
public:
    static CCScene* scene();
    
    bool init();
};



#endif /* SpriteScene_hpp */
