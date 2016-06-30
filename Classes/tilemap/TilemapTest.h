//
//  TilemapTest.hpp
//  HelloCpp
//
//  Created by lewis on 16/6/30.
//
//

#ifndef TilemapTest_hpp
#define TilemapTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TilemapTest : public CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(TilemapTest);
    
    bool init();
    
    //用于role行走
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
private:
    CCSprite *role;
    CCMoveTo *mt;
    CCTMXTiledMap *map;
    CCAnimate* animate[4];
};


#endif /* TilemapTest_hpp */
