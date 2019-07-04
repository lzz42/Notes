var http = require('http');

http.createServer(function(req,rep){
    rep.writeHead(200,{'Content-Type': 'text/plain'});
    rep.end('Hello World\n');
    console.log('new client connected!!'+req.socket.localAddress);
}).listen(8888);


console.log('Server running at http://127.0.0.1:8888/');