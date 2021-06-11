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

- (void)clipsTopCornerRadius:(CGFloat)radius;
- (void)clipsBottomCornerRadius:(CGFloat)radius;
- (void)clipsCornerRadius:(CGFloat)radius rectCorners:(UIRectCorner)corners;

@end

NS_ASSUME_NONNULL_END
