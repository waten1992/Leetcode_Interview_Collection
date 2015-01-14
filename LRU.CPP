/*
	LRU 算法的实现；
	函数：
			Get(key); //查询是否在高速缓存中
			Set(key , value); //如存在更新为头结点，不存在则有OS调度新页面进来，若缓存满了就淘汰最末尾的节点
	STL:
		list -> cacheList; 一个双链表,存储高速缓存key和key的关系
		unordered_map -> cacheMap; 一个无序的 MAP，存储看key 和value关系 ，每次查保持O(1);
*/
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache
{
private:
	struct  CacheNode
	{
		int key ;
		int value ;
		CacheNode (int k , int v):key(k) , value(v)
		{}
	};
	list<CacheNode> cacheList ;
	unordered_map <int , list<CacheNode>::iterator> cacheMap ;
	int capacity ;
public:
	LRUCache(int capacity)
	{
		this->capacity = capacity ;
	}
	int Get (int key )
	{
		if (cacheMap.find(key) == cacheMap.end() )
            return -1 ;

		cacheList.splice(cacheList.begin(), cacheList , cacheMap[key] ) ;

		cacheMap[key] = cacheList.begin();

		return cacheMap[key]->value;
	}

	void Set (int key , int value)
	{
		if(cacheMap.find(key) == cacheMap.end())
		{
			if(cacheList.size() == capacity)
			{
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}

			cacheList.push_front(CacheNode(key,value));
			cacheMap[key] = cacheList.begin();
		}
		else
		{
			cacheMap[key]->value = value ;
			cacheList.splice(cacheList.begin() , cacheList ,cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
void Display()
{
    list<CacheNode>::iterator it;
    cout<<"The Current Element-->"<<endl;
    for (it = cacheList.begin() ; it != cacheList.end() ; it++)
        cout<<"\t\t\t"<<it->value<<endl;
}


};

int main()
{
    int i = 0 ;
    LRUCache Solution(4) ;
    for(i = 0 ; i<4 ; i++) //冷启动，赋初值为10 11 12 13
        Solution.Set(i,10+i);

    Solution.Display(); //遍历cache 中的数组
    cout<<"Get the key not existed -------->"<<endl;
    cout<<Solution.Get(20); //加入一个不再高速缓存的页面
    Solution.Set(1,20); // 由OS调度这个页面

    cout<<endl<<"OS handler after----->"<<endl;
    Solution.Display(); //遍历cache 中的数组
return 0;
}

/*
The Answer as follow----->

The Current Element-->
                        13
                        12
                        11
                        10
Get the key not existed -------->
-1
OS handler after----->
The Current Element-->
                        20
                        13
                        12
                        10

Process returned 0 (0x0)   execution time : 0.016 s
Press any key to continue.

*/