#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
struct Node* temp = NULL;
void enqueue(int val)
{
	if (rear == NULL)
	{
		rear = (Node*)malloc(sizeof(Node));
		rear->data = val;
		front = rear;
		rear->next = front;
	}
	else
	{
		temp = (Node*)malloc(sizeof(Node));
		rear->next = temp;
		temp->data = val;
		temp->next = front;
		rear = temp;
	}

}
int dequeue()
{
	temp = front;
	if (front == NULL)
	{
		cout << " underflow " << endl;
		return -1;
	}
	else if (temp->next != front)
	{
		temp = temp->next;
		int val = front->data;
		free(front);
		front = temp;
		rear->next = front;
		return val;
	}
	else
	{
		int val = front->data;
		return val;
		free(front);
		front = NULL;
		rear = NULL;
	}
}
void display()
{
	temp = front;
	if (front == NULL && rear == NULL)
	{
		cout << " queue is empty " << endl;
		return;
	}
	cout << " queue elements are : " << endl;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != front);
	cout << endl;
}

int josephus(int Number_of_players, int Number_of_skip)
{
	for (int i = 1; i <= Number_of_players; i++)
	{
		enqueue(i);
	}
	while (Number_of_players > 1)
	{
		for (int i = 1; i < Number_of_skip; i++)
		{
			int data = dequeue();
			enqueue(data);
		}
		dequeue();
		Number_of_players--;
	}
	return dequeue();
}
int main()
{

	int Number_of_players;
	int Number_of_skip;
	cout << "Please enter number of players : ";
	cin >> Number_of_players;
	cout << endl;
	cout << "Please enter the increament counter : ";
	cin >> Number_of_skip;
	cout << endl;
	//index start from 1 
	int survivor = josephus(Number_of_players, Number_of_skip);
	cout << "The survivor in a circle queue of " << Number_of_players << " players with a counter of " << Number_of_skip << " is the player number : " << survivor << endl;
	return 0;

}
