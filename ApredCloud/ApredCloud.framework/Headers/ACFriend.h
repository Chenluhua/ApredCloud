//
//  ACFriend.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 2017/7/18.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ApredCloudCommon.h"

@interface ACFriend : NSObject<NSCoding>

@property (nonatomic, readonly) unsigned int    friendId;
@property (nonatomic, readonly) NSString *      userKey;
@property (nonatomic, readonly) ADD2CONState    state;
@property (nonatomic, readonly) unsigned int    time;
@property (nonatomic, readonly) NSString *      remarks;


- (id)init;
- (id)initWidthUserKey:(NSString*)userKey state:(ADD2CONState)state remarks:(NSString*)remarks;
- (id)initWidthACFriend:(ACFriend *)myfriend;
-(void)copyFrom:(ACFriend *)myfriend;

@end
