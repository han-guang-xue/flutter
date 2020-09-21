<template>
  <div class="tab1">
    hello, 我是 tab2
    <h1>good nice  {{ title }}</h1>

    <slot></slot>

  </div>
</template>

<script lang="ts" src="./Tab2.vue.ts"></script>
<style scoped>
.tab1{
    color: green;
}
</style>
