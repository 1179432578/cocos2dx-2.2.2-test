//
//  TouchTest.hpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/22.
//
//

#ifndef TouchTest_hpp
#define TouchTest_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Layer : public CCLayerColor{
public:
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
        printf("%d ccTouchBegan\n", this);
        
        return false;
    }
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
        printf("%d ccTouchMoved\n", this);
    }
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
        printf("%d ccTouchEnded\n", this);
    }
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){
        printf("%d ccTouchCancelled\n", this);
    }
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
        printf("%d ccTouchesBegan\n", this);
    }
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){
        printf("%d ccTouchesMoved\n", this);
    }
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent){
        printf("%d ccTouchesEnded\n", this);
    }
    virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent){
        printf("%d ccTouchesCancelled\n", this);
    }

    
    CREATE_FUNC(Layer);
};

class TouchTest : public CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(TouchTest);
    
    bool init();
    
private:
};

#endif /* TouchTest_hpp */
