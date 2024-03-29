//
//  TIMComm.h
//  ImSDK
//
//  Created by bodeng on 29/1/15.
//  Copyright (c) 2015 tencent. All rights reserved.
//

#ifndef ImSDK_TIMComm_h
#define ImSDK_TIMComm_h

#import <Foundation/Foundation.h>

#define ERR_IMSDK_KICKED_BY_OTHERS      6208

@protocol TIMConnListener;
@protocol TIMUserStatusListener;
@protocol TIMRefreshListener;
@protocol TIMMessageReceiptListener;
@protocol TIMMessageUpdateListener;
@protocol TIMMessageRevokeListener;
@protocol TIMUploadProgressListener;
@protocol TIMGroupEventListener;
@protocol TIMFriendshipListener;
@protocol TIMGroupListener;
@class TIMMessage;
@class TIMImageElem;
@class TIMConversation;
@class TIMAPNSConfig;
@class TIMUserProfile;
@class TIMGroupInfoOption;
@class TIMGroupMemberInfoOption;
@class TIMFriendProfileOption;

#pragma mark - 枚举类型

/**
 * 网络连接状态
 */
typedef NS_ENUM(NSInteger, TIMNetworkStatus) {
    /**
     * 已连接
     */
    TIM_NETWORK_STATUS_CONNECTED             = 1,
    /**
     * 链接断开
     */
    TIM_NETWORK_STATUS_DISCONNECTED          = 2,
};


/**
 * 日志级别
 */
typedef NS_ENUM(NSInteger, TIMLogLevel) {
    TIM_LOG_NONE                = 0,
    TIM_LOG_ERROR               = 1,
    TIM_LOG_WARN                = 2,
    TIM_LOG_INFO                = 3,
    TIM_LOG_DEBUG               = 4,
};

/**
 * 会话类型：
 *      C2C     双人聊天
 *      GROUP   群聊
 */
typedef NS_ENUM(NSInteger, TIMConversationType) {
    /**
     *  C2C 类型
     */
    TIM_C2C              = 1,
    
    /**
     *  群聊 类型
     */
    TIM_GROUP            = 2,
    
    /**
     *  系统消息
     */
    TIM_SYSTEM           = 3,
};

/**
 *  消息状态
 */
typedef NS_ENUM(NSInteger, TIMMessageStatus){
    /**
     *  消息发送中
     */
    TIM_MSG_STATUS_SENDING              = 1,
    /**
     *  消息发送成功
     */
    TIM_MSG_STATUS_SEND_SUCC            = 2,
    /**
     *  消息发送失败
     */
    TIM_MSG_STATUS_SEND_FAIL            = 3,
    /**
     *  消息被删除
     */
    TIM_MSG_STATUS_HAS_DELETED          = 4,
    /**
     *  导入到本地的消息
     */
    TIM_MSG_STATUS_LOCAL_STORED         = 5,
    /**
     *  被撤销的消息
     */
    TIM_MSG_STATUS_LOCAL_REVOKED        = 6,
};

/**
 *  消息优先级标识
 */
typedef NS_ENUM(NSInteger, TIMMessagePriority) {
    /**
     *  高优先级，一般为红包或者礼物消息
     */
    TIM_MSG_PRIORITY_HIGH               = 1,
    /**
     *  普通优先级，普通消息
     */
    TIM_MSG_PRIORITY_NORMAL             = 2,
    /**
     *  低优先级，一般为点赞消息
     */
    TIM_MSG_PRIORITY_LOW                = 3,
    /**
     *  最低优先级，一般为后台下发的成员进退群通知
     */
    TIM_MSG_PRIORITY_LOWEST             = 4,
};

/**
 *  图片压缩选项
 */
typedef NS_ENUM(NSInteger, TIM_IMAGE_COMPRESS_TYPE){
    /**
     *  原图(不压缩）
     */
    TIM_IMAGE_COMPRESS_ORIGIN              = 0x00,
    /**
     *  高压缩率：图片较小，默认值
     */
    TIM_IMAGE_COMPRESS_HIGH                = 0x01,
    /**
     *  低压缩：高清图发送(图片较大)
     */
    TIM_IMAGE_COMPRESS_LOW                 = 0x02,
};

