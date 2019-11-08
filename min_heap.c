#include<stdio.h>
#include<stdlib.h>

HEAP_SIZE = 20;

struct Heap {
	int* arr; //heap array
	int count; //����
	int capacity; //���뷮
	int heap_type; // 0 �϶��� min heap , 1 �� ���� max heap
};
typedef struct Heap Heap;

Heap* CreateHeap(int capacity, int heap_type);
void insert(Heap* h, int key);
void print(Heap* h);//�� ��ü�� ���
void heapify_bottom_top(Heap* h, int index);
void heapify_top_bottom(Heap* h, int parent_node);
int PopMin(Heap* h);
void Swap(int* a, int* b);

int main() {
	int i;
	Heap* heap = CreateHeap(HEAP_SIZE, 0); //�ּ���
	if (heap == NULL) {
		printf("__Memory Issue____\n");
		return -1;
	}

	for (i = 9; i > 0; i--)
		insert(heap, i);

	print(heap);

	for (i = 9; i >= 0; i--) {
		printf(" Pop Minima : %d\n", PopMin(heap));
		print(heap);
	}
	return 0;
}

Heap* CreateHeap(int capacity, int heap_type) {
	Heap* h = (Heap*)malloc(sizeof(Heap)); //one is number of heap

	//�޸� �Ҵ� ���� ���� Ȯ��
	if (h == NULL) {
		printf("Memory Error!");
		return;
	}
	h->heap_type = heap_type;
	h->count = 0;
	h->capacity = capacity;
	h->arr = (int*)malloc(capacity * sizeof(int)); //����Ʈ ũ�� ����

	//�Ҵ翡 �����ߴ��� Ȯ��
	if (h->arr == NULL) {
		printf("Memory Error!");
		return;
	}
	return h;
}

void insert(Heap* h, int key) {
	//arr�� count�� ũ�⸦ �÷���, key���� ���� �߰�
	
	h->count += 1;
	h->arr[h->count - 1] = key;
	heapify_bottom_top(h, h->count - 1);
}

void heapify_bottom_top(Heap* h, int index) {
	// ������ �Ҷ����� ���ο� ���Ҹ� ������ ��忡 ����, sift-up �Ѵ�.��, �ڸ� ã���ֱ�

	int parent_idx = -1;

	if (index % 2 == 0) { parent_idx = (index / 2) - 1; }
	else { parent_idx = index / 2; }

	if (h->arr[parent_idx] > h->arr[index] && index != 0) 
	{ 
		Swap(&(h->arr[parent_idx]), &(h->arr[index]));
		heapify_bottom_top(h, parent_idx);
	}
}

void heapify_top_bottom(Heap* h, int parent_node) {
	// ������ �� ������ ������ ��带 ��Ʈ ���� �ڸ��� �ű�� , ��üũ�⸦ 1��ŭ ���Դϴ�. �׸��� ��Ʈ��带 sift-down �մϴ�. (����Լ��� �̿��մϴ�)

	int left = (parent_node * 2) + 1;
	int right = (parent_node * 2) + 2;
	int smallest = parent_node;

	if (left <= (h->count) - 1 && (h->arr[left]) < (h->arr[parent_node])) { smallest = left; }
	if (right <= (h->count) - 1 && (h->arr[right]) < (h->arr[smallest])) { smallest = right; }

	if (smallest != parent_node)
	{
		Swap(&(h->arr[parent_node]), &(h->arr[smallest]));
		heapify_top_bottom(h, smallest);
	}
}

int PopMin(Heap* h) {
	//���� ����� ���� "__Heap is Empty__"�� ����Ѵ�.
	// ���� �ּҰ��� pop ���ְ�, ù ��° ���� ���������� ��ü�ϰ� ������ ��带 ����
	int root_min = -1;
	
	if (h->count != 0) 
	{ 
		root_min = h->arr[0];
		h->arr[0] = h->arr[h->count - 1];
		h->count -= 1;
		heapify_top_bottom(h, 0);
	}
	else { printf("__Heap is Empty__\n"); }
	
	return root_min;
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(Heap* h) {
	int i;
	printf("_________�� ���__________\n");
	for (i = 0; i < h->count; i++) {
		printf("-> %d ", h->arr[i]);
	}
	printf("->__/\\__\n");
}
