import { defineComponent } from 'vue';
export default defineComponent({
    props:{
        title: String
    },
    data() {
        return {
            toDay: new Date().toLocaleDateString(),
        }
    }
})