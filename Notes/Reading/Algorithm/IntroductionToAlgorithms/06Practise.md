# 对排序

- 

- 6.2-5
```C
void max_heapify_loop(int* a,int i,int len){
    int l = left(i);
    int r = right(i);
    int largest =i;
    if(l <=heap_size(a) && a[l]>a[i){
        largest =l;
    }
    if(r <=heap_size(a)&& a[r]>a[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        do
        {
            i = largest;
            l=left(i);
            r=right(i);
            if(l <=heap_size(a) && a[l]>a[i){
                largest =l;
            }
            if(r <=heap_size(a)&& a[r]>a[largest]){
                largest = r;
            }
            if(largest!=i){
                swap(a[i],a[largest]);
            }else{
                break;
            }
        }while(larget<a.length)
    }
}
```


```C
struct Element {
int Protity;
int Handle;
};

```

## 思考题

- 6-1 插入法建堆
  - 
- 6-2 d叉堆的数组表示
  - a.数组中表示d叉堆，第一个节点A[1],第i个节点的子节点,从左到右:A[d(i-1)+2],A[d(i-1)+3],...,d[d(i-1)+d+2]
  - b.含n个元素的d叉堆高度为:$h=\log_d{n}$