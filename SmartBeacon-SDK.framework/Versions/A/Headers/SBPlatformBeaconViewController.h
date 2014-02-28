//
//  SBPlatformBeaconViewController.h
//  sbplateformframework
//
//  Created by Eddy Claessens on 15/02/2014.
//  Copyright (c) 2014 sb. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SBPlatformBeaconViewController : UIViewController
{
    
    NSDictionary *pageInfos;
    
    UILabel *titleLB;
    
    UIView  *mediaView;
    
    UILabel *descLB;
    
    BOOL    alreadyAppeared;
}

- (id)initWith:(NSDictionary *)infos;

@end
