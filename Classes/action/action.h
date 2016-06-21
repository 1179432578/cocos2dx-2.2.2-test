//
//  action.hpp
//  HelloCpp
//
//  Created by lewis on 16/6/20.
//
//

#ifndef action_hpp
#define action_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class ActionScene : CCLayer{
public:
    static CCScene* scene();
    
    CREATE_FUNC(ActionScene);
    
    bool init();
    
    void reset();
    
    void menuAction1(CCObject *pSender);
    void menuAction2(CCObject *pSender);
    void menuAction3(CCObject *pSender);
    void menuAction4(CCObject *pSender);
    void menuAction5(CCObject *pSender);
    void menuAction6(CCObject *pSender);
    void menuAction7(CCObject *pSender);
    void menuAction8(CCObject *pSender);
    void menuAction9(CCObject *pSender);
    void menuAction10(CCObject *pSender);
    void menuAction11(CCObject *pSender);
    void menuAction12(CCObject *pSender);
    void menuAction13(CCObject *pSender);
    void menuAction14(CCObject *pSender);
    void menuAction15(CCObject *pSender);
    void menuAction16(CCObject *pSender);
    void menuAction17(CCObject *pSender);
    void menuAction18(CCObject *pSender);
    void menuAction19(CCObject *pSender);
    void menuAction20(CCObject *pSender);
    void fn(CCNode *);
    void fnd(CCNode *, void *data);
    void fo(CCObject *);
    void f();
    
private:
    CCSprite *m_sp1;
    CCSprite *m_sp2;
};

#endif /* action_hpp */
