#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(URLAuthenticationChallengeDelegate)
@protocol RGLURLAuthenticationChallengeDelegate <NSObject>

@required

- (NSURLCredential * _Nullable)credentialForAuthenticationChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge
NS_SWIFT_NAME(credential(for:));

@end

NS_ASSUME_NONNULL_END
