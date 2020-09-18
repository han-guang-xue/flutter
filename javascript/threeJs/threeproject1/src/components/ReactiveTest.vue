<template>
  <div class="reactive">
      <input @input="setTitle" type="text" placeholder="请输入标题(title)" 
        class="form-control" id="basic-url" aria-describedby="basic-addon3">

       <input v-model="title.value" type="text" placeholder="请输入标题(title)" 
        class="form-control"  aria-describedby="basic-addon3">
        {{message}}
  </div>
</template>

<script lang="ts" src="./ReactiveTest.vue.ts"></script>

<style>
.reactive {
    background: rgba(255, 0, 0, 0.158);
 }
</style>