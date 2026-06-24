#include <iostream>
#include <queue>

//BFS
//너비 우선 탐색
//핵심 = 다음 방문할 정점을 미리 기억해 놓기
//기억한 정점을 먼저 기억한 순서대로 방문 -> 선입선출

using namespace std;

const int VertexCount = 6;

int Graph[VertexCount][VertexCount] =
{
	//0 1 2 3 4 5
	 {0,1,0,1,0,0},
	 {1,0,1,1,0,0},
	 {0,1,0,0,0,0},
	 {1,1,0,0,1,0},
	 {0,0,0,1,0,1},
	 {0,0,0,0,1,0}
};

bool Visited[VertexCount] = { 0 };

void BFS(int Start)
{
	queue<int> VertexQueue;
	VertexQueue.push(Start);
	Visited[Start] = true;

	while (!VertexQueue.empty())
	{
		int Current = VertexQueue.front();
		cout << "방문 :" << Current << endl;
		VertexQueue.pop();

		for (int Next = 0; Next < VertexCount; Next++)
		{
			if (Graph[Current][Next] == 0)
				continue;
			if (Visited[Next] == true)
				continue;

			VertexQueue.push(Next);
			Visited[Next] = true;
		}
	}
}

int main()
{
	BFS(0);
	return 0;
}