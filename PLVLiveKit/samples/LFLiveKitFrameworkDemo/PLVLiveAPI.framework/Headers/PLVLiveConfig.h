//
//  PLVLiveConfig.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 日志等级
typedef NS_ENUM(NSUInteger, PLVLiveLogLevel) {
    /// 无 LOG 输出
    k_PLV_LIVE_LOG_NULL         = 0,
    /// ERROR 等级
    k_PLV_LIVE_LOG_ERROR        = 1,
    /// INFO 等级
    k_PLV_LIVE_LOG_INFO         = 2,
    /// DEBUG 等级
    k_PLV_LIVE_LOG_DEBUG        = 3,
};

/**
 直播 SDK 配置文件
 */
@interface PLVLiveConfig : NSObject

/// polyv 云直播账号ID
@property (nonatomic, strong, readonly) NSString *userId;
/// polyv 云直播应用ID
@property (nonatomic, strong, readonly) NSString *appId;
/// polyv 云直播应用密匙
@property (nonatomic, strong, readonly) NSString *appSecret;

/// 当前房间号/频道号
@property (nonatomic, strong) NSString *channelId;

/// 统计后台用户Id
@property (nonatomic, strong) NSString *param1;
/// 统计后台观众昵称
@property (nonatomic, strong) NSString *param2;
/// 统计后台自定义参数4
@property (nonatomic, strong) NSString *param4;
/// 统计后台自定义参数5
@property (nonatomic, strong) NSString *param5;

/// 播放器id
@property (nonatomic, strong, readonly) NSString *playerId;

/**
 LiveAPI 版本信息
 */
+ (NSString *)liveApiVersion;

/**
 播放器版本，调用+setPlayerVersion:方法后生成，否则返回 LiveAPI 版本
 */
+ (NSString *)playerVersion;

/**
 LIVE SDK CONFIG 单例类
 @discussion 调用此类属性和对象方法都需要通过此类方法获取到单例对象
 */
+ (instancetype)sharedInstance;

/**
 用户参数：Polyv 后台，云直播->开发设置->身份认证：AppID、AppSecret参数
 */
+ (instancetype)liveConfigWithAppId:(NSString *)appId appSecret:(NSString *)appSecret;

/**
 用户参数：Polyv 后台，云直播->开发设置->身份认证：userId、AppID、AppSecret参数
 */
+ (instancetype)liveConfigWithUserId:(NSString *)userId appId:(NSString *)appId appSecret:(NSString *)appSecret;

/**
 设置统计后台参数，便利生成该类的param1、param2、param4、param5属性
 
 @param param1 统计后台用户Id
 @param param2 统计后台观众昵称
 @param param4 统计后台自定义参数4
 @param param5 统计后台自定义参数5
 */
+ (void)setViewLogParam:(NSString *)param1 param2:(NSString *)param2 param4:(NSString *)param4 param5:(NSString *)param5;


#pragma mark - SDK 日志等级设置

/**
 设置Polyv Live SDK LOG等级
 
 @param logLevel 默认 k_PLV_LIVE_LOG_INFO
 */
+ (void)setLogLevel:(PLVLiveLogLevel)logLevel;

/**
 SDK 日志等级
 */
+ (PLVLiveLogLevel)logLevel;

#pragma mark - Private methods(以下方法不建议用户调用)

/**
 重置播放器 Id
 */
- (void)resetPlayerId;

/**
 设置播放器版本信息
 */
+ (void)setPlayerVersion:(NSString *)playerVersion;

@end
