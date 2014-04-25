//
//  SBLocationManagerDelegate.h
//  SmartBeacon-SDK
//
//  Created by Ludovic Riviere on 21/02/2014.
//  Copyright (c) 2014 IP Stand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class SBLocationManager;


/**
 *  Delegate for SBLocationManager
 */
@protocol SBLocationManagerDelegate <NSObject>


@optional

/**
 *  Invoked when a monitoring for a region started successfully.
 *
 *  @param manager The location manager object reporting the event.
 *  @param region  An object containing information about the region that was entered.
 */
- (void)beaconManager:(SBLocationManager *)manager didStartMonitoringForRegion:(CLRegion *)region;


/**
 *  Invoked when a region monitoring error has occured. Error types are defined in "CLError.h".
 *
 *  @param manager The location manager object reporting the event.
 *  @param region  An object containing information about the region that was entered.
 *  @param error   The error object containing the reason the location could not be monitored.
 */
- (void)beaconManager:(SBLocationManager *)manager monitoringDidFailForRegion:(CLRegion *)region withError:(NSError *)error;


/**
 *  Invoked when the user enters a monitored region. This callback will be invoked for every allocated.
 *  Manager will also start ranging beacon for this specific region.
 *
 *  @param manager The location manager object reporting the event.
 *  @param region  An object containing information about the region that was entered.
 */
- (void)beaconManager:(SBLocationManager *)manager didEnterRegion:(CLRegion *)region;


/**
 *  Invoked when the user enters in a new set of beacons.
 *
 *  @param manager The location manager object reporting the event.
 *  @param beacons Beacons array which are newly received
 */
- (void)beaconManager:(SBLocationManager *)manager didEnterBeacons:(NSArray *)beacons;


/**
 *  Invoked when the user exits a monitored region. This callback will be invoked for every allocated.
 *  Manager will also stop ranging beacon for this specific region.
 *
 *  @param manager The location manager object reporting the event.
 *  @param region  An object containing information about the region that was entered.
 */
- (void)beaconManager:(SBLocationManager *)manager didExitRegion:(CLRegion *)region;


/**
 *  Invoked when a set of listened beacons are no longer received.
 *
 *  @param manager The location manager object reporting the event.
 *  @param beacons Beacons array which are no longer received
 */
- (void)beaconManager:(SBLocationManager *)manager didExitBeacons:(NSArray *)beacons;


/**
 *  Invoked when there's a state transition for a monitored region or in response to a request
 *  for state via a call to requestStateForAllBeaconRegions.
 *
 *  @param manager The location manager object reporting the event.
 *  @param state   CLRegionState value. Tells if we are inside or outside region
 *  @param region  An object containing information about the region that was entered.
 */
- (void)beaconManager:(SBLocationManager *)manager didDeterminateState:(CLRegionState)state forRegion:(CLRegion *)region;


/**
 *  Invoked when a new set of beacons are available in the specified region.
 *  beacons is an array of CLBeacon objects.
 *  If beacons is empty, it may be assumed no beacons that match the specified region are nearby.
 *  Similarly if a specific beacon no longer appears in beacons, it may be assumed the beacon is no longer received
 *  by the device.
 *
 *  @param manager The location manager object reporting the event.
 *  @param beacons Array of beacons in range. Beacons are ordered: the nearest first,
 latest is the farest.
 *  @param region  An object containing information about the region that was entered.
 */
- (void)beaconManager:(SBLocationManager *)manager didDiscoverBeacons:(NSArray *)beacons inRegion:(CLRegion *)region;


/**
 *  Invoked when a beacon change his proximity value.
 *  This method use SBProximityFilter to stabilize proximity signal, so this invocation can take time (few seconds) before being called.
 *
 *  @param manager       The location manager object reporting the event.
 *  @param beacon        CLBeacon instance
 *  @param fromProximity Old CLProximity value of beacon
 *  @param toProximity   New CLProximity value of beacon
 */
- (void)beaconManager:(SBLocationManager *)manager beacon:(CLBeacon *)beacon didUpdateFromProximity:(CLProximity)fromProximity toProximity:(CLProximity)toProximity;


@end