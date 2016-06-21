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
    
    CREATE_FUNC(ControllerScene);
    
    bool init();
    
    void menuItemClick1(CCObject *pSender);
    
    void btnOk(CCObject *pSender);
private:
    CCMenuItemLabel *m_btn;
    CCTextFieldTTF *m_texField;
    CCLabelTTF *m_name;
};

#endif /* ControllerScene_hpp */
