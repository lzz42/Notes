# -*- coding: UTF-8 -*-

# https://docs.python.org/2/library/turtle.html

import turtle
import time

def draw_axis():
    # 设置画布
    w=800
    h=600
    turtle.screensize(w,h,'white')
    # turtle.setup(width=0.6,height=0.75,startx=100,starty=100)
    # turtle.setup(width=0.6,height=0.75,startx=100,starty=100)
    # 设置画笔
    turtle.pensize(2)
    turtle.pencolor('green')
    turtle.speed(1)
    # 画笔移动
    turtle.hideturtle()
    turtle.penup()
    turtle.speed(10)
    turtle.goto(-w/2,0)
    turtle.pendown()
    turtle.speed(1)
    turtle.forward(w)
    # draw arrow
    turtle.begin_fill()
    turtle.color('green','green')
    turtle.left(45)
    turtle.goto(w/2-6,4)
    turtle.goto(w/2-6,-4)
    turtle.goto(w/2,0)
    turtle.right(45)
    turtle.end_fill()
    turtle.penup()
    turtle.speed(10)
    turtle.goto(0,-h/2)
    turtle.left(90)
    turtle.pencolor('red')
    turtle.pendown()
    turtle.speed(1)
    turtle.forward(h)    
    # draw arrow
    turtle.begin_fill()
    turtle.color('red','red')
    turtle.left(45)
    turtle.goto(-4,h/2-6)
    turtle.goto(4,h/2-6)
    turtle.goto(0,h/2)
    turtle.right(45)
    turtle.end_fill()
    turtle.speed(10)
    turtle.penup()
    turtle.goto(-10,-10)
    turtle.hideturtle()
    turtle.write("0",font=("楷体", 16, "normal"))
    turtle.exitonclick()
    pass




if __name__ == "__main__":
    draw_axis()
    pass