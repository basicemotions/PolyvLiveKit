//
//  PLVLiveAPI.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVLiveConfig.h"
#import "PLVLiveChannel.h"
#import "PLVPushChannel.h"
#import "PLVLiveReporter.h"
#import "PLVChannelMenuInfo.h"

/// 直播加入连麦通知
extern NSString * const PLVLiveLinkMicDidJoinNotification;
/// 直播退出连麦通知
extern NSString * const PLVLiveLinkMicDidLeaveNotification;

/// SDK 通用错误码
typedef NS_ENUM(NSInteger, PLVLiveErrorCode) {
    /// 参数无效/非法
    PLVLiveErrorCodeParamInvalid                = -10000,
    
    /// 网络请求错误
    PLVLiveErrorCodeNetworkError                = -10010,
    /// 服务器响应非200
    PLVLiveErrorCodeResponseCodeNot200          = -10011,
    /// 服务器响应403
    PLVLiveErrorCodeResponseCode403             = -10012,
    
    /// JSON解析失败
    PLVLiveErrorCodeJsonDecodeFailure           = -10020,
    /// 加密JSON解析失败
    PLVLiveErrorCodeEncodeJsonDecodeFailure     = -10021,
    /// 解码失败(异常)
    PLVLiveErrorCodeDecodeFailure               = -10022,
    
    /* -- 以下主要为服务器对参数验证不通过 -- */
    /// 登录失败(登录接口)
    PLVLiveErrorCodeLoginFailure                = -10030,
    /// 请求失败
    PLVLiveErrorCodeRequestFailure              = -10031,
    /// 设置失败
    PLVLiveErrorCodeSettingFailure              = -10032,
    /// 授权验证失败
    PLVLiveErrorCodeAuthFailure                 = -10033,
    
    /// 未知类型
    PLVLiveErrorCodeUnknown                     = -9999
};

/** 返回 SDK 通用错误码对应的字符串符号*/
NSString *NameStringWithLiveErrorCode(PLVLiveErrorCode errorCode);

/// 直播状态
typedef NS_ENUM(NSInteger, PLVLiveStreamState) {
    /// 直播流状态未知
    PLVLiveStreamStateUnknown               = -1,
    /// 无直播流
    PLVLiveStreamStateNoStream              = 0,
    /// 直播中
    PLVLiveStreamStateLive                  = 1
};

/**
 直播相关接口，以下所有接口回调都在主线程中
 */
@interface PLVLiveAPI : NSObject

#pragma mark -  直播观看相关接口

/**
 获取直播频道信息（自动重试，建议）
    主接口获取三次频道信息失败会自动切换至备用接口进行请求
 @param userId 用户Id
 @param channelId 频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)loadChannelInfoRepeatedlyWithUserId:(NSString *)userId
                                  channelId:(NSUInteger)channelId
                                 completion:(void (^)(PLVLiveChannel *channel))completion
                                    failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取直播频道信息（单次请求）
 
 @param userId 用户Id
 @param channelId 频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)loadChannelInfoOnceWithUserId:(NSString *)userId
                            channelId:(NSUInteger)channelId
                           completion:(void (^)(PLVLiveChannel *channel))completion
                              failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 根据流名获取当前流状态

 @param stream 流名
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)isLiveWithStream:(NSString *)stream
              completion:(void(^)(PLVLiveStreamState streamState))completion
                 failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 根据频道号获取当前流状态（是否直播中及直播模式）

 @param channelId 频道号
 @param stream 流名
 @param completion 请求完成，参数不能为 nil
        mode 推流模式：ppt(云课堂推流)/alone(直播助手推流)
 @param failure 请求失败
 */
+ (void)getStreamStatusWithChannelId:(NSUInteger)channelId
                              stream:(NSString *)stream
                          completion:(void(^)(PLVLiveStreamState streamState, NSString *mode))completion
                             failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取频道约束信息

 @param userId 用户Id
 @param channelId 频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)getChannelRestrictInfoWithUserId:(NSString *)userId
                               channelId:(NSUInteger)channelId
                              completion:(void (^)(NSDictionary *responseDict))completion
                                 failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取频道咨询提问菜单状态

 @param channelId 频道号
 @param completion 获取成功，参数不能为 nil
 @param failure 获取失败
 */
