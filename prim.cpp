#include<iostream>
using namespace std;
#define MAXNUM 200  
#define MAXCOST 1000000;

int graph[MAXNUM][MAXNUM];

void prim(int graph[MAXNUM][MAXNUM], int n){
	//prim�㷨������С������
	int lowcost[MAXNUM];
	int mst[MAXNUM];
	int i, j, min, minnum, sum;
	sum = 0;
	for(i = 2;i <= n;i++){
		lowcost[i] = graph[1][i];				//lowcost�д�Ŷ���1�ɴ���·������ 
		mst[i] = 1 ;							//��ʼ������1��Ϊ��ʼ�� 
	}
	mst[1] = 0;
	for(i = 2;i <= n;i++){
		min = MAXCOST;
		minnum = 0;
		for(j = 2;j <= n;j++){
			if(lowcost[j] < min && lowcost[j] != 0){
				min = lowcost[j];				//�ҳ�Ȩֵ��̵�·������ 
				minnum = j;						//�ҳ���С��num 
			}
		}
		cout << "<" << mst[minnum] << "," << minnum << "> = " << min << endl;
		sum += min;								//����СȨֵ֮�� 
		lowcost[minnum] = 0;					//�������·����ֵΪ0 
		for(j = 2;j <= n;j++){
			if(graph[minnum][j] < lowcost[j]){ //����һ��ֱ��Ķ������·������ 
				lowcost[j] = graph[minnum][j];
				mst[j] = minnum;
			}
		}
	}
	cout << "��СȨֵ֮��Ϊ��" << sum << endl;
}
int main()
{
	int i, j, k, V, E;
	int weight;
	cout<<"�����붥����ߵ�������"<<endl;
    cin >> V >> E;

	for(i = 1;i <= V;i++){//��ʼ��ͼ 
		for(j = 1;j <= V;j++){
			graph[i][j] = MAXCOST;
		}
	}
	cout<<"��������ߵ���ʼ�㡢�յ㡢Ȩ�أ�"<<endl;
	for(k = 0;k < E;k++){
		cin >> i >> j >> weight;
		graph[i][j] = weight;
		graph[j][i] = weight;
	}
	prim(graph, V);
	return 0;
}