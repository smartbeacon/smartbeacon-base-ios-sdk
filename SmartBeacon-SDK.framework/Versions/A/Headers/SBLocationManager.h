//
//  SBLocationManager.h
//  SmartBeacon-SDK
//
//  Created by Ludovic Riviere on 13/01/2014.
//  Copyright (c) 2014 IP Stand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "SBLocationManagerDelegate.h"

#ifndef __SBLOCATION_MANAGER_H__

#define __SBLOCATION_MANAGER_H__

/*
 *  SBLocationManager
 *
 *  Discussion:
 *    The SBLocationManager object is your entry point to the location service.
 *
 *  @warning *Warning:* You cannot use this class manually. Please use SBInstanceSingleton to communicate
 *     with SBLocationManager object.
 *
 */
@interface SBLocationManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic)           BOOL    enableDebugMode;
@property (nonatomic)           BOOL    avoidUnknownStateBeacons;

@property (nonatomic, weak)     id <SBLocationManagerDelegate> delegate;


/**
 *  addBeaconRegion:
 *
 *  @param beaconReagion A beacon region.
 *
 *  @return YES if beaconRegion has been correctly added in regions pool.
 *
 *  @warning *Warning:* You cannot have multiple region with same identifier.
 *
 */
- (BOOL)addBeaconRegion:(CLBeaconRegion *)beaconReagion;


/**
 *  removeBeaconRegion:
 *
 *  @param beaconReagion A beacon region.
 *
 *  @return YES if beaconRegion has been correctly removed in regions pool.
 *
 */
- (BOOL)removeBeaconRegion:(CLBeaconRegion *)beaconRegion;

/**
 *  startMonitoringAllBeaconRegions
 *
 *  Discussion:
 *      Start (if not) monitoring for all registered beacon regions in pool.
 *      When a beacon region did monitored successfully, it start ranging for this specific region.
 *
 */
- (void)startMonitoringAllBeaconRegions;


/**
 *  stopMonitoringAllBeaconRegions
 *
 *  Discussion:
 *      Stop (if running) monitoring for all registered beacon regions in pool.
 *
 */
- (void)stopMonitoringAllBeaconRegions;


/**
 *  requestStateForAllBeaconRegions
 *
 *  Discussion:
 *      Asynchronously retrieve the cached state of all regions.
 *      The state is returned to the delegate via beaconManager:didDetermineState:forRegion:.
 *
 */
- (void)requestStateForAllBeaconRegions;


/**
 *  nearestBeaconFromArray:
 *
 *  @return Nearest beacon in beacons avoiding unknown state of SBLocationManager current instance.
 */
- (id)nearestBeaconFromArray:(NSArray *)beacons;


/**
 *  nearestBeaconFromArray:ignoringUnknownState:
 *
 *  @return Nearest beacon in beacons using ignoreUnknwonState
 */
+ (id)nearestBeaconFromArray:(NSArray *)beacons ignoringUnknownState:(BOOL)ignoreUnknwonState;


@end

#endif
