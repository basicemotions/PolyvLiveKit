//
//  PLVLiveReporter.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PLVLiveChannel;
/**
 直播服务质量统计
 */
@interface PLVLiveReporter : NSObject

#pragma mark - Qos

/**
 首次加载时长
 */
+ (void)reportLoading:(NSString*)pid uid:(NSString*)uid channelId:(NSString*)channelId time:(int)time session_id:(NSString *)session_id param1:(NSString*)param1 param2:(NSString*)param2 param3:(NSString*)param3 param4:(NSString*)param4 param5:(NSString*)param5;

/**
 首次加载时长（接口二）
 @discussion 使用频道号的便利方法，同上接口

 @param channel 直播频道对象
 @param pid 播放器Id，每次播放产生的唯一Id
 @param time 首次加载时长
 */
+ (void)reportLoadingWithChannel:(PLVLiveChannel *)channel pid:(NSString*)pid time:(int)time;

/**
 二次缓冲时长
 */
+ (void)reportBuffer:(NSString*)pid uid:(NSString*)uid channelId:(NSString*)channelId time:(int)time session_id:(NSString *)session_id param1:(NSString*)param1 param2:(NSString*)param2 param3:(NSString*)param3 param4:(NSString*)param4 param5:(NSString*)param5;

/**
 二次缓冲时长（接口二）
 @discussion 使用频道号的便利方法，同上接口

 @param channel 直播频道对象
 @param pid 播放器Id，每次播放产生的唯一Id
 @param time 二次缓冲时长
 */
+ (void)reportBufferWithChannel:(PLVLiveChannel *)channel pid:(NSString*)pid time:(int)time;

/**
 播放出错
 */
+ (void)reportError:(NSString *)pid uid:(NSString *)uid channelId:(NSString *)channelId session_id:(NSString *)session_id param1:(NSString *)param1 param2:(NSString *)param2 param3:(NSString *)param3 param4:(NSString *)param4 param5:(NSString *)param5 uri:(NSString *)uri status:(NSString *)status errorcode:(NSString *)errorcode errormsg:(NSString *)errormsg;

/**
 播放出错（接口二）
 @discussion 使用频道号的便利方法，同上接口

 @param channel 直播频道对象
 @param pid 播放器Id，每次播放产生的唯一Id
 @param uri 请求资源的URI
 @param status 服务器响应的状态码
 @param errorcode 错误代码
 @param errormsg 错误内容描述
 */
+ (void)reportErrorWithChannel:(PLVLiveChannel *)channel pid:(NSString *)pid uri:(NSString *)uri status:(NSString *)status errorcode:(NSString *)errorcode errormsg:(NSString *)errormsg;

#pragma mark - View log

/**
 播放信息统计（v2）

 @param pid 播放器Id，每次播放产生的唯一Id
 @param uid 用户Id
 @param cid 频道Id
 @param flow 本次播放累积加载流量大小，单位：bytes
 @param pd 视频播放时长，观众真实观看的累计时长(不能为0)，单位：秒
 @param sd 停留时长，播放器加载完成后开始计算，单位：秒
 @param session_id 播放场次Id
 @param param3 自定义参数3，统计后台直播/回放（值为live/vod）
 */
+ (void)playStatus:(NSString*)pid uid:(NSString*)uid cid:(NSUInteger)cid flow:(long)flow pd:(int)pd sd:(int)sd session_id:(NSString *)session_id param3:(NSString*)param3;

/**
 播放信息统计（v2）（接口二）
 @discussion 使用频道号的便利方法，同上接口

 @param channel 直播频道对象
 @param pid 播放器Id，每次播放产生的唯一Id
 @param flow 本次播放累积加载流量大小，单位：bytes
 @param pd 视频播放时长，观众真实观看的累计时长(不能为0)，单位：秒
 @param sd 停留时长，播放器加载完成后开始计算，单位：秒
 @param param3 自定义参数3，统计后台直播/回放（值为live/vod）
 */
+ (void)playStatusWithChannel:(PLVLiveChannel *)channel pid:(NSString*)pid flow:(long)flow pd:(int)pd sd:(int)sd param3:(NSString*)param3;

#pragma mark - Deprecated

/**
 播放信息统计（v1废弃）
 */
+ (void)stat:(NSString*)pid uid:(NSString*)uid cid:(NSString*)cid flow:(long)flow pd:(int)pd sd:(int)sd cts:(NSTimeInterval)cts duration:(int)duration __deprecated;

@end
