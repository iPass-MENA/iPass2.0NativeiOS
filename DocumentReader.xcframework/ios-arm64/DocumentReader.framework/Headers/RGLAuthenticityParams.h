//
//  RGLAuthenticityParams.h
//  DocumentReader
//
//  Created by Serge Rylko on 31.01.24.
//  Copyright © 2024 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DocumentReader/RGLMacros.h>

NS_ASSUME_NONNULL_BEGIN

@class RGLLivenessParams;
@class RGLAuthenticityPropertiesParams;

NS_SWIFT_NAME(AuthenticityParams)
@interface RGLAuthenticityParams : NSObject

/// This parameter is used to enable document liveness check.
/// Type: Bool.
@property(nullable, nonatomic, strong) NSNumber *useLivenessCheck;
@property(nullable, nonatomic, strong) RGLLivenessParams *livenessParams;
/// Set to true to enable detection of the document properties, such as holder's signature and other attributes.
@property(nullable, nonatomic, strong) NSNumber *checkProperties;
@property(nullable, nonatomic, strong) RGLAuthenticityPropertiesParams *propertiesParams;
@property(nullable, nonatomic, strong) NSNumber *checkUVLuminiscence;
@property(nullable, nonatomic, strong) NSNumber *checkIRB900;
@property(nullable, nonatomic, strong) NSNumber *checkImagePatterns;
@property(nullable, nonatomic, strong) NSNumber *checkFibers;
@property(nullable, nonatomic, strong) NSNumber *checkExtMRZ;
@property(nullable, nonatomic, strong) NSNumber *checkExtOCR;
@property(nullable, nonatomic, strong) NSNumber *checkAxial;
@property(nullable, nonatomic, strong) NSNumber *checkBarcodeFormat;
@property(nullable, nonatomic, strong) NSNumber *checkIRVisibility;
@property(nullable, nonatomic, strong) NSNumber *checkIPI;
@property(nullable, nonatomic, strong) NSNumber *checkPhotoEmbedding;
@property(nullable, nonatomic, strong) NSNumber *checkPhotoComparison;
@property(nullable, nonatomic, strong) NSNumber *checkLetterScreen;
@property(nullable, nonatomic, strong) NSNumber *checkSecurityText;

RGL_EMPTY_INIT_UNAVAILABLE

+ (instancetype)defaultParams;

@end

NS_ASSUME_NONNULL_END
