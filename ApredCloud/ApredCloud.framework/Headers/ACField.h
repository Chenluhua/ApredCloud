//
//  ACField.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 16/11/1.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, FIELDTYPE) {
    FIELDError = 0,                          // error
    FIELDInt,                                // int
    FIELDFloat,                              // float
    FIELDDouble,                             // double
    FIELDString,                             // string
    FIELDBinary,                             // binary
};

@interface ACField : NSObject
@property (nonatomic, readonly) FIELDTYPE          type;
@property (nonatomic, readonly) NSString *         name;
@property (nonatomic, readonly) int                intValue;
@property (nonatomic, readonly) float              floatValue;
@property (nonatomic, readonly) double             doubleValue;
@property (nonatomic, readonly) NSString *         stringValue;
@property (nonatomic, readonly) NSData *           binaryValue;

- (id)initWithInt:(NSString *)fieldName value:(int)value;
- (id)initWithFloat:(NSString *)fieldName value:(float)value;
- (id)initWithDouble:(NSString *)fieldName value:(double)value;
- (id)initWithString:(NSString *)fieldName value:(NSString *)value;
- (id)initWithBinary:(NSString *)fieldName value:(NSData *)value;

@end
