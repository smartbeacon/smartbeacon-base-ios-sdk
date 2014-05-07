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


FOUNDATION_EXPORT NSString *const SBPlatformDataTitleKey;
FOUNDATION_EXPORT NSString *const SBPlatformDataDescriptionKey;
FOUNDATION_EXPORT NSString *const SBPlatformDataMediaTypeKey;
FOUNDATION_EXPORT NSString *const SBPlatformDataMediaContent;


@protocol SBPlatformDelegate <NSObject>

@optional

/**
 *  Called when SDK detects some datas to display or treat from a beacon.
 *
 *  @param infos NSDictionary object (set of datas)
 */
- (void)platformTriggerBeaconWithInformations:(NSDictionary *)infos;


/**
 *  Called when SDK detects some datas to display from a beacon.
 *
 *  @param viewController UIViewController object presenting the data
 */
- (void)platformTriggerBeaconWithViewController:(UIViewController *)viewController;

@end


@interface SBPlatform : NSObject


@property (nonatomic, strong) id<SBPlatformDelegate> delegate;

/**
 *  Set YES to use custom calibration (eq. redefining proximity ranges).
 *
 *	Default NO
 */
@property (nonatomic)		  BOOL useCustomCalibration;

/**
 *  Returns the shared manager object.
 *
 *  @return the shared object
 */
+ (id)sharedManager;

/**
 *  Sets the Api key associated with the user account.
 *	This value is used to retrieve the data associated to each iBeacon configured from the web interface SmartBeacon.
 *
 *  @param key Api key
 */
- (void)setApiKey:(NSString *)key;

@end


/**
 *  Extension of SBPlatform feature
 */
@interface SBPlatform (BeaconExtension)

/**
 *  Returns beacon's name if available.
 *	Based on beacons' datas received from SmartBeacon API server.
 *
 *  @param beacon CLBeacon object
 *
 *  @return beacon's name or nil
 */
- (NSString *)nameForBeacon:(CLBeacon *)beacon;

/**
 *  Returns beacon's description if available.
 *	Based on beacons' datas received from SmartBeacon API server.
 *
 *  @param beacon CLBeacon object
 *
 *  @return beacon's description or nil
 */
- (NSString *)descriptionForBeacon:(CLBeacon *)beacon;

@end

#endif