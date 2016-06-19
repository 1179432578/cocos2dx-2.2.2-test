#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ControllerScene.h"

#define TESTSCENE(SceneName) \
void SceneName##Test(CCObject *pSender){ \
    CCScene *s = SceneName::scene(); \
    CCDirector::sharedDirector()->replaceScene(s); \
}

#define IMPLEMENT(SceneName)

class HelloWorld : public cocos2d::CCScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    //static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    //return to HelloWorld scene
    void addBackButton(cocos2d::CCScene *s);
    void returnCallback(CCObject *pSender);
    static HelloWorld* getInstance();
    
    /*font menuitem click*/
    void fontTest(CCObject *pSender);
    
    /*sprite animation menuitem click*/
    void spriteAnimationTest(CCObject *pSender);
    
    /*alpha menuitem click*/
    void alphaTest(CCObject *pSender);
    
    /*alpha menuitem click*/
    void drawTest(CCObject *pSender);
    
    //scissor test
    void scissorTest(CCObject *pSender);
    
    //controller test
    TESTSCENE(ControllerScene);
};




#endif // __HELLOWORLD_SCENE_H__