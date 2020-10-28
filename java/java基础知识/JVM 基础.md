# JVM 内存模型笔记

> JVisualVM 调试工具(安装插件 Visual GC) 调试 gc

> jdk15的文档 https://docs.oracle.com/en/java/javase/15/vm/java-virtual-machine-technology-overview.html#GUID-982B244A-9B01-479A-8651-CB6475019281

> JVM 指令集 
> 英文 https://en.wikipedia.org/wiki/Java_bytecode_instruction_listings
>中文整理 [指令集](./JVM指令集.md)

> JVM 知识图系
> +  https://www.processon.com/view/5c749debe4b0f9fba6921d15?fromnew=1
> +  https://www.processon.com/view/5edf3f5e6376891e81bdd765?fromnew=1#map
> + https://www.processon.com/diagraming/5f814c8c5653bb06eff357ee

> JVM 虚拟机规范 官方文档 https://docs.oracle.com/javase/specs/index.html

> JVM 参数 https://docs.oracle.com/javase/8/docs/technotes/tools/unix/java.html (见官方文档)

# Java 中的 synchronized


