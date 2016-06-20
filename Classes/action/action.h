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
    
private:
    CCSprite *m_sp1;
    CCSprite *m_sp2;
};

#endif /* action_hpp */
