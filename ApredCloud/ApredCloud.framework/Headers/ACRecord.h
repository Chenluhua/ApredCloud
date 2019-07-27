//
//  ACRecord.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 16/11/1.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACField.h"

@interface ACRecord : NSObject
@property (nonatomic, readonly) NSString *         tableName;
@property (nonatomic, readwrite) BOOL              isPublic;
@property (nonatomic, readonly) unsigned int       publicTag;
@property (nonatomic, readonly) unsigned int       tag;
@property (nonatomic, readonly) NSString *         owner;
@property (nonatomic, readonly) NSArray *          arFields;

- (id)initWidthTag:(unsigned int)tag tableName:(NSString *)tableName;
- (id)initWidthPublicTag:(unsigned int)tag tableName:(NSString *)tableName;
- (void)addFiled:(ACField *)field;
- (void)addIntField:(NSString*)name value:(int)intValue;
- (void)addFloatField:(NSString*)name value:(float)floatValue;
- (void)addDoubleField:(NSString*)name value:(double)doubleValue;
- (void)addStringField:(NSString*)name value:(NSString*)stringValue;
- (void)addBinaryField:(NSString*)name value:(NSData*)binaryValue;

@end
