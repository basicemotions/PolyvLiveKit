//
//  PLVLiveChannel.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 频道限制信息
typedef NS_ENUM(NSInteger, PLVLiveRestrictState) {
    /// 未知（获取失败）
    PLVLiveRestrictUnknown = -1,
    /// 无限制（可正常播放）
    PLVLiveRestrictNone    = 0,
    /// 有限制（不可播放）
    PLVLiveRestrictPlay    = 1,
};

/// 暖场类型
typedef NS_ENUM(NSUInteger, PLVLiveCoverType) {
    /// 无暖场
    PLVLiveCoverTypeNone  = 0,
    /// 图片类型
    PLVLiveCoverTypeImage = 1,
    /// 视频类型
    PLVLiveCoverTypeVideo = 2,
};

/**
 直播观看频道信息
 */
@interface PLVLiveChannel : NSObject

/// 直播频道 Id
@property (nonatomic, copy, readonly) NSNumber *channelId;
/// 直播用户 Id
@property (nonatomic, copy, readonly) NSString *userId;
/// 直播场次
@property (nonatomic, copy, readonly) NSString *sessionId;
/// 直播频道名称
@property (nonatomic, copy, readonly) NSString *name;
/// 直播流名
@property (nonatomic, copy, readonly) NSString *stream;

/// 直播默认FLV拉流地址
@property (nonatomic, copy, readonly) NSString *flvUrl;
/// 直播默认备用FLV拉流地址 (Maybe nil)
@property (nonatomic, copy, readonly) NSString *bakFlvUrl;
/// 直播默认M3U8拉流地址
@property (nonatomic, copy, readonly) NSString *m3u8Url;

/// 多码率是否开启
@property (nonatomic, readonly) BOOL isMultirateEnabled;
/// 默认清晰度，多码率开启时使用
@property (nonatomic, copy, readonly) NSString *defaultDefinition;
/// 默认清晰度地址，多码率开启时使用
@property (nonatomic, copy, readonly) NSString *defaultDefinitionUrl;
/// 所有清晰度，多码率开启时使用
@property (nonatomic, copy, readonly) NSArray<NSDictionary *> *definitions;

/// 直播线路地址数组
@property (nonatomic, copy, readonly) NSArray<NSDictionary *> *lines;

/// 直播限制状态
@property (nonatomic, readonly) PLVLiveRestrictState restrictState;
/// 限制信息：restrictState Unknown 时为 nil
@property (nonatomic, copy, readonly) NSDictionary *restrictInfo;

/// 暖场类型
@property (nonatomic, readonly) PLVLiveCoverType coverType;
/// 暖场资源地址
@property (nonatomic, copy, readonly) NSString *coverUrl;
/// 图片类型暖场的跳转链接(可能为nil)
@property (nonatomic, copy, readonly) NSString *coverHref;

/// Qos 发送频率
@property (nonatomic, copy, readonly) NSNumber *reportFreq;

/**
 便利初始化方法
 */
+ (instancetype)liveChannelWithJsonDict:(NSDictionary *)jsonDict;

/**
 更新频道限制信息
    更新当前对象数据，异步返回 channel和当前调用对象为同一实例
 @param completion 请求完成
 */
- (void)updateChannelRestrictInfo:(void (^)(PLVLiveChannel *channel))completion;

/**
 更新默认清晰度

 @param definition 清晰度
 */
- (void)updateDefaultDefinitionWithDefinition:(NSString *)definition;

@end