+ (void)getChannelMenuInfos:(NSUInteger)channelId
                 completion:(void(^)(PLVChannelMenuInfo *channelMenuInfo))completion
                    failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark -  直播推流相关接口

/**
 获取推流频道信息及地址

 @param channelId 频道号
 @param password 密码
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)loadPushInfoWithChannelId:(NSUInteger)channelId
                         password:(NSString *)password
                       completion:(void(^)(PLVPushChannel *channel, NSString *rtmpUrl))completion
                          failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取推流地址

 @param channel 推流频道信息
 @param completion 获取成功，参数不能为nil
 */
+ (void)getRtmpUrlWithPushChannel:(PLVPushChannel *)channel
                       completion:(void(^)(NSString *rtmpUrl))completion;

/**
 设置推流为单流模式

 @param channelId 频道号
 @param stream 当前频道号的流名
 @param success 设置成功，参数不能为 nil
 @param failure 设置失败
 */
+ (void)configAloneStreamModeWithChannelId:(NSUInteger)channelId
                                    stream:(NSString *)stream
                                   success:(void (^)(NSString *sessionId))success
                                   failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark - 小班课相关接口

/**
 效验验证码接口

 @param channelId 频道号
 @param invitationCode 邀请码
 @param success 验证成功，参数不能为 nil
 @param failure 验证失败，PLVLiveErrorCode: ParamInvalid、NetworkError、ResponseCodeNot200、AuthFailure、JsonDecodeFailure
 */
+ (void)requestAuthorizationForInteractiveClassWithChannelId:(NSUInteger)channelId
                                               invitaionCode:(NSString *)invitationCode
                                                     success:(void (^)(NSString *data))success
                                                     failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark - Socket、连麦授权接口

/**
 Socket、连麦授权接口

 @param channelId 频道号
 @param appId Polyv直播后台“API设置“中appId参数（用户参数）
 @param appSecret Polyv直播后台“API设置“中appSecret参数（用户参数）
 @param success 授权完成，参数不能为 nil
 @param failure 授权失败，PLVLiveErrorCode: ParamInvalid、NetworkError、ResponseCodeNot200、AuthFailure、EncodeJsonDecodeFailure、DecodeFailure、JsonDecodeFailure
 */
+ (void)requestAuthorizationForLinkingSocketWithChannelId:(NSUInteger)channelId
                                                    Appld:(NSString *)appId
                                                appSecret:(NSString *)appSecret
                                                  success:(void (^)(NSDictionary *responseDict))success
                                                  failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark - 聊天室相关

/**
 获取聊天室历史记录

 @param roomId 房间号/频道号
 // startIndex 为 0 endIndex 为 -1 时，返回全部历史记录
 @param startIndex 开始下标
 @param endIndex 结束下标
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestChatRoomHistoryWithRoomId:(NSUInteger)roomId
                              startIndex:(NSUInteger)startIndex
                                endIndex:(NSInteger)endIndex
                              completion:(void (^)(NSArray *historyList))completion
                                 failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;
/**
 获取聊天室历史记录

 @param roomId 房间号/频道号
 @param startIndex 开始下标
 @param endIndex 结束下标
 @param fullMessage 是否返回图片消息
 @param showIp 显示 IP 地址
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestChatRoomHistoryWithRoomId:(NSUInteger)roomId
                              startIndex:(NSUInteger)startIndex
                                endIndex:(NSInteger)endIndex
                             fullMessage:(BOOL)fullMessage
                                  showIp:(BOOL)showIp
                              completion:(void (^)(NSArray *))completion
                                 failure:(void (^)(PLVLiveErrorCode, NSString *))failure;

/**
 获取聊天室在线成员列表(最多一百条数据)
 @warning 该方法可能会废弃，请使用 +requestChatRoomListUsersWithRoomId:page:length:completion:failure 替代
 @param roomId 房间号/频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestChatRoomListUsersWithRoomId:(NSUInteger)roomId
                                completion:(void (^)(NSDictionary *listUsers))completion
                                   failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取聊天室在线成员列表

 @param roomId 房间号/频道号
 @param page 页数，参数 0 等于 1
 @param length 每一页数量，参数 0 等于 100
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestChatRoomListUsersWithRoomId:(NSUInteger)roomId
                                      page:(NSUInteger)page
                                    length:(NSUInteger)length
                                completion:(void (^)(NSDictionary *listUsers))completion
                                   failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark - 连麦相关

/**
 获取连麦状态

 @param roomId 房间号/频道号
 @param completion 请求完成，参数不能为 nil
        status 连麦状态：open(打开)/close(关闭)
        type 连麦类型：video(视频)/audio(音频)
 @param failure 请求失败
 */
