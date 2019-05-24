#
#  Be sure to run `pod spec lint PLVLiveKit.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "PLVLiveKit"
  s.version      = "1.2.1"
  s.summary      = "Polyv iOS streamer."

  s.homepage     = "http://git.polyv.net/ios/PolyvLiveKit"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "ftao" => "fft1026@163.com" }

  s.platform     = :ios, "8.0"

  s.source       = { :git => "http://git.polyv.net/ios/PolyvLiveKit", :tag => "#{s.version}" }
  
  s.source_files  =  "PLVLiveKit/LFLiveKit/LFLive*.{h,m}"
  s.public_header_files = "PLVLiveKit/LFLiveKit/*.h"
  
  # origin format
  # s.public_header_files = ['PLVLiveKit/LFLiveKit/*.h', 'PLVLiveKit/LFLiveKit/objects/*.h', 'PLVLiveKit/LFLiveKit/configuration/*.h']
  # s.source_files  = "PLVLiveKit/LFLiveKit/**/*.{h,m,mm,cpp,c}"

  s.frameworks = "VideoToolbox", "AudioToolbox","AVFoundation","Foundation","UIKit"
  s.libraries = "c++", "z"

  s.requires_arc = true


  # ---------- Vendor（添加PLVHeader.h文件处理pod lib lint验证不通过问题）
  s.subspec 'GPUImage' do |ss|
  	# except GPUImageFramework.h file
    ss.source_files  = ["PLVLiveKit/LFLiveKit/Vendor/GPUImage/*.{h,m}","PLVLiveKit/LFLiveKit/Vendor/GPUImage/iOS/*.{h,m}",'PLVLiveKit/LFLiveKit/Vendor/PLVHeader.h']
    ss.public_header_files = ["PLVLiveKit/LFLiveKit/Vendor/GPUImage/*.h", "PLVLiveKit/LFLiveKit/Vendor/GPUImage/iOS/*.h", 'PLVLiveKit/LFLiveKit/Vendor/PLVHeader.h']
  end

  s.subspec 'pili-librtmp' do |ss|
    ss.source_files  = ["PLVLiveKit/LFLiveKit/Vendor/pili-librtmp/*", 'PLVLiveKit/LFLiveKit/Vendor/PLVHeader.h']
    ss.public_header_files = 'PLVLiveKit/LFLiveKit/Vendor/PLVHeader.h'
  end

  # ---------- Subfiles
  s.subspec 'configuration' do |ss|
    ss.source_files  = "PLVLiveKit/LFLiveKit/configuration/*"
    ss.public_header_files = "PLVLiveKit/LFLiveKit/configuration/*.h"
  end

  s.subspec 'objects' do |ss|
    ss.source_files  = "PLVLiveKit/LFLiveKit/objects/*"
    ss.public_header_files = "PLVLiveKit/LFLiveKit/objects/*.h"

    ss.dependency 'PLVLiveKit/configuration'
  end

   s.subspec 'filter' do |ss|
   	ss.dependency 'PLVLiveKit/objects'
    ss.dependency 'PLVLiveKit/GPUImage'

    ss.source_files  = "PLVLiveKit/LFLiveKit/filter/*"
    ss.public_header_files = "PLVLiveKit/LFLiveKit/filter/*.h"
  end

  s.subspec 'capture' do |ss|
    ss.source_files  = "PLVLiveKit/LFLiveKit/capture/*"
    ss.public_header_files = "PLVLiveKit/LFLiveKit/capture/*.h"
    
    ss.dependency 'PLVLiveKit/filter'
  end

  s.subspec 'coder' do |ss|
  	# public_header_files 中不可添加H264下的.h文件，C++ header LFNALUnit.h 编译不过
    ss.source_files  = ["PLVLiveKit/LFLiveKit/coder/*.{h,m,mm}", "PLVLiveKit/LFLiveKit/coder/H264/*.{h,m,cpp}"]
    ss.public_header_files  = "PLVLiveKit/LFLiveKit/coder/*.h"
    # ss.source_files  = ["PLVLiveKit/LFLiveKit/coder/**/*.{h,m,mm,cpp}", 'PLVLiveKit/LFLiveKit/Vendor/PLVHeader.h']
    # ss.public_header_files  = ["PLVLiveKit/LFLiveKit/coder/**/*.h", 'PLVLiveKit/LFLiveKit/Vendor/PLVHeader.h']
    
    ss.dependency 'PLVLiveKit/objects' 
  end

  s.subspec 'publish' do |ss|
    ss.source_files  = "PLVLiveKit/LFLiveKit/publish/*"
    ss.public_header_files  = "PLVLiveKit/LFLiveKit/publish/*.h"

    ss.dependency 'PLVLiveKit/objects'
    ss.dependency 'PLVLiveKit/pili-librtmp'
  end

end