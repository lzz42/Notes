# -*- coding:UTF-8 -*-

# 参考资料
# '''
# https://blog.csdn.net/a33445621/article/details/80377424
# https://www.cnblogs.com/fatlyz/p/4293669.html
# https://blog.csdn.net/c406495762/article/details/78123502
# https://cuijiahua.com/blog/spider/
# https://www.cnblogs.com/xuchunlin/p/8668069.html
# 腾讯视频下载
# https://www.jianshu.com/p/eae2b7077e04
# https://blog.csdn.net/Szu_IT_Man/article/details/80449751
# https://blog.csdn.net/crysdem/article/details/80137331
# '''

# 导入http请求库
import requests
import lxml
import os
import re
import time
import sys
from bs4 import BeautifulSoup

# 一级网址
UrlBase = "http://www.79yy.cn"
# 视频列表页
URL = "http://www.79yy.cn/type/1/1.html"
URL_F = "http://www.79yy.cn/type/1/{}.html"
# 视频介绍页
URL2 = "http://www.79yy.cn/show/32276.html"
# 视频播放页
URL3 = "http://www.79yy.cn/play/32276/0/0.html"
# 视频真实播放地址
# URLX = "http://api.yyxzpc.cn/mdparse/m3u8.php?id=https://cn2.zuidadianying.com/20181216/IdYeq4aP/index.m3u8"
URLX = "http://cn7.kankia.com/hls/20191215/3be291c06e063532dc742a342bae0f46/1576392898/index.m3u8"
# m3u8 视频第一层地址
URLX2 = "https://cn2.zuidadianying.com/20181216/IdYeq4aP/index.m3u8"
URLXA = "https://cn2.zuidadianying.com"
# m3u8 视频第二层地址
URLX3 = URLXA+"/ppvod/EED4862269EEABC66B2177919345B6B1.m3u8"
# m3u8 ts文件地址
URLX4 = URLXA+"/20181216/IdYeq4aP/800kb/hls/1euHM6166000.ts"

# 根据url参数获取请求到的soup结果对象

# <video class="dplayer-video dplayer-video-current" webkit-playsinline="" playsinline="" crossorigin="anonymous" preload="metadata" src="blob:https://www.dt870.com/6498aa73-d5a2-4ffb-a4c3-137fff4bb4fc">
# </video>


def getPage(url):
    # 给请求指定一个请求头来模拟chrome浏览器
    try:
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
        req = requests.get(url, headers=headers)
        # req.encoding = 'gb2312'
        # req.encoding = 'gbk'
        # req = requests.get(url)
        soup = BeautifulSoup(req.text, 'lxml')
        return soup
    except:
        print("Unexpected error:", sys.exc_info()[0])
        pass
    return None

# 根据播放的url列表拼接出html显示结果div集合


def createHtmls(playUrls):
    if playUrls is None:
        return None
    hrefTemplate = '<div><a href="{}">{}</a></div>'
    result = ''
    for li in playUrls:
        result = result+'\n'+hrefTemplate.format(li[1], li[0])
    return result

# 创建html结果


def createIndexHtml(urls):
    htmlTemplate = '''
    <!DOCTYPE html>
    <html lang="zh-cn" manifest="" xmlns="" dir="auto">
        <head>
            <meta charset="UTF-8"\>
            <meta name="viewport" content="width=device-width, initial-scale=1.0"\>
            <meta http-equiv="X-UA-Compatible" content="ie=edge"\>
            <title>MOVIES</title>
        </head>
        <body>
            <h3>列表</h3>
            <div style="width:90%;height:100%;left:5%;text-align: center;position: relative;">
                {}
            </div>
        </body>
    </html>
    '''
    return htmlTemplate.format(urls)

# 保存html文件


def saveHtmlToFile(html, fileName):
    if not html is None:
        fp = open(fileName, 'x', 1024, 'utf-8')
        fp.write(html)
        fp.flush()
        fp.close()
        return 0
    return 1

# 查找播放电影的信息url地址


def findPlayUrl(url):
    soup = getPage(url)
    if soup is None:
        return None
    div = soup.find('div', attrs={'class': 'online-button'})
    if not div is None:
        # ,string="^\s+立即播放\s+$"
        a = div.find('a', attrs={'class': 'btn btn-success btn-block'})
        if not a is None:
            return a.attrs['href']
    return None

# 查找播放url的买m3u8地址


def findRealPlayUrl(url):
    # <iframe border="0" frameborder="0" height="460" id="player_swf" marginheight="0" marginwidth="0" scrolling="no" allowfullscreen="ture" src="http://api.yyxzpc.cn/mdparse/m3u8.php?id=https://sohu.zuida-163sina.com/20190110/xq7CpZ80/index.m3u8" width="100%"></iframe>
    soup = getPage(url)
    if soup is None:
        return None
    frame = soup.find('iframe', id='player_swf')
    if not frame is None:
        return frame.attrs['src']
    return None

# 根据m3u8地址解析所有ts文件下载地址


