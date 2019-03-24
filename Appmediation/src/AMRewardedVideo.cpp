#include "AMRewardedVideo.h"

using namespace appmediation;

bool AMRewardedVideo::isReady() {
	cocos2d::JniMethodInfo mi;
	bool exists = cocos2d::JniHelper::getStaticMethodInfo(mi, AMREWARDEDVIDEO_CLASS, "isReady", "()Z");

	if(!exists) {
		CCLOG("isReady() AMRewardedVideo doesn't exist");
		return false;
	}

	jboolean b_result = mi.env->CallStaticBooleanMethod(mi.classID,mi.methodID);

	bool return_val = (bool)b_result;

	return return_val;
}

void AMRewardedVideo::show() {
	cocos2d::JniMethodInfo mi;
}

void AMRewardedVideo::load() {

}
