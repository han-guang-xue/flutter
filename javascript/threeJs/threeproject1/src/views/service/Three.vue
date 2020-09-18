<template>
  <div>
    <div class="box">
      <ref-test :title="title"></ref-test>
      <div class="bcgcanvas">
        <canvas id="myCanvas"></canvas>
      </div>
      <reactive-test :title="title" ></reactive-test>
    </div>

    <div class="button-box">
      <button type="button" class="btn btn-default">Default</button>
      <button type="button" class="btn btn-primary">Primary</button>
      <button type="button" class="btn btn-success">Success</button>
      <button type="button" class="btn btn-info">Info</button>
      <button type="button" class="btn btn-warning">Warning</button>
      <button type="button" class="btn btn-danger">Danger</button>
      <button type="button" class="btn btn-link">Link</button>
    </div>
    
    <input v-model="title.value" type="text" placeholder="请输入标题(title)" class="form-control" id="basic-url" aria-describedby="basic-addon3">
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
</style>
