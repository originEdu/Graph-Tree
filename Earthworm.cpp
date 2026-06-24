#include <iostream>

using namespace std;

int dir[4][2] = {
	//X  Y
	{-1, 0}, //Left
	{ 1, 0}, //Right
	{ 0, 1}, //Down
	{ 0,-1}  //Up
};


const int MaxSize = 50;

bool Visited[MaxSize][MaxSize] = {0};

int Map[MaxSize][MaxSize] = {0};

int M = 0; //가로
int N = 0; //세로

void DFS(int CurrentX, int CurrentY)
{
	Visited[CurrentX][CurrentY] = true;
	for (int l = 0; l < 4; l++)
	{
		int X = CurrentX + dir[l][0];
		int Y = CurrentY + dir[l][1];
		if (X < 0 || X >= M || Y < 0 || Y >= N)
		{
			continue;
		}

		if (Map[X][Y] == 0)
		{
			continue;
		}

		if (Visited[X][Y] == true)
		{
			continue;
		}

		if (Map[X][Y] == 1)
		{
			Visited[X][Y] = true;
			DFS(X,Y);
		}
	}
}

int main()
{

	int K = 0; //배추가 심어져있는 위치
	int CabbageX = 0; //배추 X좌표
	int CabbageY = 0; //배추 Y좌표
	int EarthwormCount = 0; //지렁이 수
	scanf_s("%d %d %d", &M,&N,&K);
	for (int i=0;i<K;i++)
	{
		scanf_s("%d %d",&CabbageX,&CabbageY);
		Map[CabbageX][CabbageY] = 1;
	}

	int CurrentX = 0; //현재 X위치
	int CurrentY = 0; //현재 Y위치

	int X = 0; //탐색을 위한 X값
	int Y = 0; //탐색을 위한 Y값

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == 1 && (Visited[i][j]==false)) {
				EarthwormCount++; 
				DFS(i, j);        
			}
		}
	}
	
	cout << EarthwormCount << endl;

	return 0;
}