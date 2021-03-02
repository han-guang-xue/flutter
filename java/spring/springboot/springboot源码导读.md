# getBean 的实现

![image-20201028114425485](typoraImage/image-20201028114425485.png)

**问题 1 : getBean 是 BeanFactory 接口中的方法, 最后怎么调用到了`AbstractBeanFactory`类中的 getBean 的方法?**

> [DefaultListableBeanFactory.java](./code/DefaultListableBeanFactory.java) getBean

BeanFactory 是 ConfigurableListableBeanFactory 类的超类接口,DefaultListableBeanFactory 又实现了该类, 接口和接口可以实现多继承

**问题 2 : getBean 是如何将类的字符串转化对应的类的**

> 并没有将类转换为所需要的类, 因为返回的是 Object, 使用 getBean(String classname);还需将返回对象强制装换;
