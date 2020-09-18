<template>
  <div class="center">
      3
      <p>{{message}}</p>
  </div>
</template>
<script>
export default {
  name: "center",
  data: function () {
    return {
      message: "ddd",
    };
  },
  components: {},
};
</script>
<style>
.center {
    background: rgba(0, 255, 42, 0.438);
}
</style>