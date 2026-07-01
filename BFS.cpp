//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
////BFS
////너비 우선 탐색
////핵심 = 다음 방문할 정점을 미리 기억해 놓기
////기억한 정점을 먼저 기억한 순서대로 방문 -> 선입선출
//
//using namespace std;
//
//const int VertexCount = 6;
//
//int Graph[VertexCount][VertexCount] =
//{
//	//0 1 2 3 4 5
//	 {0,1,0,1,0,0},
//	 {1,0,1,1,0,0},
//	 {0,1,0,0,0,0},
//	 {1,1,0,0,1,0},
//	 {0,0,0,1,0,1},
//	 {0,0,0,0,1,0}
//};
//
//bool Visited[VertexCount] = { 0 };
//
//int Distance[VertexCount] = { 0 }; // 시작 지점으로 부터 떨어진 거리 기록
//int Parent[VertexCount] = { 0 };   // 해당 정점의 부모를 기록
//
//void BFS(int Start);
//void PrintShortestPath(int Start, int Dest);
//
//int main()
//{
//	PrintShortestPath(0,5);
//	return 0;
//}
//
//void BFS(int Start)
//{
//	queue<int> VertexQueue;
//	VertexQueue.push(Start);
//	Visited[Start] = true;
//	Distance[Start] = 0;
//	Parent[Start] = 0;
//
//	while (!VertexQueue.empty())
//	{
//		int Current = VertexQueue.front();
//		//cout << "방문 :" << Current << ", 부모누구?: "<< Parent[Current] << ", 거리몇?: "<< Distance[Current]<< endl;
//		VertexQueue.pop();
//
//		for (int Next = 0; Next < VertexCount; Next++)
//		{
//			if (Graph[Current][Next] == 0)
//				continue;
//			if (Visited[Next] == true)
//				continue;
//
//			VertexQueue.push(Next);
//			Visited[Next] = true;
//			Parent[Next] = Current;
//			Distance[Next] = Distance[Current] + 1;
//		}
//	}
//}
//
//void PrintShortestPath(int Start, int Dest)
//{
//	BFS(Start);
//	if (Visited[Dest] == false)
//	{
//		cout << "목적지까지 이동할 수 없습니다." << endl;
//		return;
//	}
//
//	vector<int> Path;
//
//	//스타트 지점까지 반복
//	int Temp = Dest;
//	while (Temp != Start)
//	{
//		Path.push_back(Temp);
//		Temp = Parent[Temp];
//	}
//	Path.push_back(Start);
//
//	//Path 순서 뒤집기
//	reverse(Path.begin(), Path.end());
//
//	//출력
//	for (int i = 0; i < Path.size(); i++)
//	{
//		cout << Path[i];
//		if (i < Path.size() - 1)
//		{
//			cout << "->";
//		}
//	};
//	cout << endl;
//
//	//reverse 사용하지 않고 출력하는 방법
//	//for (int i = Path.size() - 1; i >= 0; i--)
//	//{
//	//	cout << Path[i];
//	//	if (i > 0) 
//	//	{
//	//		cout << "->";
//	//	}
//	//}
//	//cout << endl;
//	//End_reverse 사용하지 않고 출력하는 방법
//}