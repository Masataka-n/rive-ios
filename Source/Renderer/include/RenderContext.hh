/*
 * Copyright 2023 Rive
 */

#pragma once

#import <MetalKit/MetalKit.h>
#import <Metal/Metal.h>

namespace rive
{
class Factory;
class Renderer;
};

/// RenderContext knows how to set up a backend-specific render context (e.g., Skia, CG, Rive, ...),
/// and provides a rive::Factory and rive::Renderer for it.
@interface RenderContext : NSObject
@property(strong) id<MTLDevice> metalDevice;
@property(strong) id<MTLCommandQueue> metalQueue;
@property MTLPixelFormat depthStencilPixelFormat;
@property BOOL framebufferOnly;
- (rive::Factory*)factory;
- (rive::Renderer*)beginFrame:(MTKView*)view;
- (void)endFrame;
@end
