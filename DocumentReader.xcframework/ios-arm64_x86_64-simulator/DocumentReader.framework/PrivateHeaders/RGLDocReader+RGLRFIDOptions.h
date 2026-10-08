//
//  RGLDocReader+RGLRFIDOptions.h
//  DocumentReader
//
//  Created by Siarhei Rylko on 11.05.2026.
//  Copyright © 2026 Regula. All rights reserved.
//

@class RGLDocReader;

NS_ASSUME_NONNULL_BEGIN

@interface RGLDocReader (RGLRFIDOptions)

/// @param inputParams Dictionary with RFID options.
/// @return `BOOL` Success status from command execution.
- (BOOL)setRFIDOptions:(NSDictionary * _Nonnull)inputParams
NS_SWIFT_NAME(setRFIDOptions(inputParams:));

@end

NS_ASSUME_NONNULL_END
