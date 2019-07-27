//
//  ACObservingPin.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 2017/6/28.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Request.h"

#define OBSTYPE_DEVICE      0
#define OBSTYPE_USERKEY     1

@interface ACObservingPin : NSObject

-(int)registerObserving:(NSArray *)arObsTags obstype:(int)type result:(RESULTBLOCK)resultBlock;
-(int)unregisterObserving:(NSArray *)arObsTags obstype:(int)type result:(RESULTBLOCK)resultBlock;
-(int)unregisterAllObserving:(int)type result:(RESULTBLOCK)resultBlock;

@end
