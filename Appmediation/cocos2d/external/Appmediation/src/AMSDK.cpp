#include "AMSDK.h"
#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

void AMSDK::init(const std::string& key) {
    JniHelper::callStaticVoidMethod(CLASS_PATH, "init", key);
}

void AMSDK::setAutoLoad(AdType ad) { 

}

void AMSDK::setAutoLoad(AdType ad_a, AdType ad_b) { 

}

void AMSDK::setAutoLoad(AdType ad_a, AdType ad_b, AdType ad_c) { 

}

void AMSDK::showConsentAutomatically(bool cond) { 

}

void AMSDK::setTestMode(bool cond) {

}

void AMSDK::setUserIdentifier(const std::string& uid) {

}
