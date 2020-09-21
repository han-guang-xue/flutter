<template>
  <div class="tab1">
    hello, 我是 tab3
    <h1>good nice  {{ title }}</h1>

    <slot></slot>

  </div>
</template>

<script lang="ts" src="./Tab3.vue.ts"></script>
<style scoped>
.tab1{
    color: yellowgreen;
}
</style>
