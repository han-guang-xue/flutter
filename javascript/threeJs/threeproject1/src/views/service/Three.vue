<template>
  <div>
    <div class="box">
      <ref-test :title="title" :todolength="todoLength" />
      <div class="bcgcanvas">
        <!-- <canvas id="myCanvas"></canvas> -->
        <keep-alive name="bounce">
          <transition name="bounce">
            <component :is="TabName">
              <!-- <i style="color:black;">我是默认插槽 nice </i> -->
              <template #slot1>
                <i style="color: #ffffff">我是命名的插槽 {{ todoLength }}</i>
              </template>
              <template #default>
                <i style="color: black">我是默认插槽 </i>
              </template>
            </component>
          </transition>
        </keep-alive>
      </div>
      <reactive-test :title="title" />
    </div>
    <div class="router"><router-view /></div>
    <div class="button-box">
      <button type="button" class="btn btn-default" @click="selectTab('Tab1')">
        Tab1
      </button>
      <button type="button" class="btn btn-primary" @click="selectTab('Tab2')">
        Tab2
      </button>
      <button type="button" class="btn btn-success" @click="selectTab('Tab3')">
        Tab3
      </button>
      <button type="button" class="btn btn-info" @click="selectTab('Tab4')">
        Tab4
      </button>
      <button type="button" class="btn btn-warning">
        <router-link to="/"> 路由 Home </router-link>
      </button>
      <button type="button" class="btn btn-danger">
        <router-link to="/Outline"> 路由 Outline </router-link>
      </button>
      <button type="button" class="btn btn-link">Link</button>
    </div>

    <input
      v-model="title.value"
      type="text"
      placeholder="请输入标题(title)"
      class="form-control"
      id="basic-url"
      aria-describedby="basic-addon3"
    />
    <div id="gameType" @click="changeGameType">ddd</div>
  </div>
</template>

<script lang="ts" src="./Three.vue.ts"></script>

<style lang="less" scoped>
.com-flex {
  display: flex;
  height: 15vh;
  width: 100vw;
}
.box {
  width: 100vw;
  height: 80vh;
  border: 1px blue solid;
  background: #447e36;
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
  background: #ffc10756;
}

// 动画实现
.bounce-enter-active {
  animation: bounce-in 0.5s;
}

.router {
  width: 300px;
  transform: scale(0.5);
  background: rgba(236, 77, 77, 0.5);
  position: absolute;
  top: 10px;
  right: 10px;
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
