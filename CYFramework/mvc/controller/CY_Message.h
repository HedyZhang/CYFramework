//
//  CY_Message.h
//  ZDFramework
//
//  Created by 张海迪 on 14-7-18.
//  Copyright (c) 2014年 haidi. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark -

#undef AS_MESSAGE
#define AS_MESSAGE( __name )	AS_STATIC_PROPERTY( __name )

#undef	DEF_MESSAGE
#define DEF_MESSAGE( __name )	DEF_STATIC_PROPERTY3( __name, @"message", [self description] )

#undef	DEF_MESSAGE2
#define DEF_MESSAGE2( __name, __msg ) \
        DEF_STATIC_PROPERTY3( __name, @"message", [self description] ); \
        - (void)__name:(BeeMessage *)__msg

#undef	DEF_MESSAGE3
#define DEF_MESSAGE3( __name, __type, __msg ) \
        DEF_STATIC_PROPERTY3( __name, @"message", [self description] ); \
         - (void)__name:(__type *)__msg

#undef	DEF_MESSAGE_
#define DEF_MESSAGE_( __name, __msg )	DEF_MESSAGE2( __name, __msg )

#pragma mark -

#undef	ON_MESSAGE
#define ON_MESSAGE( __msg ) \
        - (void)handleMessage:(BeeMessage *)__msg

#undef	ON_MESSAGE2
#define ON_MESSAGE2( __filter, __msg ) \
        - (void)handleMessage_##__filter:(BeeMessage *)__msg

#undef	ON_MESSAGE3
#define ON_MESSAGE3( __class, __name, __msg ) \
        - (void)handleMessage_##__class##_##__name:(BeeMessage *)__msg

@interface CY_Message : NSObject

@end
