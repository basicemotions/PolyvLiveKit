//
//  PLVConsoleLogger.m
//  LFLiveKit
//
//  Created by POLYV-UX on 2021/8/16.
//  Copyright © 2021 admin. All rights reserved.
//

#import "PLVConsoleLogger.h"

@implementation PLVConsoleLogger

#pragma mark - Public

+ (instancetype)defaultLogger {
    static PLVConsoleLogger *logger = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        logger = [[PLVConsoleLogger alloc] init];
    });
    return logger;
}

- (void)logWithModule:(NSString *)module type:(PLVConsoleLogType)type format:(NSString *)frmt, ... {
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

- (NSString *)stringWithLogType:(PLVConsoleLogType)type {
    switch (type) {
        case PLVConsoleLogTypeERROR:
            return @"[ERROR]";
        case PLVConsoleLogTypeWARN:
            return @"[WARN]";
        case PLVConsoleLogTypeDEBUG:
            return @"[DEBUG]";
        case PLVConsoleLogTypeINFO:
            return @"[INFO]";
        default:
            return @"";
    }
}

@end
