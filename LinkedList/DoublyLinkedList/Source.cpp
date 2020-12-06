#include <iostream>
#include <stdio.h>
#include <conio.h>


using namespace std;


struct node
{

	int data;
	node* right, * left;

}*head, * tail, * n_tmp, * p_tmp;


void insertAtTheBegining(int value)
{
	node* square;
	square = new node;

	square->data = value;
	square->left = NULL;
	square->right = head;

	if (head == NULL)
	{
		tail = square;
	}

	else
	{
		head->left = square;
	}

	head = square;
}

void insertAtTheEnd(int value)
{
	node* square;
	square = new node;

	square->data = value;
	square->left = tail;
	square->right = NULL;

	if (tail == NULL)
	{
		head = square;
	}

	else
	{
		tail->right = square;
	}

	tail = square;
}

void showSquares()
{
	cout << "\n\nLikedList :\t";

	if (head != NULL)
	{
		node* next;
		next = new node;
		next = head;

		while (next != NULL)
		{
			cout << next->data << "   ";
			next = next->right;
		}
	}

	else
	{
		cout << "there is no LinkedList";
	}

	cout << endl << endl;
}

void insertAfterData(int value, int data)
{
	if (head != NULL) //this means your list is empty.
	{
		if (tail->data == data)
		{
			insertAtTheEnd(value);
		}

		else
		{
			node* next, * square;

			square = new node;
			next = head;
			square->data = value;

			while (next != NULL && next->data != data)
			{
				next = next->right;
			}

			if (next != NULL) //this means your value isn't excited.
			{
				square->right = next->right;
				square->left = next;
				next->right->left = square;
				next->right = square;
			}

			else
			{
				cout << "\nyour data isn't excited\n";
			}
		}

	}

	else
	{
		cout << "\nyour list is empty\n";
	}

}

void insertBeforeData(int value, int data)
{
	if (head != NULL)
	{
		if (head->data == data)
		{
			insertAtTheBegining(value);
		}

		else
		{
			node* next, * square;

			square = new node;
			next = head;
			square->data = value;

			while (next != NULL && next->data != data)
			{
				next = next->right;
			}

			if (next != NULL)
			{
				square->left = next->left;
				square->right = next;
				next->left->right = square;
				next->left = square;
			}
			else
			{
				cout << "\nyour data isn't excited\n";
			}
		}
	}

	else
	{
		cout << "\nyour list is empty\n";
	}
}

void deleteSquare(int value)
{
	if (head != NULL)
	{
		node* next;
		next = head;

		if (head->data == value && head == tail) // there is one memmber
		{
			head = head->right;
			tail = head;
			delete next;
		}

		else if (head->right->data == tail->data) // there are two memmbers
		{
			if (head->data == value)
			{
				head = head->right;
				head->left = NULL;
				delete next;
			}

			else if (tail->data == value)
			{
				node* square = new node;
				int tmp = head->data;

				square->data = tmp;
				square->right = NULL;
				square->left = NULL;

				delete next;

				head = square;
				tail = head;
			}
		}

		else
		{
			if (head->data == value)
			{
				head = head->right;
				head->left = NULL;
				delete next;
			}

			else if (tail->data == value)
			{
				node* square;

				square = tail->left;
				square->right = NULL;

				delete tail;

				tail = square;
			}

			else
			{
				while (next != NULL && next->data != value)
				{
					next = next->right;
				}


				if (next != NULL) //if (next == NULL) means we have nothing to delete.
				{
					if (next->right == NULL)
					{
						next->left->right = NULL;
						tail = next->left;
					}

					else
					{
						next->left->right = next->right;
						next->right->left = next->left;
					}
					delete next;
				}

				else
				{
					cout << "\nyour square isn't excited\n";
				}
			}

		}
	}

	else
	{
		cout << "\nyour list is empty\n";
	}
}