/**
 *  图片类型
 */
typedef NS_ENUM(NSInteger, TIM_IMAGE_TYPE){
    /**
     *  原图
     */
    TIM_IMAGE_TYPE_ORIGIN              = 0x01,
    /**
     *  缩略图
     */
    TIM_IMAGE_TYPE_THUMB               = 0x02,
    /**
     *  大图
     */
    TIM_IMAGE_TYPE_LARGE               = 0x04,
};

/**
 *  图片格式
 */
typedef NS_ENUM(NSInteger, TIM_IMAGE_FORMAT){
    /**
     *  JPG格式
     */
    TIM_IMAGE_FORMAT_JPG            = 0x1,
    /**
     *  GIF格式
     */
    TIM_IMAGE_FORMAT_GIF            = 0x2,
    /**
     *  PNG格式
     */
    TIM_IMAGE_FORMAT_PNG            = 0x3,
    /**
     *  BMP格式
     */
    TIM_IMAGE_FORMAT_BMP            = 0x4,
    /**
     *  未知格式
     */
    TIM_IMAGE_FORMAT_UNKNOWN        = 0xff,
};

typedef NS_ENUM(NSInteger, TIMLoginStatus) {
    /**
     *  已登陆
     */
    TIM_STATUS_LOGINED             = 1,
    
    /**
     *  登陆中
     */
    TIM_STATUS_LOGINING            = 2,
    
    /**
     *  无登陆
     */
    TIM_STATUS_LOGOUT              = 3,
};

typedef NS_ENUM(NSInteger, TIMGroupMemberVisibleType) {
    /**
     *  未知
     */
    TIM_GROUP_MEMBER_VISIBLE_UNKNOWN          = 0x00,
    /**
     *  群组成员不可见
     */
    TIM_GROUP_MEMBER_VISIBLE_NO               = 0x01,
    /**
     *  群组成员可见
     */
    TIM_GROUP_MEMBER_VISIBLE_YES              = 0x02,
};

typedef NS_ENUM(NSInteger, TIMGroupSearchableType) {
    /**
     *  未知
     */
    TIM_GROUP_SEARCHABLE_UNKNOWN              = 0x00,
    /**
     *  群组不能被搜到
     */
    TIM_GROUP_SEARCHABLE_NO                   = 0x01,
    /**
     *  群组能被搜到
     */
    TIM_GROUP_SEARCHABLE_YES                  = 0x02,
};

/**
 * 加群选项
 */
typedef NS_ENUM(NSInteger, TIMGroupAddOpt) {
    /**
     *  禁止加群
     */
    TIM_GROUP_ADD_FORBID                    = 0,
    
    /**
     *  需要管理员审批
     */
    TIM_GROUP_ADD_AUTH                      = 1,
    
    /**
     *  任何人可以加入
     */
    TIM_GROUP_ADD_ANY                       = 2,
};

/**
 *  群组提示类型
 */
typedef NS_ENUM(NSInteger, TIMGroupTipsType){
    /**
     *  成员加入
     */
    TIM_GROUP_TIPS_JOIN              = 1,
    /**
     *  成员离开
     */
    TIM_GROUP_TIPS_QUIT              = 2,
    /**
     *  成员被踢
     */
    TIM_GROUP_TIPS_KICK              = 3,
    /**
     *  成员设置管理员
     */
    TIM_GROUP_TIPS_SET_ADMIN         = 4,
    /**
     *  成员取消管理员
     */
    TIM_GROUP_TIPS_CANCEL_ADMIN      = 5,
};

/**
 * 群消息接受选项
 */
typedef NS_ENUM(NSInteger, TIMGroupReceiveMessageOpt) {
    /**
     *  接收消息
     */
    TIM_GROUP_RECEIVE_MESSAGE                       = 0,
    /**
     *  不接收消息，服务器不进行转发
     */
    TIM_GROUP_NOT_RECEIVE_MESSAGE                   = 1,
    /**
     *  接受消息，不进行iOS APNs 推送
     */
    TIM_GROUP_RECEIVE_NOT_NOTIFY_MESSAGE            = 2,
};

/**
 *  群Tips类型
 */
