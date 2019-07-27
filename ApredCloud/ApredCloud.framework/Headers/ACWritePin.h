//
//  ACWritePin.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 16/10/21.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACRecord.h"
#import "Request.h"



@interface ACWritePin : NSObject

@property (nonatomic, readonly) NSString * name;

/*
 * 添加记录
 * flag - 可选(AC_WR_FLAG_FAILIFEXISTS, AC_WR_FLAG_UPDATEIFEXISTS)
 */
-(int)addRecord:(ACRecord*)record flag:(unsigned int)flag result:(RESULTBLOCK)resultBlock progress:(PROGRESSBLOCK)progressBlock;
-(int)updateRecord:(ACRecord*)record result:(RESULTBLOCK)resultBlock progress:(PROGRESSBLOCK)progressBlock;
-(int)delRecords:(NSString*)tableName tags:(NSArray *)tags result:(RESULTBLOCK)resultBlock;
-(int)delRecords:(NSString*)tableName publicTags:(NSArray *)tags result:(RESULTBLOCK)resultBlock;

@end
