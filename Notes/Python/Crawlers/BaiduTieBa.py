# -*- coding:UTF-8 -*-

import os
import re
import time
import sys
import requests
import lxml
import chardet
import urllib3
from bs4 import BeautifulSoup

URL = 'http://tieba.baidu.com/home/main?un=%E4%BA%91%E9%9A%8F%E9%A3%8E%E7%9A%84%E6%A2%A6&ie=utf-8&id=7131e4ba91e99a8fe9a38ee79a84e6a2a68739?t=1542020948&fr=pb&red_tag=q2935449511'

PostUrls = []

OnePostPageUrls = []

OnePostPageFloor = []


# 获取网站
def getPageSoup(url):
    # 给请求指定一个请求头来模拟chrome浏览器
    # headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'}
    # urllib3.disable_warnings()
    try:
        # req = requests.get(url, headers=headers, verify=False)
        req = requests.get(url, headers=headers)
        req.encoding = 'utf-8'
        # print("This Web Coding is %s"%(chardet.detect(req)))
        # req.encoding = 'gbk'
        # req = requests.get(url)
        soup = BeautifulSoup(req.text, 'lxml')
        return soup
        pass
    except:
        print("getPage Exception:", sys.exc_info()[0])
        pass

class baiDuTieBa():
    pUrl = ''
    
    PostUrls = []

    OnePostPageUrls = []

    OnePostPageFloor = []

    # 取到帖子链接
    def getPostUrls(self):
        soup = getPageSoup(self.pUrl)
        if not soup is None:
            lis = soup.find_all(class='thread_name')
        pass