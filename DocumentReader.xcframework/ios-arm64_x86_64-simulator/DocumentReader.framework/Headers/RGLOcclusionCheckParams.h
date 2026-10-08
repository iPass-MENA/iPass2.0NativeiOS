//
//  RGLOcclusionCheckParams.h
//  DocumentReader
//
//  Copyright © 2026 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ImageQA.OcclusionCheckParams)
@interface RGLOcclusionCheckParams : NSObject

/// The maximum size for the occluded area of a document; only those exceeding this size will be validated.
/// Type: Double.
@property (nonatomic, strong, nullable) NSNumber *maxOcclusionPart;

@end

NS_ASSUME_NONNULL_END
