//
//  SBPlatform.h
//  SmartBeacon-SDK
//
//  Created by Ludovic Riviere on 24/02/2014.
//  Copyright (c) 2014 IP Stand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
#import <SmartBeacon-SDK/SmartBeacon.h>


@protocol SBPlatformDelegate <NSObject>

@optional

- (void)platformTriggerBeaconWithInformations:(NSDictionary *)infos;
- (void)platformTriggerBeaconWithViewController:(UIViewController *)viewController;

@end


@interface SBPlatform : NSObject

@property (nonatomic, strong) id<SBPlatformDelegate> delegate;


+ (id)sharedManager;

- (void)setApiKey:(NSString *)key;

@end
