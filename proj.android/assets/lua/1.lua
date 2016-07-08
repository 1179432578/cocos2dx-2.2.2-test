local label = CCLabelTTF:create("hello world(lua)", "Arial", 24)
label:setPosition(ccp(320, 200))
CCDirector:sharedDirector():getRunningScene():addChild(label)
print(tostring(label))
print({})

-- label:removeFromParentAndCleanup(true)
-- label:release()
-- label:release()
-- print(tostring(label))
function eventHandle(event)
	if event = "enter" then
		-- call enter handler
	elseif event = "exit" then
		-- call exit handler
	elseif event = "enterTransitionFinish" then
		-- call enterTransitionFinish handler
	elseif event = "exitTransitionStart" then
		-- call exitTransitionStart handler
	elseif event = "cleanup" then
		-- call cleanup handler
	end
end