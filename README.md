# appmediation-cocos2dx
Cocos2d-x wrapper for appmediation.com

Note:
Before using this you have to go to appmediation.com for integrating the neccessary .jar files.
Once you have a succesful build in android studio then move onto this.

Integration instructions:

* First clone the repo
* Copy the `Appmediation` directory to `your_project_root/cocos2d/external` directory
* Then go to your `Android.mk` located under `your_project_root/proj.android/app/jni`
* Open your `Android.mk` and do the following
  
   Add `$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external/Appmediation)`                                           
   wherever you have your`$(call import-add-path...)` statements.
  
   Add `$(LOCAL_PATH)/../../../cocos2d/external/Appmediation/include` to your `LOCAL_C_INCLUDES`
   
   Then right after `LOCAL_STATIC_LIBRARIES := cocos2dx_static`
   add on the next line, `LOCAL_STATIC_LIBRARIES := appmediation_static`
   
You are all set!

Use `#include "appmediation.h"` to access the library.

Note:                                                                                                                             
API access is the exact same as you would interact with the native appmediation SDK for Android.
