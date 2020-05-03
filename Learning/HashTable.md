# HashTable

## 参考资料

- https://www.cnblogs.com/xuanyuan/p/12776866.html

## 存储结构与冲突解决

- 存储结构：数组存储，每一个元素是一个bucket
- 冲突解决：链表解决；链表超过长度 采用红黑树结构；双重散列算法：出现冲突后，采用另一个算法；开放寻址法；

## 哈希到位置映射

- index = hash % length
- index = hash & (lenght -1)
- index = hash' & (lenght -1) [hash' = ((hash <<16) >>16)^(hash >>16)]

## 初始容量与扩容

- 初始容量：16
- 负载因子：0.75（使用超过75%进行扩容）;0.72;2/3;
- 扩容策略：2的指数次方扩容；素数扩容（求模运算减少冲突）;