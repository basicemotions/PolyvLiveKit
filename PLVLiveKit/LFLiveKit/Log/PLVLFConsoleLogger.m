//
//  PLVLFConsoleLogger.m
//  LFLiveKit
//
//  Created by POLYV-UX on 2021/8/16.
//  Copyright © 2021 admin. All rights reserved.
//

#import "PLVLFConsoleLogger.h"

@implementation PLVLFConsoleLogger

#pragma mark - Public

+ (instancetype)defaultLogger {
    static PLVLFConsoleLogger *logger = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        logger = [[PLVLFConsoleLogger alloc] init];
    });
    return logger;
}

- (void)logWithModule:(NSString *)module type:(PLVLFConsoleLogType)type format:(NSString *)frmt, ... {
    if (!(type & self.logLevel)) {
        return;
    }
    
    if (!frmt) {
        frmt = @"";
        return;
    }
    
    va_list args;
    va_start(args, frmt);
    NSString *message = [[NSString alloc] initWithFormat:frmt arguments:args];
    va_end(args);
    
    NSLog(@"%@%@%@", (module ? [NSString stringWithFormat:@"[%@]", module] : @""), [self stringWithLogType:type], message);
}

#pragma mark - Private

- (NSString *)stringWithLogType:(PLVLFConsoleLogType)type {
    switch (type) {
        case PLVLFConsoleLogTypeERROR:
            return @"[PLVLF_ERROR]";
        case PLVLFConsoleLogTypeWARN:
            return @"[PLVLF_WARN]";
        case PLVLFConsoleLogTypeDEBUG:
            return @"[PLVLF_DEBUG]";
        case PLVLFConsoleLogTypeINFO:
            return @"[PLVLF_INFO]";
        default:
            return @"";
    }
}

@end
