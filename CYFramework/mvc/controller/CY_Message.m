//
//  CY_Message.m
//  ZDFramework
//
//  Created by 张海迪 on 14-7-18.
//  Copyright (c) 2014年 haidi. All rights reserved.
//

#import "CY_Message.h"

@implementation CY_Message

DEF_STRING( ERROR_DOMAIN_UNKNOWN,	@"domain.unknown" )
DEF_STRING( ERROR_DOMAIN_SERVER,	@"domain.server" )
DEF_STRING( ERROR_DOMAIN_CLIENT,	@"domain.client" )
DEF_STRING( ERROR_DOMAIN_NETWORK,	@"domain.network" )

DEF_INT( ERROR_CODE_OK,			0 )
DEF_INT( ERROR_CODE_UNKNOWN,	-1 )
DEF_INT( ERROR_CODE_TIMEOUT,	-2 )
DEF_INT( ERROR_CODE_PARAMS,		-3 )
DEF_INT( ERROR_CODE_ROUTES,		-4 )

DEF_INT( STATE_CREATED,		0 )
DEF_INT( STATE_SENDING,		1 )
DEF_INT( STATE_SUCCEED,		2 )
DEF_INT( STATE_FAILED,		3 )
DEF_INT( STATE_CANCELLED,	4 )
DEF_INT( STATE_WAITING,		5 )

@end
