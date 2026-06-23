#include <iostream>
#include <vector>

using namespace std;

const int VertexCount = 6;

int Graph[VertexCount][VertexCount] =
{
	//0 1 2 3 4 5
	 {0,1,0,1,0,0},
	 {1,0,1,1,0,0},
	 {0,1,0,0,0,0},
	 {1,1,0,0,0,0},
	 {0,0,0,0,0,1},
	 {0,0,0,0,1,0}
};

bool Visited[VertexCount] = { 0 };

void DFS(int Current);

void AllSearchDFS(int Current);

int IsAllVisited();

void SearchAll(int StartVertex);

int main()
{
	//AllSearchDFS(0);
	//SearchAll(4);

	return 0;
}

void DFS(int Current)
{
	cout << "방문 : " << Current << endl;
	Visited[Current] = true;
	for (int Next=0;Next< VertexCount;Next++)
	{
		if (Graph[Current][Next] == 0)
			continue;
		if (Visited[Next] == true)
			continue;
		DFS(Next);
	}
}

void AllSearchDFS(int Current)
{
	DFS(Current);
	while (IsAllVisited()!=-1)
	{
		DFS(IsAllVisited());
	}
}

int IsAllVisited()
{
	for (int i=0;i< VertexCount;i++)
	{
		if(Visited[i]==false)
			return i;
	}
	return -1;
}

void SearchAll(int StartVertex)
{
	for (int i = 0; i < VertexCount; i++)
	{
		int Current = (StartVertex + i) % VertexCount;
		if (Visited[Current] == true)
			continue;
		DFS(Current);
	}
}