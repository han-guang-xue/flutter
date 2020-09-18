import { defineComponent } from 'vue';
export default defineComponent({
    props: {
        title: {
            type: Object,
            required: true
        },
    },

    data() {
        return {
            message: '这个 Vue 是真滴难学',
        }
    },
    
    setup(props, { attrs, slots, emit }){
        console.log('---reactive---');
        console.log(props);
        console.log(attrs);
        console.log(slots);
        console.log(emit);
    },

    methods: {
        setTitle(e) {
            console.error(e.target.value);
            this.$store.commit('setName', e.target.value);
        }
    },

    mounted() {
        
    }
})
