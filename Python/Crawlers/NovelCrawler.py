
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
import os
import re
import time
import sys
import requests
import lxml
import chardet
import urllib3
from bs4 import BeautifulSoup

# 爬虫接口
# -------------------------------------------------------------

class INovelCrawler:
    URL = ''
    Index = 0
    URLS = []
    # 是否还有要爬取的页面
    def hasCarwlPage(): pass

    # 获取网站网址
    def getWebUrl(): pass

    # 获取导航网址小说信息 小说全名 作者等信息
    def getNovelInfo(): pass

    # 获取导航网址所有章节 url
    def getNovelAllUrls(): pass

    # 获取单个章节页面数据
    def getSinglePageData(): pass

# -------------------------------------------------------------

# 顶点小说https://www.booktxt.net


class DingDianXiaoShuo(INovelCrawler):
    URL = 'https://www.dingdiann.com/ddk67087/'
    mURL0 = 'https://www.dingdiann.com/'

    def getPage(self):
        # 给请求指定一个请求头来模拟chrome浏览器
        # headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'}
        import urllib3
        # urllib3.disable_warnings()
        try:
            req = requests.get(self.URL, headers=headers)
            req.encoding = 'utf-8'
            # req.encoding = 'gbk'
            # req = requests.get(url)
            soup = BeautifulSoup(req.text, 'lxml')
            return soup
            pass
        except:
            print("getPage Exception:", sys.exc_info()[0])
            pass

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
                        href = dd.attrs['href']
                        indexPageUrl = self.mURL0
                        if(indexPageUrl.endswith('/')):
                            if(href.startswith('/')):
                                lis.append(indexPageUrl+href[1:])
                            else:
                                lis.append(indexPageUrl+href)
                        else:
                            if(href.startswith('/')):
                                lis.append(indexPageUrl+href)
                            else:
                                lis.append(indexPageUrl+'/'+href)
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
                print(cap)
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


class BiqugeCrawler(INovelCrawler):
    URL = ''
    Index = 0
    URLS = []

    def hasCarwlPage(self):
        if self.URLS != None and len(self.URLS) > 0:
            return len(self.URLS) > self.Index
        return False
        pass

    # 获取网站
    def getPage(self, url):
        # 给请求指定一个请求头来模拟chrome浏览器
        # headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'}
        # urllib3.disable_warnings()
        try:
            # req = requests.get(url, headers=headers, verify=False)
            req = requests.get(url, headers=headers)
            # req.encoding = 'utf-8'
            # print("This Web Coding is %s"%(chardet.detect(req)))
            req.encoding = 'gbk'
            # req = requests.get(url)
            soup = BeautifulSoup(req.text, 'lxml')
            return soup
            pass
        except:
            print("getPage Exception:", sys.exc_info()[0])
            pass

    def getWebUrl(self):
        # 给请求指定一个请求头来模拟chrome浏览器
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'}
        urllib3.disable_warnings()
        try:
            req = requests.get(self.URL, headers=headers, verify=False)
            # req.encoding = 'gbk'
            soup = BeautifulSoup(req.text, 'lxml')
            return soup
            pass
        except:
            print("getPage Exception:", sys.exc_info()[0])
            pass
        pass

    # 获取导航网址小说信息 小说全名 作者等信息
    def getNovelInfo(self):
        try:
            soup = self.getPage(self.URL)
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
                            if p.text.startswith("作者"):
                                novelAuthor = p.text.replace(
                                    '作者', '')
                                break
                return (novelName, novelAuthor)
            pass
        except:
            print("Unexpected error:", sys.exc_info()[0])
            pass
        return None

    # 获取导航网址所有章节 url
    def getNovelAllUrls(self):
        try:
            soup = self.getPage(self.URL)
            if not soup is None:
                list_div = soup.find('div', id='list')
                if not list_div is None:
                    lis = []
                    res = list_div.find_all('a')
                    for dd in res:
                        href = dd.attrs['href']
                        url = self.URL
                        if not url.startswith(url):
                            if(url.endswith('/')):
                                if(href.startswith('/')):
                                    lis.append(url+href[1:])
                                else:
                                    lis.append(url+href)
                            else:
                                if(href.startswith('/')):
                                    lis.append(url+href)
                                else:
                                    lis.append(url+'/'+href)
                        else:
                            lis.append(href)
                    for li in lis:
                        self.URLS.append(li)
                    return lis
        except:
            print("Unexpected error:", sys.exc_info()[0])
            pass

    # 获取单个章节页面数据
    def getSinglePageData(self):
        try:
            if len(self.URLS) > 0:
                if len(self.URLS) > self.Index:
                    url = self.URLS[self.Index]
                    self.Index += 1
                    soup2 = self.getPage(url)
                    cc = soup2.find('div', id='content')
                    title = soup2.find('h1')
                    if not title is None:
                        cap = '\n\n'+title.text+'\n\n'
                        print(cap)
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
        k = 12
        for u in list_urls:
            k = k-1
            if k > 0:
                continue
            print("Get Page URL:"+u)
            time.sleep(0.5)
            data = dingDianXiaoShuo.getSinglePageData(u)
            if not data is None:
                # 输出信息
                print(data[0])
                fp.write(data[0])
                fp.write(data[1])
                fp.flush()
        fp.close()
    print("ALL DONE !!!")


def main3():
    print("Python Novel Crawler")
    crawler = BiqugeCrawler()
    crawler.URL = 'https://www.biquge5.com/0_63/'
    info = crawler.getNovelInfo()
    urls = crawler.getNovelAllUrls()
    if not urls is None:
        dir = os.getcwd()
        tc = time.strftime('%Y%m%d%H%M', time.localtime(time.time()))
        f = dir+"\\" + info[0] + "_" + tc + ".txt"
        fp = open(f, 'w', encoding='utf-8')
        fp.write(info[0]+'\n')
        fp.write("\nby : "+info[1]+'\n')
        kt = crawler.hasCarwlPage()
        while kt:
            kt = crawler.hasCarwlPage()
            time.sleep(0.5)
            data = crawler.getSinglePageData()
            if not data is None:
                # 输出信息
                print(data[0])
                fp.write(data[0])
                fp.write(data[1])
                fp.flush()
        fp.close()
    print("ALL DONE !!!")


if __name__ == '__main__':
    # main2()
    main3()