void searchSquare(int data)
{
	node* next;
	next = head;

	while (next != NULL && next->data != data)
	{
		next = next->right;
	}

	if (next == NULL)
		cout << "\nelement hasn't found.\n";
	else
		cout << "\nelement has found."
		<< "\nelement is: " << next->data
		<< "\nits address is :" << next
		<< "\n\n";
}

void updateData(int value, int data)
{
	if (head != NULL)
	{
		if (head->data == data)
		{
			head->data = value;
		}

		else
		{
			node* next;
			next = head;

			while (next != NULL && next->data != data)
			{
				next = next->right;
			}

			if (next != NULL) //if (next == NULL) means we have nothing to update.
			{
				next->data = value;
			}

			else
			{
				cout << "\nyour square isn't excited\n";
			}
		}
	}

	else
	{
		cout << "\nyour list is empty\n";
	}
}


void swapSquares(node* p, node* n)
{
	//there are seven states

	if (p == head && p->right == n) //for first two squares
	{
		if (n->right == NULL) //there are just two members
		{
			n->left = p->left;
			n->right = p;
			p->left = n;
			p->right = NULL;
			tail = p;
		}

		else
		{
			p->right = n->right;
			n->right->left = p;
			n->right = p;
			p->left = n;
		}

		head = n;
	}

	else
	{
		if (n->right == NULL && p->right == n) //for last two squares
		{
			n->left = p->left;
			p->left->right = n;
			n->right = p;
			p->left = n;
			p->right = NULL;
			tail = p;
		}

		else if (p == head && n->right != NULL) //for first square and n->link != NULL
		{
			node* tmp_n, * tmp_p;
			tmp_n = n->right;
			tmp_p = n->left;

			n->left->right = p;
			n->left = NULL;
			p->right->left = n;
			n->right->left = p;
			n->right = p->right;
			p->right = tmp_n;
			p->left = tmp_p;
			head = n;
		}

		else if (p != head && n->right == NULL) //for last square and p != start
		{
			node* tmp_p, * tmp_n;
			tmp_p = p->right;
			tmp_n = n->left;

			p->left->right = n;
			n->left->right = p;
			n->left = p->left;
			p->right->left = n;
			p->right = NULL;
			n->right = tmp_p;
			p->left = tmp_n;
			tail = p;
		}

		else if (p != head && n->right != NULL && p->right == n) //for two squares are beside each other at the middle of list +
		{
			n->left = p->left;
			p->left->right = n;
			p->right = n->right;
			n->right->left = p;
			n->right = p;
			n->right->left = n;

		}

		else if (p == head && n == tail) //for first square and last square
		{
			n->left->right = p;
			n->right = p->right;
			p->right->left = n;
			p->right = NULL;
			p->left = n->left;
			n->left = NULL;
			head = n;
			tail = p;
		}

		else if ((p != head && n != tail) || (n != head && p != tail)) // n is at the middle and p is at the middle, too and also, there is a distance between them +
		{
			node* tmp_p, * tmp_n;

			tmp_p = p->right;
			tmp_n = n->left;

			n->left->right = p;
			n->left = p->left;
			p->right->left = n;
			p->right = n->right;
			p->left->right = n;
			p->left = tmp_n;
			n->right->left = p;
			n->right = tmp_p;
		}
	}

	n_tmp = n;
	p_tmp = p;
}



void bubbleSort()
{
	if (head != NULL)
	{
		node* next, * prev;
		prev = head;

		while (prev != NULL)
		{
			next = prev->right;

			while (next != NULL)
			{
				if (next->data < prev->data)
				{
					swapSquares(prev, next);
					prev = n_tmp;
					next = p_tmp;
				}
				next = next->right;
			}

			prev = prev->right;
		}
	}

	else
	{
		cout << "\nyour list is empty\n";
	}
}

int main()
{
	//insertAtTheBegining();
	//insertAtTheEnd();
	//insertAfterData();
	//insertBeforeData();
	//deleteSquare();
	//searchSquare();
	//updateData();
	//showSquares();
	//bubbleSort();

	return 0;
}