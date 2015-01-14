# Leetcode_Interview_Collection
=============================
> *背景：题目来至leetcode 和其它面试书的例子；代码有借鉴和自己改写和写注释；
> *目的：用github 来记录自己；

--------------------------------------
## 001-->Judge_int_is_palindorme ##
[001-->Judge_int_is_palindorme][1]
![001-->Judge_int_is_palindorme][2]


----------
## 002-->Not_Use_add ##
[002-->Not_Use_add][3]
![002-->Not_Use_add][4]


----------
## 003-->全排列 ##
[003-->全排列递归解法][5]
![003-->全排列递归解法][6]
----------
[All_Permutations_Not_Repeat.cpp][7]
![All_Permutations_Not_Repeat][8]


----------
## 004->LRU ##
[004------>LRU][9]
![LRU_implementation][10]
>C++代码：
```c++
LRUCache(int capacity)
	{
		this->capacity = capacity ;
	}
--------------------------------------------
	int Get (int key )
	{
		if (cacheMap.find(key) == cacheMap.end() )
            return -1 ;

		cacheList.splice(cacheList.begin(), cacheList , cacheMap[key] ) ;

		cacheMap[key] = cacheList.begin();

		return cacheMap[key]->value;
	}
--------------------------------
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
----------------------------------------------
void Display()
{
    list<CacheNode>::iterator it;
    cout<<"The Current Element-->"<<endl;
    for (it = cacheList.begin() ; it != cacheList.end() ; it++)
        cout<<"\t\t\t"<<it->value<<endl;
}
```
>流程图：
```flow
st=>start: Start
op=>operation: Get(key)
cond=>condition: Yes or No?
sub=>subroutine: Set(key,value)
e=>end

st->op->cond
cond(yes)->e
cond(no)->sub->op
```


  [1]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/Judge_Int_Is_Palindorme.cpp
  [2]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/Image/Judge_int_is%20plindrome.JPG
  [3]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/Not_Use_add.C
  [4]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/Image/Not_use_add.JPG
  [5]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/%E5%85%A8%E6%8E%92%E5%88%97
  [6]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/Image/%E5%85%A8%E6%8E%92%E5%88%97.JPG
  [7]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/All_Permutations_Not_Repeat.cpp
  [8]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/Image/All_Permutation_Not_Repeat.JPG
  [9]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/LRU.CPP
  [10]: https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/Image/LRU_Implementation.JPG
