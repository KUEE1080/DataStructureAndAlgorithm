#include <stdio.h>
#define SIZE 5

#define FALSE 0 //C언어에는 Boolean 자료형이 없어서 상수로 만듬
#define TRUE 1

int items[SIZE];
int front = -1, rear = -1; //초기 front, rear값
int cnt_item = 0; //circular queue 안에 요소가 몇개 있는 지 카운팅 하는 변수

int isFull()
{
	if(cnt_item == SIZE) { return TRUE; }
	else  { return FALSE; }
}
int isEmpty()
{
	if (cnt_item == 0) { return TRUE; }
	else { return FALSE; }
}

void enQueue(int element)
{
	if (isFull()) { printf("Queue가 가득 찼습니다 \n\n"); }
	else
	{
		rear = (rear + 1) % SIZE;
		items[rear] = element;
		cnt_item++;
		printf("Inserted -> %d \n", element);
	}
	
}
void deQueue()
{
	if (isEmpty()) { printf("Queue가 비었습니다! \n\n"); }
	else
	{
		front = (front + 1) % SIZE;
		cnt_item--;
		printf("Deleted element -> %d \n\n", items[front]);
	}

}
void display()
{
	if (isEmpty() == FALSE) 
	{ 
		printf("Front 값 -> %d \n", front + 1);

		printf("Items 출력 -> ");

		int i = front + 1;
		while (1)
		{
			printf("%d ", items[i]);
			if (i == rear) { break; }
			i = (i + 1) % SIZE;
		}

		printf("\n");
		printf("Rear 값 -> %d \n\n", rear);
	}
	else { printf("Queue가 비었습니다! \n\n"); }


}
int main()
{

	deQueue();

	enQueue(1);
	enQueue(2);
	enQueue(3);
	display();
	enQueue(10);
	enQueue(5);
	display();
	enQueue(6);
	display();
	deQueue();
	display();
	enQueue(5);
	display();
	deQueue();

	enQueue(8);
	display();
	return 0;
}
