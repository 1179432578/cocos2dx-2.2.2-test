//
//  CurlTest.cpp
//  HelloCpp
//
//  Created by 鲁飞 on 16/7/7.
//
//

#include "CurlTest.h"
#include "HelloWorldScene.h"
#include <stdlib.h>

//http://www.cnblogs.com/moodlxs/archive/2012/10/15/2724318.html
#include <stdio.h>
#include <curl/curl.h>

bool getUrlFile(const char *filename, const char *url)
{
    bool ret = false;
    CURL *curl;
    CURLcode res;
    FILE *fp = fopen(filename, "w+");
    if (!fp) {
        return false;
    }
    
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: Agent-007");
    curl = curl_easy_init();    // 初始化
    if (curl)
    {
        //curl_easy_setopt(curl, CURLOPT_PROXY, "10.99.60.201:8080");// 代理
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);// 改协议头
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp); //将返回的http头输出到fp指向的文件
//        curl_easy_setopt(curl, CURLOPT_HEADERDATA, fp); //将返回的html主体数据输出到fp指向的文件
        res = curl_easy_perform(curl);   // 执行

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        ret = true;
    }
    
    // print log
    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buf = new char[length + 1];
    fread(buf, 1, length, fp);
    buf[length] = '\0';
    printf("%s", buf);
    delete [] buf;
    
    fclose(fp);
    return ret;
}

bool postUrl(char *filename)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    if ((fp = fopen(filename, "w")) == NULL)
        return false;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt"); // 指定cookie文件
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "&logintype=uid&u=xieyan&psw=xxx86");    // 指定post内容
        //curl_easy_setopt(curl, CURLOPT_PROXY, "10.99.60.201:8080");
        curl_easy_setopt(curl, CURLOPT_URL, " http://mail.sina.com.cn/cgi-bin/login.cgi ");   // 指定url
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    fclose(fp);
    return true;
}


CCScene* CurlTest::scene(){
    CCScene *ret = CCScene::create();
    
    CurlTest *layer = CurlTest::create();
    ret->addChild(layer);
    
    HelloWorld::getInstance()->addBackButton(ret);
    
    return ret;
}

bool CurlTest::init(){
    CCControlButton *btn = CCControlButton::create("test curl", "Arial", 24);
    btn->setPosition(ccp(320, 1000));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(CurlTest::btnClick), CCControlEventTouchDown);
    
    btn = CCControlButton::create("test CCHttpClient", "Arial", 24);
    btn->setPosition(ccp(320, 950));
    this->addChild(btn);
    btn->addTargetWithActionForControlEvents(this, cccontrol_selector(CurlTest::btnClick2), CCControlEventTouchDown);
    
    return true;
}

// 一组角色
void CurlTest::btnClick(CCObject* pSender, CCControlEvent event){
    std::string path = CCFileUtils::sharedFileUtils()->getWritablePath() + "file.jpg";
    bool success = getUrlFile(path.c_str(), "http://avatar.csdn.net/A/1/6/1_tspangle.jpg");
    if (success) {//创建精灵
        CCSprite *sp = CCSprite::create(path.c_str());
        sp->setPosition(ccp(320, 500));
        this->addChild(sp);
    }
}

void CurlTest::btnClick2(CCObject* pSender, CCControlEvent event){
    
}