typedef NS_ENUM(NSInteger, TIM_GROUP_TIPS_TYPE){
    /**
     *  邀请加入群 (opUser & groupName & userList)
     */
    TIM_GROUP_TIPS_TYPE_INVITE              = 0x01,
    /**
     *  退出群 (opUser & groupName & userList)
     */
    TIM_GROUP_TIPS_TYPE_QUIT_GRP            = 0x02,
    /**
     *  踢出群 (opUser & groupName & userList)
     */
    TIM_GROUP_TIPS_TYPE_KICKED              = 0x03,
    /**
     *  设置管理员 (opUser & groupName & userList)
     */
    TIM_GROUP_TIPS_TYPE_SET_ADMIN           = 0x04,
    /**
     *  取消管理员 (opUser & groupName & userList)
     */
    TIM_GROUP_TIPS_TYPE_CANCEL_ADMIN        = 0x05,
    /**
     *  群资料变更 (opUser & groupName & introduction & notification & faceUrl & owner)
     */
    TIM_GROUP_TIPS_TYPE_INFO_CHANGE         = 0x06,
    /**
     *  群成员资料变更 (opUser & groupName & memberInfoList)
     */
    TIM_GROUP_TIPS_TYPE_MEMBER_INFO_CHANGE         = 0x07,
};

/**
 *  群Tips类型
 */
typedef NS_ENUM(NSInteger, TIM_GROUP_INFO_CHANGE_TYPE){
    /**
     *  群名修改
     */
    TIM_GROUP_INFO_CHANGE_GROUP_NAME                    = 0x01,
    /**
     *  群简介修改
     */
    TIM_GROUP_INFO_CHANGE_GROUP_INTRODUCTION            = 0x02,
    /**
     *  群公告修改
     */
    TIM_GROUP_INFO_CHANGE_GROUP_NOTIFICATION            = 0x03,
    /**
     *  群头像修改
     */
    TIM_GROUP_INFO_CHANGE_GROUP_FACE                    = 0x04,
    /**
     *  群主变更
     */
    TIM_GROUP_INFO_CHANGE_GROUP_OWNER                   = 0x05,
};

/**
 *  群系统消息类型
 */
typedef NS_ENUM(NSInteger, TIM_GROUP_SYSTEM_TYPE){
    /**
     *  申请加群请求（只有管理员会收到）
     */
    TIM_GROUP_SYSTEM_ADD_GROUP_REQUEST_TYPE              = 0x01,
    /**
     *  申请加群被同意（只有申请人能够收到）
     */
    TIM_GROUP_SYSTEM_ADD_GROUP_ACCEPT_TYPE               = 0x02,
    /**
     *  申请加群被拒绝（只有申请人能够收到）
     */
    TIM_GROUP_SYSTEM_ADD_GROUP_REFUSE_TYPE               = 0x03,
    /**
     *  被管理员踢出群（只有被踢的人能够收到）
     */
    TIM_GROUP_SYSTEM_KICK_OFF_FROM_GROUP_TYPE            = 0x04,
    /**
     *  群被解散（全员能够收到）
     */
    TIM_GROUP_SYSTEM_DELETE_GROUP_TYPE                   = 0x05,
    /**
     *  创建群消息（创建者能够收到）
     */
    TIM_GROUP_SYSTEM_CREATE_GROUP_TYPE                   = 0x06,
    /**
     *  邀请入群通知(被邀请者能够收到)
     */
    TIM_GROUP_SYSTEM_INVITED_TO_GROUP_TYPE               = 0x07,
    /**
     *  主动退群（主动退群者能够收到）
     */
    TIM_GROUP_SYSTEM_QUIT_GROUP_TYPE                     = 0x08,
    /**
     *  设置管理员(被设置者接收)
     */
    TIM_GROUP_SYSTEM_GRANT_ADMIN_TYPE                    = 0x09,
    /**
     *  取消管理员(被取消者接收)
     */
    TIM_GROUP_SYSTEM_CANCEL_ADMIN_TYPE                   = 0x0a,
    /**
     *  群已被回收(全员接收)
     */
    TIM_GROUP_SYSTEM_REVOKE_GROUP_TYPE                   = 0x0b,
    /**
     *  邀请入群请求(被邀请者接收)
     */
    TIM_GROUP_SYSTEM_INVITE_TO_GROUP_REQUEST_TYPE        = 0x0c,
    /**
     *  邀请加群被同意(只有发出邀请者会接收到)
     */
    TIM_GROUP_SYSTEM_INVITE_TO_GROUP_ACCEPT_TYPE         = 0x0d,
    /**
     *  邀请加群被拒绝(只有发出邀请者会接收到)
     */
    TIM_GROUP_SYSTEM_INVITE_TO_GROUP_REFUSE_TYPE         = 0x0e,
    /**
     *  用户自定义通知(默认全员接收)
     */
    TIM_GROUP_SYSTEM_CUSTOM_INFO                         = 0xff,
};

