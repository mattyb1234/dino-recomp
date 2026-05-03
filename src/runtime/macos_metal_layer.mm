#import <Cocoa/Cocoa.h>
#import <QuartzCore/CAMetalLayer.h>

extern "C" void* dino_create_metal_layer(void* nsWindowPtr) {
    NSWindow* nsWindow = (__bridge NSWindow*)nsWindowPtr;
    NSView* contentView = [nsWindow contentView];

    [contentView setWantsLayer:YES];

    CAMetalLayer* metalLayer = [[CAMetalLayer alloc] init];
    metalLayer.frame = contentView.bounds;
    metalLayer.autoresizingMask = kCALayerWidthSizable | kCALayerHeightSizable;
    metalLayer.contentsScale = [nsWindow backingScaleFactor];
    metalLayer.needsDisplayOnBoundsChange = YES;

    [contentView setLayer:metalLayer];

    return (__bridge_retained void*)metalLayer;
}
