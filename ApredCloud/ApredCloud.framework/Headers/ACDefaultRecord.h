//
//  ACDefaultRecord.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 17/3/22.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACRecord.h"


@interface ACDefaultRecord : ACRecord

- (id)initWidthTag:(unsigned int)tag;
- (FIELDTYPE)getFieldType;
- (void)setIntValue:(int)intValue;
- (int)getInt;
- (void)setFloatValue:(float)floatValue;
- (float)getFloat;
- (void)setDoubleValue:(double)doubleValue;
- (double)getDouble;
- (void)setStringValue:(NSString*)stringValue;
- (NSString *)getString;
- (void)setBinaryValue:(NSData*)binaryValue;
- (NSData *)getBinary;

@end
