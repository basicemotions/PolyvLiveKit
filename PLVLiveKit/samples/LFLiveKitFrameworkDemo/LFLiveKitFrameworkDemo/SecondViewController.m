//
//  SecondViewController.m
//  LFLiveKitFrameworkDemo
//
//  Created by admin on 2016/10/20.
//  Copyright © 2016年 admin. All rights reserved.
//

#import "SecondViewController.h"
#import "LFLivePreview.h"
#import <PLVLiveAPI/PLVLiveAPI.h>

@interface SecondViewController ()

@end

@implementation SecondViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    __weak typeof(self)weakSelf = self;
    [PLVLiveAPI loadPushInfoWithChannelId:103117 password:@"" completion:^(PLVPushChannel *channel, NSString *rtmpUrl) {
        LFLivePreview *preview = [LFLivePreview alloc];
        preview.url = rtmpUrl;
        [weakSelf.view addSubview:[preview initWithFrame:weakSelf.view.bounds]];
    } failure:^(PLVLiveErrorCode errorCode, NSString *description) {
        NSLog(@"频道加载失败：%@",description);
    }];
}


- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
    return YES;
}


@end
