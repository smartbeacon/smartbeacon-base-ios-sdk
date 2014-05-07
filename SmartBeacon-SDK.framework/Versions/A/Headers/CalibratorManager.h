//
//  CalibratorManager.h
//  SmartBeaconIOS-Calibrate
//
//  Created by Ludovic Riviere on 01/05/2014.
//  Copyright (c) 2014 SmartBeacon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class Calibrator;

@interface CalibratorManager : NSObject

+ (instancetype)manager;

- (BOOL)hasDatas;

- (void)addBeaconRepresentation:(NSDictionary *)dictionary;

- (void)setValuesForDictionary:(NSDictionary *)dictionary;

- (Calibrator *)calibratorForBeacon:(CLBeacon *)beacon;

@end

@interface CalibratorManager (SBPlatform)

- (void)applyForAllUsingCalibratorConfiguration:(Calibrator *)calibrator;

- (void)clear;

- (NSError *)error;

- (NSDictionary *)exportRepresentation;

@end
