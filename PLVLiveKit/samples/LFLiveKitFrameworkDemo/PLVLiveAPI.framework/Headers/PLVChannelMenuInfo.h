//
//  PLVChannelMenuInfo.h
//  PLVLiveSDK
//
//  Created by zykhbl(zhangyukun@polyv.net) on 2018/7/19.
//  Copyright © 2018年 polyv.net. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLVChannelMenu : NSObject

/// 菜单Id
@property (nonatomic, copy, readonly) NSString *menuId;
/// 菜单类型
@property (nonatomic, copy, readonly) NSString *menuType;
/// 菜单名称
@property (nonatomic, copy, readonly) NSString *name;
/// 菜单内容，html文本，有可能为NSNull
@property (nonatomic, copy, readonly) NSString *content;
/// 菜单显示顺序
@property (nonatomic, copy, readonly) NSNumber *ordered;

@end



@interface PLVChannelMenuInfo : NSObject

/// 直播标题
@property (nonatomic, copy, readonly) NSString *name;
/// 主持人头像
@property (nonatomic, copy, readonly) NSString *coverImage;
/// 主持人
@property (nonatomic, copy, readonly) NSString *publisher;
/// 点赞数
@property (nonatomic, copy, readonly) NSNumber *likes;
/// 观看数
@property (nonatomic, copy, readonly) NSNumber *pageView;
/// 直播时间
@property (nonatomic, copy, readonly) NSString *startTime;
/// 直播状态
@property (nonatomic, copy, readonly) NSString *status;
///频道菜单列表
@property (nonatomic, strong, readonly) NSArray<PLVChannelMenu*> *channelMenus;

/**
 便利初始化方法
 */
+ (instancetype)channelMenuInfoWithJsonDict:(NSDictionary *)jsonDict;

@end
