import { createRouter, createWebHashHistory } from 'vue-router'
import Home from '../views/service/Home.vue'

//路由管理器
const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/Outline',
    name: 'Outline',
    //访问路由时延迟加载
    component: () => import(/* webpackChunkName: "about" */ '../views/service/Outline.vue')
  }  
]

const router = createRouter({
  history: createWebHashHistory(),
  routes
})

export default router
