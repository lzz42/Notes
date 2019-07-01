# -*-coding:utf-8-*-
import sys
import math


# 寻找水仙花数
def find_Narcissistic_number():
    # 寻找三位数的水仙花数
    for i in range(100, 999):
        i0 = i % 10
        i1 = (i % 100)/10
        i2 = i/100
        sum = i0**3 + i1**3 + i2**3
        if sum == i:
            print("3 Nar:%d,%d %d %d " % (i, i2, i1, i0))
    # 寻找四位数的水仙花数
    for i in range(1000, 9999):
        i0 = i % 10
        i1 = (i % 100)/10
        i2 = (i % 1000)/100
        i3 = i/1000
        sum = i0**4 + i1**4 + i2**4 + i3**4
        if sum == i:
            print("4 Nar:%d,%d,%d %d %d " % (i, i3, i2, i1, i0))
    # 寻找2-6位的水仙花数
    for i in range(2, 6):
        for j in range(10**i, 10**(i+1)-1):
            arrs = []
            for k in range(0, i+1):
                temp = (j % (10**k))/(10**(k-1))
                arrs.append(temp)
            sum = 0
            for m in arrs:
                sum = sum + m**i
            if sum == j:
                print("%d Narciss:%d" % (i, j))
    pass


# 寻找完美数
def find_Perfect_Number():
    # 直接因子求和
    for i in range(32000000, 34000000):
        factor = []
        sum = 0
        n = int(math.sqrt(i)+1)
        for j in range(2, n):
            if i % j == 0:
                factor.append(j)
                sum = sum+j+i/j
        sum += 1
        # print("i:%d Sum:%d"%(i,sum))
        if sum == i:
            print(i)
    print("Done!")
    #
    pass

# 斐波那契数列
def fibonacci_Sequence(n=100):
    a = 0
    b = 1
    for i in range(1,n):
        a=a^b
        b=a^b
        a=a^b
        print(b)
        b=a+b
    return b
    pass

# yield

def yieldfunc():
    m = 100
    while True:
        m-=1
        print(m)
        yield m


import os


def print_board(board):
    print(board['TL'] + '|' + board['TM'] + '|' + board['TR'])
    print('-+-+-')
    print(board['ML'] + '|' + board['MM'] + '|' + board['MR'])
    print('-+-+-')
    print(board['BL'] + '|' + board['BM'] + '|' + board['BR'])


def main():
    init_board = {
        'TL': ' ', 'TM': ' ', 'TR': ' ',
        'ML': ' ', 'MM': ' ', 'MR': ' ',
        'BL': ' ', 'BM': ' ', 'BR': ' '
    }
    begin = True
    while begin:
        curr_board = init_board.copy()
        begin = False
        turn = 'x'
        counter = 0
        os.system('clear')
        print_board(curr_board)
        while counter < 9:
            move = input('轮到%s走棋, 请输入位置: ' % turn)
            if curr_board[move] == ' ':
                counter += 1
                curr_board[move] = turn
                if turn == 'x':
                    turn = 'o'
                else:
                    turn = 'x'
            os.system('clear')
            print_board(curr_board)
        choice = input('再玩一局?(yes|no)')
        begin = choice == 'yes'


if __name__ == "__main__":
    # find_Narcissistic_number()
    # find_Perfect_Number()
    # fibonacci_Sequence()
    main()
    pass
