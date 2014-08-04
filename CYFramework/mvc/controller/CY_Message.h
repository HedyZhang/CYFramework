//
//  CY_Message.h
//  ZDFramework
//
//  Created by 张海迪 on 14-7-18.
//  Copyright (c) 2014年 haidi. All rights reserved.
//

#import "CY_Foundation.h"

#pragma mark -

#undef AS_MESSAGE
#define AS_MESSAGE( __name )	AS_STATIC_PROPERTY( __name )

#pragma mark -

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

#pragma mark -
@class CY_Message;
@compatibility_alias CYMessage CY_Message;

#pragma mark -

@class CYMessage;

typedef void			(^CYMessageBlock)( void );
typedef CYMessage *	    (^CYMessageBlockV)( void );
typedef CYMessage *	    (^CYMessageBlockN)( id key, ... );
typedef CYMessage *	    (^CYMessageBlockT)( NSTimeInterval time );
typedef id				(^CYMessageObjectBlockN)( id key, ... );


@interface CY_Message : NSObject

AS_INT( STATE_CREATED )			// 消息被创建
AS_INT( STATE_SENDING )			// 消息正在发送
AS_INT( STATE_WAITING )			// 消息正在等待回应
AS_INT( STATE_SUCCEED )			// 消息处理成功（本地或网络）
AS_INT( STATE_FAILED )			// 消息处理失败（本地或网络）
AS_INT( STATE_CANCELLED )		// 消息被取消了


@property (nonatomic, readonly) CYMessageBlockN       INPUT;
@property (nonatomic, readonly) CYMessageBlockN       OUTPUT;
@property (nonatomic, readonly) CYMessageObjectBlockN GET_INPUT;
@property (nonatomic, readonly) CYMessageObjectBlockN GET_OUTPUT;
@property (nonatomic, readonly) CYMessageBlockT       TIMEOUT;
@property (nonatomic, readonly) CYMessageBlockV       TOLD_PROGRESS;

@property (nonatomic, assign  ) BOOL                  unique;      // 是否同时只能发一个
@property (nonatomic, assign  ) BOOL                  disabled;    // 是否被禁止回调
@property (nonatomic, assign  ) BOOL                  async;       // 是否异步
@property (nonatomic, assign  ) BOOL                  timeout;     // 是否超时了
@property (nonatomic, assign  ) BOOL                  cached;      // 是否从缓存读取的
@property (nonatomic, assign  ) BOOL                  emitted;     // 是否被发送了
@property (nonatomic, assign  ) BOOL                  oneDirection;// 是否单方向发送
@property (nonatomic, assign  ) NSTimeInterval        seconds;     // 超时时间
@property (nonatomic, assign  ) BOOL                  useCache;

@property (nonatomic, assign  ) BOOL                  toldProgress;
@property (nonatomic, assign  ) BOOL                  progressed;

@property (nonatomic, assign  ) id                    responder;
@property (nonatomic, assign  ) NSInteger             nextState;
@property (nonatomic, assign  ) NSInteger             state;
@property (nonatomic, retain  ) NSString              *message;
@property (nonatomic, retain  ) NSMutableDictionary   *input;
@property (nonatomic, retain  ) NSMutableDictionary   *output;


+ (CYMessage *)message;
+ (CYMessage *)message:(NSString *)msg;
+ (CYMessage *)message:(NSString *)msg timeoutSeconds:(NSUInteger)seconds;
+ (CYMessage *)message:(NSString *)msg responder:(id)responder;
+ (CYMessage *)message:(NSString *)msg responder:(id)responder timeoutSeconds:(NSUInteger)seconds;

- (CYMessage *)send;
- (CYMessage *)input:(id)first, ...;
- (CYMessage *)output:(id)first, ...;
- (CYMessage *)cancel;
- (CYMessage *)reset;

- (BOOL)is:(NSString *)name;
- (BOOL)isKindOf:(NSString *)prefix;
- (BOOL)isTwinWith:(CYMessage *)msg;	// 与某消息同属于一个发起源，相同NAME




@end
