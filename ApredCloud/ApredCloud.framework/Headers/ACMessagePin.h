//
//  ACMessagePin.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 2017/7/3.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACMessage.h"
#import "Request.h"


@class ACMessagePin;

@protocol ACMessagePinDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void) acMessagePin:(ACMessagePin *_Nonnull)pin didRecvMessage:(ACMessage*_Nonnull)message;
- (void) acMessagePin:(ACMessagePin *_Nonnull)pin didHasNewContactsMsg:(unsigned int)msgCount;
- (void) acMessagePin:(ACMessagePin *_Nonnull)pin didMsgArrived:(NSString*_Nonnull)topic data:(NSData *_Nonnull)data clientId:(NSString *_Nullable)clientId timestamp:(unsigned int)timestamp;

@end

@interface ACMessagePin : NSObject
@property (nonatomic, assign) id<ACMessagePinDelegate> _Nullable delegate;

-(int)postMessage:(NSString*_Nonnull)uid message:(ACMessage*_Nonnull)message result:(RESULTBLOCK _Nullable )resultBlock progress:(PROGRESSBLOCK _Nullable )progressBlock;
-(int)getMessageList:(GMFlag)flag offset:(unsigned int)offset rows:(unsigned int)rows result:(RESULTBLOCK _Nullable )resultBlock progress:(PROGRESSBLOCK _Nullable )progressBlock;
-(int)getMessageListForAfterTimestamp:(unsigned int)timestamp gmFlag:(GMFlag)flag offset:(unsigned int)offset rows:(unsigned int)rows result:(RESULTBLOCK _Nullable )resultBlock progress:(PROGRESSBLOCK _Nullable )progressBlock;
-(int)getMessage:(NSString*_Nonnull)msgUid result:(RESULTBLOCK _Nullable )resultBlock progress:(PROGRESSBLOCK _Nullable )progressBlock;
-(int)getNewMessageList:(unsigned int)rows result:(RESULTBLOCK _Nullable )resultBlock;
-(int)setMessagesReadState:(NSArray *_Nonnull)msgUids state:(MSGRState)state result:(RESULTBLOCK _Nullable )resultBlock;
-(int)reqAdd2Contacts:(NSString*_Nonnull)userKey remarks:(NSString*_Nonnull)remarks result:(RESULTBLOCK _Nullable )resultBlock;
-(int)agreeAdd2Contacts:(NSString*_Nonnull)userKey remarks:(NSString*_Nonnull)remarks result:(RESULTBLOCK _Nullable )resultBlock;
-(int)declineAdd2Contacts:(NSString*_Nonnull)userKey remarks:(NSString*_Nonnull)remarks result:(RESULTBLOCK _Nullable )resultBlock;
-(int)deleteFriend:(NSString*_Nonnull)userKey result:(RESULTBLOCK _Nullable)resultBlock;

/*
 * 准备就绪，可以开始聊天，向服务器表明，阅读了同意或被同意加好友的消息，以使服务器更改状态
 */
-(int)readyChat:(NSString*_Nonnull)userKey result:(RESULTBLOCK _Nullable )resultBlock;

-(int)getFriendList:(unsigned int)timestamp result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 创建一个topic
 * topicName - topic名字
 * accessType - 访问方式，参看TOPICACCESSTYPE的定义
 * tag - tag
 * notes - 备注
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)createTopic:(NSString *_Nonnull)topicName accessType:(TOPICACCESSTYPE)accessType tag:(int)tag notes:(NSString *_Nullable)notes result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 删除topic
 * topicUuid - 要删除的topic的uuid(注：调用createTopic时有返回topic的uuid)
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)deleteTopic:(NSString *_Nonnull)topicUuid result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 发布消息
 * topic - topic主题（顶层为topic的uuid，可以有多层设计, 如: 1234567890abcdef1234567890abcdef/txt）
 * data - 消息内容
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)publishMessage:(NSString *_Nonnull)topic data:(NSData *_Nonnull)data result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 订阅消息
 * topic - topic主题（顶层为topic的uuid，可以有多层设计, 如: 1234567890abcdef1234567890abcdef/txt）
 * qos - qos
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)subscription:(NSString *_Nonnull)topic qos:(int)qos result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 取得关注的topic
 * tag -- tag, 如果为0, 取所有
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)getFocusOnTopicList:(int)tag result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 取得topic的关注用户列表
 * topicUuid - topic的uuid(注：调用createTopic时有返回topic的uuid)
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)getTopicFans:(NSString *_Nonnull)topicUuid result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 关注topic，相当于加入或申请加入topic的白名单中
 * topicUuid - topic的uuid(注：调用createTopic时有返回topic的uuid)
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)focusOnTopic:(NSString *_Nonnull)topicUuid result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 取消关注topic，相当于退群等操作，从topic的白名单中移除
 * topicUuid - topic的uuid(注：调用createTopic时有返回topic的uuid)
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)cancelFocusOnTopic:(NSString *_Nonnull)topicUuid result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 设置指定topic的指定关注者的权限
 * topicUuid - topic的uuid(注：调用createTopic时有返回topic的uuid)
 * userKey - userKey关注者uuid
 * newPermissions - 新的权限
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)setTopicFansPermissions:(NSString *_Nonnull)topicUuid userKey:(NSString *_Nonnull)userKey newPermissions:(int)newPermissions result:(RESULTBLOCK _Nullable )resultBlock;

/*
 * 删除指定topic的某个关注者
 * topicUuid - topic的uuid(注：调用createTopic时有返回topic的uuid)
 * userKey - 要删除的userKey关注者uuid
 * resultBlock - 收到响应后SDK执行此block以使调用者得到执行结果
 */
-(int)deleteTopicFans:(NSString *_Nonnull)topicUuid userKey:(NSString *_Nonnull)userKey result:(RESULTBLOCK _Nullable )resultBlock;

@end