typedef NS_ENUM(NSInteger, TIMOfflinePushFlag) {
    /**
     *  按照默认规则进行推送
     */
    TIM_OFFLINE_PUSH_DEFAULT    = 0,
    /**
     *  不进行推送
     */
    TIM_OFFLINE_PUSH_NO_PUSH    = 1,
};

typedef NS_ENUM(NSInteger, TIMAndroidOfflinePushNotifyMode) {
    /**
     *  通知栏消息
     */
    TIM_ANDROID_OFFLINE_PUSH_NOTIFY_MODE_NOTIFICATION = 0x00,
    /**
     *  不弹窗，由应用自行处理
     */
    TIM_ANDROID_OFFLINE_PUSH_NOTIFY_MODE_CUSTOM = 0x01,
};

/**
 * 群成员角色
 */
typedef NS_ENUM(NSInteger, TIMGroupMemberRole) {
    /**
     *  未定义（没有获取该字段）
     */
    TIM_GROUP_MEMBER_UNDEFINED              = 0,
    
    /**
     *  群成员
     */
    TIM_GROUP_MEMBER_ROLE_MEMBER              = 200,
    
    /**
     *  群管理员
     */
    TIM_GROUP_MEMBER_ROLE_ADMIN               = 300,
    
    /**
     *  群主
     */
    TIM_GROUP_MEMBER_ROLE_SUPER               = 400,
};

typedef NS_ENUM(NSInteger, TIMFriendAllowType) {
    /**
     *  同意任何用户加好友
     */
    TIM_FRIEND_ALLOW_ANY                    = 0,
    
    /**
     *  需要验证
     */
    TIM_FRIEND_NEED_CONFIRM                 = 1,
    
    /**
     *  拒绝任何人加好友
     */
    TIM_FRIEND_DENY_ANY                     = 2,
};

typedef NS_ENUM(NSInteger, TIMGender) {
    /**
     *  未知性别
     */
    TIM_GENDER_UNKNOWN      = 0,
    /**
     *  男性
     */
    TIM_GENDER_MALE         = 1,
    /**
     *  女性
     */
    TIM_GENDER_FEMALE       = 2,
    
};

/**
 * 基本资料标志位
 */
typedef NS_ENUM(NSInteger, TIMProfileFlag) {
    /**
     * 昵称
     */
    TIM_PROFILE_FLAG_NICK                = 0x01,
    /**
     * 好友验证方式
     */
    TIM_PROFILE_FLAG_ALLOW_TYPE          = (0x01 << 1),
    /**
     * 头像
     */
    TIM_PROFILE_FLAG_FACE_URL            = (0x01 << 2),
    /**
     * 好友备注
     */
    TIM_PROFILE_FLAG_REMARK              = (0x01 << 3),
    /**
     * 好友分组
     */
    TIM_PROFILE_FLAG_GROUP               = (0x01 << 4),
    /**
     * 用户签名
     */
    TIM_PROFILE_FLAG_SELFSIGNATURE       = (0x01 << 5),
    /**
     * 用户性别
     */
    TIM_PROFILE_FLAG_GENDER              = (0x01 << 6),
    /**
     * 用户生日
     */
    TIM_PROFILE_FLAG_BIRTHDAY            = (0x01 << 7),
    /**
     * 用户区域
     */
    TIM_PROFILE_FLAG_LOCATION            = (0x01 << 8),
    /**
     * 用户语言
     */
    TIM_PROFILE_FLAG_LANGUAGE            = (0x01 << 9),
    /**
     * 用户等级
     */
    TIM_PROFILE_FLAG_LEVEL               = (0x01 << 10),
    /**
     * 用户角色
     */
    TIM_PROFILE_FLAG_ROLE                = (0x01 << 11),
};

