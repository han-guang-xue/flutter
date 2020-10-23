## docker

### docker 镜像管理命令

学习视频 https://www.bilibili.com/video/BV1og4y1q7M4
```shell
docker run -d [镜像名称] /bin/bash          # 启动容器
docker run -it [镜像名称] /bin/bash         # 启动并进入容器
docker exec -it [容器ID] /bin/bash          # /bin/bash 命令 进入已经启动的容器id
docker attach [容器ID]                  # 进入已经启动的容器id

docker rm -f $(docker ps -aq)          # 删除所有的容器

```