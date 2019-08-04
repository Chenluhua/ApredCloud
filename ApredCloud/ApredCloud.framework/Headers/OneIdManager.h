//
//  OneIdManager.h
//  ACUserSDK
//
//  Created by 陈泸华 on 2017/7/15.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OneIdConnection.h"

@interface OneIdManager : NSObject

@property (nonatomic, readonly) unsigned int version;
@property (nonatomic, readonly) NSString * _Nonnull versionCode;
@property (nonatomic, readonly) NSString * _Nonnull deviceUUID;

+ (OneIdManager* _Nonnull)getSharedOneIdManager;
+ (NSString *_Nonnull)iphoneType;
- (OneIdConnection *_Nullable)connectAndAuth:(NSString*_Nonnull)server port:(unsigned int)port projectKey:(NSString*_Nonnull)projectKey email:(NSString*_Nonnull)emial password:(NSString*_Nonnull)password delegate:(id _Nullable )delegate error:(NSError *_Nonnull*_Nonnull)error;
- (OneIdConnection *_Nullable)connectAndAuth:(NSString*_Nonnull)server port:(unsigned int)port projectKey:(NSString*_Nonnull)projectKey mobile:(NSString*_Nonnull)mobile password:(NSString*_Nonnull)password delegate:(id _Nullable )delegate error:(NSError *_Nonnull*_Nonnull)error;
- (OneIdConnection *_Nullable)connectAndAuth:(NSString*_Nonnull)server port:(unsigned int)port projectKey:(NSString*_Nonnull)projectKey userKey:(NSString *_Nonnull)userKey token:(NSString*_Nonnull)token delegate:(id _Nullable )delegate error:(NSError *_Nonnull*_Nonnull)error;
- (OneIdConnection *_Nullable)connect:(NSString*_Nonnull)server port:(unsigned int)port projectKey:(NSString*_Nonnull)projectKey delegate:(id _Nullable )delegate error:(NSError *_Nonnull*_Nonnull)error;
- (BOOL)releaseConnection:(OneIdConnection *_Nonnull)connection;

@end
