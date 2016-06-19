//
//  scissor.cpp
//  HelloCpp
//
//  Created by lewis on 16/6/19.
//
//

#include "scissor.h"
#include "HelloWorldScene.h"

CCScene* ScissorScene::scene(){
    CCScene *ret = CCScene::create();
    
    ScissorScene *layer = new ScissorScene;
    layer->init();
    layer->autorelease();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool ScissorScene::init(){
    CCDrawNode *draw = CCDrawNode::create();
    //    draw->setPosition(320, 900);
    addChild(draw);
    
    /*画点或圆*/
    draw->drawDot(ccp(200, 700), 10, ccc4f(1, 0, 0, 1));/*画的位置是相对于结点本地坐标的*/
    
    /*画线*/
    draw->drawSegment(ccp(0, 0), ccp(750, 750), 1, ccc4f(1, 0, 0, 1));
    
    /*画多边形*/
    CCPoint p[4] = {ccp(100, 100), ccp(100, 200), ccp(200, 200), ccp(200, 100)};
    draw->drawPolygon(p, 4, ccc4f(0, 0, 1, 1), 1, ccc4f(1, 0, 0, 1));
}

void ScissorScene::visit(){
//    glEnable(GL_SCISSOR_TEST);
//    glScissor(0, 0, 100, 100);
    
    CCNode::visit();
    
//    glDisable(GL_SCISSOR_TEST);
}