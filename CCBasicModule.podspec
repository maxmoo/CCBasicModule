#
#  Be sure to run `pod spec lint CCBasicModule.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "CCBasicModule"
  spec.version      = "0.0.6"
  spec.summary      = "A short description of CCBasicModule."
  spec.description  = "CCBasicModule basic module"
  spec.homepage     = "https://github.com/maxmoo/CCBasicModule"
  spec.license      = "MIT"
  # spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  spec.platform     = :ios, "9.0"
  spec.author       = { "maxmoo" => "maxmoo@163.com" }
  spec.source       = { :git => "https://github.com/maxmoo/CCBasicModule.git", :tag => "#{spec.version}" }
  # spec.source_files  = "Classes/**/*.{h,m}"
  # spec.exclude_files = "Classes/Exclude"
  # spec.public_header_files = "Classes/**/*.h"
  # spec.resource  = "icon.png"
  # spec.resources = "Classes/*"
  # spec.preserve_paths = "FilesToSave", "MoreFilesToSave"
  spec.framework  = "UIKit"
  # spec.frameworks = "SomeFramework", "AnotherFramework"
  # spec.dependency 'YYKit'
  # spec.requires_arc = true

   #二级目录
  spec.subspec 'Category' do |ss|
    ss.source_files = 'Classes/Category/*.{h,m}'
  end

  spec.subspec 'Macro' do |ss|
    ss.source_files = 'Classes/Macro/*.{h,m}'
  end

  spec.subspec 'Tools' do |ss|
    ss.source_files = 'Classes/Tools/*.{h,m}'
  end

end
