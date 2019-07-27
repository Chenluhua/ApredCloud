//
//  ACReadPin.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 16/11/6.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ApredCloudCommon.h"
#import "Request.h"

@interface ACReadPin : NSObject
@property (nonatomic, readonly) NSString * name;

- (int)readRecord:(NSString*)tableName tag:(unsigned int)tag fields:(NSArray *)fields result:(RESULTBLOCK)resultBlock progress:(PROGRESSBLOCK)progressBlock;
- (int)readRecord:(NSString*)tableName publicTag:(unsigned int)tag fields:(NSArray *)fields result:(RESULTBLOCK)resultBlock progress:(PROGRESSBLOCK)progressBlock;
- (int)readRecords:(NSString*)tableName tags:(NSArray*)arTags fields:(NSArray *)fields result:(RESULTBLOCK)resultBlock progress:(PROGRESSBLOCK)progressBlock;
- (int)readRecords:(NSString*)tableName publicTags:(NSArray*)arTags fields:(NSArray *)fields result:(RESULTBLOCK)resultBlock progress:(PROGRESSBLOCK)progressBlock;
-(int)queryRecords:(QUERYSCOPE)queryScope tableName:(NSString *)tableName offset:(unsigned int)offset rows:(unsigned int)rows where:(NSString*)where orderby:(NSString*)orderby result:(RESULTBLOCK)resultBlock progress:(PROGRESSBLOCK)progressBlock;
-(int)queryRecords:(QUERYSCOPE)queryScope tableName:(NSString *)tableName offset:(unsigned int)offset rows:(unsigned int)rows where:(NSString*)where orderby:(NSString*)orderby fields:(NSArray*)fields result:(RESULTBLOCK)resultBlock progress:(PROGRESSBLOCK)progressBlock;

@end
