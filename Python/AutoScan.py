import os
import re
import time
import sys
import requests
import lxml
from bs4 import BeautifulSoup

'''
<td><a href="tools/向日葵远程工具.exe" download="tools/向日葵远程工具.exe">向日葵客户端</a></td>
'''

template ='<td><a href="tools/{0}" download="tools/{1}">{2}</a></td>'
dir ='tools\\'
# dir ='Other'
def createIndexHtml(urls):
    htmlTemplate = '''
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="text/html; charset=utf-8" />
</head>
<title>测试</title>
<body>
    <div style="text-align:center;">
        </br>
        <p> This is a Test <a href="WSClient.html">WebSocket Client</a></p>
        </br>
        <table style="text-align:center; width:80%;left:10%;" id="tools">
            {}
        </table>
    </div>
</body>
</html>
    '''
    return htmlTemplate.format(urls)

def main():
    files=[]
    cdir=os.getcwd()
    ddir = os.path.join(cdir,dir)
    for mdir,subdir,file_list in os.walk(ddir):
        for f in file_list:
            files.append(f)
    print(files)
    print('\r\r')
    result =[]
    for f in files:
        ss =template.format(f,f,f)
        print(ss)
        result.append(ss)
    content =''
    cc=''
    i = 0
    for r in result:
        if i%3==0 and i!=0:
            content =content +'<tr>'+cc+'</tr>\r'
            cc =''
        cc+=r+'\r'
        i+=1
    if cc!='':
        content =content +'<tr>'+cc+'</tr>\r'
    r = createIndexHtml(content)
    if os.path.exists("main.html"):
        os.remove("main.html")
    f = os.open("main.html", os.O_RDWR|os.O_CREAT )
    os.write(f,str.encode(r))
    os.close(f)

if __name__ == "__main__":
    main()
    pass