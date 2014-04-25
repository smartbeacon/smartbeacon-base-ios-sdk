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

#ifndef __SB_PLATFORM_H__

#define __SB_PLATFORM_H__


@protocol SBPlatformDelegate <NSObject>

@optional

- (void)platformTriggerBeaconWithInformations:(NSDictionary *)infos;
- (void)platformTriggerBeaconWithViewController:(UIViewController *)viewController;

@end


@interface SBPlatform : NSObject


@property (nonatomic, strong) id<SBPlatformDelegate> delegate;

/**
 *  Set YES to use custom calibration (eq. redefining proximity ranges).
 */
@property (nonatomic)		  BOOL					 useCustomCalibration; // default NO

/**
 *  Returns the shared manager object.
 *
 *  @return the shared object.
 */
+ (id)sharedManager;

/**
 *  Sets the Api key associated with the user account.
 *	This value is used to retrieve the data associated to each iBeacon configured from the web interface SmartBeacon.
 *
 *  @param key Api key.
 */
- (void)setApiKey:(NSString *)key;

@end

#endif