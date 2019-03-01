
package main//定义包名称 main

import "fmt" //导入包 fmt
const (
	CInt = iota
	CBoolen = true
	CStr = "ok"
	CInt2 = iota
	CInt3
	CInt4
)
//定义函数 main
func main(){	
	//调用fmt包中的方法Printf
	fmt.Printf("hello world! main \n")
	fmt.Println(CInt,CBoolen,CStr,CInt2,CInt3,CInt4)
	var a,b = 11,22
	var c int
	 c = add(a,b)
	 fmt.Println(c)
}
//先调用init 函数 然后再调用main函数
func init(){
	fmt.Printf("hello init ! \n")
}
func add(num1 int,num2 int) int{
	return num1+num2;
}
func complex(num1 int,str string)(int,string){
	return num1,str+"00";
}

