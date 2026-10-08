#import <Foundation/Foundation.h>
#import <DocumentReader/RGLMacros.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(AuthenticityPropertiesParams)
@interface RGLAuthenticityPropertiesParams : NSObject

/// Set to true to enable detection of the document holder's signature.
@property(nonatomic, strong, nullable) NSNumber *checkHoldersSignature;

+ (instancetype)defaultParams;

RGL_EMPTY_INIT_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END
