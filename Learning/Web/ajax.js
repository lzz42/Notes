/*
AJAX Asynchronous JavaScript and Xml
异步的JS和XML
无需重新加载整个网页的情况下，能够更新部分网页的技术
*/
function AjaxRequest() {
    //创建XMLHttpRequest对象
    var req;
    if (window.XMLHttpRequest) {
        req = new XMLHttpRequest();
    } else { //老版本IE5，IE6
        req = new ActiveXObject("Microsoft.XMLHTTP");
    }
    //向服务器发送请求
    var reqType = "GET"; //get或者post
    var url = ""; //服务器上文件的地址，该文件可以是任何类型
    var async = true;
    req.open(reqType, url, async);
    req.send(); //将请求发送到服务器
    /* GET And POST
    使用post情况：
    1.无法使用缓存文件；
    2.发送大量数据（post无大小限制，get1024k）
    3.发送包含未知字符
    */
    req.open("POST", url, true);
    var header = "headerName";
    var hv ="headervalue"

    req.setRequestHeader(header, hv); //向请求添加HTTP头
    req.send("发的数据");
    //异步执行时，在响应事件onreadystatechange中添加就绪执行函数
    req.onreadystatechange = function() {
        if (req.readyState == 4 && req.status == 200) {
            alert(req.responseText);
        }
    }
}

function AJAXResponse() {
    //创建XMLHttpRequest对象
    var req;
    if (window.XMLHttpRequest) {
        req = new XMLHttpRequest();
    } else { //老版本IE5，IE6
        req = new ActiveXObject("Microsoft.XMLHTTP");
    }
    //文本响应和xml响应，xml需要解析
    var txt = req.responseText;
    var xml = req.responseXML;
}

function AJAXReadyStateChange() {
    //创建XMLHttpRequest对象
    var req;
    if (window.XMLHttpRequest) {
        req = new XMLHttpRequest();
    } else { //老版本IE5，IE6
        req = new ActiveXObject("Microsoft.XMLHTTP");
    }
    req.onreadystatechange = function() {
            if (req.readyState == 4 && req.status == 200) {
                alert(req.responseText);
            }
        }
        /*
        readyState:
            0:请求未初始化
            1：服务器连接已建立
            2：请求已接收
            3：请求处理中
            4：请求已完成，且响应已就绪
        status：
            200："ok"
            404:未找到页面
        */
}

function AJAX_ASP_PHP() {
    var str = ""; //参数
    xmlhttp.open("GET", "gethint.asp?q=" + str, true);
    xmlhttp.send();
    xmlhttp.open("GET", "gethint.php?q=" + str, true);
    xmlhttp.send();
    xmlhttp.onreadystatechange = function() {
        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {

        }
    }
}

function AJAXDb() {}

function AJAXXml() {}