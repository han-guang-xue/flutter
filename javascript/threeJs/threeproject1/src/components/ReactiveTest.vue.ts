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
        setTitle: function () {
            console.log(this)
        }
    },

    mounted() {
        let that = this;
        const ele = document.getElementById("basic-url");
        ele['value'] = this.title;
        ele? ele.oninput = function(){
            console.log(this['value']);
            that.message = this['value'];
            that.title = this['value'];
        } : null;
    }
})
