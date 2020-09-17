----------------工作--------------
111.229.248.28
192.168.2.23
39.99.215.127
47.11.162.176

----------------git 命令--------------
git reset
git revert
git checkout bb.txt //修改本地文件的所有修改(修改的内容未 add)
----------------postsql--------------
systemctl
systemctl status postgresql-12.service
su - postgres
psql
\l
pg_dump -h localhost -U postgres --insert -d ycx_database -f YCXDB_PICC.sql;

----------------mysql--------------
!#Ha19841984*
------------------项目笔记----------------
文件: `.gitignore` 对不需要的目录或是文件忽略上传
文件: `.gitmodules`  https://blog.csdn.net/qq_27295403/article/details/80486116
文件: `.gitattributes` 文件中的一行定义一个路径的若干个属性

文件: `eslintrc.js` Vue的配置文件

-----------------liunx----------------
远程传输 https://blog.csdn.net/ibosea/article/details/88777862
scp `本地文件` root@ip:目录


select distinct on('AIP') 'AIP'  from(select 'AIP' from 'ACT' where  'AIP' not in ('117.60.62.89','49.74.50.127') and 'AUID' like '%000001%') t1;