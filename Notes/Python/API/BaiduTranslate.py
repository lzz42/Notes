# coding=utf8

'''
http://api.fanyi.baidu.com/api/trans/product/apidoc
'''

import http.client
import hashlib
import urllib
import random
import sys
import json

class Translater:

    appid = ''  # 你的appid
    secretKey = ''  # 你的密钥
    httpClient = None
    myurlE = '/api/trans/vip/translate'
    q = 'pear'
    fromLang = 'en'
    toLang = 'zh'

    def __init__(self, id, key):
        self.appid = id
        self.secretKey = key
        pass

    def Translate(self, word):
        q = word
        appid = self.appid
        myurlE = self.myurlE
        fromLang = self.fromLang
        toLang = self.toLang
        secretKey = self.secretKey
        salt = random.randint(32768, 65536)
        sign = appid+q+str(salt)+secretKey
        m1 = hashlib.md5()
        m1.update(sign.encode())
        sign = m1.hexdigest()
        myurl = myurlE+'?appid='+appid+'&q=' + \
            urllib.parse.quote(q)+'&from='+fromLang+'&to='+toLang + \
            '&salt='+str(salt)+'&sign='+sign
        try:
            httpClient = http.client.HTTPConnection('api.fanyi.baidu.com')
            httpClient.request('GET', myurl)
            # response是HTTPResponse对象
            response = httpClient.getresponse()
            txt = response.read()
            data = json.loads(txt)['trans_result']
            src = data[0]['src']
            dst = data[0]['dst']
            print("%s --- %s" % (src, dst))
        except:
            print("Unexpected error:", sys.exc_info()[0])
        finally:
            if httpClient:
                httpClient.close()
        return dst


if __name__ == "__main__":
    print(sys.getdefaultencoding())
    print('输入百度翻译API ID和key：[ID]:[key]')
    iStr = str(input())
    id = iStr.split(':')[0]
    key = iStr.split(':')[1]
    print('ID:%s,KEY:%s' % (id, key))
    t = Translater(id, key)
    print('输入翻译词汇:')
    word = str(input())
    res = t.Translate(word)
    print('翻译结果：%s' % res)
    pass
