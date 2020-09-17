
# 笔记

> h5

  + javascript/typescript, vue,jquery,layui,bootstrap

  + html/wxml_微信小程序, cshtml_.NetWeb, jsp_java-Web

  + css/less,sass

# css3 单位:

+ 绝对单位
	
  + `px `(`cm`,`mm`,`q`,`in`,`pt`,`pc`): px像素（Pixel）。相对长度单位。像素px是相对于显示器屏幕分辨率而言的。

+ 相对单位
  + `em` (**%**): 是相对长度单位。相对于当前对象内文本的字体尺寸。如当前对行内文本的字体尺寸未被人为设置，则相对于浏览器的默认字体尺寸。

  + `rem`:为元素设定字体大小时，仍然是相对大小，但相对的只是HTML根元素。 less, sass(css 预编译语言)

    ```css
    @media only screen and (min-width:400px){
        html{
            font-size: 400%;
        }
    }	
    ```

  + `vh`/`vw`, `vmax`/`vmin`:相对于视口的高度。视口被均分为100单位的vh/vw

+ 自适应
  
  + `fr`

## display

+ 块/行

  + 盒子模型

+ table

## 作用于子元素

-moz代表baifirefox浏览器私有属性；

-ms代表IE浏览器私有属性；

-webkit代表chrome、safari私有属性；

> //本身是一个行内块元素,但是和同级别行级元素不同行
所有属性的通用属性
`initial`:默认值
`inherit`:该属性继承父元素 
`unset`:取消该属性继承父元素