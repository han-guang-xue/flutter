<template>
  <div class="about">
    <h3>{{ title }}</h3>
    <div class="layout-flex">
      <div class="messageBox" v-for="i in 1" v-bind:key="i">
        <div class="messageHead"><h4>客户端发送消息</h4></div>
        <div class="messageShow">
          <div class="message-item" v-for="item in message" :key="item.value">
            <div class="mi1" :style="{float: item.type == 0 ? 'right' : 'left'}">{{ item.value }}</div>
          </div>
        </div>
        <div class="messageFoot">
          <div class="input-group">
            <input type="text" id="messageInput" class="form-control" placeholder="请输入">
            <span class="input-group-btn" >
              <button class="btn btn-info"  @click="send" type="button">Go!</button>
            </span>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>
<script>

var websocket = null;
export default {
  data() {
    return {
      title: "测试 WebScoket 通信机制",
      message: [],
    }
  },

  created() {
        
  },

  mounted() {
    //判断当前浏览器是否支持WebSocket, 主要此处要更换为自己的地址
    if ('WebSocket' in window) {
        websocket = new WebSocket("ws://localhost:8050/test/one");
    } else {
        alert('Not support websocket')
    }

    websocket.onopen = function() {
      console.log("webscoket 握手成功, 现在可以发送消息了...")
    }
  },
  methods: {
    send() {
      const ele = document.getElementById('messageInput');
      this.setMessage(ele.value);
      ele.value = "";
    },

    //将消息显示在网页上
    setMessage: function(value) {
      if(!value) return;
      this.message.push({
        type: 0,
        value: value
      })
      websocket.send(value);
    },

    //关闭连接
    closeWebSocket: function () {
        websocket.close();
    },
  }
}
</script>
<style scoped>
.messageBox * {
  box-sizing: border-box;
} 
.messageBox {
  width: 300px;
  height: 500px;
  border: 1px solid rgba(0, 0, 0, 0.527);
  margin-right: 20px;
  display: flex;
  flex-direction: column;
}
.layout-flex {
  display: flex;
  align-content: center;
  justify-content: center;
}
.messageHead {
  text-align: center;
  background: rgba(255, 0, 0, 0.055);
  flex-shrink: 0;
}
.messageShow {
  box-sizing: border-box;
  background: rgba(172, 255, 47, 0.3);
  flex-grow: 1;
  overflow: auto;
}
.messageFoot {
  background: rgba(95, 158, 160, 0.164);
  height: 50px;
  flex-shrink: 0;
  padding: 5px;
  display: flex;
  align-items: center;
  justify-content: center;
}
.message-item {
  height: 30px;
  width: 100%;
  margin: 5px 0;
}
.mi1 {
  height: 100%;
  max-width: 80%;
  text-align: center;
  background: rgba(32, 140, 230, 0.411);
  border: blue;
  border-radius: 30px;
  float: right;
  display: grid;
  align-content: center;
  justify-content: center;
  padding:0 20px;
  font-size: 13px;
  font-family: '黑体';
}
</style>