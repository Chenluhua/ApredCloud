//
//  OneIdConnection.h
//  OneIdSDK
//
//  Created by 陈泸华 on 2017/7/15.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Request.h"
#import "ApredCloudCommon.h"
#import "ACUser.h"

typedef NS_ENUM(NSInteger, LOGINMODE) {
    LOGIN_MODE_USERNAME = 0,                 // 用户名
    LOGIN_MODE_EMAIL,                        // Email
    LOGIN_MODE_MOBILE,                       // 电话
    LOGIN_MODE_TOKEN,                       // token
};

/*
 * OneIdConnection State
 */
typedef enum
{
    ACUCState_Unknow               = 0,
    ACUCState_Connecting,
    ACUCState_ConnectFailure,
    ACUCState_Connected,
    ACUCState_TimeOut,
    ACUCState_Ready,
    ACUCState_Authing,
    ACUCState_AuthFailure,
    ACUCState_AuthSucces,
    ACUCState_LOGOUT,
    ACUCState_Disconnected,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
} ACUConnectionState;


typedef enum
{
    REQ_UNKONW = 0,
    REQ_GETINFO,
    REQ_EDITINFO,
    REQ_CHANGEPASSWORD,
    REQ_GETUSERCOUNT,
    REQ_GETONLINEUSERCOUNT,
    REQ_GETUSERLIST,
    REQ_GETPROJECTLIST,
    REQ_EDITPROJECT,
    REQ_ADDPROJECT,
    REQ_DELPROJECTS,
    REQ_GETTABLELIST,
    REQ_ADDTABLE,
    REQ_EDITTABLE,
    REQ_DELTABLES,
    REQ_INITTABLE,
    REQ_ADDFIELD,
    REQ_GETFIELDLIST,
    REQ_EDITFIELD,
    REQ_DELFIELDS,
} REQUEST;

@class OneIdConnection;
@protocol OneIdConnectionDelegate <NSObject>

@required

- (void) oneIdConnection:(OneIdConnection *_Nonnull)connection didStateChanged:(ACUConnectionState)state;
- (void) oneIdConnection:(OneIdConnection *_Nonnull)connection didRespone:(REQUEST)req resultCode:(int)result msg:(NSString *_Nullable)msg obj:(NSObject *_Nullable)obj;
- (void) oneIdConnection:(OneIdConnection *_Nonnull)connection didTokenChanged:(NSString*_Nonnull)token;
@end


@interface OneIdConnection : NSObject
@property (nonatomic, assign) id<OneIdConnectionDelegate> _Nullable delegate;
@property (nonatomic, readonly) NSString * _Nullable server;
@property (nonatomic, readonly) unsigned int port;
@property (nonatomic, readonly) NSString * _Nullable account;
@property (nonatomic, readonly) LOGINMODE loginMode;
@property (nonatomic, readonly) ACUConnectionState state;
@property (nonatomic, readonly) NSString * _Nullable userKey;
@property (nonatomic, readonly) NSString * _Nullable tempKey;
@property (nonatomic, readonly) NSString * _Nullable token;
@property (nonatomic, readonly) NSString * _Nullable lastLoginDeviceName;
@property (nonatomic, readonly) int lastErrorCode;
@property (nonatomic, readonly) NSString * _Nullable lastRespMsg;
@property (nonatomic, readonly) unsigned int level;

-(BOOL) isConnected;
-(void)disConnect;
-(void)reConnect;
-(int)searchUser:(NSString*_Nonnull)keyword result:(RESULTBLOCK _Nonnull )resultBlock;
-(int)accountIsRegistered:(NSString*)account result:(RESULTBLOCK _Nonnull)resultBlock;
-(int)getUser:(NSString*_Nonnull)userKey updateTime:(unsigned int)updateTime getHeadPhoto:(BOOL)isGetHeadPhoto result:(RESULTBLOCK _Nonnull )resultBlock;
-(int)reqVcode:(VCODEType)type serviceCode:(int)serviceCode receiver:(NSString*_Nonnull)receiver tag:(NSString*_Nonnull)tag result:(RESULTBLOCK _Nonnull )resultBlock;
-(int)registerAccount:(ACCOUNTType)accountType account:(NSString*_Nonnull)account password:(NSString*_Nonnull)password vcodeTag:(NSString*_Nonnull)vcodeTag vcode:(NSString*_Nonnull)vcode result:(RESULTBLOCK _Nonnull )resultBlock;
-(int)logout;
-(int)changePassword:(NSString*_Nonnull)password newPassword:(NSString*_Nonnull)newPassword result:(RESULTBLOCK _Nonnull )resultBlock;
-(int)resetPassword:(ACCOUNTType)accountType account:(NSString*_Nonnull)account password:(NSString*_Nonnull)password vcodeTag:(NSString*_Nonnull)vcodeTag vcode:(NSString*_Nonnull)vcode result:(RESULTBLOCK _Nonnull )resultBlock;
-(int)modifyMyProfile:(ACUser*_Nonnull)user result:(RESULTBLOCK _Nonnull )resultBlock;

@end
