//  Copyright (C) 2015-2019 Pierre-Olivier Latour <info@pol-online.net>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#import <AppKit/AppKit.h>

// FIXME - Contribute this upstream to GNUstep
#if GNUSTEP
@protocol NSSplitViewDelegate <NSObject>
@optional
- (void) splitView: (NSSplitView *)sender 
resizeSubviewsWithOldSize: (NSSize)oldSize;

- (void) splitView: (NSSplitView *)sender 
constrainMinCoordinate: (CGFloat *)min 
     maxCoordinate: (CGFloat *)max 
       ofSubviewAt: (NSInteger)offset;

- (CGFloat) splitView: (NSSplitView *)sender
constrainSplitPosition: (CGFloat)proposedPosition
	ofSubviewAt: (NSInteger)offset;

- (void) splitViewWillResizeSubviews: (NSNotification *)notification;
- (void) splitViewDidResizeSubviews: (NSNotification *)notification;

#if OS_API_VERSION(GS_API_MACOSX, GS_API_LATEST)
- (BOOL) splitView: (NSSplitView *)sender
canCollapseSubview: (NSView *)subview;

- (CGFloat) splitView: (NSSplitView *)sender
constrainMaxCoordinate: (CGFloat)proposedMax
	ofSubviewAt: (NSInteger)offset;

- (CGFloat) splitView: (NSSplitView *)sender
constrainMinCoordinate: (CGFloat)proposedMin
	ofSubviewAt: (NSInteger)offset;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_5, GS_API_LATEST)
- (NSRect) splitView: (NSSplitView *)splitView
additionalEffectiveRectOfDividerAtIndex: (NSInteger)dividerIndex;

- (NSRect) splitView: (NSSplitView *)splitView
       effectiveRect: (NSRect)proposedEffectiveRect
        forDrawnRect: (NSRect)drawnRect
    ofDividerAtIndex: (NSInteger)dividerIndex;

- (BOOL) splitView: (NSSplitView *)splitView 
shouldCollapseSubview: (NSView *)subview
forDoubleClickOnDividerAtIndex: (NSInteger)dividerIndex;

- (BOOL) splitView: (NSSplitView *)splitView
shouldHideDividerAtIndex: (NSInteger)dividerIndex;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
- (BOOL) splitView: (NSSplitView *)splitView
shouldAdjustSizeOfSubview: (NSView *)view;
#endif

@end
#endif // GNUSTEP

typedef NS_ENUM(NSUInteger, GIAlertType) {
  kGIAlertType_Note = 0,
  kGIAlertType_Caution,
  kGIAlertType_Stop,
  kGIAlertType_Danger
};

extern NSString* const GICommitMessageViewUserDefaultKey_ShowInvisibleCharacters;
extern NSString* const GICommitMessageViewUserDefaultKey_ShowMargins;
extern NSString* const GICommitMessageViewUserDefaultKey_EnableSpellChecking;
extern NSString* const GIUserDefaultKey_FontSize;  // NSNumber. Base font size for user interface text. Read this with GIFontSize() to always get a valid value.

extern CGFloat const GIDefaultFontSize;

FOUNDATION_EXPORT CGFloat GIFontSize(void);  // Reads GIUserDefaultKey_FontSize, falling back to GIDefaultFontSize if the user defaults value is not usable.

FOUNDATION_EXPORT void GIPerformOnMainRunLoop(dispatch_block_t block);

@interface NSMutableAttributedString (GIAppKit)
- (void)appendString:(NSString*)string withAttributes:(NSDictionary*)attributes;
@end

@interface NSAlert (GIAppKit)
- (void)setType:(GIAlertType)type;  // Set the alert icon
@end

@interface NSView (GIAppKit)
- (void)replaceWithView:(NSView*)view;  // Preserves frame and autoresizing mask
- (NSImage*)takeSnapshot;
@end

@interface NSMenu (GIAppKit)
- (NSMenuItem*)addItemWithTitle:(NSString*)title block:(dispatch_block_t)block;
- (NSMenuItem*)addItemWithTitle:(NSString*)title keyEquivalent:(unichar)code modifierMask:(NSUInteger)mask block:(dispatch_block_t)block;  // Pass a NULL block to add a disabled item
@end

