//
//  Copyright (c) 2019 Open Whisper Systems. All rights reserved.
//

#import "TSYapDatabaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@class OWSPrimaryStorage;
@class OWSStorage;
@class SSKProtoEnvelope;

@interface OWSMessageDecryptJob : TSYapDatabaseObject

@property (nonatomic, readonly) NSDate *createdAt;
@property (nonatomic, readonly) NSData *envelopeData;
@property (nonatomic, readonly, nullable) SSKProtoEnvelope *envelopeProto;

- (instancetype)initWithEnvelopeData:(NSData *)envelopeData NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithUniqueId:(NSString *_Nullable)uniqueId NS_UNAVAILABLE;

// --- CODE GENERATION MARKER

// clang-format off

- (instancetype)initWithUniqueId:(NSString *)uniqueId
                       createdAt:(NSDate *)createdAt
                    envelopeData:(NSData *)envelopeData
NS_DESIGNATED_INITIALIZER 
NS_SWIFT_NAME(init(uniqueId:createdAt:envelopeData:));

// clang-format on

// --- CODE GENERATION MARKER

@end

#pragma mark -

// This class is used to write incoming (encrypted, unprocessed)
// messages to a durable queue and then decrypt them in the order
// in which they were received.  Successfully decrypted messages
// are forwarded to OWSBatchMessageProcessor.
@interface OWSMessageReceiver : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithPrimaryStorage:(OWSPrimaryStorage *)primaryStorage NS_DESIGNATED_INITIALIZER;

+ (NSString *)databaseExtensionName;
+ (void)asyncRegisterDatabaseExtension:(OWSStorage *)storage;

- (void)handleReceivedEnvelopeData:(NSData *)envelopeData;

@end

NS_ASSUME_NONNULL_END
