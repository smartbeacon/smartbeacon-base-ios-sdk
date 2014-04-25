//
//  Calibrator.h
//  SmartBeaconIOS-Calibrate
//
//  Created by Ludovic Riviere on 18/04/2014.
//  Copyright (c) 2014 SmartBeacon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#ifndef	__CALIBRATOR_H__

#define	__CALIBRATOR_H__


@interface Calibrator : NSObject

@property (nonatomic)			int		baseTxPower; // by default -68 (the txPower of SmartBeacon's beacons), you must change it if you are using other beacons

@property (nonatomic, readonly) float	minDistance;

@property (nonatomic)			float	immediateLimit;
@property (nonatomic)			float	nearLimit;
@property (nonatomic)			float	farLimit;
//@property (nonatomic)			float	outLimit;


+ (instancetype)defaultCalibrator;

- (BOOL)hasValues;
- (CLProximity)customProximityForAccuracy:(float)value;
- (CLProximity)proximityForCustomAccuracyForBeacon:(CLBeacon *)beacon;

- (void)importConfiguration;
- (void)importConfigurationFromUserDefaults;

- (void)exportConfiguration;
- (NSString *)exportConfigurationAsString;
- (void)saveConfigurationIntoUserDefaults;

- (void)cleanConfiguration;

@end

@interface Calibrator (SBPlatform)

- (void)setValuesWithDictionary:(NSDictionary *)dictionary;

@end

@interface Calibrator (CLBeacon)

- (float)accuracyFromBeacon:(CLBeacon *)beacon;

@end

#endif