def getDownLoadUrls_m3u8(url):
    # URLX = "http://api.yyxzpc.cn/mdparse/m3u8.php?id=https://cn2.zuidadianying.com/20181216/IdYeq4aP/index.m3u8"
    # url = "https://jx.wlzy.tv/jx.php?url=http://cn7.kankia.com/hls/20191215/3be291c06e063532dc742a342bae0f46/1576392898/index.m3u8"
    p1 = url.find('?id=')
    if p1 is -1:
        return
    urlx1 = url[-(len(url)-p1-4):]
    if not (urlx1.startswith('https://') or urlx1.startswith('http://')) and urlx1.endswith('.m3u8'):
        return
    soup = getPage(urlx1)
    if soup is None:
        return
    # https://cn2.zuidadianying.com/20181216/IdYeq4aP/index.m3u8
    print(soup.text)
    baseUrl = urlx1[0:urlx1.find('.com')+4]
    textLines = soup.text.split('\n')
    eUrl = None
    for line in textLines:
        if line.upper() is '#EXTM3U':
            print('Is m3u8 Video')
        if line.endswith('.m3u8'):
            eUrl = line
            break
    if eUrl is None:
        return
    urlx2 = baseUrl+eUrl
    time.sleep(3.0)
    soup2 = getPage(urlx2)
    if soup2 is None:
        return
    # print(soup2.text)
    tsLines = soup2.text.split('\n')
    eUlrs = []
    for tsl in tsLines:
        if tsl.endswith('.ts'):
            eUlrs.append(baseUrl+tsl)
            # print(baseUrl+tsl)
    return eUlrs

# 根据ts文件地址下载所有ts文件到指定文件夹中


def downLoadVideo_m3u8_ts(urls, dir):
    if not os.path.isdir(dir):
        os.mkdir(dir)
    index = 0
    l = "{:0>" + str(len(str(len(urls)))+1)+"d}"
    for url in urls:
        index = index+1
        try:
            # soup = getPage(url)
            soup = requests.get(url)
            if not soup is None:
                fn = dir+'\\'+l.format(index)+'.ts'
                if os.path.isfile(fn):
                    os.remove(fn)
                fs = open(fn, 'wb')
                fs.write(soup.content)
                fs.flush()
                fs.close()
            time.sleep(2.0)
            print("{:.2%}".format(index/len(urls)))
        except expression as identifier:
            pass

# 下载单个页的视频


def main():
    lis = []
    playUrls = []
    realUrls = []
    soup = getPage(URL)
    if soup is None:
        return None
    divs = soup.find_all(
        'div', attrs={'class': 'col-md-1-5 col-sm-4 col-xs-6'})
    k = 0
    if not divs is None:
        for div in divs:
            k = k + 1
            a = div.find('a')
            if not a is None:
                lis.append(
                    (str(k)+' ' + a.attrs['title'], UrlBase+a.attrs['href']))
    for dd in lis:
        time.sleep(2.7)
        print(" Name:{},URL:{}".format(dd[0], dd[1]))
        p0 = findPlayUrl(dd[1])
        if not p0 is None:
            playUrls.append((dd[0], UrlBase+p0))
    for dd in playUrls:
        time.sleep(2.0)
        p0 = findRealPlayUrl(dd[1])
        if not p0 is None:
            print(" Name:{},RealURL:{}".format(dd[0], p0))
            realUrls.append((dd[0], p0))
    result2 = createHtmls(realUrls)
    result = createIndexHtml(result2)
    if not result is None:
        dir = 'Python\\Crawlers\\'
        tc = time.strftime('%Y%m%d%H%M', time.localtime(time.time()))
        if os.path.isdir(dir):
            htmlFile = dir + tc + "_Movie.html"
        else:
            htmlFile = tc + "_Movie.html"
        if os.path.isfile(htmlFile):
            os.remove(htmlFile)
        saveHtmlToFile(result, htmlFile)

# 下载所有分页的视频


def main2():
    lis = []
    playUrls = []
    realUrls = []
    bUrls = []
    k = 0
    # 第一层解析 解析从视频列表解析出URL
    for i in range(1, 10):
        u = URL_F.format(i)
        bUrls.append(u)
        # for uUrl in bUrls:
        time.sleep(3.0)
        soup = getPage(u)
        if soup is None:
            continue
        divs = soup.find_all(
            'div', attrs={'class': 'col-md-1-5 col-sm-4 col-xs-6'})
        if not divs is None:
            for div in divs:
                k = k + 1
                a = div.find('a')
                if not a is None:
                    lis.append(
                        (str(k)+' ' + a.attrs['title'], UrlBase+a.attrs['href']))
    # 第二层 解析从视频URL获取视频播放连接 以及视频介绍相关信息
    for dd in lis:
        time.sleep(3.7)
        print(" Name:{},URL:{}".format(dd[0], dd[1]))
        p0 = findPlayUrl(dd[1])
        if not p0 is None:
            playUrls.append((dd[0], UrlBase+p0))
    # 第三层 从播放页面解析出真正的视频资源URL
    for dd in playUrls:
        time.sleep(2.0)
        p0 = findRealPlayUrl(dd[1])
        if not p0 is None:
            print(" Name:{},RealURL:{}".format(dd[0], p0))
            realUrls.append((dd[0], p0))
    # 处理所有是视频播放真实URL 到HTML集合中
    result2 = createHtmls(realUrls)
    # 添加HTML展示模版
    result = createIndexHtml(result2)
    # 保存HTML文件
    if not result is None:
        dir = 'Python\\Crawlers\\'
        if os.path.isdir(dir):
            htmlFile = dir + \
                time.strftime('%Y%m%d%H%M', time.localtime(
                    time.time()))+"_Movie.html"
        else:
            htmlFile = time.strftime(
                '%Y%m%d%H%M', time.localtime(time.time()))+"_Movie.html"
        if os.path.isfile(htmlFile):
            os.remove(htmlFile)
        saveHtmlToFile(result, htmlFile)


def main3():
    # 解析m3u8获取到所有的ts文件下载地址
    urlxs = getDownLoadUrls_m3u8(URLX)
    # 下载所有的ts文件到本地目录
    downLoadVideo_m3u8_ts(urlxs, 'Python\\Crawlers\\0001')

    # 使用dos命令合并ts文件 copy /b *.ts 01.mp4
    # os.system('dir')


if __name__ == '__main__':
    print("Video Crawler Start!")
    # main2()
    main3()
    print("Video Crawler Done!")
