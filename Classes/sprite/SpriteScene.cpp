//
//  SpriteScene.cpp
//  cocos2dx
//
//  Created by lewis on 16/6/11.
//
//

#include "SpriteScene.h"

CCScene* SpriteScene::scene(){
    CCScene *ret = CCScene::create();
    
    SpriteScene *s = new SpriteScene;
    if (s && s->init()) {
        s->autorelease();
    }
    
    ret->addChild(s);
    
    return ret;
}

bool SpriteScene::init(){
    CCLabelTTF *label = CCLabelTTF::create("精灵帧动画测试", "Arial", 24);
    label->cocos2d::CCNode::setPosition(320, 1000);
    addChild(label);
    
    /*精灵帧动画动作*/
    /*读取plist的创建精灵帧，每个精灵帧保存了精灵每帧的纹理名、纹理区域*/
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("images/grossini.plist");
    /*用精灵帧创建一个精灵*/
    CCSprite *sprite = CCSprite::createWithSpriteFrameName("grossini_dance_01.png");
    sprite->setPosition(ccp(320, 500));
    addChild(sprite);
    /*用一组精灵帧创建一个精灵帧动画*/
    CCArray *spriteFrames = CCArray::create();
    char str[64];
    for (int i=1; i<=14; i++) {
        sprintf(str, "grossini_dance_%02d.png", i);
        spriteFrames->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str));
    }
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(spriteFrames, 0.2f);/*循环一次*/
    /*用动画创建一个动画动作，并执行*/
    CCAnimate *animate = CCAnimate::create(animation);
    sprite->runAction(CCRepeatForever::create(animate));
    
    /*显式定义循环动作 delaytime->callfunc*/
    //sprite->setDisplayFrame(<#cocos2d::CCSpriteFrame *pNewFrame#>)
    
    return true;
}