#pragma mark - block回调

/**
 *  获取消息回调
 *
 *  @param msgs 消息列表
 */
typedef void (^TIMGetMsgSucc)(NSArray * msgs);

/**
 *  一般操作成功回调
 */
typedef void (^TIMSucc)();

/**
 *  操作失败回调
 *
 *  @param code 错误码
 *  @param msg  错误描述，配合错误码使用，如果问题建议打印信息定位
 */
typedef void (^TIMFail)(int code, NSString * msg);

/**
 *  登陆成功回调
 */
typedef void (^TIMLoginSucc)();

/**
 *  获取资源
 *
 *  @param data 资源二进制
 */
typedef void (^TIMGetResourceSucc)(NSData * data);

/**
 *  日志回调
 *
 *  @param lvl      输出的日志级别
 *  @param msg 日志内容
 */
typedef void (^TIMLogFunc)(TIMLogLevel lvl, NSString * msg);

/**
 *  上传图片成功回调
 *
 *  @param elem 上传图片成功后elem
 */
typedef void (^TIMUploadImageSucc)(TIMImageElem * elem);

/**
 *  APNs推送配置更新成功回调
 *
 *  @param config 配置
 */
typedef void (^TIMAPNSConfigSucc)(TIMAPNSConfig* config);

/**
 *  群创建成功
 *
 *  @param groupId 群组Id
 */
typedef void (^TIMCreateGroupSucc)(NSString * groupId);

/**
 *  好友列表
 *
 *  @param friends 好友列表
 */
typedef void (^TIMFriendSucc)(NSArray * friends);

/**
 *  获取资料回调
 *
 *  @param profile 资料
 */
typedef void (^TIMGetProfileSucc)(TIMUserProfile * profile);

#pragma mark - 基本类型

@interface TIMCodingModel : NSObject <NSCoding>

- (void)encodeWithCoder:(NSCoder *)encoder;
- (id)initWithCoder:(NSCoder *)decoder;

@end

@interface TIMSdkConfig : NSObject

/**
 *  用户标识接入SDK的应用ID，必填
 */
@property(nonatomic,assign) int sdkAppId;

/**
 *  用户的账号类型，必填
 */
@property(nonatomic,strong) NSString * accountType;

/**
 *  禁用crash上报，默认上报
 */
@property(nonatomic,assign) BOOL disableCrashReport;

/**
 *  禁止在控制台打印log
 */
@property(nonatomic,assign) BOOL disableLogPrint;

/**
 *  本地写log文件的等级，默认DEBUG等级
 */
@property(nonatomic,assign) TIMLogLevel logLevel;

/**
 *  log文件路径，不设置时为默认路径
 */
@property(nonatomic,strong) NSString * logPath;

/**
 *  回调给log函数的log等级，默认DEBUG等级
 */
@property(nonatomic,assign) TIMLogLevel logFuncLevel;

/**
 *  log监听函数
 */
@property(nonatomic,copy) TIMLogFunc logFunc;

/**
 *  消息数据库路径，不设置时为默认路径
 */
@property(nonatomic,strong) NSString * dbPath;

/**
 *  网络监听器
 */
@property(nonatomic,strong) id<TIMConnListener> connListener;

@end


@interface TIMUserConfig : NSObject

/**
 *  禁用本地存储（加载消息扩展包有效）
 */
@property(nonatomic,assign) BOOL disableStorage;

/**
 *  禁止自动上报（加载消息扩展包有效）
 */
@property(nonatomic,assign) BOOL disableAutoReport;

/**
 *  开启C2C已读回执（加载消息扩展包有效）
 */
@property(nonatomic,assign) BOOL enableReadReceipt;

/**
 *  不开启最近联系人（加载消息扩展包有效）
 */
@property(nonatomic,assign) BOOL disableRecnetContact;

