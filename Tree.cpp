#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T> 
class TreeNode
{
public:
	TreeNode(const T& Value) :Data(Value)
	{
	}
	~TreeNode()
	{
		for (TreeNode<T>* Child : Children)
		{
			delete Child;
		}
	}

	T Data;
	vector<TreeNode<T>*> Children;
};

TreeNode<string>* MakeTree();

void PrintTree(TreeNode<string>* Root);
void PrintTreeOrder(TreeNode<string>* Root);

int GetHight(TreeNode<string>* Root);
int GetHightTwoParm(TreeNode<string>* Root, int PreHight);



int main()
{
    TreeNode<string>* Root = MakeTree();
    PrintTree(Root); //깊이우선
    PrintTreeOrder(Root); //너비우선  A B C 순으로
    cout << MaxDepth << endl; //외국방식(?)
    cout << GetHight(Root) << endl; //인자 1개
    cout << GetHightTwoParm(Root, 0) << endl; //인자 2개
    
    delete Root;
	return 0;
}

TreeNode<string>* MakeTree()
{
    TreeNode<string>* Root = new TreeNode<string>("A");
    {
        TreeNode<string>* NodeB = new TreeNode<string>("B");
        {
            TreeNode<string>* NodeD = new TreeNode<string>("D");
            TreeNode<string>* NodeE = new TreeNode<string>("E");
            {
                TreeNode<string>* NodeI = new TreeNode<string>("I");
                NodeE->Children.push_back(NodeI);
            }
            TreeNode<string>* NodeF = new TreeNode<string>("F");

            NodeB->Children.push_back(NodeD);
            NodeB->Children.push_back(NodeE);
            NodeB->Children.push_back(NodeF);
        }

        TreeNode<string>* NodeC = new TreeNode<string>("C");
        {
            NodeC->Children.push_back(new TreeNode<string>("G"));
            NodeC->Children.push_back(new TreeNode<string>("H"));
        }

        Root->Children.push_back(NodeB);
        Root->Children.push_back(NodeC);
    }

    return Root;
}

int CurrnetDepth = 0;
int MaxDepth = 0;
void PrintTree(TreeNode<string>* Root)
{
    cout << Root->Data << endl;
    if (Root->Children.empty())
    {
        if (CurrnetDepth > MaxDepth)
        {
            MaxDepth = CurrnetDepth;
        }
        CurrnetDepth = CurrnetDepth - 1;
    }
    for (TreeNode<string>* Child : Root->Children)
    {
        CurrnetDepth++;
        PrintTree(Child);
    }

}

int GetHightTwoParm(TreeNode<string>* Root, int PreHight)
{
    int Hight = PreHight;

    for (TreeNode<string>* Child : Root->Children)
    {
        int NewHight = GetHightTwoParm(Child, PreHight + 1);
        if (NewHight > Hight)
        {
            Hight = NewHight;
        }
    }

    return Hight;
}

int GetHight(TreeNode<string>* Root)
{
    int Hight = 0;

    for (TreeNode<string>* Child : Root->Children)
    {
        int ChildHight = GetHight(Child) + 1;
        if (ChildHight > Hight)
        {
            Hight = ChildHight;
        }
    }

    return Hight;
}

void PrintTreeOrder(TreeNode<string>* Root)
{
    queue<TreeNode<string>*> q;

    q.push(Root);

    while (!q.empty())
    {
        TreeNode<string>* Current = q.front();
        q.pop();

        cout << Current->Data << endl;

        for (TreeNode<string>* Child : Current->Children)
        {
            q.push(Child);
        }
    }
}