//
//  ViewController.m
//  CCBasicModule
//
//  Created by maxmoo on 2021/6/11.
//

#import "ViewController.h"
#import "CCMacro.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = kRandomColor;
    
    NSLog(@"tabbar height:%f",kTabbarHeight);
}


@end
