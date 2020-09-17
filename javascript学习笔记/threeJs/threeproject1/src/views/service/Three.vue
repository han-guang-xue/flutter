<template>
  <div class="box">
    10
    <div class="box-child">{{name}}</div>
  </div>
</template>

<script lang="ts" src="./Three.vue.ts"></script>

<style lang="less" scoped>
.box {
    width: 100vw;
    height: 100vh;
    background-color: red;
    .box-child {
        background-color: blue;
    }
}
</style>
