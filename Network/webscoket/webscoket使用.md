## WebSocket (HTML5)

> WebSocket 是 HTML5 开始提供的一种在单个 TCP 连接上进行全双工通讯的协议。
>
> WebSocket 使得客户端和服务器之间的数据交换变得更加简单，允许服务端主动向客户端推送数据。在 WebSocket API 中，浏览器和服务器只需要完成一次握手，两者之间就直接可以创建持久性的连接，并进行双向数据传输。
>
> 在 WebSocket API 中，浏览器和服务器只需要做一个握手的动作，然后，浏览器和服务器之间就形成了一条快速通道。两者之间就直接可以数据互相传送。
>
> 现在，很多网站为了实现推送技术，所用的技术都是 Ajax 轮询。轮询是在特定的的时间间隔（如每 1 秒），由浏览器对服务器发出 HTTP 请求，然后由服务器返回最新的数据给客户端的浏览器。这种传统的模式带来很明显的缺点，即浏览器需要不断的向服务器发出请求，然而 HTTP 请求可能包含较长的头部，其中真正有效的数据可能只是很小的一部分，显然这样会浪费很多的带宽等资源。
>
> HTML5 定义的 WebSocket 协议，能更好的节省服务器资源和带宽，并且能够更实时地进行通讯。

浏览器通过 JavaScript 向服务器发出建立 WebSocket 连接的请求，连接建立以后，客户端和服务器端就可以通过 TCP 连接直接交换数据。

当你获取 Web Socket 连接后，你可以通过 **send()** 方法来向服务器发送数据，并通过 **onmessage** 事件来接收服务器返回的数据。

以下 API 用于创建 WebSocket 对象。

```javascript
var Socket = new WebSocket(url, [protocol]);
```

#### WebSocket 事件

| 事件    | 事件处理         |            描述            |
| :------ | ---------------- | :------------------------: |
| open    | Socket.onopen    |       连接建立时触发       |
| message | Socket.onmessage | 客户端接收服务端数据时触发 |
| error   | Socket.onerror   |     通信发生错误时触发     |
| close   | Socket.onclose   |       连接关闭时触发       |

#### WebSocket 方法

| 方法           | 描述     |
| -------------- | -------- |
| Socket.send()  | 发送数据 |
| Socket.close() | 关闭连接 |

## WebSocket 服务搭建 Springboot

> 引入依赖

```xml
<dependency>
   <groupId>org.springframework.boot</groupId>
   <artifactId>spring-boot-starter-websocket</artifactId>
</dependency>
```