@interface GIFlippedView : NSView
@end

@interface GITextView : NSTextView
@end

@interface GICommitMessageView : GITextView
@end

// HACK - We should fix this upstream!
#if GNUSTEP


typedef NS_ENUM(NSInteger, NSTableViewRowSizeStyle) {
    /* The table will use the system default layout size: small, medium or large. */
    NSTableViewRowSizeStyleDefault = -1,
    
    /* The table will use the -rowHeight or ask the delegate for a variable row height (if implemented) and cell layout is not changed. */
    NSTableViewRowSizeStyleCustom = 0,
    
    /* The table will use a row height specified for a small/medium or large table.
     It is required that all sizes be fully tested and supported if NSTableViewRowSizeStyleCustom is not used.
     Some standard Aqua metrics may be applied to cells based on the current size. Specifically, the metrics will be applied to the NSTableCellView's textField and imageView outlets. Don't use these and add your own outlets if you wish to control the metrics yourself. */
    NSTableViewRowSizeStyleSmall = 1,
    NSTableViewRowSizeStyleMedium = 2,
    NSTableViewRowSizeStyleLarge = 3,
} API_AVAILABLE(macos(10.7));

@class NSTextField, NSImageView, NSDraggingImageComponent;

/* View Based NSTableView: The NSTableCellView is a reusable container view shown for a particular cell in the table. See NSTableView.h for more information. 
 */
API_AVAILABLE(macos(10.7))
@interface NSTableCellView : NSView

/* The 'objectValue' is automatically set by the table when using bindings, or the result from the dataSource method -tableView:objectValueForTableColumn:row:. Key Value Observing (KVO) compliant so user interface elements can be bound to the 'objectValue'. 
 */
@property (nullable, strong) id objectValue;

/* The following two properties are provided for the developer to hook up as outlets. These outlets can then be accessed in -tableView:viewForTableColumn:row: and modified. Additional outlets can be added by subclassing NSTableCellView, adding appropriate ivars and properties, and hooking it up in Interface Builder.
 */
@property (nullable, assign) IBOutlet NSTextField *textField;
@property (nullable, assign) IBOutlet NSImageView *imageView;

/* The backgroundStyle property is automatically set by the enclosing NSTableRowView to let this view know what its background looks like. For instance, when the -backgroundStyle is NSBackgroundStyleEmphasized, the view should use a contrasting text color. The system label colors (labelColor, secondaryLabelColor, tertiaryLabelColor, and quaternaryLabelColor) automatically adapt when displayed with an emphasized backgroundStyle. Upon setting, the default implementation automatically forwards calls to all subviews that implement -setBackgroundStyle: or are an NSControl (which have NSCells that respond to -setBackgroundStyle:).
 */
@property NSBackgroundStyle backgroundStyle;

/* The rowSizeStyle is set by the NSTableView to its -effectiveRowSizeStyle. The cell view will layout the textField and imageView based on the rowSizeStyle. A value of NSTableViewRowSizeStyleDefault should never be set on the cell view, as it is an appropriate value only for the table. See NSTableView.h for more information. 
 */
@property NSTableViewRowSizeStyle rowSizeStyle;

/* Multi-Item Drag Support. The default implementation will return an array of up to two NSDraggingImageComponent instances -- one for the imageView and another for the textField (if not nil). These methods can be subclassed and overridden to provide a custom set of NSDraggingImageComponents to create the drag image from this view.
 */
@property (readonly, strong) NSArray<NSDraggingImageComponent *> *draggingImageComponents;

@end
#endif

@interface GITableCellView : NSTableCellView
@property(nonatomic) NSInteger row;
- (void)saveTextFieldColors;
@end

@interface GITableView : NSTableView
@end

@interface GIDualSplitView : NSSplitView <NSSplitViewDelegate>  // This view assumes only 2 subviews and is its own delegate!
@property(nonatomic) IBInspectable CGFloat minSize1;
@property(nonatomic) IBInspectable CGFloat minSize2;
@end

@interface NSAppearance (GIAppearance)
@property(nonatomic, readonly) BOOL matchesDarkAppearance;
@end
