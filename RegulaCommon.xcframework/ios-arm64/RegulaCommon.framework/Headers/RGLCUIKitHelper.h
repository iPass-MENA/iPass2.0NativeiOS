//
//  RGLUIKitHelper.h
//  DocumentReader
//
//  Created by Igor on 6.11.25.
//  Copyright © 2025 Regula. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RGLCUIKitHelper : NSObject

+ (void)setDisableScreenshots:(BOOL)disable forLayer:(CALayer *)layer;
+ (UIInterfaceOrientation)currentInterfaceOrientation;

@end

NS_ASSUME_NONNULL_END
