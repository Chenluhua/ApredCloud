//
//  ACTopic.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 2019/5/26.
//  Copyright © 2019年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ACTopic : NSObject
@property (nonatomic, readonly) NSString *         uuid;
@property (nonatomic, readonly) NSString *         name;
@property (nonatomic, readonly) NSString *         notes;
@property (nonatomic, readonly) int                tag;

@end