/**
 *  不通过onNewMessage:抛出最近联系人的最后一条消息（加载消息扩展包有效）
 */
@property(nonatomic,assign) BOOL disableRecentContactNotify;

/**
 *  开启关系链数据本地缓存功能（加载好友扩展包有效）
 */
@property(nonatomic,assign) BOOL enableFriendshipProxy;

/**
 *  开启群组数据本地缓存功能（加载群组扩展包有效）
 */
@property(nonatomic,assign) BOOL enableGroupAssistant;

/**
 *  设置默认拉取的群组资料
 */
@property(nonatomic,strong) TIMGroupInfoOption * groupInfoOpt;

/**
 *  设置默认拉取的群成员资料
 */
@property(nonatomic,strong) TIMGroupMemberInfoOption * groupMemberInfoOpt;

/**
 *  设置默认拉取的好友资料
 */
@property(nonatomic,strong) TIMFriendProfileOption * friendProfileOpt;

/**
 *  用户登录状态监听器
 */
@property(nonatomic,strong) id<TIMUserStatusListener> userStatusListener;

/**
 *  会话刷新监听器（未读计数、已读同步）（加载消息扩展包有效）
 */
@property(nonatomic,strong) id<TIMRefreshListener> refreshListener;

/**
 *  消息已读回执监听器（加载消息扩展包有效）
 */
@property(nonatomic,strong) id<TIMMessageReceiptListener> receiptListener;

/**
 *  消息svr重写监听器（加载消息扩展包有效）
 */
@property(nonatomic,strong) id<TIMMessageUpdateListener> messageUpdateListener;

/**
 *  消息撤回监听器（加载消息扩展包有效）
 */
@property(nonatomic,strong) id<TIMMessageRevokeListener> messgeRevokeListener;

/**
 *  文件上传进度监听器
 */
@property(nonatomic,strong) id<TIMUploadProgressListener> uploadProgressListener;

/**
 *  群组事件通知监听器
 */
@property(nonatomic,strong) id<TIMGroupEventListener> groupEventListener;

/**
 *  关系链数据本地缓存监听器（加载好友扩展包、enableFriendshipProxy有效）
 */
@property(nonatomic,strong) id<TIMFriendshipListener> friendshipListener;

/**
 *  群组据本地缓存监听器（加载群组扩展包、enableGroupAssistant有效）
 */
@property(nonatomic,strong) id<TIMGroupListener> groupListener;

@end

/**
 *  登陆信息
 */

@interface TIMLoginParam : NSObject

/**
 * 用户名
 */
@property(nonatomic,strong) NSString* identifier;

/**
 *  鉴权Token
 */
@property(nonatomic,strong) NSString* userSig;

/**
 *  App用户使用OAuth授权体系分配的Appid
 */
@property(nonatomic,strong) NSString* appidAt3rd;


@end

/**
 *  APNs 配置
 */
@interface TIMAPNSConfig : NSObject
/**
 *  是否开启推送：0-不进行设置 1-开启推送 2-关闭推送
 */
@property(nonatomic,assign) uint32_t openPush;
/**
 *  C2C消息声音,不设置传入nil
 */
@property(nonatomic,strong) NSString * c2cSound;

/**
 *  Group消息声音,不设置传入nil
 */
@property(nonatomic,strong) NSString * groupSound;

/**
 *  Video声音,不设置传入nil
 */
@property(nonatomic,strong) NSString * videoSound;

@end

/**
 *  SetToken 参数
 */
@interface TIMTokenParam : NSObject
/**
 *  获取的客户端Token信息
 */
@property(nonatomic,strong) NSData* token;
/**
 *  业务ID，传递证书时分配
 */
@property(nonatomic,assign) uint32_t busiId;

@end


/**
 *  切后台参数
 */
@interface TIMBackgroundParam : NSObject

/**
 *  C2C 未读计数
 */
@property(nonatomic,assign) int c2cUnread;

/**
 *  群 未读计数
 */
@property(nonatomic,assign) int groupUnread;

@end

@interface TIMMessageLocator : NSObject
/**
 *  所属会话的id
 */
@property(nonatomic,strong) NSString * sessId;
/**
 *  所属会话的类型
 */
@property(nonatomic,assign) TIMConversationType sessType;
/**
 *  消息序列号
 */
