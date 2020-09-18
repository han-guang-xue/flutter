import { defineComponent } from 'vue';
import RefTest from '../../components/RefTest.vue';
import ReactiveTest from '../../components/ReactiveTest.vue';
export default defineComponent({

    components: {
        RefTest,
        ReactiveTest
    },

    data() {
        return {
            name : '韩广学',
            title: '我爱人民, 人民也爱我'
        }
    },

    methods: {
        getCanvas() {

        },
        initData() {
           
        }
    },
    //执行时尚未创建组件实例，因此选项this内部没有任何内容setup。这意味着，除了props，您将无法访问组件中声明的任何属性- 本地状态，计算属性或方法
    setup() {
        console.log('setup');
    },
    //加载html 页面之前
    created() {
        console.log('created');

    },
    //架子啊html 页面之后执行
    mounted() {
        console.log('mounted');        
    },
    
})