#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct Map
{
	int speed, cur_dir, size;
};
vector<Map> map[101][101];
vector<pair<int, pair<int, int>>> info;					// info에 (상어 크기, (행, 열)) 형태로 저장
int R, C, M, r, c, s, d, z, cur_place, ans;

void catch_shark(int cur_place)
{
	bool caught = false;								// 상어 잡으면 true
	for (int r = 1; r <= R && !caught; r++)
	{
		if (map[r][cur_place].size())					// 현재 열에서 1행부터 밑으로 살피며 해당 칸에 상어가 있을 경우
		{
			int shark = map[r][cur_place][0].size;
			ans += shark;
			map[r][cur_place].clear();					// 크기 더하고 해당 칸의 상어 제거
			for(int i = 0; i < (int)info.size(); i++)	// info에도 제거된 상어 제거해줘야 함!
				if (info[i].first == shark)
				{
					info.erase(info.begin() + i);
					caught = true;
					break;
				}
		}
	}
}

void move_shark()
{
	vector<Map> tmp;
	for (int i = 0; i < (int)info.size(); i++)									// 모든 상어 이동
	{
		tmp.push_back(map[info[i].second.first][info[i].second.second][0]);
		map[info[i].second.first][info[i].second.second].clear();				// 원래 상어 있던 자리 제거
		int sero_move = tmp[i].speed % ((R - 1) * 2);
		int garo_move = tmp[i].speed % ((C - 1) * 2);
		if (tmp[i].cur_dir < 3)													// 세로로 움직일 경우
		{
			for (int m = 0; m < sero_move; )
			{
				if (tmp[i].cur_dir == 1)
				{
					if (info[i].second.first - 1 >= 1)
					{
						info[i].second.first--;
						m++;
					}
					else
						tmp[i].cur_dir = 2;
				}
				else
				{
					if (info[i].second.first + 1 <= R)
					{
						info[i].second.first++;
						m++;
					}
					else
						tmp[i].cur_dir = 1;
				}
			}
		}
		else											// 가로로 움직일 경우
		{
			for (int m = 0; m < garo_move; )
			{
				if (tmp[i].cur_dir == 4)
				{
					if (info[i].second.second - 1 >= 1)
					{
						info[i].second.second--;
						m++;
					}
					else
						tmp[i].cur_dir = 3;
				}
				else
				{
					if (info[i].second.second + 1 <= C)
					{
						info[i].second.second++;
						m++;
					}
					else
						tmp[i].cur_dir = 4;
				}
			}
		}
	}

	for (int i = 0; i < (int)tmp.size(); i++)			// 각 상어를 새로운 위치로 다시 넣음
		map[info[i].second.first][info[i].second.second].push_back(tmp[i]);

	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++)
			while (map[r][c].size() > 1)				// map 모두 살펴서 상어가 2마리 이상 있는 곳은 한 마리로 줄임
			{
				if (map[r][c][0].size > map[r][c][1].size)
				{
					for (int i = 0; i < (int)info.size(); i++)
						if (info[i].first == map[r][c][1].size)		// info에 제거하려는 상어 제거
						{
							info.erase(info.begin() + i);
							break;
						}
					map[r][c].erase(map[r][c].begin() + 1);			// map에 해당 위치의 상어 제거
				}
				else
				{
					for (int i = 0; i < (int)info.size(); i++)
						if (info[i].first == map[r][c][0].size)
						{
							info.erase(info.begin() + i);
							break;
						}
					map[r][c].erase(map[r][c].begin());
				}					
			}
}

int Solve()
{
	while (cur_place <= C)
	{
		cur_place++;
		catch_shark(cur_place);
		move_shark();
	}
	return ans;
}

int main()
{
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		map[r][c].push_back({ s, d, z });
		info.push_back({ z, {r, c} });
	}
	printf("%d", Solve());
	return 0;
}