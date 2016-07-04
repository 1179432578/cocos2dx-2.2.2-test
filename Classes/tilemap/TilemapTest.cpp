//
//  TilemapTest.cpp
//  HelloCpp
//
//  Created by lewis on 16/6/30.
//
//

#include "TilemapTest.h"
#include "HelloWorldScene.h"
#include <cmath>

CCScene* TilemapTest::scene(){
    CCScene *ret = CCScene::create();
    
    TilemapTest *layer = TilemapTest::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool TilemapTest::init(){
    //add tilemap
    map = CCTMXTiledMap::create("scene1.tmx");
    map->setPosition(CCPointZero);
    this->addChild(map);
    
    //get objectgroup npc
    CCTMXObjectGroup *npcgroup = map->objectGroupNamed("npc");
    CCArray *objects = npcgroup->getObjects();
    CCDictionary *obj= npcgroup->objectNamed("0003");
    const char *nextSceneName = obj->valueForKey("nextscene")->getCString();
    printf("next scene:%s\n", nextSceneName);
    
    //add npc
//    CCSpriteFrame *sf = CCSpriteFrame::create("npc96x99.png", CCRectMake(0, 0, 96, 99));
//    CCSprite *sp = CCSprite::createWithSpriteFrame(sf);
//    CCPoint pt = CCPointMake(obj->valueForKey("x")->floatValue(), obj->valueForKey("y")->floatValue());
//    sp->setPosition(pt);
//    this->addChild(sp);
    
    //add role
    CCPoint pt = CCPointMake(obj->valueForKey("x")->floatValue(), obj->valueForKey("y")->floatValue());
    CCSpriteFrame *sf = CCSpriteFrame::create("role-run/assassin1a.png", CCRectMake(0, 0, 32, 32));
    role = CCSprite::createWithSpriteFrame(sf);
    role->setPosition(pt);
    map->addChild(role);
    
//    CCArray *arr = CCArray::create();
//    for (int i=0; i<8; i++) {
//        CCSpriteFrame *sf = CCSpriteFrame::create("player1.png", CCRectMake(i*143, 0, 143, 113));
//        arr->addObject(sf);
//    }
//    CCAnimation *animation = CCAnimation::createWithSpriteFrames(arr, 0.1);
//    CCAnimate *animate = CCAnimate::create(animation);
//    role->runAction(CCRepeatForever::create(animate));
    
    //开启单点触摸
    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);
    this->setTouchPriority(1000);
    
    //4个方向行走图
    for (int i=0; i<4; i++) {
        CCArray *arr = CCArray::create();
        for (int j=0; j<3; j++) {
            CCSpriteFrame *sf = CCSpriteFrame::create("role-run/assassin1a.png", CCRectMake(j*32, i*32, 32, 32));
            arr->addObject(sf);
        }
        CCAnimation *animation = CCAnimation::createWithSpriteFrames(arr, 0.1);
        animate[i] = CCAnimate::create(animation);
        animate[i]->retain();
    }
    
    //获得地图不可到达区域，然后移动时，使用A*算法，获得行走路径
    collision = map->layerNamed("collision");
    //collision->setVisible(false);
    
    
    //添加扩展控件
    CCSpriteFrame *btnSf = CCSpriteFrame::create("ui.png", CCRectMake(760, 163, 64, 60));
    CCScale9Sprite *btnS9 = CCScale9Sprite::createWithSpriteFrame(btnSf);
    CCControlButton *btn = CCControlButton::create(btnS9);
    btn->setPreferredSize(CCSizeMake(64, 64));
    btn->setPosition(ccp(100, 50));
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(TilemapTest::itemsBarClick), CCControlEventTouchDown);
    this->addChild(btn);
    
    btn->setTitleForState(CCString::create("物品"), CCControlStateHighlighted);
    btn->setTitleColorForState(ccc3(255, 0, 0), CCControlStateHighlighted);
    
    
    //添加一个粒子
    
    
    return true;
}

