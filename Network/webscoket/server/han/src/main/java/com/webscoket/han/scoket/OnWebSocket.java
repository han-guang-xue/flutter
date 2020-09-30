package com.webscoket.han.scoket;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

import javax.websocket.server.ServerEndpoint;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.websocket.OnClose;
import javax.websocket.OnError;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
import javax.websocket.Session;
import org.springframework.stereotype.Component;

@ServerEndpoint(value = "/test/one")
@Component
public class OnWebSocket {

    public static Logger logger = LoggerFactory.getLogger(OnWebSocket.class);

    public static AtomicInteger onlineCount = new AtomicInteger(0);

    public static Map<String,Session> clients = new HashMap<>();

    @OnOpen
    public void onOpen(Session session) {
        onlineCount.incrementAndGet();
        logger.info("打开连接" + onlineCount.get());
    }

    @OnClose
    public void onClose(Session session) {
        onlineCount.decrementAndGet(); // 在线数减1
        logger.info("关闭连接");
    }

    @OnMessage
    public void onMessage(String message, Session session) {
        logger.info("接收到客户端的消息: " + message);
    }

    @OnError
    public void onError(Session session, Throwable error) {
        logger.info("发生错误");
        error.printStackTrace();
    }

    /**
     * 服务端发送消息给客户端
     */
    private void sendMessage(String message, Session toSession) {
        try {
            logger.info("服务端给客户端[{}]发送消息[{}]", toSession.getId(), message);
            toSession.getBasicRemote().sendText(message);
        } catch (Exception e) {
            logger.error("服务端发送消息给客户端失败：{}", e);
        }
    }

}
