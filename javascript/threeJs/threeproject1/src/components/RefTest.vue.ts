import { defineComponent } from 'vue';
export default defineComponent({
    props:{
        title: String,
    },
    data() {
        return {
            toDay: new Date().toLocaleDateString(),
        }
    },
    
    inject: ['todoLength'],

    created() {
        console.log(`注入属性 todoLength: ${this.todoLength}`) // > Injected property: John Doe
    },

    computed: {
        count() {
            return this.$store.state.name;
        }
    }
})