+ (void)requestLinkMicStatusWithRoomId:(NSUInteger)roomId
                            completion:(void (^)(NSString *status, NSString *type))completion
                               failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取连麦在线人员列表
 
 @param roomId 房间号/频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestLinkMicOnlineListWithRoomId:(NSUInteger)roomId
                                completion:(void (^)(NSArray *onlineList))completion
                                   failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark - 云课堂相关

/**
 获取PPT的图片数据

 @param autoId PPT的Id
 @param completion 获取成功，参数不能为 nil
 @param failure 获取失败
 */
+ (void)requestPPTResourceInfoWithAutoId:(NSInteger)autoId
                              completion:(void (^)(NSDictionary *responseDict))completion
                                 failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 中途进入或回看PPT时请求接口

 @param roomId 房间/频道号
 @param sessionId 场次 id
 @param completion 获取成功，参数不能为 nil
 @param failure 获取失败
 */
+ (void)requestPPTContentWithRoomId:(NSUInteger)roomId
                          sessionId:(NSString *)sessionId
                         completion:(void (^)(NSArray *contentlist))completion
                            failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark - Deprecated

/**
 获取直播频道信息（旧，0.6.0版本以下）
 
 @param userId 用户Id
 @param channelId 频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)loadChannelInfoWithUserId:(NSString *)userId
                        channelId:(NSUInteger)channelId
                       completion:(void (^)(PLVLiveChannel *channel))completion
                          failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure __deprecated;
/**
 获取直播频道信息（废弃，缓存较短，0.6.0版本以下）
 */
+ (void)loadChannelInfo_BUWithUserId:(NSString *)userId
                           channelId:(NSUInteger)channelId
                          completion:(void (^)(PLVLiveChannel *channel))completion
                             failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure __unavailable;

/**
 SocketIO心跳请求（废弃，SocketIO内部处理）
 
 @param socketId Socket Id
 @param success 请求成功
 @param failure 请求失败
 */
+ (void)socketIOHeartbeatRequestWithSocketId:(NSString *)socketId
                                     success:(void (^)(NSString *content))success
                                     failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure __deprecated;

/// 获取推流信息(废弃，0.3.0版本以下使用)
+ (void)loadStreamerInfoWithChannelId:(NSUInteger)channelId
                             password:(NSString *)password
                           completion:(void(^)(PLVPushChannel *channel))completion
                              failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure __deprecated;

/**
 获取频道咨询提问菜单状态(废弃，0.4.0版本以下使用，新版本使用 getChannelMenuInfos:completion:failure 接口)
 
 @param channelId 频道号
 @param completion 获取成功，参数不能为 nil
 @param failure 获取失败
 */
+ (void)getChannelInfoWithQuestionMenuStatus:(NSUInteger)channelId
                                  completion:(void(^)(BOOL isOn))completion
                                     failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure __deprecated;
@end
