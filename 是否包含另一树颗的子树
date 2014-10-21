#include <iostream>
using namespace std;
struct  Tree
{
	int data ;
	struct Tree * Left ;
	struct Tree * Right ;
};
typedef struct Tree * TreeNode ;

bool MatchTree(TreeNode r1 , TreeNode r2)
{
	if (r1 == NULL && r2 == NULL) //都为空树
		return true;
	if (r1->data != r2->data)
		return false;
	return (MatchTree(r1->Left,r2->Left) && MatchTree(r1->Right , r2->Right ) );
}

bool SubTree(TreeNode r1 , TreeNode r2)
{
	if (r1 == NULL)
		return false;
	if ( r1->data == r2->data )
        if ( MatchTree(r1,r2) )
            return true ;
    return ( SubTree(r1->Left , r2) || SubTree(r1->Right , r2) ) ;
}


bool ContainsTree(TreeNode t1 , TreeNode t2)
{
	if ( t2 == NULL) //t2为空树，必定为t1的子树；
		return true;
	return SubTree(t1,t2);
}
TreeNode Insert_Node(TreeNode Tmp , int item )
{

	if (Tmp == NULL)
	{
		Tmp = new struct Tree;
        Tmp->data = item;
		Tmp->Left = Tmp->Right = NULL;
	}
	else if ( Tmp->data > item )
	{
		Tmp->Left = Insert_Node(Tmp->Left , item);
	}
	else if (Tmp->data < item )
	{
		Tmp->Right = Insert_Node(Tmp->Right ,item);
	}
	else
		;// The same vaule ,DO NOTHING !
	return Tmp;
}

void PrintTree (TreeNode T) //递归调用 前序遍历
{
    if (T != NULL )
        {
            //printf("%d \t" , T->data );
            PrintTree(T->Left);
            printf("%d \t" , T->data ); //中序遍历 二叉搜索树，成递增序列,
            PrintTree(T->Right);
        }
}


int main()
{
TreeNode root;
root = NULL;
int a[] = {5,3,7,4,6};
int len = sizeof(a) / sizeof(a[0]);
for(int i = 0 ; i < len ; i++ )
root =Insert_Node(root,a[i]);
PrintTree(root);
return 0;
}
