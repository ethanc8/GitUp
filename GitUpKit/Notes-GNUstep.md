
### macOS graphics APIs

### Bridging

We have bridging from void* to object types, which should be fine

Also:
* NSString* &rarr; CFStringRef
* CFStringRef &rarr; NSString*
* void* &rarr; NSArray*
* void* &rarr; NSMutableDictionary*
* void* &rarr; NSString*

### CarbonCore

We need [UTI functions](https://developer.apple.com/library/archive/documentation/FileManagement/Conceptual/understanding_utis/understand_utis_intro/understand_utis_intro.html#//apple_ref/doc/uid/TP40001319-CH201-SW1), which are provided by [CarbonCore/LaunchServices and MobileCoreServices](https://developer.apple.com/documentation/coreservices/1448939-uttypecreatepreferredidentifierf?language=objc), [gnustep/libs-boron](https://github.com/gnustep/libs-boron/blob/master/Headers/LaunchServices/UTType.h) and by [ravynOS Launch Services](https://github.com/ravynsoft/ravynos/blob/main/Frameworks/LaunchServices/UTTypes.h). Boron looks more complete.

Note that these functions were deprecated in macOS 12.0 in favor of [Uniform Type Identifiers.framework](https://developer.apple.com/documentation/uniformtypeidentifiers?language=objc)
