//
//  PLVConsoleLogger.h
//  LFLiveKit
//
//  Created by POLYV-UX on 2021/8/16.
//  Copyright © 2021 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PLVConsoleLogType) {
    PLVConsoleLogTypeERROR     = 1 << 0,
    PLVConsoleLogTypeWARN      = 1 << 1,
    PLVConsoleLogTypeDEBUG     = 1 << 2,
    PLVConsoleLogTypeINFO      = 1 << 3
};

typedef NS_ENUM(NSUInteger, PLVConsoleLogLevel) {
    ///关闭所有打印
    PLVConsoleLogLevelOFF      = 0,
    ///只允许打印ERROR级别打印
    PLVConsoleLogLevelERROR    = PLVConsoleLogTypeERROR,
    ///允许打印ERROR、WARN级别打印
    PLVConsoleLogLevelWARN     = PLVConsoleLogTypeERROR  | PLVConsoleLogTypeWARN,
    ///允许打印INFO、DEBUG级别打印
    PLVConsoleLogLevelDEBUG    = PLVConsoleLogTypeINFO   | PLVConsoleLogTypeDEBUG,
    ///只允许打印INFO级别打印
    PLVConsoleLogLevelINFO     = PLVConsoleLogTypeINFO,
    ///允许所有级别打印
    PLVConsoleLogLevelALL      = 0xF
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVConsoleLogger : NSObject

///打印等级，默认关闭所有打印
@property (nonatomic, assign) PLVConsoleLogLevel logLevel;

+ (instancetype)defaultLogger;

- (void)logWithModule:(NSString * _Nullable)module type:(PLVConsoleLogType)type format:(NSString *)frmt, ...;

@end

#define PLVLOG_ERROR( frmt, ...) PLVLOG( nil, PLVConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVLOG_WARN( frmt, ...) PLVLOG( nil, PLVConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVLOG_DEBUG( frmt, ...) PLVLOG( nil, PLVConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVLOG_INFO( frmt, ...) PLVLOG( nil, PLVConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLV_NORMAL_LOG_ERROR( module, frmt, ...) PLVLOG( module, PLVConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLV_NORMAL_LOG_WARN( module, frmt, ...) PLVLOG( module, PLVConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLV_NORMAL_LOG_DEBUG( module, frmt, ...) PLVLOG( module, PLVConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLV_NORMAL_LOG_INFO( module, frmt, ...) PLVLOG( module, PLVConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVLOG(module, logType, frmt, ...) \
{ \
    [[PLVConsoleLogger defaultLogger] logWithModule : module \
                                        type : logType \
                                          format : (frmt), ## __VA_ARGS__]; \
}

NS_ASSUME_NONNULL_END