@property(nonatomic,assign) uint64_t seq;
/**
 *  消息随机码
 */
@property(nonatomic,assign) uint64_t rand;
/**
 *  消息时间戳
 */
@property(nonatomic,assign) time_t time;
/**
 *  是否本人消息
 */
@property(nonatomic,assign) BOOL isSelf;

/**
 *  是否来自撤销通知
 */
@property(nonatomic,assign) BOOL isFromRevokeNotify;

@end

/**
 *  已读回执
 */
@interface TIMMessageReceipt : NSObject
/**
 *  已读回执对应的会话（目前只支持C2C会话）
 */
@property(nonatomic,strong) TIMConversation * conversation;
/**
 *  收到已读回执时，这个时间戳之前的消息都已读
 */
@property(nonatomic,assign) time_t timestamp;
@end

@interface TIMAndroidOfflinePushConfig : NSObject
/**
 *  离线推送时展示标签
 */
@property(nonatomic,strong) NSString * title;
/**
 *  Android离线Push时声音字段信息
 */
@property(nonatomic,strong) NSString * sound;
/**
 *  离线推送时通知形式
 */
@property(nonatomic,assign) TIMAndroidOfflinePushNotifyMode notifyMode;

@end

@interface TIMIOSOfflinePushConfig : NSObject
/**
 *  离线Push时声音字段信息
 */
@property(nonatomic,strong) NSString * sound;
/**
 *  忽略badge计数
 */
@property(nonatomic,assign) BOOL ignoreBadge;

@end

/**
 *  群组内的本人信息
 */
@interface TIMGroupSelfInfo : NSObject

/**
 *  加入群组时间
 */
@property(nonatomic,assign) uint32_t joinTime;

/**
 *  群组中的角色
 */
@property(nonatomic,assign) TIMGroupMemberRole role;

/**
 *  群组消息接收选项
 */
@property(nonatomic,assign) TIMGroupReceiveMessageOpt recvOpt;

/**
 *  群组中的未读消息数
 */
@property(nonatomic,assign) uint32_t unReadMessageNum;

@end

/**
 *  群资料信息
 */
@interface TIMGroupInfo : TIMCodingModel

/**
 *  群组Id
 */
@property(nonatomic,strong) NSString* group;
/**
 *  群名
 */
@property(nonatomic,strong) NSString* groupName;
/**
 *  群创建人/管理员
 */
@property(nonatomic,strong) NSString * owner;
/**
 *  群类型：Private,Public,ChatRoom
 */
@property(nonatomic,strong) NSString* groupType;
/**
 *  群创建时间
 */
@property(nonatomic,assign) uint32_t createTime;
/**
 *  最近一次群资料修改时间
 */
@property(nonatomic,assign) uint32_t lastInfoTime;
/**
 *  最近一次发消息时间
 */
@property(nonatomic,assign) uint32_t lastMsgTime;
/**
 *  最大成员数
 */
@property(nonatomic,assign) uint32_t maxMemberNum;
/**
 *  群成员数量
 */
@property(nonatomic,assign) uint32_t memberNum;

/**
 *  入群类型
 */
@property(nonatomic,assign) TIMGroupAddOpt addOpt;

/**
 *  群公告
 */
@property(nonatomic,strong) NSString* notification;

/**
 *  群简介
 */
@property(nonatomic,strong) NSString* introduction;

/**
 *  群头像
 */
@property(nonatomic,strong) NSString* faceURL;

/**
 *  最后一条消息
 */
@property(nonatomic,strong) TIMMessage* lastMsg;

/**
 *  在线成员数量
 */
@property(nonatomic,assign) uint32_t onlineMemberNum;

/**
 *  群组是否被搜索类型
 */
@property(nonatomic,assign) TIMGroupSearchableType isSearchable;

/**
 *  群组成员可见类型
 */
@property(nonatomic,assign) TIMGroupMemberVisibleType isMemberVisible;

/**
 是否全员禁言
 */
@property(nonatomic,assign) BOOL allShutup;

/**
 *  群组中的本人信息
 */
@property(nonatomic,strong) TIMGroupSelfInfo* selfInfo;

