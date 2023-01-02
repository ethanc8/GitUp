include $(GNUSTEP_MAKEFILES)/common.make

LIBRARY_NAME = libGitUpKit
libGitUpKit_HEADER_FILES = \
	GitUpKit.h \
	\
	GCBranch.h GCCommitDatabase.h GCCommit.h GCCore.h GCDiff.h \
	GCError.h GCFoundation.h GCFunctions.h GCHistory.h GCIndex.h \
	GCLiveRepository.h GCMacros.h GCObject.h GCOrderedSet.h \
	GCReference.h GCReferenceTransform.h GCReflogMessages.h GCRemote.h \
	GCRepository+Bare.h GCRepository+Config.h GCRepository.h GCRepository+HEAD.h \
	GCRepository+Mock.h GCRepository+Reflog.h GCRepository+Reset.h \
	GCRepository+Status.h GCSnapshot.h GCSQLiteRepository.h GCStash.h \
	GCSubmodule.h GCTag.h \
	\
	XLFacilityMacros.h \
	\
	# GCHistory+Rewrite.h GCLiveRepository+Utilities.h \
	# GCRepository+Index.h GCRepository+Utilities.h

# XCTest is not supported
# GCTestCase.h \

libGitUpKit_OBJC_FILES = \
	Core/GCBranch.m  Core/GCCommitDatabase.m  \
	Core/GCCommit.m  Core/GCDiff.m  Core/GCFoundation.m \
	 Core/GCFunctions.m Core/GCHistory.m  \
	Core/GCIndex.m Core/GCLiveRepository.m Core/GCObject.m Core/GCOrderedSet.m \
	 Core/GCPrivate.m Core/GCReference.m Core/GCReferenceTransform.m \
	Core/GCRemote.m  Core/GCRepository+Bare.m  \
	Core/GCRepository+Config.m  Core/GCRepository+HEAD.m \
	 Core/GCRepository.m Core/GCRepository+Mock.m \
	 Core/GCRepository+Reflog.m  \
	Core/GCRepository+Reset.m  Core/GCRepository+Status.m \
	  Core/GCSnapshot.m \
	 Core/GCSQLiteRepository.m  \
	Core/GCStash.m  Core/GCSubmodule.m  \
	Core/GCTag.m \
	\
	# Extensions/GCHistory+Rewrite.m Extensions/GCLiveRepository+Utilities.m \
	# Extensions/GCRepository+Index.m Extensions/GCRepository+Utilities.m
	
# XCTest is not supported

libGitUpKit_INCLUDE_DIRS += -IHeaders -IHeaders/GitUpKit
libGitUpKit_HAEDER_FILES_DIR = Headers

# ARC
libGitUpKit_OBJCFLAGS = -fobjc-arc -fobjc-weak -D_GNU_SOURCE=

Core/GCCommitDatabase.m_FILE_FILTER_OUT_FLAGS = -fobjc-arc
Core/GCHistory.m_FILE_FILTER_OUT_FLAGS = -fobjc-arc
Core/GCRepository+Reflog.m_FILE_FILTER_OUT_FLAGS = -fobjc-arc
Core/GCSnapshot.m_FILE_FILTER_OUT_FLAGS = -fobjc-arc

# libgit2
libGitUpKit_LIBRARIES_DEPEND_UPON = -lgit2
libGitUpKit_INCLUDE_DIRS += -I$(GNUSTEP_LOCAL_HEADERS)/GitUpKitGit2 

include $(GNUSTEP_MAKEFILES)/library.make