#include <vector>
#include <queue>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <limits.h>
#include <cereal\types\vector.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>
#include <time.h>
using namespace std;
class Graph
{
private:
	struct Point
	{
		int x;
		int y;
	};
	vector< vector<int> > D;
	vector< vector<int> > S;
	bool *Visited;
public:
	vector< vector<int> > matrix;
	int *BF;
	int counterBF;
	int *DF;
	int counterDF;
	vector< Point> nodePosition;
	vector<int> paths;
	int before=0;
private:
	void DepthFirst(int node)
	{
		Visited[node] = true;
		DF[counterDF] = node;
		counterDF++;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[node][i] != 32767 && matrix[node][i] != -1 && matrix[node][i] != 0)
			{
				if (Visited[i] == false)
				{
					Visited[i] = true;
					DepthFirst(i);
				}
			}
		}
	}
	void fetsh(int k)
	{
		vector< vector<int>> D1(matrix.size(), vector<int>(matrix.size()));
		vector< vector<int>> S1(matrix.size(), vector<int>(matrix.size()));
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = i; j < matrix.size(); j++)
			{
				if (i == j)
				{
					D1[i][j] = -1;
					S1[j][i] = S[j][i];

				}
				else if (i == k || j == k)
				{
					D1[i][j] = D[i][j];
					D1[j][i] = D[i][j];
					S1[j][i] = S[j][i];
					S1[i][j] = S[i][j];
				}
				else if (D[i][j]> D[i][k] + D[k][j])
				{
					D1[i][j] = D[i][k] + D[k][j];
					D1[j][i] = D[i][k] + D[k][j];
					S1[i][j] = k;
					S1[j][i] = k;
				}
				else
				{
					D1[i][j] = D[i][j];
					D1[j][i] = D[i][j];
					S1[j][i] = S[j][i];
					S1[i][j] = S[i][j];
				}
			}
		}
		S = S1;
		D = D1;
	}