/**
 *  自定义字段集合,key是NSString*类型,value是NSData*类型
 */
@property(nonatomic,strong) NSDictionary* customInfo;

@end

/**
 *  事件上报信息
 */
@interface TIMEventReportItem : NSObject
/**
 *  事件id
 */
@property(nonatomic,assign) uint32_t event;
/**
 *  错误码
 */
@property(nonatomic,assign) uint32_t code;
/**
 *  错误描述
 */
@property(nonatomic,strong) NSString * desc;
/**
 *  事件延迟（单位ms）
 */
@property(nonatomic,assign) uint32_t delay;

@end

@interface TIMGroupInfoOption : NSObject

/**
 *  需要获取的群组信息标志（TIMGetGroupBaseInfoFlag）,默认为0xffffff
 */
@property(nonatomic,assign) uint64_t groupFlags;

/**
 *  需要获取群组资料的自定义信息（NSString*）列表
 */
@property(nonatomic,strong) NSArray * groupCustom;

@end

@interface TIMGroupMemberInfoOption : NSObject

/**
 *  需要获取的群成员标志（TIMGetGroupMemInfoFlag）,默认为0xffffff
 */
@property(nonatomic,assign) uint64_t memberFlags;

/**
 *  需要获取群成员资料的自定义信息（NSString*）列表
 */
@property(nonatomic,strong) NSArray * memberCustom;

@end

/**
 *  成员操作返回值
 */
@interface TIMGroupMemberInfo : TIMCodingModel

/**
 *  被操作成员
 */
@property(nonatomic,strong) NSString* member;

/**
 *  群名片
 */
@property(nonatomic,strong) NSString* nameCard;

/**
 *  加入群组时间
 */
@property(nonatomic,assign) time_t joinTime;

/**
 *  成员类型
 */
@property(nonatomic,assign) TIMGroupMemberRole role;

/**
 *  禁言结束时间（时间戳）
 */
@property(nonatomic,assign) uint32_t silentUntil;

/**
 *  自定义字段集合,key是NSString*类型,value是NSData*类型
 */
@property(nonatomic,strong) NSDictionary* customInfo;

@end

@interface TIMFriendProfileOption : NSObject

/**
 *  需要获取的好友信息标志（TIMProfileFlag）,默认为0xffffff
 */
@property(nonatomic,assign) uint64_t friendFlags;

/**
 *  需要获取的好友自定义信息（NSString*）列表
 */
@property(nonatomic,strong) NSArray * friendCustom;

/**
 *  需要获取的用户自定义信息（NSString*）列表
 */
@property(nonatomic,strong) NSArray * userCustom;

@end

/**
 *  好友资料
 */
@interface TIMUserProfile : TIMCodingModel

/**
 *  用户identifier
 */
@property(nonatomic,strong) NSString* identifier;

/**
 *  用户昵称
 */
@property(nonatomic,strong) NSString* nickname;

/**
 *  用户备注（最大96字节，获取自己资料时，该字段为空）
 */
@property(nonatomic,strong) NSString* remark;

/**
 *  好友验证方式
 */
@property(nonatomic,assign) TIMFriendAllowType allowType;

/**
 * 用户头像
 */
@property(nonatomic,strong) NSString* faceURL;

/**
 *  用户签名
 */
@property(nonatomic,strong) NSData* selfSignature;

/**
 *  好友性别
 */
@property(nonatomic,assign) TIMGender gender;

/**
 *  好友生日
 */
@property(nonatomic,assign) uint32_t birthday;

/**
 *  好友区域
 */
@property(nonatomic,strong) NSData* location;

/**
 *  好友语言
 */
@property(nonatomic,assign) uint32_t language;

/**
 *  等级
 */
@property(nonatomic,assign) uint32_t level;

/**
 *  角色
 */
@property(nonatomic,assign) uint32_t role;

/**
 *  好友分组名称 NSString* 列表
 */
@property(nonatomic,strong) NSArray* friendGroups;

/**
 *  自定义字段集合,key是NSString类型,value是NSData类型或者NSNumber类型
 *  (key值按照后台配置的字符串传入)
 */
@property(nonatomic,strong) NSDictionary* customInfo;

@end

#endif
