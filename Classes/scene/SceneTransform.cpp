//
//  SceneTestScene.cpp
//  HelloCpp
//
//  Created by lewis on 16/6/19.
//
//

#include "SceneTransform.h"
#include "HelloWorldScene.h"

#define MENUBTN(actionname, menuaction, posy) \
label = CCLabelTTF::create(#actionname" test", "Arial", 24);\
item = CCMenuItemLabel::create(label, this, menu_selector(SceneTransform::menuaction));\
item->setPosition(ccp(320, posy));\
menu->addChild(item);

CCScene* SceneTransform::scene(){
    CCScene *ret = CCScene::create();
    
    SceneTransform *layer = new SceneTransform;
    layer->init();
    layer->autorelease();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool SceneTransform::init(){
    //添加菜单项，用于实现不同的场景切换
    CCMenu *menu = CCMenu::create();
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    //CCTransitionSceneOriented
    CCLabelTTF *label = CCLabelTTF::create("CCTransitionSceneOriented test", "Arial", 24);
    CCMenuItemLabel *item = CCMenuItemLabel::create(label, this, menu_selector(SceneTransform::menuAction1));
    item->setPosition(ccp(320, 1100));
    menu->addChild(item);
    
    //CCTransitionRotoZoom
    label = CCLabelTTF::create("CCTransitionRotoZoom test", "Arial", 24);
    item = CCMenuItemLabel::create(label, this, menu_selector(SceneTransform::menuAction2));
    item->setPosition(ccp(320, 1050));
    menu->addChild(item);
    
    label = CCLabelTTF::create("CCTransitionJumpZoom test", "Arial", 24);
    item = CCMenuItemLabel::create(label, this, menu_selector(SceneTransform::menuAction3));
    item->setPosition(ccp(320, 1000));
    menu->addChild(item);
    
    MENUBTN(CCTransitionMoveInL, menuAction4, 950)
    MENUBTN(CCTransitionSlideInL, menuAction5, 900)
    MENUBTN(CCTransitionShrinkGrow, menuAction6, 850)
    MENUBTN(CCTransitionFlipX, menuAction7, 800)
    MENUBTN(CCTransitionFlipY, menuAction8, 750)
    MENUBTN(CCTransitionFlipAngular, menuAction9, 700)
    MENUBTN(CCTransitionZoomFlipX, menuAction10, 650)
    MENUBTN(CCTransitionZoomFlipAngular, menuAction11, 600)
    MENUBTN(CCTransitionFade, menuAction12, 550)
    MENUBTN(CCTransitionCrossFade, menuAction13, 500)
    MENUBTN(CCTransitionTurnOffTiles, menuAction14, 450)
    MENUBTN(CCTransitionSplitCols, menuAction15, 400)
    MENUBTN(CCTransitionSplitRows, menuAction16, 350)
    MENUBTN(CCTransitionFadeTR, menuAction17, 300)
    MENUBTN(CCTransitionFadeBL, menuAction18, 250)
    MENUBTN(CCTransitionFadeUp, menuAction19, 200)
}

//CCTransitionScene is base class

/**CCTransitionSceneOriented supports orientation like.
 * Possible orientation: LeftOver, RightOver, UpOver, DownOver
 */
void SceneTransform::menuAction1(CCObject *pSender){
    CCScene *s = CCTransitionSceneOriented::create(10.0f, HelloWorld::create(), kCCTransitionOrientationUpOver);
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionRotoZoom
void SceneTransform::menuAction2(CCObject *pSender){
    CCScene *s = CCTransitionRotoZoom::create(6.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionJumpZoom
void SceneTransform::menuAction3(CCObject *pSender){
    CCScene *s = CCTransitionJumpZoom::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionMoveInL\CCTransitionMoveInR\CCTransitionMoveInT\CCTransitionMoveInB
void SceneTransform::menuAction4(CCObject *pSender){
    CCScene *s = CCTransitionMoveInL::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionSlideInL\CCTransitionSlideInR\CCTransitionSlideInB\CCTransitionSlideInT
void SceneTransform::menuAction5(CCObject *pSender){
    CCScene *s = CCTransitionSlideInL::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionShrinkGrow 收缩grow
void SceneTransform::menuAction6(CCObject *pSender){
    CCScene *s = CCTransitionShrinkGrow::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionFlipX 可以带方向
void SceneTransform::menuAction7(CCObject *pSender){
    CCScene *s = CCTransitionFlipX::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionFlipY 可以带方向
void SceneTransform::menuAction8(CCObject *pSender){
    CCScene *s = CCTransitionFlipY::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionFlipAngular 翻转角 可以带方向
void SceneTransform::menuAction9(CCObject *pSender){
    CCScene *s = CCTransitionSlideInL::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionZoomFlipX/CCTransitionZoomFlipY 可以带方向
void SceneTransform::menuAction10(CCObject *pSender){
    CCScene *s = CCTransitionZoomFlipX::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionZoomFlipAngular orientation
void SceneTransform::menuAction11(CCObject *pSender){
    CCScene *s = CCTransitionZoomFlipAngular::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionFade color
void SceneTransform::menuAction12(CCObject *pSender){
    CCScene *s = CCTransitionFade::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionCrossFade use CCRenderTexture
void SceneTransform::menuAction13(CCObject *pSender){
    CCScene *s = CCTransitionCrossFade::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionTurnOffTiles
void SceneTransform::menuAction14(CCObject *pSender){
    CCScene *s = CCTransitionTurnOffTiles::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionSplitCols
void SceneTransform::menuAction15(CCObject *pSender){
    CCScene *s = CCTransitionSplitCols::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionSplitRows
void SceneTransform::menuAction16(CCObject *pSender){
    CCScene *s = CCTransitionSplitRows::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionFadeTR
void SceneTransform::menuAction17(CCObject *pSender){
    CCScene *s = CCTransitionFadeTR::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionFadeBL
void SceneTransform::menuAction18(CCObject *pSender){
    CCScene *s = CCTransitionFadeBL::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}

//CCTransitionFadeUp/CCTransitionFadeDown
void SceneTransform::menuAction19(CCObject *pSender){
    CCScene *s = CCTransitionFadeUp::create(10.0f, HelloWorld::create());
    
    CCDirector::sharedDirector()->replaceScene(s);
}
