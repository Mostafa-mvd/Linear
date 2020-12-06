#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct node
{

	int data;
	node* link;

}*start, * n_tmp, * p_tmp;


void insertAtTheBegining(int value)
{
	node* square;
	square = new node;

	square->data = value;

	if (start == NULL)
	{
		square->link = NULL;
	}

	else
	{
		square->link = start;
	}

	start = square;
}

void insertAtTheEnd(int value)
{
	node* next;
	next = start;

	node* last;
	last = new node;

	if (next != NULL)
	{
		node* last_plus_one;
		last_plus_one = new node;

		while (next != NULL)
		{
			last = next;
			next = next->link;
		}

		last_plus_one->link = NULL;
		last_plus_one->data = value;
		last->link = last_plus_one;
	}

	else
	{
		last->data = value;
		last->link = start;
		start = last;
	}
}

void insertAfterData(int value, int data)
{
	node* next, * square;

	square = new node;

	next = start;

	if (next != NULL) //this means your list is empty.
	{
		square->data = value;

		if (next->data == data) //for first item
		{
			square->link = next->link;
			next->link = square;
		}

		else
		{
			while (next != NULL && next->data != data)
			{
				next = next->link;
			}

			if (next != NULL) //this means your value isn't excited.
			{
				square->link = next->link;
				next->link = square;
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
	node* next, * square, * last;

	next = start;

	if (next != NULL)
	{
		square = new node;
		last = new node;
		square->data = value;

		if (next->data == data)
		{
			square->link = next;
			start = square;
		}

		else
		{
			while (next != NULL && next->data != data)
			{
				last = next;
				next = next->link;
			}

			if (next != NULL)
			{
				last->link = square;
				square->link = next;
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

void searchSquare(int data)
{
	node* next;
	next = start;

	while (next != NULL && next->data != data)
	{
		next = next->link;
	}

	if (next == NULL)
		cout << "\nelemet hasn't found.\n";
	else
		cout << "\nelemet has found."
		<< "\nelement is: " << next->data
		<< "\nits address is :" << next
		<< "\n\n";
}

void deleteSquare(int value)
{
	node* next, * last;

	next = start;
	last = new node;

	if (next != NULL)
	{
		if (next->data == value)
		{
			start = start->link;
			delete next;
		}

		else
		{
			while (next != NULL && next->data != value)
			{
				last = next;
				next = next->link;
			}

			if (next != NULL) //if (next == NULL) means we have nothing to delete.
			{
				last->link = next->link;
				delete next;
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

void updateData(int value, int data)
{
	node* next;

	next = start;

	if (next != NULL)
	{
		if (next->data == data)
		{
			next->data = value;
		}

		else
		{
			while (next != NULL && next->data != data)
			{
				next = next->link;
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

void showSquares()
{
	node* next;
	next = new node;
	next = start;

	cout << "\n\nLikedList :\t";

	if (next != NULL)
	{
		while (next != NULL)
		{
			cout << next->data << "   ";
			next = next->link;
		}
	}

	else
	{
		cout << "there is no LinkedList";
	}

	cout << endl << endl;
}


void reverseList()
{
	node* square, * prev, * next;

	next = start;

	if (next == NULL)
	{
		cout << "\nyour list is empty\n";
	}

	else
	{
		prev = NULL;

		while (next != NULL)
		{
			square = prev;
			prev = next;
			next = next->link;
			prev->link = square;

		}
		start = prev;
	}
}

void swapSquares(node* p, node* n)
{
	//there are seven states

	if (p == start && p->link == n) //for first two squares
	{
		if (n->link == NULL) //there are just two members
		{
			node* tmp;
			tmp = new node;

			tmp->data = p->data;
			n->link = tmp;
			tmp->link = NULL;
			p_tmp = tmp;

			delete p;
		}

		else
		{
			p->link = n->link;
			n->link = p;
			p_tmp = p;
		}

		start = n;
		n_tmp = n;
	}

	else
	{
		node* prev_p, * prev_n, * item_p, * item_n, * tmp;

		if (n->link == NULL && p->link == n) //for last two squares
		{
			item_p = start;
			prev_p = new node;

			while (item_p != p)
			{
				prev_p = item_p;
				item_p = item_p->link;
			}

			p->link = NULL;
			n->link = p;
			prev_p->link = n;
		}

		else if (p == start && n->link != NULL) //for first square and n->link != NULL
		{
			prev_n = new node;
			item_n = start;

			while (item_n != n)
			{
				prev_n = item_n;
				item_n = item_n->link;
			}

			tmp = p->link;
			p->link = n->link;
			n->link = tmp;
			start = n;
			prev_n->link = p;
		}

		else if (p != start && n->link == NULL) //for last square and p != start
		{
			prev_n = new node;
			prev_p = new node;
			item_n = start;
			item_p = start;

			while (item_n != n)
			{
				prev_n = item_n;
				item_n = item_n->link;
			}

			while (item_p != p)
			{
				prev_p = item_p;
				item_p = item_p->link;
			}

			n->link = p->link;
			prev_p->link = n;

			p->link = NULL;
			prev_n->link = p;
		}

		else if (p->link == n) //for two squares are beside each other at the middle of list
		{
			prev_p = new node;
			item_p = start;

			while (item_p != p)
			{
				prev_p = item_p;
				item_p = item_p->link;
			}

			p->link = n->link;
			n->link = p;
			prev_p->link = n;

		}

		else if (p == start && n->link == NULL) //for first square and last square
		{
			prev_n = new node;
			item_n = start;

			while (item_n != n)
			{
				prev_n = item_n;
				item_n = item_n->link;
			}

			n->link = p->link;
			start = n;
			prev_n->link = p;
			p->link = NULL;
		}

		else // n is at the middle and p is at the middle, too and also, there is a distance between them
		{
			prev_n = new node;
			prev_p = new node;
			item_n = start;
			item_p = start;

			while (item_n != n)
			{
				prev_n = item_n;
				item_n = item_n->link;
			}

			while (item_p != p)
			{
				prev_p = item_p;
				item_p = item_p->link;
			}

			tmp = n->link;
			n->link = p->link;
			prev_p->link = n;

			p->link = tmp;
			prev_n->link = p;
		}

		n_tmp = n;
		p_tmp = p;
	}


}



void bubbleSort()
{
	node* next, * prev;
	prev = start;

	if (prev != NULL)
	{

		while (prev != NULL)
		{
			next = prev->link;

			while (next != NULL)
			{
				if (next->data < prev->data)
				{
					swapSquares(prev, next);
					prev = n_tmp;
					next = p_tmp;
				}
				next = next->link;
			}

			prev = prev->link;
		}
	}

	else
	{
		cout << "\nyour list is empty\n";
	}
}

int main()
{
	//these fuctions need value, you have to give arguments to them.

	//insertAtTheBegining();
	//insertAtTheEnd();
	//insertAfterData();
	//insertBeforeData();
	//updateData();
	//deleteSquare();
	//searchSquare();
	//reverseList();
	//bubbleSort();
	//showSquares();

	(void)_getch(); //ignore return value of _getch()

	return 0;
}