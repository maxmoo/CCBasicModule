//
//  UIView+CCAdd.h
//  Abegal
//
//  Created by Tocoding on 2020/12/07.
//  Copyright © 2020 Chen. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CCAdd)


/// 上圆角
/// @param radius 圆角大小
- (void)clipsTopCornerRadius:(CGFloat)radius;

/// 下圆角
/// @param radius 圆角大小
- (void)clipsBottomCornerRadius:(CGFloat)radius;

/// 圆角
/// @param radius 圆角大小
/// @param corners 圆角位置
- (void)clipsCornerRadius:(CGFloat)radius rectCorners:(UIRectCorner)corners;

/// 画虚线 （虚线高度为view的高度）
/// @param lineLength 实线部分长度
/// @param lineSpacing 实线间隔
/// @param lineColor 实线颜色
- (void)drawDashLineWithLength:(int)lineLength lineSpacing:(int)lineSpacing lineColor:(UIColor *)lineColor;

@end

NS_ASSUME_NONNULL_END
