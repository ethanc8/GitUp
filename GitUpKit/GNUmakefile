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
	GCHistory+Rewrite.h GCLiveRepository+Utilities.h \
	GCRepository+Index.h GCRepository+Utilities.h \
	\
	# GIBranch.h GIConstants.h GIDiffView.h GIFunctions.h GIGraph.h GIGraphView.h \
	# GIImageDiffView.h GIInterface.h GILayer.h GILine.h GINode.h GIPrivate.h \
	# GISplitDiffView.h GIUnifiedDiffView.h

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
	Core/GCSnapshot.m Core/GCSQLiteRepository.m  \
	Core/GCStash.m  Core/GCSubmodule.m  \
	Core/GCTag.m \
	\
	Extensions/GCHistory+Rewrite.m Extensions/GCLiveRepository+Utilities.m \
	Extensions/GCRepository+Index.m Extensions/GCRepository+Utilities.m \
	\
	# Interface/GIBranch.m Interface/GIDiffView.m Interface/GIFunctions.m \
	# Interface/GIGraph.m Interface/GIGraphView.m Interface/GIImageDiffView.m \
	# Interface/GILayer.m Interface/GILine.m Interface/GINode.m \
	# Interface/GIPrivate.m Interface/GISplitDiffView.m Interface/GIUnifiedDiffView.m

libGitUpKit_INCLUDE_DIRS += -IHeaders -IHeaders/GitUpKit
libGitUpKit_HEADER_FILES_DIR = Headers/GitUpKit
libGitUpKit_HEADER_FILES_INSTALL_DIR = GitUpKit

# ARC
libGitUpKit_OBJCFLAGS = -fobjc-arc -fobjc-weak -D_GNU_SOURCE=

Core/GCCommitDatabase.m_FILE_FILTER_OUT_FLAGS = -fobjc-arc
Core/GCHistory.m_FILE_FILTER_OUT_FLAGS = -fobjc-arc
Core/GCRepository+Reflog.m_FILE_FILTER_OUT_FLAGS = -fobjc-arc
Core/GCSnapshot.m_FILE_FILTER_OUT_FLAGS = -fobjc-arc

# libgit2
libGitUpKit_LIBRARIES_DEPEND_UPON = -lGitUpKitGit2 -lCoreFoundation
libGitUpKit_INCLUDE_DIRS += -I$(GNUSTEP_LOCAL_HEADERS)/GitUpKitGit2 

# Tests
BUNDLE_NAME = GitUpKitTests
# FIXME - Core/GCCommitDatabase-Tests.m, Core/GCDiff-Tests.m, Core/GCRemote-Tests.m try to use nonexistent methods
# Maybe they're in Extensions?
GitUpKitTests_OBJC_FILES = \
	Core/GCBranch-Tests.m Core/GCCommitDatabase-Tests.m Core/GCCommit-Tests.m \
	Core/GCDiff-Tests.m Core/GCFoundation-Tests.m Core/GCHistory-Tests.m \
	Core/GCOrderedSet-Tests.m Core/GCRemote-Tests.m Core/GCRepository+Bare-Tests.m \
	Core/GCRepository+Config-Tests.m Core/GCRepository+HEAD-Tests.m \
	Core/GCRepository+Mock-Tests.m Core/GCRepository+Reflog-Tests.m \
	Core/GCRepository+Reset-Tests.m Core/GCRepository+Status-Tests.m \
	Core/GCRepository-Tests.m Core/GCSnapshot-Tests.m Core/GCSQLiteRepository-Tests.m \
	Core/GCStash-Tests.m Core/GCSubmodule-Tests.m Core/GCTag-Tests.m \
	Core/GCTestCase.m \
	\
	# Extensions/GCHistory+Rewrite-Tests.m Extensions/GCRepository+Index-Tests.m Extensions/GCRepository+Utilities-Tests.m

GitUpKitTests_INCLUDE_DIRS = -IHeaders -IHeaders/GitUpKit -I$(GNUSTEP_LOCAL_HEADERS)/GitUpKitGit2
GitUpKitTests_OBJCFLAGS = -fobjc-arc -fobjc-weak -D_GNU_SOURCE= -DDEBUG=1
GitUpKitTests_OBJC_LIBS = -lGitUpKit -lXCTest -lGitUpKitGit2
GitUpKitTests_LIB_DIRS = -Lobj

include $(GNUSTEP_MAKEFILES)/library.make
include $(GNUSTEP_MAKEFILES)/bundle.make

after-check::
	LD_LIBRARY_PATH=${PWD}/obj:${LD_LIBRARY_PATH} xctest GitUpKitTests.bundle