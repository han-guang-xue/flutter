import { createStore } from 'vuex'

export default createStore({
  state: {
    name: '哔哩哔哩小王子' 
  },
  mutations: {
    setName(state,name){
      state.name = name;
    }
  },
  actions: {
  },
  modules: {
  }
})
