//
//  SmartBeacon.h
//  SmartBeacon-SDK
//
//  Created by Ludovic Riviere on 17/01/2014.
//  Copyright (c) 2014 IP Stand. All rights reserved.
//

/**
 *  Version 1.2.1 - What's new
 *	==========================
 *
 *	- More debug logs added
 *	- Comments added
 *
 *
 *	Version 1.2 - What's new
 *	========================
 *
 *	- Calibrator 
 *		Let you to have another proximity (CLProximity) calculate using anoter third-part formula.
 *		Formula is based to iBeacon Rssi, accuracy, thrid-part TxPower (configurable with SmartBeacon Calibrator) and other constants.
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

#import "Calibrator.h"
#import "CalibratorManager.h"

#endif
