# Building and Installing on GNUstep

## Dependencies

### Debian and Ubuntu

```bash
sudo apt install libgit2-dev
```

### Other

[MiscHeaders](https://github.com/ethanc8/MiscHeaders)

### CFNetwork

```
git clone https://github.com/gerickson/opencfnetwork.git --branch 129.20.4
cd opencfnetwork
CC=$(gnustep-config --variable=CC) CFLAGS="-Wno-elaborated-enum-base" ./configure --with-CoreFoundation-includes="$(gnustep-config --variable=GNUSTEP_LOCAL_HEADERS)" --with-CoreFoundation-libs="$(gnustep-config --variable=GNUSTEP_LOCAL_LIBRARIES)"
```

#### Problems

##### CFFileDescriptor

[Apple's documentation](https://developer.apple.com/documentation/corefoundation/cffiledescriptor?language=objc)

Need (without c-ares):
* `CFFileDescriptorRef`
* `CFFileDescriptorEnableCallBacks`
* `kCFFileDescriptorReadCallBack`
* `kCFFileDescriptorWriteCallBack`
* `CFFileDescriptorNativeDescriptor`
* `CFFileDescriptorGetNativeDescriptor`
* `CFFileDescriptorContext`
* `CFFileDescriptorCreate`
