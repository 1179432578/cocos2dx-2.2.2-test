local label = Label:create("hello world(custom lua api)", BIG)
label:setPosition(ccp(320, 500))
CCDirector:sharedDirector():getRunningScene():addChild(label)

