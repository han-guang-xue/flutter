### 网络相关命令
 
 nmcli 网卡管理命令

发包
tcpreplay -i enp4s0 -P t3.pcapng

抓包
tcpdump -i any tcp -w /test/test.cap

jobs 查看后台运行命令
kill %num 结束jobs查询出的num进程

ifconfig eth1 promisc  设置混杂模式
ifconfig eth1 -promisc 取消混杂模式


chmod +x filename 

