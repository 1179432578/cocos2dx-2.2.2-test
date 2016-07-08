# build and install the debug APK

# update the local.properties
android update project -p . -t android-14
android update project -p ../../../cocos2dx/platform/android/java -t android-14
#android update project -p ./google-play-services_lib -t android-14
#android update project -p ./mopub-with-jni -t android-14

# use the debug version Application.mk
#cmp -s jni/Application-debug.mk jni/Application.mk > /dev/null
#if [ $? -eq 1 ]; then
#    echo "Update Application.mk"
#    cp jni/Application-debug.mk jni/Application.mk
#fi

#./build_native.sh && ant -Dbuild.compiler=javac1.7 debug && adb install -r bin/SalonLuaTest-debug.apk

ant -Dbuild.compiler=javac1.7 debug && adb install -r bin/MyApp.apk

if [ $? -eq 0 ]; then
    echo "Done! Run the app from device now and see the log below:"
    adb logcat|grep -i -e cocos2d -e flurry -e mopub -e chartboost -e admob -e opengl -e helper\. -e newsblast -e mopub
else
    echo "Fail!"
fi

