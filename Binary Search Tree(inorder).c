#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAX_SIZE 100
#define MAX_NAME 15

#define LEFT 1
#define RIGHT 2

int Direction = 0;

// treePointer, nd 정의

typedef struct NODE {
	int score;
	char name[MAX_NAME];
	struct NODE* leftChild, * rightChild;
} Node;

typedef Node* treePointer;

// 함수 정의
void inorder(treePointer ptr);
void insertNode(treePointer* node, int key);
treePointer nodeSearch(treePointer root, int key);

// 중순위 운행 – 재귀 호출
void inorder(treePointer ptr) {
	if (ptr != NULL) {
		inorder(ptr->leftChild);
		printf("%d %s \n", ptr->score, ptr->name);
		inorder(ptr->rightChild);
	}
}


// 트리에 노드를 추가
void insertNode(treePointer* node, int key, char* str) {
	treePointer newNode; //= nodeSearch(*node, key);
	newNode = (treePointer)malloc(sizeof(Node));

	newNode->score = key;
	strcpy(newNode->name, str);
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	treePointer final_node = nodeSearch(*node, key);
	if(Direction == LEFT)
		final_node->leftChild = newNode;
	else if(Direction == RIGHT)
		final_node->rightChild = newNode;
	
	// ptr ; Node->child = newNode
}

// 새로운 노드가 삽입될 위치를 search
treePointer nodeSearch(treePointer root, int key) {
	
	treePointer search_node = root;

	while (1)
	{
		if (search_node->score < key) {
			if (search_node->rightChild != NULL)
			{
				search_node = search_node->rightChild;
			}
			else
			{
				//search_node = search_node->rightChild;
				Direction = RIGHT;
				break;
			}
		}
		else {
			if (search_node->leftChild != NULL)
			{
				search_node = search_node->leftChild;
			}
			else
			{
				//search_node = search_node->leftChild;
				Direction = LEFT;
				break;
			}
		}
	}
	return search_node;
}

// 메인 함수
int main() {
	char file_name[MAX_SIZE];
	char inputName[MAX_NAME];
	int inputScore;

	printf("Enter file name to open (ex : input.txt) : ");
	scanf("%s", file_name);		// 사용자에게 읽을 file을 입력 받음

	FILE* inFile = NULL;
	inFile = fopen(file_name, "r+");	// file open

	int loop;
	fscanf(inFile, "%d", &loop);	// 몇 개의 input이 들어오는지에 대한 값을 파일에서 읽어옴

	fscanf(inFile, "%d", &inputScore);
	fscanf(inFile, "%s", inputName);	// root node의 값
	loop--;

	treePointer rootNode;
	rootNode = (treePointer)malloc(sizeof(Node));	// malloc으로 rootNode 동적할당
	rootNode->score = inputScore;
	strcpy(rootNode->name, inputName);
	rootNode->leftChild = NULL;
	rootNode->rightChild = NULL;		// root node 값 설정. leftChild와 rightChild는 NULL로 초기화

	while (loop--) {
		fscanf(inFile, "%d", &inputScore);
		fscanf(inFile, "%s", inputName);	// 각 줄의 score와 name을 파일에서 읽어옴

		insertNode(&rootNode, inputScore, inputName);	//새로 만든 node를 트리에 삽입
	}

	printf("\n(1) In-order Traversal : 중순위 운행 결과\n");
	inorder(rootNode);	// 중순위 운행 결과 출력
	//printf("\n(2) Level-order Traversal : 레벨순위 운행 결과\n");
	//levelOrder(rootNode);	// 레벨 순위 운행 결과 출력

	printf("\n");

	fclose(inFile);		// file close
	return 0;
}

