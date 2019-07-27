//
//  ACMessage.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 2017/7/3.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ApredCloudCommon.h"
@interface ACMessage : NSObject<NSCoding>

@property (nonatomic, readonly) unsigned int   messageId;
@property (nonatomic, readonly) NSString *     UUID;
@property (nonatomic, readonly) NSString *     groupId;
@property (nonatomic, readonly) NSString *     from;
@property (nonatomic, readonly) NSString *     owner;
@property (nonatomic, readonly) unsigned int   timestamp;
@property (nonatomic, readonly) unsigned int   userData;
@property (nonatomic, readonly) NSString *     bodyText;
@property (nonatomic, readonly) NSData *       bodyBinary;


- (id)initWidthString:(NSString*)body userData:(unsigned int)userData;
- (id)initWidthData:(NSData*)body userData:(unsigned int)userData;
-(NSDate *)getMessageDate;

@end
