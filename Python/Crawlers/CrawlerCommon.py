
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