//
//  ACManager.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 16/8/20.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACConnection.h"



#define AUTH_DEVICEMODE 1
#define AUTH_USERMODE   2


@interface ACManager : NSObject

@property (nonatomic, readonly) unsigned int version;
@property (nonatomic, readonly) NSString * versionCode;
@property (nonatomic, readonly) NSString * deviceUUID;

+ (ACManager*)getSharedACManager;
+ (NSString *)iphoneType;
- (ACConnection *)connectInUserMode:(NSString*)server port:(unsigned int)port projectKey:(NSString*)projectKey authKey:(NSString*)authKey userKey:(NSString *)userKey userTempKey:(NSString*)userTempKey delegate:(id)delegate;
- (ACConnection *)connectInDeviceMode:(NSString*)server port:(unsigned int)port projectKey:(NSString*)projectKey authKey:(NSString*)authKey delegate:(id)delegate;

@end
