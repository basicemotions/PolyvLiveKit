//
//  PLVLFConsoleLogger.h
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

@interface PLVLFConsoleLogger : NSObject

///打印等级，默认关闭所有打印
@property (nonatomic, assign) PLVConsoleLogLevel logLevel;

+ (instancetype)defaultLogger;

- (void)logWithModule:(NSString * _Nullable)module type:(PLVConsoleLogType)type format:(NSString *)frmt, ...;

@end

#define PLVLFLOG_ERROR( frmt, ...) PLVLFLOG( nil, PLVConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVLFLOG_WARN( frmt, ...) PLVLFLOG( nil, PLVConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVLFLOG_DEBUG( frmt, ...) PLVLFLOG( nil, PLVConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVLFLOG_INFO( frmt, ...) PLVLFLOG( nil, PLVConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVLF_NORMAL_LOG_ERROR( module, frmt, ...) PLVLFLOG( module, PLVConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVLF_NORMAL_LOG_WARN( module, frmt, ...) PLVLFLOG( module, PLVConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVLF_NORMAL_LOG_DEBUG( module, frmt, ...) PLVLFLOG( module, PLVConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVLF_NORMAL_LOG_INFO( module, frmt, ...) PLVLFLOG( module, PLVConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVLFLOG(module, logType, frmt, ...) \
{ \
    [[PLVLFConsoleLogger defaultLogger] logWithModule : module \
                                        type : logType \
                                          format : (frmt), ## __VA_ARGS__]; \
}

NS_ASSUME_NONNULL_END
