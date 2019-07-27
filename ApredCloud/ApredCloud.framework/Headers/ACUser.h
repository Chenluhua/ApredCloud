//
//  ACUser.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 2017/7/17.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ACUser : NSObject<NSCoding>

@property (nonatomic, readonly) unsigned int    userId;
@property (nonatomic, readonly) NSString *      proUUID;
@property (nonatomic, readonly) NSString *      userKey;
@property (nonatomic, readonly) NSString *      name;
@property (nonatomic, readonly) NSString *      tel;
@property (nonatomic, readwrite) NSString *     nickname;
@property (nonatomic, readonly) NSString *      email;
@property (nonatomic, readwrite) NSString *     address;
@property (nonatomic, readwrite) NSString *     mysignature;
@property (nonatomic, readwrite) unsigned int   birthday;
@property (nonatomic, readwrite) NSData *       headphoto;
@property (nonatomic, readonly) unsigned int    registertime;
@property (nonatomic, readonly) unsigned int    updateTimestamp;


- (id)init;
- (id)initWidthACUser:(ACUser *)user;
-(void)copyFrom:(ACUser *)user;


@end
