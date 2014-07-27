//
//  NSObject+CYMessage.h
//  CYFramework
//
//  Created by 张海迪 on 14-7-27.
//  Copyright (c) 2014年 haidi. All rights reserved.
//

#import "CY_Precompile.h"
#import "CY_Foundation.h"
#import "CY_Message.h"

@interface NSObject (CYMessage)
@property (nonatomic, readonly) CYMessageBlockN MSG;
@property (nonatomic, readonly) CYMessageBlockN MSG_IF_NOT_SENDING;
@property (nonatomic, readonly) CYMessageBlockN MSG_CANCEL_IF_SENDING;
@property (nonatomic, readonly) CYMessageBlockN CANCEL_MSG;


- (BOOL)sendingMessage:(NSString *)msg;
- (void)cancelMessage:(NSString *)msg;
- (void)cancelMessages;

- (CYMessage *)message:(NSString *)msg;
- (CYMessage *)message:(NSString *)msg timeoutSeconds:(NSUInteger)seconds;

- (CYMessage *)sendMessage:(NSString *)msg;
- (CYMessage *)sendMessage:(NSString *)msg timeoutSeconds:(NSUInteger)seconds;

- (BOOL)prehandleMessage:(CYMessage *)msg;
- (void)posthandleMessage:(CYMessage *)msg;
- (void)handleMessage:(CYMessage *)msg;

@end
