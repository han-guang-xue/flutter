export default {
    name: "center",
    data: function () {
      return {
        message: "ddd"
      };
    },
    computed: {
      count() {
        return this.$store.state.count
      }
    },
    components: {},
  };