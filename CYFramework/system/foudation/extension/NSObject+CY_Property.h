//
//  NSObject+CY_Property.h
//  ZDFramework
//
//  Created by 张海迪 on 14-7-18.
//  Copyright (c) 2014年 haidi. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark -

#undef	AS_STATIC_PROPERTY
#define AS_STATIC_PROPERTY( __name ) \
        - (NSString *)__name; \
        + (NSString *)__name;

#if __has_feature(objc_arc)

#undef	DEF_STATIC_PROPERTY
#define DEF_STATIC_PROPERTY( __name ) \
        - (NSString *)__name \
        { \
        return (NSString *)[[self class] __name]; \
        } \
        + (NSString *)__name \
        { \
        return [NSString stringWithFormat:@"%s", #__name]; \
        }

#else

#undef	DEF_STATIC_PROPERTY
#define DEF_STATIC_PROPERTY( __name ) \
        - (NSString *)__name \
        { \
        return (NSString *)[[self class] __name]; \
        } \
        + (NSString *)__name \
        { \
        return [NSString stringWithFormat:@"%s", #__name]; \
        }

#endif



@interface NSObject (CY_Property)

@end