void TilemapTest::itemsBarClick(CCObject *pSender, CCControlEvent event){
}

bool TilemapTest::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    //判断目的地是否不可达，for test
    CCPoint pos = collision->convertToNodeSpace(pTouch->getLocation());
    pos = pos / map->getTileSize().width;
    int gid= collision->tileGIDAt(ccp((int)pos.x, map->getMapSize().height - 1 - (int)pos.y));
    if (gid) {
        return false;
    }
    
    CCPoint targetPos = pTouch->getLocation();
    CCPoint targetPosInParent = role->getParent()->convertToNodeSpace(targetPos);
    CCPoint rolePos = role->getPosition();
    
    //stop pre actions
    map->stopAllActions();
    role->stopAllActions();
    
    //让role移动
    CCPoint deltaPonit = targetPosInParent-rolePos;
    float delta = sqrtf(deltaPonit.x * deltaPonit.x + deltaPonit.y * deltaPonit.y);
    mt = CCMoveTo::create(abs(delta) / 64, targetPosInParent);
    role->runAction(mt);
    int index;
    if (abs(deltaPonit.x) >= abs(deltaPonit.y)) {
        if (deltaPonit.x > 0) {
            index = 2;
        }
        else{
            index = 1;
        }
    }
    else {
        if (deltaPonit.y > 0) {
            index = 3;
        }
        else{
            index = 0;
        }
    }
    
    role->runAction(CCRepeatForever::create(animate[index]));//0wai/1l/2r/3li
    
    //调整地图让人物尽量居中
    //获得屏幕中心距离role的位置，然后对地图移动，让role居中，并且地图不出界
    //计算地图移动的目的地
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    CCPoint deltaMapPoint = ccp(s.width/2, s.height/2) - targetPos;
    //计算地图到底移动多少，不能越界
    CCPoint posMapInView = map->getParent()->convertToWorldSpace(map->getPosition());
    CCPoint posMapInView2 = posMapInView + deltaMapPoint;//新位置
    CCSize mapSize = map->getContentSize();
    //调整地图位置
    //左下角
    if (posMapInView2.x > 0 || posMapInView2.y > 0) {
        if (posMapInView2.x > 0) {
            posMapInView2.x = 0;
        }
        if (posMapInView2.y > 0) {
            posMapInView2.y = 0;
        }
    }
    
    //左上角
    if (posMapInView2.x > 0 ||posMapInView2.y + mapSize.height < s.height) {
        if (posMapInView2.x > 0) {
            posMapInView2.x = 0;
        }
        if (posMapInView2.y + mapSize.height < s.height) {
            posMapInView2.y = s.height - mapSize.height;
        }
    }
    
    //右下角
    if (posMapInView2.x + mapSize.width < s.width || posMapInView2.y > 0) {
        if (posMapInView2.x + mapSize.width < s.width) {
            posMapInView2.x = s.width - mapSize.width;
        }
        if (posMapInView2.y > 0) {
            posMapInView2.y = 0;
        }
    }
    
    //左下角
    if (posMapInView2.x + mapSize.width < s.width || posMapInView2.y + mapSize.height < s.height) {
        if (posMapInView2.x + mapSize.width < s.width) {
            posMapInView2.x = s.width - mapSize.width;
        }
        if (posMapInView2.y + mapSize.height < s.height) {
            posMapInView2.y = s.height - mapSize.height;
        }
    }
    deltaMapPoint =  posMapInView2 - posMapInView;
    float deltaMap = sqrtf(deltaMapPoint.x * deltaMapPoint.x + deltaMapPoint.y * deltaMapPoint.y);
    map->runAction(CCMoveTo::create(abs(deltaMap) / 64, map->getParent()->convertToNodeSpace(posMapInView2)));
    
    
    return true;//总是吞并触摸点，可以把触摸优先级调大，让其它节点先获得触摸
}

void TilemapTest::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){

}

void TilemapTest::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){

}