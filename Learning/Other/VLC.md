# VLC

## 参考资料

- [git源代码](https://github.com/ZeBobo5/Vlc.DotNet)
- [帮助文档](https://github.com/ZeBobo5/Vlc.DotNet/wiki/Getting-started)

## 使用过程

- 1.安装VLC Nuge包：VLC.Net.Forms
- 2.安装VideoLAN.LibVLC.Windows.3.0.7.1 较大 可独自下载后解压缩 使用Build文件夹内的x86或x64
- 3.添加播放控件Vlc.DotNet.Forms.VlcControl：
- 4.BeginInit() -> instance.VlcLibDirectory =【路径】设置VideoLAN.LibVLC.Windows中引用的文件夹路径->设置日志参数instance.VlcMediaplayerOptions =【参数】->EndInit()
- 5.播放视频源：instance.SetMedia(url,paras) - URL播放路径 Paras - 播放参数,
- 6.播放控制：instance.Play(),instance.Stop(),instance.Pause()

## 打开参数

- 播放路径：捕捉屏幕：:URL:screen://
- 播放参数：屏幕帧率：:creen-fps=25.000000
- 播放参数：鼠标图片：:screen-mouse-image=16.png

## 其他

- [可能生成代码说明文档CHM](https://archive.codeplex.com/?p=shfb)
