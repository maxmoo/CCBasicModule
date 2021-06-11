//
//  UIView+CCAdd.m
//  Abegal
//
//  Created by Tocoding on 2020/12/07.
//  Copyright © 2020 Chen. All rights reserved.
//

#import "UIView+CCAdd.h"

@implementation UIView (CCAdd)


- (void)clipsTopCornerRadius:(CGFloat)radius {
    [self clipsCornerRadius:radius rectCorners:UIRectCornerTopLeft|UIRectCornerTopRight];
}

- (void)clipsBottomCornerRadius:(CGFloat)radius {
    [self clipsCornerRadius:radius rectCorners:UIRectCornerBottomLeft|UIRectCornerBottomRight];
}

- (void)clipsCornerRadius:(CGFloat)radius rectCorners:(UIRectCorner)corners {
    UIBezierPath *maskPath = [UIBezierPath bezierPathWithRoundedRect:self.bounds byRoundingCorners:corners cornerRadii:CGSizeMake(radius, radius)];
    CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];
    maskLayer.frame = self.bounds;
    maskLayer.path = maskPath.CGPath;
    self.layer.mask = maskLayer;
}

@end
