//
//  CY_Message.m
//  ZDFramework
//
//  Created by 张海迪 on 14-7-18.
//  Copyright (c) 2014年 haidi. All rights reserved.
//

#import "CY_Message.h"

@implementation CY_Message

DEF_INT( STATE_CREATED,		0 )
DEF_INT( STATE_SENDING,		1 )
DEF_INT( STATE_SUCCEED,		2 )
DEF_INT( STATE_FAILED,		3 )
DEF_INT( STATE_CANCELLED,	4 )
DEF_INT( STATE_WAITING,		5 )

@dynamic INPUT;
@dynamic OUTPUT;
@dynamic GET_INPUT;
@dynamic GET_OUTPUT;
@dynamic TIMEOUT;


@end
