import { createApp } from 'vue'
import App from './App.vue'
import 'bootstrap/dist/css/bootstrap.css';
import store from './store';
import router from './router'

createApp(App).use(router).use(store).mount('#app')