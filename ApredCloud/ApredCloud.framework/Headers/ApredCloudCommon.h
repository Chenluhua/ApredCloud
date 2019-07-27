//
//  ApredCloudCommon.h
//  ApredYunClient
//
//  Created by 陈泸华 on 16/6/21.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#ifndef ApredCloudCommon_h
#define ApredCloudCommon_h


#define ACS_ERR_NOERROR					    0			/* 成功 */
#define ACS_ERR_NOERROR_NORECORD            1           /* 成功，但没有记录 */
#define ACS_ERR_NOERROR_COMMITQEQUEST	    2           /* 已成功提交请求，但需要等待处理结果 */
#define ACS_ERR_NOERROR_QEQUESTRESULT	    3			/* 已成功处理请求 */
#define ACS_ERR_PACKETERROR				    4			/* 数据包格式错误 */
#define ACS_ERR_SQLERROR				    5			/* 数据库操作错误 */
#define ACS_ERR_AUTHERROR				    6			/* 认证出错(用户名或密码不正确) */
#define ACS_ERR_PASSWORDERROR			    7			/* 认证出错(密码不正确) */
#define ACS_ERR_PERMISSIONERROR			    8			/* 权限不足 */
#define ACS_ERR_ENCODABNFERROR			    9			/* ABNF编码出错 */
#define ACS_ERR_EMPTYAUTHKEY			    10			/* 客户端未取得Auth Key */
#define ACS_ERR_DONTSUPPORT				    11			/* 不支持的请求 */
#define ACS_ERR_PARAMERROR				    12			/* 参数不足 */
#define ACS_ERR_PARAM_TEXT_NO_ABC123	    13			/* 某个参数必须以字母开头并且为字母和数字的组合 */
#define ACS_ERR_GET_PROJECTINFO_ERROR	    14			/* 获取project失败 */
#define ACS_ERR_GET_TABLEINFO_ERROR		    15			/* 获取table失败 */
#define ACS_ERR_GET_PERIPHERAL_ERROR	    16			/* 获取peripheral失败 */
#define ACS_ERR_PARAM_TEXT_RESERVED		    17			/* 保留字 */
#define ACS_ERR_NOTABLE					    18			/* 不存在的数据表 */
#define ACS_ERR_FORCEDIS_ANOTHERLOGIN	    19			/* 强制断开：用户在另一设备端登录 */
#define ACS_ERR_FORCEDIS_INACTIVITY		    20			/* 强制断开：不活动 */
#define ACS_ERR_MAX_LIMIT                   21          /* 最大数量限制 */
#define ACS_ERR_NOWIRTEPERMISSION		    22			/* 权限不足(没有写权限) */
#define ACS_ERR_MAPUSER_ERROR			    23			/* 映射用户出错 */
#define ACS_ERR_UNMAPUSER_ERROR             24            /* 解除映射用户出错 */
#define ACS_ERR_AUTHERROR_DEVICE_KICKOUT    25            /* 认证出错(其它设备踢出) */
#define ACS_ERR_REQ_ADD2CONTACTS_FAILED     26            /* 添加用户到通讯录失败 */
#define ACS_ERR_SPON_ADD2CONTACTS_FAILED    27            /* 添加用户到通讯录失败 */
#define ACS_ERR_ISNMYFRIEND                 28            /* 对方不是我的好友 */
#define ACS_ERR_ISNHERFRIEND                29            /* 我不是他的好友 */
#define ACS_ERR_ACCOUNT_HASREGISTERED       30            /* 账户已经被注册 */
#define ACS_ERR_VCODE_ERROR                 31            /* 验证码错误或已过期 */

#define ACC_ERR_NOERROR             10000       /* 没有错误 */
#define ACC_ERR_UNKNOW              10001       /* 未知错误 */
#define ACC_ERR_DONTSUPPORT         10002       /* 不支持 */
#define ACC_ERR_PARAMERROR          10003       /* 参数出错 */
#define ACC_ERR_DECODEERROR         10004       /* 解码出错 */
#define ACC_ERR_DISCONNECTED        10005       /* 未连接 */


//bFailIfExists
#define AC_WR_FLAG_FAILIFEXISTS         0x01        /* 存在则失败 */
#define AC_WR_FLAG_UPDATEIFEXISTS       0x02        /* 存在则更新 */
#define AC_WR_FLAG_ADDIFUNEXISTS        0x04        /* 不存在则添加 */


// Get Msg Flag
typedef NS_ENUM(NSInteger, GMFlag) {
    GM_NEW = 01,                      // 新消息
    GM_READ,                          // 已读消息
    GM_ALL,                           // 已读和新消息
};


