## 修改镜像
> 解决方案

    在当前项目下,既 package.json 所在的目录下创建 .npmrc||.yarnrc (`这个是npm默认的配置文件`)
    在文件中加入以下代码

```shell
sass_binary_site=https://npm.taobao.org/mirrors/node-sass/
phantomjs_cdnurl=https://npm.taobao.org/mirrors/phantomjs/
electron_mirror=https://npm.taobao.org/mirrors/electron/
puppeteer_download_host=https://npm.taobao.org/mirrors/
registry=https://registry.npm.taobao.org
```

## 开启热加载

```shell
npm install --save-dev electron-reloader
```

```javascript
const { app, BrowserWindow } = require('electron')

// 热加载
try {
    require('electron-reloader')(module, {});
} catch (_) {}

function createWindow() {
    // 创建浏览器窗口
    const win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            nodeIntegration: true
        }
    })

    // 并且为你的应用加载index.html
    win.loadFile('./view/index.html')
}

app.whenReady().then(createWindow)
```

cnpm

https://blog.csdn.net/u014540814/article/details/78777961

cnpm install -g electron

> npm 安装 安装源修改为阿里巴巴

npm install -gd express --registry=http://registry.npm.taobao.org

> 永久设置

npm config set registry http://registry.npm.taobao.org

> .npmrc

electron_mirror = https://npm.taobao.org/mirrors/electron/

> npm install -g yrm  #包管理
>
> yrm use taobao
>
> yrm add aliyun http://maven.aliyun.com/nexus/content/groups/public
>
> yrm test aliyun