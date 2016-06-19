//
//  draw.cpp
//  HelloCpp
//
//  Created by lewis on 16/6/11.
//
//

#include "draw.h"

CCScene* DrawScene::scene(){
    CCScene *ret = CCScene::create();
    
    DrawScene *layer = new DrawScene;
    layer->init();
    layer->autorelease();
    ret->addChild(layer);
    
    return ret;
}

bool DrawScene::init(){
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