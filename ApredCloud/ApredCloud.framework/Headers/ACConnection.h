//
//  ACConnection.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 16/8/21.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACWritePin.h"
#import "ACReadPin.h"
#import "ACObservingPin.h"
#import "ACMessagePin.h"

/*
 * ACConnection State
 */
typedef enum
{
    ACCState_Unknow               = 0,
    ACCState_Connecting,
    ACCState_ConnectFailure,
    ACCState_Connected,
    ACCState_TimeOut,
    ACCState_Ready,
    ACCState_Authing,
    ACCState_AuthFailure,
    ACCState_AuthSucces,
    ACCState_Disconnected,
} ACConnectionState;

/*
 * ACConnection UDP State
 */
typedef enum
{
    ACUDPState_Unknow               = 0,
    ACUDPState_Activity,
    ACUDPState_Inactivity,
} ACConnectionUDPState;

/*
 * ACConnection Event
 */
typedef enum
{
    ACEvent_Unknow               = 0,
    ACEvent_Forcedis,
} ACConnectionEvent;


@class ACConnection;
@protocol ACConnectionDelegate <NSObject>

@required

- (void)onACConnection:(ACConnection *_Nonnull)acConnection didStateChanged:(ACConnectionState)state;
- (void)onACConnection:(ACConnection *_Nonnull)acConnection didUDPStateChanged:(ACConnectionUDPState)state;
- (void)onACConnection:(ACConnection *_Nonnull)acConnection didRecvRawData:(NSString *_Nonnull)rawText;
- (void)onACConnection:(ACConnection *_Nonnull)acConnection didRespone:(int)req resultCode:(int)result msg:(NSString *_Nullable)msg obj:(NSObject *_Nullable)obj;
- (void)onACConnection:(ACConnection *_Nonnull)acConnection didEvent:(ACConnectionEvent)event respCode:(int)respCode msg:(NSString*_Nullable)msg data:(NSData*_Nullable)data;

@end

@interface ACConnection : NSObject
@property (nonatomic, assign) id<ACConnectionDelegate> _Nullable delegate;
@property (nonatomic, readonly) NSString * _Nonnull server;
@property (nonatomic, readonly) unsigned int port;
@property (nonatomic, readonly) NSString * _Nonnull projectKey;
@property (nonatomic, readonly) ACConnectionState state;
@property (nonatomic, readonly) int lastErrorCode;
@property (nonatomic, readonly) NSString * _Nullable lastRespMsg;

-(BOOL)isConnected;
+(NSString *_Nonnull) getStateString:(ACConnectionState)state;
-(NSString *_Nonnull) getUDPStateString:(ACConnectionUDPState)state;
-(ACConnectionUDPState)getUDPState;
-(void)reConnect;
-(void)disConnect;
-(void)disUDPConnect;
-(int)test:(int)type result:(RESULTBLOCK _Nullable )resultBlock;
-(ACWritePin *_Nonnull)getACWritePin;
-(ACReadPin *_Nonnull)getACReadPin;
-(ACObservingPin *_Nonnull)getACObservingPin;
-(ACMessagePin *_Nonnull)getACMessagePin;

@end
