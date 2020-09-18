<template>
  <div id="app">
    <right-setting />
    <center-setting />
    <left-setting />
  </div>
</template>
<script>
import RightSetting from './components/RightSetting.vue';
import CenterSetting from './components/CenterSetting.vue';
import LeftSetting from './components/LeftSetting.vue';

export default {
  name: 'App',
  components: {
    RightSetting,
    CenterSetting,
    LeftSetting,
  }
}
</script>

<style scoped>
  #app {
    width: 100vw;
    height: 100vh;
    display: grid;
    grid-template-columns: 1fr 1fr 1fr;
    font-size: 40px;
  }
</style>