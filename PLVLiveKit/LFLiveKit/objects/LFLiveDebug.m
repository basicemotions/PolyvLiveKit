//
//  LFLiveDebug.m
//  LaiFeng
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import "LFLiveDebug.h"

@implementation LFLiveDebug

- (NSString *)description {
    return [NSString stringWithFormat:@"丢掉的帧数:%ld 总帧数:%ld 上次的音频捕获个数:%d 上次的视频捕获个数:%d 未发送个数:%ld 总流量:%0.f",_dropFrame,_totalFrame,_currentCapturedAudioCount,_currentCapturedVideoCount,_unSendCount,_dataFlow];
}

/*
- (NSString *)description{
    NSString *desc = [NSString stringWithFormat:@"\nstreamId = %@, uploadUrl = %@, videoSize = %@, isRtmp = %@;\n\
                      elapsedMilli = %.02f, timeStamp = %.02f, dataFlow = %.02f, bandwidth = %.02f, currentBandwidth = %.02f;\n\
                      dropFrame = %ld, totalFrame = %ld;\n\
                      capturedAudioCount = %ld, capturedVideoCount = %ld, currentCapturedAudioCount = %ld, currentCapturedVideoCount = %ld;\n\
                      unSendCount = %ld\n",
                      _streamId, _uploadUrl, NSStringFromCGSize(_videoSize), @(_isRtmp),
                      _elapsedMilli, _timeStamp, _dataFlow, _bandwidth, _currentBandwidth,
                      _dropFrame, _totalFrame,
                      _capturedAudioCount, _capturedVideoCount, _currentCapturedAudioCount, _currentCapturedVideoCount,
                      _unSendCount];
    return desc;
}*/

@end
