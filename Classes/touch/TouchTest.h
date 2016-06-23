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
#include <string>

USING_NS_CC;

class Layer : public CCLayerColor{
public:
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
        printf("%d ccTouchBegan \n", this);
        printf("name: %s\n", name.c_str());
        
        return true;
    }
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
        printf("%d ccTouchMoved\n", this);
        printf("name: %s\n", name.c_str());
    }
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
        printf("%d ccTouchEnded\n", this);
        printf("name: %s\n", name.c_str());
    }
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){
        printf("%d ccTouchCancelled\n", this);
        printf("name: %s\n", name.c_str());
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
    
    static Layer* create(const CCRect &rt, const char *name);
    
private:
    std::string name;
};

class TouchTest : public CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(TouchTest);
    
    bool init();
    
private:
};

#endif /* TouchTest_hpp */
