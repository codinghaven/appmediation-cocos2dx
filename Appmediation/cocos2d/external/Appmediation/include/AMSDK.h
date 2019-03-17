#ifndef AMSDK_H_DEFINE
#define AMSDK_H_DEFINE

#include "AdType.h"
#include "GdprConsent.h"
#include <string>

struct AMSDK {
public:
	static void init(const std::string&);
	static void setAutoLoad(AdType);
	static void setAutoLoad(AdType, AdType);
	static void setAutoLoad(AdType, AdType, AdType);
	static void showConsentAutomatically(bool);
	static void setTestMode(bool);
	static void setUserIdentifier(const std::string&);
	
	enum GdprConsent { AGREE, DISAGREE, NOT_REQUIRED, UNKNOWN };

};

#endif
