//
//  action2.hpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/6/21.
//
//

#ifndef action2_hpp
#define action2_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class ActionScene2 : public CCLayer{
public:
    CREATE_FUNC(ActionScene2);
    
    static CCScene* scene();
    
    virtual bool init();
    
    void reset();
    
    void menuaction1(CCObject *pSender);
    void menuaction2(CCObject *pSender);
    void menuaction3(CCObject *pSender);
    void menuaction4(CCObject *pSender);
    void menuaction5(CCObject *pSender);
    void menuaction6(CCObject *pSender);
    void menuaction7(CCObject *pSender);
    void menuaction8(CCObject *pSender);
    void menuaction9(CCObject *pSender);
    void menuaction10(CCObject *pSender);
    void menuaction11(CCObject *pSender);
    void menuaction12(CCObject *pSender);
    void menuaction13(CCObject *pSender);
    void menuaction14(CCObject *pSender);
    void menuaction15(CCObject *pSender);
    void menuaction16(CCObject *pSender);
    void menuaction17(CCObject *pSender);
    void menuaction18(CCObject *pSender);
    void menuaction19(CCObject *pSender);
    void menuaction20(CCObject *pSender);
    void menuaction21(CCObject *pSender);
    void menuaction22(CCObject *pSender);
    
    CCActionInterval* getAction(){
        switch (m_action) {
            case MOVE:
                return CCMoveBy::create(2, ccp(0, 600));
                break;
            case ROTATION:
                return CCRotateBy::create(2, 180);
                break;
            case SCALE:
                return CCScaleBy::create(2, 2);
                break;
            default:
                break;
        }
    }
    
    void changeActionState(CCObject *pSender);
    
private:
    CCSprite *m_sp1;
    CCSprite *m_sp2;
    enum ActionState {MOVE, ROTATION, SCALE};
    ActionState m_action;
    CCLabelTTF *m_label;
};

#endif /* action2_hpp */
