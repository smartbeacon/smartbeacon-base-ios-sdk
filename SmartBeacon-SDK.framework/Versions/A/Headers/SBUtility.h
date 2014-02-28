//
//  SBUtility.h
//  SmartBeacon-SDK
//
//  Created by Ludovic Riviere on 13/01/2014.
//  Copyright (c) 2014 IP Stand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


typedef enum
{
    SBLogTypeInfo,
    SBLogTypeWarning,
    SBLogTypeError
}
SBLogType;


@interface SBUtility : NSObject


/**
*  Generate ID (combinaison of proximity UUIID, major, minor and separator).
*
*  @param beacon Beacon to use.
*
*  @return ID as string.
*/
+ (NSString *)uniqueIDForBeacon:(CLBeacon *)beacon;


/**
 *  Generate ID (combinaison of proximity UUIID, major, minor and separator).
 *
 *  @param beaconRegion Beacon to use.
 *
 *  @return ID as string.
 *
 *  @see uniqueIDForBeacon:
 *
 */
+ (NSString *)uniqueIDForBeaconRegion:(CLBeaconRegion *)beaconRegion;


/**
 *  Explode beacon id and extract minor id.
 *
 *  @param beaconId Beacon ID to explode.
 *
 *  @return minor id as NSNumber.
 *
 */
+ (NSNumber *)minorForBeaconId:(NSString *)beaconId;


/**
 *  NSLog alias
 *
 *  @param type    Type of message, see SBLogType
 *  @param message Text you want display.
 *  @param object  Sender object.
 */
+ (void)log:(SBLogType)type withMessage:(NSString *)message fromObject:(id)object;

@end