// Message Read State
typedef NS_ENUM(NSInteger, MSGRState) {
    MSGRS_NEW = 0x0,                 // 新消息
    MSGRS_READ,                       // 已读消息
};


// Error Code
typedef NS_ENUM(NSInteger, ERRCode) {
    ERRCODE_NOERROR = 0,                      // 没有错误
    ERRCODE_UNKNOW = -1,                      // unknow
    ERRCODE_TABLE_DONTEXIST = -2,             // Table 不存在
    ERRCODE_PARAM_INVALID = -3,               // 参数无效
    ERRCODE_NET_DISCONNECT = -4,              // 网络断开或未连接
    ERRCODE_NOFIELD = -5,                     // 找不到对应名字的字段
    ERRCODE_FIELDTYPE_ERROR = -6,             // 字段类型不匹配
    ERRCODE_FIELD_LENERROR = -7,              // 长段长度错误
    ERRCODE_FIELD_VALUEERROR = -8,            // VALUE error
    ERRCODE_LIMIT_LOGIN = -9,                 // 限制登录(同一服务器的同一Project，在同一APP中仅允许一个用户登录)
    ERRCODE_NEEDWAIT = -10,                   // 某一连接正在认证中，必须等待它完成
    ERRCODE_UNAUTH = -11,                     // 未认证

};


// Query Scope
typedef NS_ENUM(NSInteger, QUERYSCOPE) {
    QSCOPE_PRIVATE = 0,                     // 私有
    QSCOPE_PUBLIC,                          // 公开
    QSCOPE_ALL,                             // 私有和公开
};



/* add2Contacts state */
typedef NS_ENUM(NSInteger, ADD2CONState) {
    ADD2CON_STATE_READY = 0,                     /* 就绪，已互为好友, 由ADD2CON_STATE_AGREE2转化来 */
    ADD2CON_STATE_REQ,                           /* 请求好友中 */
    ADD2CON_STATE_AGREE,                         /* 同意加好友 */
    ADD2CON_STATE_DECLINE,                       /* 拒绝加好友 */
    ADD2CON_STATE_ADD,                           /* 直接添加 */
    ADD2CON_STATE_REQ2,                         /* 被请求 */
    ADD2CON_STATE_AGREE2,                       /* 被同意 */
    ADD2CON_STATE_DECLINE2,                     /* 被拒绝 */
    ADD2CON_STATE_ADD2,                         /* 直接被添加，不需要验证 */
    ADD2CON_STATE_BLACKLIST,                    /* 黑名单 */
    ADD2CON_STATE_DELETE,                       /* 删除 */
};

/* vcode type */
typedef NS_ENUM(NSInteger, VCODEType) {
    VCODE_TYPE_EMAIL = 0,                       /* 邮件验证码 */
    VCODE_TYPE_SMS,                             /* 短信验证码 */
};

/* 验证码的服务代码 */
typedef NS_ENUM(NSInteger, VCODEServiceCode) {
    VCODE_SERVICE_UNKNOW = 0,                   /* 未知，或未说明业务类型 */
    VCODE_SERVICE_REGISTER,                     /* 注册 */
    VCODE_SERVICE_CHANGEPASSWORD,               /* 修改密码 */
    VCODE_SERVICE_RETRIEVEPASSWORD,             /* 找回密码 */
    VCODE_SERVICE_LOGIN,                        /* 验证码登录 */
};

/* add2Contacts state */
typedef NS_ENUM(NSInteger, ACCOUNTType) {
    ACCOUNT_TYPE_ID = 0,                        /* 账户ID，如不重复的用户名 */
    ACCOUNT_TYPE_EMAIL,                         /* 邮箱 */
    ACCOUNT_TYPE_MOBILE,                        /* 手机 */
};

/* topic的权限 */
typedef NS_ENUM(NSInteger, TOPICPERMISSIONS) {
    DENT = 0x1,                                 /* 拒绝，即黑名单 */
    PUBLISH = 0x2,                              /* 发布 */
    SUBCRIPTION = 0x4,                          /* 订阅 */
    CREATER = 0x8,                              /* 创建者 */
    ADMIN = 0x10,                               /* 管理权限（修改备注，通过或拒绝加入）*/
    VERIFYING = 0x20,                           /* 审核中, 等待通过验证 */
};

/* topic的访问方式 */
typedef NS_ENUM(NSInteger, TOPICACCESSTYPE) {
    WHITELIST = 0x1,                              /* 白名单可访问 */
    EXCLUDE_BLACKLIST = 0x2,                      /* 除黑名单外的可以访问 */
    VERIFY = 0x4,                                 /* 关注需要创建者或topic管理员审核，验证通过后出现在白名单 */
};

#endif /* ApredCloudCommon_h */