public:
	template <class Archive>
	void serialize(Archive & ar)
	{
		for (int i = 0; i < nodePosition.size(); i++)
			ar(nodePosition[i].x, nodePosition[i].y);
		ar(D, S, matrix, paths);
	}
	int getDistance(int start, int arrival)
	{

		vector<int> other;
		paths.clear();
		paths.push_back(start);
		paths.push_back(arrival);
		for (int i = 0; i < paths.size() - 1; i++)
		{
			
			if (S[paths[i]][paths[i + 1]] != paths[i + 1])
			{
				for (int j = 0; j < paths.size(); j++)
				{
					if (i + 1 == j)
					{
						other.push_back(S[paths[i]][paths[i + 1]]);

					}
					other.push_back(paths.at(j));
				}
				paths = other;
				other.clear();
				i --;
			}
		}
		return D[start][arrival];
	}
	void DepthFirstStart(int node)
	{
		counterDF = 0;
		DF = new int[matrix.size()];
		Visited = new bool[matrix.size()];
		for (int i = 0; i < matrix.size(); i++)
			Visited[i] = false;
		DepthFirst(node);
	}
	void addNode(POINT p)
	{
		Point p1;
		p1.x = p.x;
		p1.y = p.y;
		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i].push_back(0);
			D[i].push_back(0);
			S[i].push_back(0);

		}
		
		D.push_back(vector<int>(matrix.size() + 1));
		S.push_back(vector<int>(matrix.size() + 1));
		matrix.push_back(vector<int>(matrix.size() + 1));
		nodePosition.push_back(p1);

	
	}
	void addLength(int x, int y, int length)
	{
		if (length == 32767)
			return;
		matrix[x][y] = length;
		matrix[y][x] = length;
	}
	void adjust(int n1, int n2,int adder)
	{
		if (nodePosition[n1].x > nodePosition[n2].x)
		{
			nodePosition[n1].x -= adder;
			nodePosition[n2].x += adder;
		}
		else
		{
			nodePosition[n1].x += adder;
			nodePosition[n2].x -= adder;
		}
		if (nodePosition[n1].y > nodePosition[n2].y)
		{
			nodePosition[n1].y -= adder;
			nodePosition[n2].y += adder;
		}
		else
		{
			nodePosition[n1].y += adder;
			nodePosition[n2].y -= adder;
		}
	}
	void adjustdistances(int n1, int n2)
	{
		int d = calculatedistance(n1, n2);
		int original = matrix[n1][n2] * 50;
		if (d > original){
			while (d > original)
			{
				adjust(n1, n2,5);
				d = calculatedistance(n1, n2);
			}
			return;
		}
		else while (d < original)
		{
			d = calculatedistance(n1, n2);
			adjust(n2, n1,-5);
		}
		
	}
	double calculatedistance(int n1,int n2)
	{
		return sqrt(pow(nodePosition[n1].x - nodePosition[n2].x, 2.0) + pow(nodePosition[n1].y - nodePosition[n2].y, 2.0));
	}
	void undirect()
	{
		for (int i = 0; i <matrix.size(); i++)
		{
			for (int j = 0; j < matrix.size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][j] = 32767;
				}
			}
		}
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = i; j < matrix.size(); j++)
			{
				if (i == j)
					D[i][j] = -1;
				else if (matrix[i][j] <= matrix[j][i])
				{
					D[j][i] = matrix[i][j];
					D[i][j] = matrix[i][j];


				}
				else
				{
					D[j][i] = matrix[j][i];
					D[i][j] = matrix[j][i];

				}
			}
		}

	}
	void Floyd()
	{
		undirect();
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix.size(); j++)
			{
				if (i == j)
					S[j][i] = -1;
				else
					S[j][i] = i;
			}
		}
		for (int k = 0; k < matrix.size(); k++)
		{
			fetsh(k);
		}


	}
	void BreadthFirst(int sNode)
	{
		select `hospital1`.`patient`.`title` AS `title`,`hospital1`.`patient`.`insurance` AS `insurance`,`hospital1`.`patient`.`last_visit` AS `last_visit`,`hospital1`.`patient`.`employmentstatus` AS `employmentstatus`,`hospital1`.`patient`.`bloodtype` AS `bloodtype`,`hospital1`.`record`.`type_id_record` AS `type_id_record`,`hospital1`.`record`.`value` AS `value`,`hospital1`.`record`.`date` AS `date`,`hospital1`.`record`.`historyorexamination` AS `historyorexamination`,`hospital1`.`user`.`fullname` AS `fullname`,`hospital1`.`user`.`age` AS `age`,`hospital1`.`user`.`gender` AS `gender`,`hospital1`.`user`.`phone` AS `phone`,`hospital1`.`user`.`address` AS `address` from ((`hospital1`.`patient` join `hospital1`.`record`) join `hospital1`.`user`) where ((`hospital1`.`patient`.`id` = `hospital1`.`record`.`patient_id`) and (`hospital1`.`user`.`id` = `hospital1`.`patient`.`user_id`))
		undirect();
		queue<int> q;
		BF = new int[matrix.size()];
		Visited = new bool[matrix.size()];
		q.push(sNode);
		Visited[sNode] = true;
		counterBF = 0;

		while (!q.empty())
		{
			int node = q.front();
			BF[counterBF] = node;
			counterBF++;
			q.pop();
			for (int i = 0; i < matrix.size(); i++)
			{
				if ((matrix[node][i] == 32767) || matrix[node][i] == 0 || (Visited[i] == true))
					continue;
				Visited[i] = true;

				q.push(i);
			}

		}
	}
	void deletGraph()
	{
		delete Visited;
		D.clear();
		S.clear();
		matrix.clear();
		delete BF;
		delete DF;
		nodePosition.clear();
		paths.clear();
	}

};
