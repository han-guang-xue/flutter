<template>
  <div class="date">
    <h3>{{ title }}</h3>
    <p>{{ toDay }}</p>
    <p>vuex 状态管理</p>
    <button>count: {{ count }}</button>

    <h4>todoLength: {{ todoLength }}</h4>
  </div>
</template>
<script lang="ts" src="./RefTest.vue.ts"></script>
<style style="less" scoped>
.date {
    width: 100%;
    height: 100%;
    background: rgba(255, 0, 0, 0.301);
}
</style>