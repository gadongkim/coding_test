//200118_BFS와 DFS
//백준 1260번

#include <stdio.h>

int n, m, v;
//n = 정점, m = 간선, v = 시작점
int visit_DFS[1001], visit_BFS[1001], arr[1001][1001], que[1001];

//후입선출 - stack
void DFS(int sn)
{
    //탐색을 시작하는 첫 정점부터 하나씩 출력한다
    printf("&d", sn);
    //출력한 정점을 방문 처리한다
    visit_DFS[sn] = 1;

    int i;
    //방문할 수 있는 정점 여러 개일 경우 정점 번호가 작은 것을 먼저 방문
    for(i=1; i<=n; i++){
        //시작점 start와 i 사이 간선이 존재하는 동시에 i가 아직 방문 처리 되어있지 않을 경우
        if(arr[sn][i]==1 && visit_DFS[i]=0) 
        DFS(i); //재귀함수
    }
    return;
}

//선입선출 - queue
void BFS(int sn)
{

    int i, pop, front=1, rear=1;

    //시작점을 출력, 방문처리
    printf("%d ", sn);
    que[rear]=sn;
    rear++;
	visit_BFS[sn]=1;

    //선입선출의 구조로 breath마다 노드 방문하기 위해
    while(front<rear){
        //front와 rear가 1 2, 2 3, 3 4 ... 이렇게 값이 변하면서 반복된다
        //부모노드를 pop에 집어넣는다                      
        pop=que[front];
        front++;
        //방문할 수 있는 정점 여러 개일 경우 정점 번호가 작은 것을 먼저 방문
        for(i=1; i<=n; i++){
        //부모노드 Pop과 자식노드 i 사이 간선이 있고 i가 아직 방문 처리 X일 경우
            if(arr[pop][i]==1 && visit_BFS[i]==0) {
            //i를 출력, 방문처리
            printf("&d",i);
            que[rear]=i;
            rear++;
            visit_BFS[i]==1;
            }
        }
    }
    return;
}

int main()
{
	printf("그래프 정점의 개수 : ");
	scanf("%d", &n);

	printf("\n그래프 간선의 개수 : ");
	scanf("%d", &m);

	printf("\n시작할 정점의 번호 : ");
	scanf("%d", &v);
	printf("\n");
	
	int i;
	for(i=1; i<=m; i++) {
		int a, b;
		printf("간선으로 연결된 두 정점의 번호 : ");
		scanf("%d %d", &a, &b);
		arr[a][b]=arr[b][a]=1; // 양방향
	}

	printf("\nDFS 수행 결과 : ");
	DFS(v);
	printf("\nBFS 수행 결과 : ");
	BFS(v);
	
	return 0;
}