var http = require('http');

http.createServer(function(req,rep){
    rep.writeHead(200,{'Content-Type': 'text/plain'});
    rep.end('Hello World\n');
    console.log('new client connected!!'+req.socket.localAddress);
}).listen(8888);


console.log('Server running at http://127.0.0.1:8888/');

// 引入events
var events = require("events");
// 创建EventEmitter对象
var eventEmitter = new events.EventEmitter();
//绑定事件
eventEmitter.on('load',function(){
    console.debug("On load event occurs");
});
// 触发事件
eventEmitter.emit(load);