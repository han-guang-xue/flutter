<template>
  <div>
    <div class="box">
      <ref-test :title="title"></ref-test>
      <div class="bcgcanvas">
        <!-- <canvas id="myCanvas"></canvas> -->
        <keep-alive name="bounce">
          <transition name="bounce">
            <component :is="TabName">
              <!-- <i style="color:black;">我是默认插槽 nice </i> -->
              <template v-slot:slot1>
                <i style="color:#ffffff;">我是命名的插槽 </i>
              </template>
              <template v-slot:default>
                <i style="color:black;">我是默认插槽 </i>
              </template>
            </component>
          </transition>
        </keep-alive>

        
      </div>
      <reactive-test :title="title" ></reactive-test>
    </div>

    <div class="button-box">
      <button type="button" class="btn btn-default" @click="selectTab('Tab1')">Tab1</button>
      <button type="button" class="btn btn-primary" @click="selectTab('Tab2')">Tab2</button>
      <button type="button" class="btn btn-success" @click="selectTab('Tab3')">Tab3</button>
      <button type="button" class="btn btn-info">Info</button>
      <button type="button" class="btn btn-warning">Warning</button>
      <button type="button" class="btn btn-danger">Danger</button>
      <button type="button" class="btn btn-link">Link</button>
    </div>
    
    <input v-model="title.value" type="text" placeholder="请输入标题(title)" class="form-control" id="basic-url" aria-describedby="basic-addon3">
    <div id="gameType" @click="changeGameType">ddd</div>
</div>
</template>

<script lang="ts" src="./Three.vue.ts"></script>

<style lang="less" scoped>
.com-flex{
  display: flex;
  height: 15vh;
  width: 100vw;
}
.box {
    width: 100vw;
    height: 80vh;
    border: 1px blue solid;
    background: #447E36;
    display: grid;
    grid-template-columns: 1fr 1fr 1fr;
}
.button-box {
  display: flex;
  justify-content: center;
  align-items: center;
  button {
    margin-top: 30px;
    margin-left: 20px;
  }
}
.bcgcanvas {
  height: 100%;
  background: #FFC10756;
}

// 动画实现
.bounce-enter-active {
  animation: bounce-in 0.5s;
}

@keyframes bounce-in {
  0% {
    opacity: 0;
    transform: translateY(100px);
  }
  100% {
    opacity: 1;
    transform: translateY(0px);
  }
  
}
// .bounce-leave-active {
//   animation: bounce-leave 0.5s reverse;
// }
// @keyframes bounce-leave {
//   0% {
//     opacity: 1;
//     transform: translateY(0px);
//   }
//   100% {
//     opacity: 0;
//     transform: translateY(-100px);
//   }
// }
</style>
