const electron = require('electron')
const {
    app,
    BrowserWindow,
    Menu
} = require('electron')

// keep a  global reference of the win object if not the window will be closed Automatically when the javascript is garbage collected.
let win

function createWindow() {
    //隐藏关闭放大缩小最外层菜单栏目
    Menu.setApplicationMenu(null);
    // create browser window
    win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            nodeIntegration: true
        }
    })


    // load index.html file
    win.loadFile('./WebSocketClient.html')

    // 打开开发者工具。
    win.webContents.openDevTools()

}

app.on('ready', createWindow)

app.on('window-all-closed', function () {
    if (process.platform != 'darwin') {
        app.quit()
    }
})

app.on('activate', function () {
    // On OS X it's common to re-create a window in the app when the
    // dock icon is clicked and there are no other windows open.
    if (mainWindow === null) {
        createWindow()
    }
})