#include "HelloWorldScene.h"
#include "SpriteScene.h"
#include "alpha.h"
#include "draw.h"
#include "scissor.h"


USING_NS_CC;

//创建菜单项marco
#define CREATEBTN(SceneName, posy) \
label = CCLabelTTF::create(#SceneName" test", "Arial", 24); \
item = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::SceneName##Test)); \
item->setPosition(320, posy); \
pMenu->addChild(item);


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCScene::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create();
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
    pMenu->addChild(pCloseItem);
    
    /*进入字体测试*/
    CCLabelTTF *label = CCLabelTTF::create("font test", "Arial", 24);
    CCMenuItemLabel *item = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::fontTest));
    item->setPosition(320, 1000);
    pMenu->addChild(item);
 
    /*进入精灵帧动画测试*/
    label = CCLabelTTF::create("sprite animation test", "Arial", 24);
    item = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::spriteAnimationTest));
    item->setPosition(320, 950);
    pMenu->addChild(item);
    
    /*进入精灵帧动画测试*/
    label = CCLabelTTF::create("alpha test", "Arial", 24);
    item = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::alphaTest));
    item->setPosition(320, 900);
    pMenu->addChild(item);

    /*进入基本图元绘制测试*/
    label = CCLabelTTF::create("draw primitives test", "Arial", 24);
    item = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::drawTest));
    item->setPosition(320, 850);
    pMenu->addChild(item);

   
    /*裁剪测试*/
    label = CCLabelTTF::create("scissor test", "Arial", 24);
    item = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::scissorTest));
    item->setPosition(320, 800);
    pMenu->addChild(item);
    
    /*控件测试*/
    label = CCLabelTTF::create("controller test", "Arial", 24);
    item = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::ControllerSceneTest));
    item->setPosition(320, 750);
    pMenu->addChild(item);
    
    //场景变换测试
    CREATEBTN(SceneTransform, 700)
    
    return true;
}

HelloWorld* HelloWorld::getInstance(){
    static HelloWorld *ret = NULL;
    if (!ret) {
        ret = HelloWorld::create();
    }
    
    return ret;
}

void HelloWorld::addBackButton(CCScene *s){
//    CCScene *currentScene = CCDirector::sharedDirector()->getRunningScene();
    CCSize size  = CCDirector::sharedDirector()->getWinSize();
    
    //布置菜单的layer
    CCMenu *menu = CCMenu::create();
    menu->setPosition(CCPointZero);//菜单锚点被设为0.5 0.5了，改回来
    s->addChild(menu);
    
    CCMenuItemImage *item = CCMenuItemImage::create("backward.png", "backward.png");
    item->setPosition(ccp(size.width-50, size.height-50));
    menu->addChild(item);
    item->setTarget(this, menu_selector(HelloWorld::returnCallback));
}

void HelloWorld::returnCallback(CCObject *pSender){
    CCDirector::sharedDirector()->replaceScene(HelloWorld::create());
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

/*创建一个场景进行字体测试*/
void HelloWorld::fontTest(CCObject *pSender){
    
}

/*测试 cocos2dx2.2.2的各项功能*/
/*创建一个场景进行精灵帧动画测试*/
void HelloWorld::spriteAnimationTest(CCObject *pSender){
    CCScene *s = SpriteScene::scene();
    CCDirector::sharedDirector()->replaceScene(s);
}

/*创建一个场景进行alpha混合测试*/
void HelloWorld::alphaTest(CCObject *pSender){
    CCScene *s = AlphaScene::scene();
    CCDirector::sharedDirector()->replaceScene(s);
}

/*创建一个场景进行绘制基本图元测试*/
void HelloWorld::drawTest(CCObject *pSender){
    CCScene *s = DrawScene::scene();
    CCDirector::sharedDirector()->replaceScene(s);
}

/*创建一个场景进行场景变换测试*/
IMPLEMENT(SceneTestScene)
/*创建一个场景进行粒子特效测试*/

/*创建一个场景进行裁剪测试*/
void HelloWorld::scissorTest(CCObject *pSender){
    CCScene *s = ScissorScene::scene();
    CCDirector::sharedDirector()->replaceScene(s);
}

/*创建一个场景进行控件测试*/
IMPLEMENT(ControllerScene)

/*创建一个场景进行动作测试*/

/*创建一个场景进行着色测试*/

/*创建一个场景进行lua脚本测试*/

/*创建一个场景进行触摸测试*/

/*创建一个场景进行骨骼动画测试*/

/*创建一个场景进行精灵动作测试*/







