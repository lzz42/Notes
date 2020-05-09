
# -*- coding:UTF-8 -*-

import os
import re
import time

import itchat
from itchat.content import *

# itchat: https://itchat.readthedocs.io/zh/latest/


def main():
    LogIn()


def LogIn():
    itchat.auto_login()
    itchat.send('Hello, filehelper', toUserName='filehelper')

@itchat.msg_register([TEXT])
def text_reply(msg):
    res = re.search('ok', msg['Text'])
    if res:
        itchat.send(('fine thanks'), msg['FromUserName'])
    else:
        itchat.send(('are you ok?'), msg['FromUserName'])

@itchat.msg_register([PICTURE, RECORDING, VIDEO, SHARING])
def other_msg(msg):
    itchat.send(('hello?'), msg['FromUserName'])

def start_itchat():
    itchat.auto_login(enableCmdQR=True, hotReload=True)
    itchat.run()

if __name__ == '__main__':
    main()
