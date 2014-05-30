//
//  SBInstanceSingleton.h
//  SmartBeacon-SDK
//
//  Created by Ludovic Riviere on 13/01/2014.
//  Copyright (c) 2014 IP Stand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "SBLocationManager.h"

/**
 * Three region identifiers created for fast coding.
 *
 * Use it as you want!
 */
static NSString *SBRegionID_A	= @"eu.smartbeacon.region.id.A";
static NSString *SBRegionID_B	= @"eu.smartbeacon.region.id.B";
static NSString *SBRegionID_C	= @"eu.smartbeacon.region.id.A";

__deprecated static  NSString *SBDefaultRegionIdentifier         = @"fr.ipstand.libraries.smartbeacon.region.identifier.one";
__deprecated static  NSString *SBDefaultTwoRegionIdentifier      = @"fr.ipstand.libraries.smartbeacon.region.identifier.two";
__deprecated static  NSString *SBDefaultThreeRegionIdentifier    = @"fr.ipstand.libraries.smartbeacon.region.identifier.three";


@interface SBInstanceSingleton : NSObject <SBLocationManagerDelegate>


/**
 * Default NO.
 * 
 * Set YES if you would be aware for any warning.
 *
 */
@property (nonatomic, getter = debugModeEnabled)    BOOL    enableDebugMode;

@property (nonatomic)   BOOL    isListening;



/**
 * Getting the App Instance
 *
 * @return The shared instance.
 */
+ (SBInstanceSingleton *)sharedInstance;


/**
 * Add a beacon region with specific proximity UUID and identifier.
 *
 * @param proximityUUID A proximity UUID.
 * @param identifier An unique identifier for beacon region.
 *
 * @return YES if beacon region is correctly added.
 *
 * @warning *Warning:* You can't have many beacon regions for an identifier. You must have an unique identifier per beacon region created.
 */
- (BOOL)addBeaconRegionUsingProximityUUID:(NSUUID *)proxmityUUID withIdentifier:(NSString *)identifier;


/**
 * Add a beacon region with specific proximity UUID, major and identifier.
 *
 * @param proximityUUID A proximity UUID.
 * @param major A major id.
 * @param identifier An unique identifier for beacon region.
 *
 * @return YES if beacon region is correctly added.
 *
 * @warning *Warning:* You can't have many beacon regions for an identifier. You must have an unique identifier per beacon region created.
 */
- (BOOL)addBeaconRegionUsingProximityUUID:(NSUUID *)proxmityUUID withMajor:(CLBeaconMajorValue)major withIdentifier:(NSString *)identifier;


/**
 * Add a beacon region with specific proximity UUID, major, minor and identifier.
 *
 * @param proximityUUID A proximity UUID.
 * @param major A major id.
 * @param minor A minor id.
 * @param identifier An unique identifier for beacon region.
 *
 * @return YES if beacon region is correctly added.
 *
 * @warning *Warning:* You can't have many beacon regions for an identifier. You must have an unique identifier per beacon region created.
 */
- (BOOL)addBeaconRegionUsingProximityUUID:(NSUUID *)proxmityUUID withMajor:(CLBeaconMajorValue)major withMinor:(CLBeaconMinorValue)minor withIdentifier:(NSString *)identifier;


/**
 * Add whole SmartBeacon region with identifier.
 *
 * @param identifier An unique identifier for beacon region.
 *
 * @return YES if beacon is correctly added.
 *
 * @warning *Warning:* It is not necessary to use other addBeaconRegion... methods.
 */
- (BOOL)addEntireBeaconRegionWithIdentifier:(NSString *)identifier;


/**
 * Add a SmartBeacon region with specific major and identifier.
 *
 * @param major A major id.
 * @param identifier An unique identifier for beacon region.
 *
 * @return YES if beacon region is correctly added.
 *
 * @warning *Warning:* You can't have many beacon regions for an identifier. You must have an unique identifier per beacon region created.
 */
- (BOOL)addBeaconRegionWithMajor:(CLBeaconMajorValue)major withIdentifier:(NSString *)identifier;


/**
 * Add a SmartBeacon region with specific major, minor and identifier.
 *
 * @param major A major id.
 * @param minor A minor id.
 * @param identifier An unique identifier for beacon region.
 *
 * @return YES if beacon region is correctly added.
 *
 * @warning *Warning:* You can't have many beacon regions for an identifier. You must have an unique identifier per beacon region created.
 */
- (BOOL)addBeaconRegionWithMajor:(CLBeaconMajorValue)major withMinor:(CLBeaconMinorValue)minor withIdentifier:(NSString *)identifier;


/**
 * Start monitoring and ranging for all beacon regions added.
 *
 * @param target A class which will receive beacon events. All events declared in SBLocationManagerDelegate
 *
 * @warning *Warning:* Monitoring and ranging will be called asynchronously. Ranging beacon region will be called after monitoring service.
 */
- (void)startServicesForTarget:(id<SBLocationManagerDelegate>)target;


/**
 * Stop monitoring and ranging for all beacon regions added.
 *
 * @param target A class which will stop beacon events. All events declared in SBLocationManagerDelegate
 */
- (void)stopServicesForTarget:(id<SBLocationManagerDelegate>)target;


/**
 * Ask if target is in delegates stack. This method doesn't check if target implements any SBLocationManagerDelegate methods.
 *
 * @param target A class
 *
 * @return YES if target is in delegate stack
 */
- (BOOL)isListeningTarget:(id<SBLocationManagerDelegate>)target;


/**
 *  Returns ranged beacons.
 *
 *  @return array of ranged beacons
 */
- (NSArray *)rangedBeacons;


@end

