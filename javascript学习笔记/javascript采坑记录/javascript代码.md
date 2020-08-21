### javascript 实现 深度复制的方法

摘自: https://www.jb51.net/article/99013.htm

+ JSON.parse() 
    > + 但是这种方法也有不少坏处，譬如它会抛弃对象的constructor。也就是深拷贝之后，不管这个对象原来的构造函数是什么，在深拷贝之后都会变成Object。 
    > + 这种方法能正确处理的对象只有 Number, String, Boolean, Array, 扁平对象，即那些能够被 json 直接表示的数据结构。RegExp对象是无法通过这种方式深拷贝。
+ Object.create() 
    `var newObj = Object.create(oldObj)`

+ jQuery.extend()


### javascript 中如何对 对象数组实现去重

```JavaScript
    function arrayUnique2(arr, name) {
        var hash = {};
        return arr.reduce(function(item, next) {
            hash[next[name]] ? '' : hash[next[name]] = true && item.push(next);
            return item;
        }, []);
    };
    let arr = [
        {name:'张三1',age:15,id:1},
        {name:'张三2',age:15,id:2},
        {name:'张三3',age:15,id:3},
        {name:'张三4',age:15,id:1},
        {name:'张三5',age:15,id:2},
    ]
    arrayUnique2(arr,'id') //根据ID 去重
```
