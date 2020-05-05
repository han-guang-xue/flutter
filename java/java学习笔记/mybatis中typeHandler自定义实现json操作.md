##mybatis中typeHandler自定义实现typeHandler与数据库映射JSON读取
参考文档
+ 自定义typeHander实现教程 https://blog.csdn.net/jokemqc/article/details/81326109 
+ 自定义typeHander实现JSON转化 https://blog.csdn.net/inflarunas/article/details/99588535
+ github提供 第三方对JSON操作的typeHander https://github.com/jneat/mybatis-gson
+ spring+mybatis中typehandler怎么配置 https://blog.csdn.net/zhaoyf7746/article/details/71131578


JSON 插件对比
![图示](images/fastjson.png)
![图示](images/Gson.png)
![图示](images/jackjson.png)


## 如何自定义 typeHandler 实现json从数据库中读取
环境:  postgreSql(DB) + springMVC +   fastjson(阿里巴巴)
将 postgreSql 中json 格式的数据与 mybais转化
###步骤
> 1.继承BaseTypeHandler类
    该类中有四个方法
```java
    public class JSONHandler extends BaseTypeHandler {
        @Override
        public void setNonNullParameter(PreparedStatement ps, int i, Object parameter, JdbcType jdbcType) throws SQLException {
            
        }

        @Override
        public Object getNullableResult(ResultSet rs, String columnName) throws SQLException {
            return null;
        }

        @Override
        public Object getNullableResult(ResultSet rs, int columnIndex) throws SQLException {
            return null;
        }

        @Override
        public Object getNullableResult(CallableStatement cs, int columnIndex) throws SQLException {
            return null;
        }
    }
```

重写这四个方法,然后接着配置文件 spring-mybatis.xml (数据源配置的文件)

```xml
<bean id="sqlSessionFactory" class="org.mybatis.spring.SqlSessionFactoryBean">
    <!-- 数据源配置 -->
    <property name="dataSource" ref="dataSource" />
    <!-- 自动扫描mapping.xml文件 -->
    <property name="mapperLocations" value="classpath:mapper/*/*.xml"></property>
    <!-- 加入自定义typeHandler -->
    <property name="typeHandlers">
    <!-- 示例加入多个 typeHandler -->
        <list>
            <bean class="com.xingshu.utils.typehandler.JSONArrayHandler"></bean>
            <bean class="com.xingshu.utils.typehandler.JSONObjectHandler"></bean>
        </list>
    </property>
</bean>
```

然后直接可以引用,经实验,属性名后面 typeHandler 可以直接去掉, Mybatis 会自动映射,mybatis对jdbctype 和 typeHandler 会有一个优先级的匹配,如果实现类只有一个,可以省略不写

```xml
 <insert id="insert" parameterType="com.xingshu.bean.business.UFriendsRelation">
    insert into "UFriendsRelation" ("UHashId","UFriends","UGroupIds","UFCreateTime")
    values (
        #{UHashId},
        <if test="UFriends==null">null, </if>
        <if test="UFriends!=null">(#{UFriends,typeHandler=com.xingshu.utils.typehandler.JSONArrayHandler})::json,</if>
        <if test="UGroupIds==null">null, </if>
        <if test="UGroupIds!=null">(#{UGroupIds,typeHandler=com.xingshu.utils.typehandler.JSONObjectHandler})::json,</if>
        now()
    )
  </insert>
```

不写 typehandler 
```xml
 <insert id="insert" parameterType="com.xingshu.bean.business.UFriendsRelation">
    insert into "UFriendsRelation" ("UHashId","UFriends","UGroupIds","UFCreateTime")
    values (
        #{UHashId},
        <if test="UFriends==null">null, </if>
        <if test="UFriends!=null">(#{UFriends})::json,</if>
        <if test="UGroupIds==null">null, </if>
        <if test="UGroupIds!=null">(#{UGroupIds})::json,</if>
        now()
    )
  </insert>
```

### java 类示例 JSONArrayHandler 
```java
package com.xingshu.utils.typehandler;

import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONException;
import org.apache.ibatis.type.BaseTypeHandler;
import org.apache.ibatis.type.JdbcType;

import java.sql.CallableStatement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class JSONArrayHandler extends BaseTypeHandler<JSONArray> {

    public JSONArray delResult(String jsonSource) throws SQLException {
        if(jsonSource != null){
            JSONArray jsonArray;
            try{
                jsonArray = JSONArray.parseArray(jsonSource);
            }catch (JSONException ex){
                throw new SQLException("There is an error converting JSONArray to json format for the content:" + jsonSource);
            }
            return jsonArray;
        }
        return null;
    }
    
    @Override
    public void setNonNullParameter(PreparedStatement ps, 
                                    int i,
                                    JSONArray parameter, //需要转换的类型,JSON类型
                                    JdbcType jdbcType) throws SQLException {
        ps.setString(i,parameter.toJSONString());
    }

    @Override
    public JSONArray getNullableResult(ResultSet rs, String columnName) throws SQLException {
        return delResult(rs.getString(columnName));
    }

    @Override
    public JSONArray getNullableResult(ResultSet rs, int columnIndex) throws SQLException {
        return delResult(rs.getString(columnIndex));
    }
    
    @Override
    public JSONArray getNullableResult(CallableStatement cs, int columnIndex) throws SQLException {
        return delResult(cs.getString(columnIndex));
    }    
    
}

```
### java 类示例 JSONObjectHandler

```java
package com.xingshu.utils.typehandler;

import com.alibaba.fastjson.JSONException;
import com.alibaba.fastjson.JSONObject;
import org.apache.ibatis.type.BaseTypeHandler;
import org.apache.ibatis.type.JdbcType;

import java.sql.CallableStatement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class JSONObjectHandler extends BaseTypeHandler<JSONObject> {

    public JSONObject delResult(String jsonSource) throws SQLException {
        if(jsonSource != null){
            JSONObject jsonObject;
            try{
                jsonObject = JSONObject.parseObject(jsonSource);
            }catch (JSONException ex){
                throw new SQLException("There is an error converting JSONObject to json format for the content:" + jsonSource);
            }
            return jsonObject;
        }
        return null;
    }

    @Override
    public void setNonNullParameter(PreparedStatement ps,
                                    int i,
                                    JSONObject parameter, //需要转换的类型,JSON类型
                                    JdbcType jdbcType) throws SQLException {
        ps.setString(i,parameter.toJSONString());
    }

    @Override
    public JSONObject getNullableResult(ResultSet rs, String columnName) throws SQLException {
        return delResult(rs.getString(columnName));
    }

    @Override
    public JSONObject getNullableResult(ResultSet rs, int columnIndex) throws SQLException {
        return delResult(rs.getString(columnIndex));
    }

    @Override
    public JSONObject getNullableResult(CallableStatement cs, int columnIndex) throws SQLException {
        return delResult(cs.getString(columnIndex));
    }

}

```

