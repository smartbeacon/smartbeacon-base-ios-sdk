SmartBeacon Base iOS SDK v2 for iOS 7
====================

Introduction
--------------------

SmartBeacon’s SDK simplifies the use of Apple’s iBeacon technology with SmartBeacon’s hardware. In only few steps, you will be able to communicate with our beacons and send notifications.

Installation
--------------------

Follow steps described below to install SmartBeacon-SDK library:

1. Download SmartBeacon-SDK.framework and copy it into your project directory.

2. Open your Xcode project, go to targets pane, then go to Build Phases tab. In Link Binary With Libraries section, click +. In the popup window click add other at the bottom and select SmartBeacon-SDK.framework file.

  SmartBeacon-SDK requires following native iOS framework: 
  * CoreLocation.framework

3. That's about it ;)


Integration
--------------------

In few steps, you can integrate our SDK, quick and easy.

In the following example, we want to notify the user when he gets out of the range defined by SmartBeacon private proximity UUID. The following code shows implementation in a basic View Controller named DemoViewController.

DemoViewController.h

	#import <UIKit/UIKit.h>

	@interface DemoViewController : UIViewController
	
	@end

DemoViewController.m

	#import "DemoViewController.h"

	// make sure you add frameworks header
	#import <CoreLocation/CoreLocation.h>
	#import <SmartBeacon-SDK/SmartBeacon.h>

	@interface DemoViewController () <SBLocationManagerDelegate>
	@end

	@implementation DemoViewController

	// UIViewController life cycle

	- (void)viewDidLoad
	{
	    [super viewDidLoad];

	    // getting shared instance
	    SBInstanceSingleton *sbInstance = [SBInstanceSingleton sharedInstance];
    
	    // add entire SmartBeacon region
	    // identifier is a value that you specify and can use to identify this region inside your application
	    [sbInstance addEntireBeaconRegionWithIdentifier:SBDefaultRegionIdentifier];
    
	    // start listening beacon region
	    [sbInstance startServicesForTarget:self];
	}

	// SBLocationManagerDelegate
	
	//
	// This method is called when the user enter in the listened region.
	// Called if the user is not already inside the region.
	//
	- (void)beaconManager:(SBLocationManager *)manager didEnterRegion:(CLRegion *)region
	{
	    // Local notifications are visible only if the app is in background (and if the user allowed them).
	    //
	    // That's why, in this case, we open an UIAlertView popup if app is visible and a local notification if is in background.

	    if (UIApplicationStateActive == [[UIApplication sharedApplication] applicationState])
	    {
	        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"SmartBeaconSDK" message:@"Hello, how are you?" delegate:nil cancelButtonTitle:@"Close" otherButtonTitles:nil];
	        [alertView show];
	    }
	    else if (UIApplicationStateBackground == [[UIApplication sharedApplication] applicationState])
	    {
	        UILocalNotification *localNotification = [[UILocalNotification alloc] init];
	        [localNotification setSoundName:UILocalNotificationDefaultSoundName];
	        [localNotification setAlertBody:@"SmartBeaconSDK - Hello, how are you?"];
        
	        [[UIApplication sharedApplication] presentLocalNotificationNow:localNotification];
	    }
	}

	//
	// This method is called when the user exit the listened region.
	// It is not immediate, we can wait over 10 seconds before call.
	// 
	- (void)beaconManager:(SBLocationManager *)manager didExitRegion:(CLRegion *)region
	{
	    // Local notifications are visible only if the app is in background (and if the user allowed them).
	    //
	    // That's why, in this case, we open an UIAlertView popup if app is visible and a local notification if is in background.

	    if (UIApplicationStateActive == [[UIApplication sharedApplication] applicationState])
	    {
	        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"SmartBeaconSDK" message:@"Bye, see you next time !" delegate:nil cancelButtonTitle:@"Close" otherButtonTitles:nil];
	        [alertView show];
	    }
	    else if (UIApplicationStateBackground == [[UIApplication sharedApplication] applicationState])
	    {
	        UILocalNotification *localNotification = [[UILocalNotification alloc] init];
	        [localNotification setSoundName:UILocalNotificationDefaultSoundName];
	        [localNotification setAlertBody:@"SmartBeaconSDK - Bye, see you next time !"];
        
	        [[UIApplication sharedApplication] presentLocalNotificationNow:localNotification];
	    }
	}
	
	// 
	// This method is called when proximity changes for a given beacon.
	// 
	- (void)beaconManager:(SBLocationManager *)manager beacon:(CLBeacon *)beacon didUpdateFromProximity:(CLProximity)fromProximity toProximity:(CLProximity)toProximity
	{
		if (fromProximity > toProximity)
		{
			NSLog(@"I approach the beacon!");
		}
		else 
		{
			NSLog(@"I distant beacon.");
		}
	}
	
	- (void)beaconManager:(SBLocationManager *)manager didDiscoverBeacons:(NSArray *)beacons inRegion:(CLRegion *)region
	{
	    NSLog(@"example app discover %d beacons!", [beacons count]);

	    if ([beacons count])
	    {
	     	CLBeacon *nearestBeacon = [beacons firstObject];
	    	NSLog(@"Nearest beacon ID: %@ / %@ / %@", [nearestBeacon proximityUUID], [nearestBeacon major], [nearestBeacon minor]);
	    }
	}

	// let see SBLocationManagerDelegate protocol for more useful methods

	@end

