include $(GNUSTEP_MAKEFILES)/common.make

APP_NAME = GitY

GitY_OBJC_FILES = AppDelegate.m Document.m DocumentController.m main.m
GitY_OBJC_LIBS = -lGitUpKit -lGL -lopal
GitY_RESOURCE_FILES = CommitViewTemplate.png HistoryViewTemplate.png Base.lproj/Document.xib Base.lproj/MainMenu.xib
GitY_MAIN_MODEL_FILE = MainMenu.xib

# ARC
GitY_OBJCFLAGS += -fobjc-arc -fobjc-weak

include $(GNUSTEP_MAKEFILES)/application.make