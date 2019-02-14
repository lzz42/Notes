
# -*- coding:UTF-8 -*-

# Pyhon 文本网络爬虫 Selenium + PhatomJS
'''
需要安装的库：requests,lxml,BeautifulSoup4
pip install requests
pip install lxml
pip install BeautifulSoup4
https://www.cnblogs.com/Albert-Lee/p/6238866.html
PhatomJS 基于webkit的JS API的隐形浏览器:
http://phantomjs.org/
Selenium:pip install selenium
'''

# 导入http请求库
import requests
import lxml
import os
import re
import time
import sys
from bs4 import BeautifulSoup

URL = 'https://www.booktxt.net/0_362/'
# URL = 'https://www.booktxt.net/1_1562/'

# itchat: https://itchat.readthedocs.io/zh/latest/


def requestsTest():
    # get
    # 给请求指定一个请求头来模拟chrome浏览器
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
    rep = requests.get(URL, headers=headers)
    rep = requests.post(URL)


def BeautifulSoupTest():
    soup = BeautifulSoup('htmltext', 'html.parser')
    print(soup.prettify())
    # find title
    title = soup.title


def getTotalPage(url):
    # 给请求指定一个请求头来模拟chrome浏览器
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
    req = requests.get(url, headers=headers)
    # req.encoding = 'gb2312'
    req.encoding = 'gbk'
    # req = requests.get(url)
    soup = BeautifulSoup(req.text, 'lxml')
    return soup


def getNovelInfo(soup):
    infoDiv = soup.find('div', id='info')
    novelName = 'None'
    novelAuthor = 'Nobody'
    if not infoDiv is None:
        h1 = infoDiv.find('h1')
        if not h1 is None:
            novelName = h1.text
        for p in infoDiv.find_all('p'):
            if not p.text is None:
                if p.text.startswith("作\xa0\xa0\xa0\xa0者："):
                    novelAuthor = p.text.replace('作\xa0\xa0\xa0\xa0者：', '')
                    break
    return (novelName, novelAuthor)


def getAllIndexes(soup):
    list_div = soup.find('div', id='list')
    lis = []
    res = list_div.find_all('a')
    for dd in res:
        lis.append(dd.attrs['href'])
    return lis


def getOnePageData(url):
    soup = getTotalPage(url)
    cc = soup2.find('div', id='content')
    title = soup2.find('h1')
    if not title is None:
        cap = '\n\n第' + k + '章 '+title.text+'\n\n'
    if not cc is None:
        c = cc.text.replace('\xa0\xa0\xa0\xa0', '\n').replace('\ufffd', '').replace(
            '\u30fb', '').replace('\\u', '').replace('\xa0', '')
        text = cc
    else:
        return None
    return (cap, text)


def main():
    print("Python Novel Crawler")
    soup = getTotalPage(URL)
    lis = getAllIndexes(soup)
    dir = os.getcwd()
    tc = time.strftime('%Y%m%d%H%M', time.localtime(time.time()))
    info = getNovelInfo(soup)
    f = dir+"\\" + info[0] + "_" + tc + ".txt"
    fp = open(f, 'w')
    fp.write(info[0]+'\n')
    fp.write("\nby : "+info[1]+'\n')
    print(info[0])
    print(info[1])
    i = 0
    k = 0
    for l in lis:
        i = i+1
        # 跳过前面倒序的几章
        if i < 9:
            continue
        k = k+1
        # if k > 3:
        #     break
        # 此处睡眠 1S 防止过频繁的访问被网站禁IP
        time.sleep(0.5)
        url = URL+"/" + l
        soup2 = getTotalPage(url)
        cc = soup2.find('div', id='content')
        title = soup2.find('h1')
        if not cc is None:
            c = cc.text.replace('\xa0\xa0\xa0\xa0', '\n').replace('\ufffd', '').replace(
                '\u30fb', '').replace('\\u', '').replace('\xa0', '')
            cap = '\n\n第' + str(k)+'章 '+title.text+'\n\n'
            print(cap)
            fp.write(cap)
            fp.write(c)
            fp.flush()
    fp.close()
    print("ALL DONE !!!")


# 爬虫接口


