include $(GNUSTEP_MAKEFILES)/common.make

APP_NAME = GitDown

GitDown_OBJC_FILES = AppDelegate.m main.m
GitDown_OBJC_LIBS = -lGitUpKit
GitDown_RESOURCE_FILES = Base.lproj/MainMenu.xib
GitDown_MAIN_MODEL_FILE = MainMenu.xib

# ARC
GitDown_OBJCFLAGS += -fobjc-arc -fobjc-weak

include $(GNUSTEP_MAKEFILES)/application.make