//
//  PLVLFConsoleLogger.h
//  LFLiveKit
//
//  Created by POLYV-UX on 2021/8/16.
//  Copyright © 2021 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PLVLFConsoleLogType) {
    PLVLFConsoleLogTypeERROR     = 1 << 0,
    PLVLFConsoleLogTypeWARN      = 1 << 1,
    PLVLFConsoleLogTypeDEBUG     = 1 << 2,
    PLVLFConsoleLogTypeINFO      = 1 << 3
};

typedef NS_ENUM(NSUInteger, PLVLFConsoleLogLevel) {
    ///关闭所有打印
    PLVLFConsoleLogLevelOFF      = 0,
    ///只允许打印ERROR级别打印
    PLVLFConsoleLogLevelERROR    = PLVLFConsoleLogTypeERROR,
    ///允许打印ERROR、WARN级别打印
    PLVLFConsoleLogLevelWARN     = PLVLFConsoleLogTypeERROR  | PLVLFConsoleLogTypeWARN,
    ///允许打印INFO、DEBUG级别打印
    PLVLFConsoleLogLevelDEBUG    = PLVLFConsoleLogTypeINFO   | PLVLFConsoleLogTypeDEBUG,
    ///只允许打印INFO级别打印
    PLVLFConsoleLogLevelINFO     = PLVLFConsoleLogTypeINFO,
    ///允许所有级别打印
    PLVLFConsoleLogLevelALL      = 0xF
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVLFConsoleLogger : NSObject

///打印等级，默认关闭所有打印
@property (nonatomic, assign) PLVLFConsoleLogLevel logLevel;

+ (instancetype)defaultLogger;

- (void)logWithModule:(NSString * _Nullable)module type:(PLVLFConsoleLogType)type format:(NSString *)frmt, ...;

@end

#define PLVLFLOG_ERROR( frmt, ...) PLVLFLOG( nil, PLVLFConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVLFLOG_WARN( frmt, ...) PLVLFLOG( nil, PLVLFConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVLFLOG_DEBUG( frmt, ...) PLVLFLOG( nil, PLVLFConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVLFLOG_INFO( frmt, ...) PLVLFLOG( nil, PLVLFConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVLF_NORMAL_LOG_ERROR( module, frmt, ...) PLVLFLOG( module, PLVLFConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVLF_NORMAL_LOG_WARN( module, frmt, ...) PLVLFLOG( module, PLVLFConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVLF_NORMAL_LOG_DEBUG( module, frmt, ...) PLVLFLOG( module, PLVLFConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVLF_NORMAL_LOG_INFO( module, frmt, ...) PLVLFLOG( module, PLVLFConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVLFLOG(module, logType, frmt, ...) \
{ \
    [[PLVLFConsoleLogger defaultLogger] logWithModule : module \
                                        type : logType \
                                          format : (frmt), ## __VA_ARGS__]; \
}

NS_ASSUME_NONNULL_END
