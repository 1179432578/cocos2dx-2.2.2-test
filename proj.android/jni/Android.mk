LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hellocpp_shared

LOCAL_MODULE_FILENAME := libhellocpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
									 ../../Classes/action/action.cpp \
									 ../../Classes/action/action2.cpp \
									 ../../Classes/alpha/alpha.cpp \
									 ../../Classes/batchnode/BatchTest.cpp \
									 ../../Classes/controller/ControllerScene.cpp \
									 ../../Classes/curl/CurlTest.cpp \
									 ../../Classes/datapesistent/UserDefaultScene.cpp \
									 ../../Classes/draw/draw.cpp \
									 ../../Classes/particle/ParticleTest.cpp \
									 ../../Classes/plist/PlistTest.cpp \
									 ../../Classes/scene/SceneTransform.cpp \
									 ../../Classes/scissor/scissor.cpp \
									 ../../Classes/sprite/SpriteScene.cpp \
									 ../../Classes/tilemap/TilemapTest.cpp \
									 ../../Classes/touch/TouchTest.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
										$(LOCAL_PATH)/../../Classes/action \
										$(LOCAL_PATH)/../../Classes/alpha \
										$(LOCAL_PATH)/../../Classes/batchnode \
										$(LOCAL_PATH)/../../Classes/controller \
										$(LOCAL_PATH)/../../Classes/curl \
										$(LOCAL_PATH)/../../Classes/datapesistent \
										$(LOCAL_PATH)/../../Classes/draw \
										$(LOCAL_PATH)/../../Classes/particle \
										$(LOCAL_PATH)/../../Classes/plist \
										$(LOCAL_PATH)/../../Classes/scene \
										$(LOCAL_PATH)/../../Classes/scissor \
										$(LOCAL_PATH)/../../Classes/sprite \
										$(LOCAL_PATH)/../../Classes/tilemap \
										$(LOCAL_PATH)/../../Classes/touch \
										$(LOCAL_PATH)/../../../../cocos2dx/platform/android/jni

LOCAL_STATIC_LIBRARIES := curl_static_prebuilt

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_lua_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,CocosDenshion/android)
$(call import-module,scripting/lua/proj.android)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
