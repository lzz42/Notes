# -*- coding:UTF-8 -*-

# 参考资料
# '''
#
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
UrlBase = "http://5sing.kugou.com/"
# 搜索列表页
URL = "http://search.5sing.kugou.com/home/index?keyword=起风了"
URL_F = "http://search.5sing.kugou.com/home/index?keyword={find}"

# 歌曲介绍页
URL2 = "http://5sing.kugou.com/yc/3769096.html"
'''
<audio id="wsp_player_1548910800954" name="wsp_player_1548910800954" src="http://wsaudio.bssdlbig.kugou.com/1901311259/to-iHmCI0MJwb3iGEFGZuA/1548997198/bss/extname/wsaudio/e693d9a9a61a304850714ff828a1da30.mp3" autoplay="false" preload="auto"></audio>
'''
# 歌曲下载地址
URL_D = "http://wsaudio.bssdlbig.kugou.com/1901311243/8kzvKAeS1LILmrgn_5IPwQ/1548996236/bss/extname/wsaudio/f3abb73be83e4667b3ee62465c53252e.mp3"

# 根据url参数获取请求到的soup结果对象


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


def analysiUrl_5Sing(url):
    soup = getPage(url)
    if soup is None:
        return None
    audio = soup.find('audio')
    if audio is None:
        return None
    dURl = audio.attrs['src']
    dic = {'url': dURl}
    h1 = soup.find('h1')
    if not h1 is None:
        dic.update('name', h1.text)
    info_ul = soup.find('ul', attrs={'class': 'It mb15'})
    if not info_ul is None:
        lis = info_ul.findAll('li')
        if not lis is None:
            for li in lis:
                em = li.find('em')
                a = li.find('a')
                if em is None & em.text is None:
                    continue
                if a is None & a.text is None:
                    continue
                dic.update(em.text, a.text)
    return dic


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


def saveToFile(html, fileName):
    if not html is None:
        fp = open(fileName, 'x', 1024, 'utf-8')
        fp.write(html)
        fp.flush()
        fp.close()
        return 0
    return 1


def downMp3File(url, fn):
    if url is None:
        return
    req = requests.get(url)
    if req is None:
        return
    if os.path.isfile(fn):
        os.remove(fn)
    fs = open(fn, 'wb')
    fs.write(req.content)
    fs.flush()
    fs.close()


def main():
    # 获取到MP3下载地址
    dic = analysiUrl_5Sing(URL2)
    if dic is None:
        return
    mp3Url = dic['url']
    name = dic['name']
    # 保存文件
    dir = 'Python\\Crawlers\\'
    tc = time.strftime('%Y%m%d%H%M', time.localtime(time.time()))
    if os.path.isdir(dir):
        htmlFile = dir + tc + name+".mp3"
    else:
        htmlFile = tc + name+".mp3"
    if os.path.isfile(htmlFile):
        os.remove(htmlFile)
    downMp3File(mp3Url, htmlFile)


if __name__ == '__main__':
    print("Audio Crawler Start!")
    main()
    print("Audio Crawler Done!")
