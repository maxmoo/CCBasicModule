//
//  CCMacro.h
//  CCBasicModule
//
//  Created by maxmoo on 2021/6/11.
//
/*
 基础库宏定义
 */

#ifndef CCMacro_h
#define CCMacro_h

/***********************UI*********************************/
//设备屏幕的宽和高
#define kScreenWidth  ([UIScreen mainScreen].bounds.size.width)
#define kScreenHeight  ([UIScreen mainScreen].bounds.size.height)
#define kScreenMaxLength (MAX(kScreenWidth, kScreenHeight))
#define kScreenMinLength (MIN(kScreenWidth, kScreenHeight))
//6为标准适配的,如果需要其他标准可以修改
#define kScale_W(w) ((kScreenWidth)/414.0) * (w)
#define kScale_H(h) (kScreenHeight/736.0) * (h)
//状态栏
#define kStatusBarHeight \
^(){\
if (@available(iOS 13.0, *)) {\
    UIStatusBarManager *statusBarManager = [UIApplication sharedApplication].windows.firstObject.windowScene.statusBarManager;\
    return statusBarManager.statusBarFrame.size.height;\
} else {\
    return [UIApplication sharedApplication].statusBarFrame.size.height;\
}\
}()
//底部指示条
#define kIndicatorHeight \
^(){\
if (@available(iOS 11.0, *)) {\
    UIEdgeInsets safeAreaInsets = [[UIApplication sharedApplication] delegate].window.safeAreaInsets;\
    return safeAreaInsets.bottom;\
} else {\
    return UIEdgeInsetsMake(0, 0, 0, 0).bottom;\
}\
}()

#define kNavBarHeight (44.0)
#define kNavBarBottom (kStatusBarHeight + 44.0)
#define kTabbarHeight (kIndicatorHeight + 49.0)

/***********************判断设备*********************************/
//判断是否为iPhone
#define kISiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//判断是否为iPad
#define kISiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
//判断是否为ipod
#define kISiPod ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])
#define kISiPhone5 (kISiPhone && kScreenMaxLength == 568.0)
#define kISiPhone6 (kISiPhone && kScreenMaxLength == 667.0)
#define kISiPhone6P (kISiPhone && kScreenMaxLength == 736.0)
#define kISiPhoneX (kISiPhone && kScreenMaxLength == 812.0)
#define kISiPhoneXr (kISiPhone && kScreenMaxLength == 896.0)
#define kISiPhoneXX (kISiPhone && kScreenMaxLength > 811.0)

/***********************Color*********************************/
//颜色
#define kHEX(value) kRGBA(((float)((value & 0xFF0000) >> 16))/255.0, ((float)((value & 0xFF00) >> 8))/255.0, ((float)(value & 0xFF))/255.0, 1.0f)
//RGB
#define kRGB(r, g, b) kRGBA(r, g, b, 1.0f)
//RGBA
#define kRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]
// 随机色
#define kRandomColor kRGB(arc4random()%256, arc4random()%256, arc4random()%256)

/***********************log*********************************/
//Log
#ifdef DEBUG
#   define CLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#   define CLog(...)
#endif

//point size rect
#ifdef DEBUG
#define kLogPoint(point)    NSLog(@"%s = { x:%.4f, y:%.4f }", #point, point.x, point.y)
#define kLogSize(size)      NSLog(@"%s = { w:%.4f, h:%.4f }", #size, size.width, size.height)
#define kLogRect(rect)      NSLog(@"%s = { x:%.4f, y:%.4f, w:%.4f, h:%.4f }", #rect, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height)
#endif


/**
 Synthesize a weak or strong reference.
 
 Example:
    @weakify(self)
    [self doSomething^{
        @strongify(self)
        if (!self) return;
        ...
    }];

 */
#ifndef weakify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
        #define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
        #define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

#ifndef strongify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
        #define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
        #define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif

#define kWeakSelf __weak typeof(self) weakSelf = self;
#define kStrongSelf __strong typeof(weakSelf) strongSelf = weakSelf;

//存储对象
#define UserDefaultSetObjectForKey(__VALUE__,__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] setObject:__VALUE__ forKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

//获得存储的对象
#define UserDefaultObjectForKey(__KEY__)  [[NSUserDefaults standardUserDefaults] objectForKey:__KEY__]

//删除对象
#define UserDefaultRemoveObjectForKey(__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] removeObjectForKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

//
#define kKeyWindow ([UIApplication sharedApplication].keyWindow)
#define kAppDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)

//----------------------快速查询一段代码的执行时间
#define TICK NSDate *startTime = [NSDate date];
#define TOCK NSLog(@"Time:%f", -[startTime timeIntervalSinceNow]);

/**
    含义：(AVAILABLE：可用； DEPRECATED：弃用)
    NS_AVAILABLE(10_11, 7_0) 表示自 Mac10.11 和 iOS7.0 引入该函数，即 iOS7之后 使用这个函数
    NS_AVAILABEL_IOS(6_0) 表示自 iOS6.0 引入该方法，若在iOS6.0之前的版本使用该函数，则会导致 Crash；
    NS_DEPRECATED_IOS(2_0, 7_0, "替代函数")  表示该函数自 iOS2.0 引入，在 iOS7.0 被废弃。推荐 iOS7.0 之后使用替代函数。
    NS_DEPRECATED(10_6, 10_9, 2_0, 7_0) 表示自 Mac10.6 和 iOS2.0 引入，在 Mac10.9 和 iOS7.0 被废弃
 */

#endif /* CCMacro_h */
