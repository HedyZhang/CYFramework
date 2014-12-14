//
//  CY_Precompile.pch
//  CYFramework
//
//  Created by 张海迪 on 14-7-27.
//  Copyright (c) 2014年 haidi. All rights reserved.
//

#if __IPHONE_OS_VERSION_MAX_ALLOWED <= __IPHONE_7_0

#define NSLineBreakMode                 UILineBreakMode
#define NSLineBreakByWordWrapping       UILineBreakModeWordWrap
#define NSLineBreakByCharWrapping       UILineBreakModeCharacterWrap
#define NSLineBreakByClipping           UILineBreakModeClip
#define NSLineBreakByTruncatingHead     UILineBreakModeHeadTruncation
#define NSLineBreakByTruncatingTail     UILineBreakModeTailTruncation
#define NSLineBreakByTruncatingMiddle   UILineBreakModeMiddleTruncation

#define NSTextAlignmentLeft				UITextAlignmentLeft
#define NSTextAlignmentCenter			UITextAlignmentCenter
#define NSTextAlignmentRight			UITextAlignmentRight
#define	NSTextAlignment					UITextAlignment

#endif	// #if __IPHONE_OS_VERSION_MAX_ALLOWED >= 60000

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define kScreenWidth      CGRectGetWidth([UIScreen mainScreen].applicationFrame)
#define kScreenHeight     CGRectGetHeight([UIScreen mainScreen].applicationFrame)

#ifndef	weakify
#if __has_feature(objc_arc)
#define weakify( x )	autoreleasepool{} __weak __typeof__(x) __weak_##x##__ = x;
#else	// #if __has_feature(objc_arc)
#define weakify( x )	autoreleasepool{} __block __typeof__(x) __block_##x##__ = x;
#endif	// #if __has_feature(objc_arc)
#endif	// #ifndef	weakify

