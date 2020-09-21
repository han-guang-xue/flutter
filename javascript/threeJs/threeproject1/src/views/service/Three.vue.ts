import { defineComponent } from 'vue';
import RefTest from '../../components/RefTest.vue';
import ReactiveTest from '../../components/ReactiveTest.vue';
import Tab1 from '../tab/Tab1.vue';
import Tab2 from '../tab/Tab2.vue';
import Tab3 from '../tab/Tab3.vue';

export default defineComponent({

    components: {
        RefTest,
        ReactiveTest,
        Tab1,
        Tab2,
        Tab3,
    },

    data() {
        return {
            name : 'sadf',
            title: {value : '我爱人民, 人民也爱我'},
            TabName: 'Tab1',
            solt1 : '<div name="slot1">'+
            '  <i style="color:black;">我是插槽 </i>'+
            '    </div><div name="slot1">'+
            '    <i style="color:black;">我是插槽 </i>'+
            '</div>',
    }
    },

    methods: {
        getCanvas() {

        },
        initData() {
           
        },
        selectTab(tabname) {
            this.TabName = tabname;
        },
        // 测试 vuex 状态管理
        changeGameType() {
            console.log('----------ddd----------');
            console.log(document.getElementById('gameType'));
            document.getElementById('gameType').innerHTML = '成吉思汗';
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



