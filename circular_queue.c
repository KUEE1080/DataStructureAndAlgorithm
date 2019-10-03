#include <stdio.h>
#define SIZE 5

#define FALSE 0 //C���� Boolean �ڷ����� ��� ����� ����
#define TRUE 1

int items[SIZE];
int front = -1, rear = -1; //�ʱ� front, rear��
int cnt_item = 0; //circular queue �ȿ� ��Ұ� � �ִ� �� ī���� �ϴ� ����

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
	if (isFull()) { printf("Queue�� ���� á���ϴ� \n\n"); }
	else
	{
		rear = (rear + 1) % SIZE;
		items[rear % SIZE] = element;
		cnt_item++;
		printf("Inserted -> %d \n", element);
	}
	
}
void deQueue()
{
	if (isEmpty()) { printf("Queue�� ������ϴ�! \n\n"); }
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
		printf("Front �� -> %d \n", front + 1);

		printf("Items ��� -> ");

		int i = front + 1;
		while (1)
		{
			printf("%d ", items[i]);
			if (i == rear) { break; }
			i = (i + 1) % SIZE;
		}

		printf("\n");
		printf("Rear �� -> %d \n\n", rear);
	}
	else { printf("Queue�� ������ϴ�! \n\n"); }


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
