<template>
  <div class="left">
    2
    <input v-model="message" />
    <p>{{ message }}</p>

    <button @click="add">点我 {{ count }} </button>
  </div>
</template>
<script>
export default {
  name: "left",
  data: function () {
    return {
      message: "ddd",
    };
  },
  components: {

  },

  computed: {
    count() {
      return this.$store.state.count;
    }
  },
  methods: {
    add() {
      this.$store.commit('increment');
      console.log(this.$store.state.count);
    }
  }
};
</script>
<style>
.left {
  background: rgba(255, 0, 242, 0.438);
}
</style>