class INovelCrawler:
    def getWebUrl(): pass
    # 获取网站网址

    def getNovelInfo(indexPageUrl): pass
    # 获取导航网址小说信息 小说全名 作者等信息

    def getNovelAllUrls(indexPageUrl): pass
    # 获取导航网址所有章节 url

    def getSinglePageData(singlePageUrl): pass
    # 获取单个章节页面数据

# 顶点小说https://www.booktxt.net


class DingDianXiaoShuo(INovelCrawler):
    # mURL = 'https://www.booktxt.net/0_362/'
    mURL = 'https://www.booktxt.net/2_2219/'

    def getPage(self, url):
        # 给请求指定一个请求头来模拟chrome浏览器
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
        req = requests.get(url, headers=headers)
        # req.encoding = 'gb2312'
        req.encoding = 'gbk'
        # req = requests.get(url)
        soup = BeautifulSoup(req.text, 'lxml')
        return soup

    def getWebUrl(self):
        return self.mURL

    def getNovelInfo(self, indexPageUrl):
        try:
            soup = self.getPage(indexPageUrl)
            if not soup is None:
                infoDiv = soup.find('div', id='info')
                novelName = 'None'
                novelAuthor = 'Nobody'
                if not infoDiv is None:
                    h1 = infoDiv.find('h1')
                    if not h1 is None:
                        novelName = h1.text
                    for p in infoDiv.find_all('p'):
                        if not p.text is None:
                            if p.text.startswith("作\xa0\xa0\xa0\xa0者："):
                                novelAuthor = p.text.replace(
                                    '作\xa0\xa0\xa0\xa0者：', '')
                                break
                return (novelName, novelAuthor)
            pass
        except:
            print("Unexpected error:", sys.exc_info()[0])
            pass
        return None

    def getNovelAllUrls(self, indexPageUrl):
        try:
            soup = self.getPage(indexPageUrl)
            if not soup is None:
                list_div = soup.find('div', id='list')
                if not list_div is None:
                    lis = []
                    res = list_div.find_all('a')
                    for dd in res:
                        lis.append(indexPageUrl+dd.attrs['href'])
                    return lis
            pass
        except:
            print("Unexpected error:", sys.exc_info()[0])
            pass

    def getSinglePageData(self, singlePageUrl):
        try:
            soup2 = self.getPage(singlePageUrl)
            cc = soup2.find('div', id='content')
            title = soup2.find('h1')
            if not title is None:
                cap = '\n\n'+title.text+'\n\n'
            if not cc is None:
                c = cc.text.replace('\xa0\xa0\xa0\xa0', '\n').replace('\ufffd', '').replace(
                    '\u30fb', '').replace('\\u', '').replace('\xa0', '')
                text = c
            else:
                return None
            return (cap, text)
            pass
        except:
            print("Unexpected error:", sys.exc_info()[0])
            pass
        return None

# 顶点小说 https://www.dingdiann.com/


class DingDiannXiaoShuo(INovelCrawler):
    # 获取网站网址
    def getWebUrl():
        pass

    # 获取导航网址小说信息 小说全名 作者等信息
    def getNovelInfo(indexPageUrl):
        pass

    # 获取导航网址所有章节 url
    def getNovelAllUrls(indexPageUrl):
        pass

    def getSinglePageData(singlePageUrl):
        pass


def main2():
    print("Python Novel Crawler")
    dingDianXiaoShuo = DingDianXiaoShuo()
    url = dingDianXiaoShuo.getWebUrl()
    info = dingDianXiaoShuo.getNovelInfo(url)
    list_urls = dingDianXiaoShuo.getNovelAllUrls(url)
    if not list_urls is None:
        dir = os.getcwd()
        tc = time.strftime('%Y%m%d%H%M', time.localtime(time.time()))
        f = dir+"\\" + info[0] + "_" + tc + ".txt"
        fp = open(f, 'w')
        fp.write(info[0]+'\n')
        fp.write("\nby : "+info[1]+'\n')
        k = 5
        for u in list_urls:
            time.sleep(0.5)
            k = k-1
            if k < 0:
                break
            data = dingDianXiaoShuo.getSinglePageData(u)
            if not data is None:
                # 输出信息
                print(data[0])
                fp.write(data[0])
                fp.write(data[1])
                fp.flush()
        fp.close()
    print("ALL DONE !!!")


if __name__ == '__main__':
    main2()
