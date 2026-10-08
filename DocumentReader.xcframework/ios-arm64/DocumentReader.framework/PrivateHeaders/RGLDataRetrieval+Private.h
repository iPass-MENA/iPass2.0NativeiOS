//
//  RGLDataRetrieval+Private.h
//  DocumentReader
//
//  Created by Dmitry Evglevsky on 17.12.25.
//  Copyright © 2025 Regula. All rights reserved.
//

#import <DocumentReader/RGLDataRetrieval.h>

NS_ASSUME_NONNULL_BEGIN

@interface RGLDataRetrieval (Private)

@property (nonatomic, assign, readwrite) RGLeMDLDeviceRetrieval deviceRetrieval;

- (instancetype)initWithJSON:(NSDictionary<NSString *, id> *)json;
- (NSDictionary<NSString *, id> *)toJSON;

@end

NS_ASSUME_NONNULL_END
