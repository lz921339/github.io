
/*说明：输入顶点数，边数，依次输入顶点名，依次按 ‘入口顶点数字 出口顶点数字’ 格式输入边
 输出顶点的拓扑排序顺序
例：
5 6
a b c d e
0 3
0 4
1 2
2 3
1 3
3 4
*/
 
#include<iostream>
using namespace std;
#include<string.h>
typedef struct Arc
{
	int into;
	Arc* next;

}*Arcptr;
typedef struct Vex
{
	char ch;
	int front_num;
	Arc* first;
	Arc* front;
}*Vexptr;
typedef struct Graph
{
	Vex* vex;
	int vexnum;
	int arcnum;
	int *visit;
};
void CreateArc(Vexptr& vex, int n1, int n2);
void CreateGraph(Graph& G)
{
	
	cin >> G.vexnum;
	cin >> G.arcnum;
	G.vex = new Vex[G.vexnum];
	G.visit = new int[G.vexnum];
	memset(G.visit,0,sizeof(int)*G.vexnum);
	for (int i=0;i< G.vexnum;i++)
	{
		cin >> G.vex[i].ch;
		G.vex[i].first = NULL;
		G.vex[i].front = NULL;
		G.vex[i].front_num = 0;
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		int n1 ;
		int n2;
		cin >> n1 >> n2;
		
		CreateArc(G.vex,n1,n2);
	}
}
void CreateArc(Vexptr& vex,int n1,int n2)
{
	Arc* p= new Arc;
	p->into = n2;
	p->next = vex[n1].first;
	vex[n1].first = p;
	p = new Arc;
	p->into = n1;
	p->next = vex[n2].front;
	vex[n2].front = p;
	vex[n2].front_num++;
}
void DrawGraph(Graph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		Arc* p=G.vex[i].first;
		while (p!=NULL)
		{
			cout<<p->into<<" ";
			p = p->next;
		}
		cout <<G.vex[i].front_num<< endl;
	}
}
void TPinsert(Graph& G, int n1);
void TPsort(Graph& G)
{
	cout << "---------------------------------------------------------------------------" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vex[i].front_num==0&&!G.visit[i])
		{
			TPinsert( G,i);
			
		}
	}
	int leap = 0;
	for (int i=0;i< G.vexnum;i+=1)
	{
		if (!G.visit[i])
		{
			leap = 1;
			break;
		}
	}
	if (leap)
	{
		cout << "EXIST A CIRCLE " ;
	}
}
void TPinsert(Graph &G,int n1)
{
	cout << G.vex[n1].ch << ' ';
	G.visit[n1] = 1;
			Arc* p = G.vex[n1].first;
			while (p != NULL)
			{

				G.vex[p->into].front_num--;
				//cout <<G.vex[p->into].ch<<" " << G.vex[p->into].front_num <<endl;
				p = p->next;

			}
			for (int j = 0; j < G.vexnum; j += 1)
			{
				
				if (!G.visit[j])
				{
					if (G.vex[j].front_num == 0)
					{
						TPinsert(G, j);
					}
				}

			}

}

int main()
{
	Graph G;
	CreateGraph( G);
	//DrawGraph( G);
	TPsort( G);

}