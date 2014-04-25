//
//  SmartBeacon.h
//  SmartBeacon-SDK
//
//  Created by Ludovic Riviere on 17/01/2014.
//  Copyright (c) 2014 IP Stand. All rights reserved.
//

/**
 *
 *	Version 1.2 - What's new
 *	========================
 *
 *	- Calibrator 
 *		Let you to have another proximity (CLProximity) calculate using anoter third-part formula.
 *
 *	- CLBeacon+Extension
 *		Get custom accuracy.
 *		Formula is based to iBeacon Rssi, accuracy, thrid-part TxPower (configurable with SmartBeacon Calibrator) and other constants.
 *
 *	- UIDevice+Hardware
 *		Get iDevice type name (aka. iPhone 4S, iPhone 5, iPhone 5S, ...)
 *
 */

#ifndef SmartBeacon_SDK_SmartBeacon_h
#define SmartBeacon_SDK_SmartBeacon_h

#import "SBInstanceSingleton.h"

#import "SBLocationManager.h"
#import "SBLocationManagerDelegate.h"

#import "SBPlatform.h"

#import "SBProximityFilter.h"
#import "SBUtility.h"

#import "UIDevice+Hardware.h"

#import "Calibrator.h"

#endif
