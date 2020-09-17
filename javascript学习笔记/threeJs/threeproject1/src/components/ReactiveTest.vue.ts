import { defineComponent } from 'vue';
export default defineComponent({
    props: {
        title: {
            type: String,
            required: true
        },
    },
    data() {
        return {
            message: '这个 Vue 是真滴难学',
            rtitle: '',
        }
    },
    
    setup(props){
        console.log('---reactive---');
        console.log(props);
        console.log();
    },

    methods: {
        setTitle() {
            console.log(this.rtitle);
        }
    },
})
