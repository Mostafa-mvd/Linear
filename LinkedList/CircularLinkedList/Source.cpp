#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct node
{

	int data;
	node* link;

}*start, * n_tmp, * p_tmp;

//start pointer is the last node ******
//address of start->link is the last added node

void insertAtTheBegining(int value)
{
	node* square;
	square = new node;

	square->data = value;

	if (start == NULL)
	{
		square->link = square;
		start = square;
	}

	else
	{
		node* tmp = start->link;
		start->link = square; //address of start->link will change
		square->link = tmp;
	}
}


void insertAtTheEnd(int value)
{
	node* square;
	square = new node;

	square->data = value;

	if (start == NULL)
	{
		square->link = square;
		start = square;
	}

	else
	{
		node* tmp = start->link;
		start->link = square;
		square->link = tmp;
		start = square;
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
		do
		{
			next = next->link;
			cout << next->data << "   ";
		} while (next != start);

	}

	else
	{
		cout << "there is no LinkedList";
	}

	cout << endl << endl;
}

void insertAfterData(int value, int data)
{
	node* next, * square;

	square = new node;

	next = start;

	if (next != NULL) //this means your list is empty.
	{
		square->data = value;

		if (next->data == data) //for start
		{
			insertAtTheEnd(value);
		}

		else
		{
			do
			{
				next = next->link;

			} while (next != start && next->data != data);


			if (next->data == data) //this means your value isn't excited.
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


		if (next->link->data == data) //for start->link
		{
			insertAtTheBegining(value);
		}

		else
		{
			do
			{
				last = next;
				next = next->link;

			} while (next != start && next->data != data);


			if (next->data == data)
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
			do
			{
				next = next->link;

			} while (next != start && next->data != data);

			if (next != start) //if (next == start) means we have nothing to update.
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

void deleteSquare(int value)
{
	node* next, * last;

	next = start;
	last = new node;

	if (next != NULL)
	{
		if (next->link->data == value)
		{
			node* tmp;
			tmp = next->link->link;
			delete next->link;
			start->link = tmp;
		}

		else
		{
			do
			{
				last = next;
				next = next->link;

			} while (next != start && next->data != value);

			if (next->data == value) //if (next->data != value) means we have nothing to delete.
			{
				last->link = next->link;

				if (next == start) //if start will delete
				{
					start = last;
				}


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

void searchSquare(int data)
{
	node* next;
	next = start;

	if (next->data != data)
	{
		do
		{
			next = next->link;
		} while (next != start && next->data != data);
	}


	if (next == start && next->data != data)
		cout << "\nelemet hasn't found.\n";

	else
		cout << "\nelemet has found."
		<< "\nelement is: " << next->data
		<< "\nits address is :" << next
		<< "\n\n";
}

void reverseList()
{
	node* square, * prev, * next, * first;

	next = start;
	square = new node;

	if (next == NULL)
	{
		cout << "\nyour list is empty\n";
	}

	else if (next->link != next)
	{
		first = start->link; //first pointer
		prev = start;
		next = next->link;

		while (next != start)
		{
			square = next;
			next = next->link;
			square->link = prev;
			prev = square;
		}

		next->link = square;
		start = first;
	}
}


void swapSquares(node* p, node* n)
{
	//there are seven states

	if (p == start->link && p->link == n) //for first two squares
	{
		if (n->link == p) //there are just two members
		{
			node* tmp;
			tmp = new node;

			tmp->data = p->data;
			n->link = tmp;
			tmp->link = n;

			delete p;

			start = tmp;
			p_tmp = tmp;
		}

		else
		{
			p->link = n->link;
			n->link = p;
			start->link = n;
			p_tmp = p;
		}

		n_tmp = n;
	}

	else
	{
		node* prev_p, * prev_n, * item_p, * item_n, * tmp;

		if (p == start->link && n == start) //for first square and last square
		{
			prev_n = new node;
			item_n = p;

			while (item_n != n)
			{
				prev_n = item_n;
				item_n = item_n->link;
			}

			n->link = p->link;
			start = p;
			prev_n->link = p;
			p->link = n;
		}

		else if (n == start && p->link == n) //for last two squares
		{
			item_p = n;
			prev_p = new node;

			while (item_p != p)
			{
				prev_p = item_p;
				item_p = item_p->link;
			}

			p->link = n->link;
			n->link = p;
			prev_p->link = n;
			start = p;
		}

		else if (p == start->link && n != start) //for first square and n != start
		{
			prev_n = new node;
			item_n = p;

			while (item_n != n)
			{
				prev_n = item_n;
				item_n = item_n->link;
			}

			tmp = p->link;
			p->link = n->link;
			n->link = tmp;
			start->link = n;
			prev_n->link = p;
		}

		else if (p != start && n == start) //for last square and p != start
		{
			prev_n = new node;
			prev_p = new node;
			item_n = p;
			item_p = n;

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
			start = p;
		}

		else if (p->link == n) //for two squares are beside each other at the middle of list
		{
			prev_p = new node;
			item_p = n;

			while (item_p != p)
			{
				prev_p = item_p;
				item_p = item_p->link;
			}

			p->link = n->link;
			n->link = p;
			prev_p->link = n;

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

	if (start != NULL)
	{
		prev = start->link;

		while (prev != start)
		{
			next = prev;

			do
			{
				next = next->link;

				if (next->data < prev->data)
				{
					swapSquares(prev, next);
					prev = n_tmp;
					next = p_tmp;
				}

			} while (next != start);

			prev = prev->link;
		}
	}

	else
	{
		cout << "\nyour list is empty\n";
	}
}


node* getNodeWithData(int data)
{
	node* square, * next;
	square = new node;
	next = start;

	do
	{
		next = next->link;

		if (next->data == data)
		{
			square = next;
			return square;
		}

	} while (next != start);

	return square;
}


void replaceSquare(int data1, int data2)
{
	node* square1, * square2;

	square1 = new node;
	square2 = new node;

	square1 = getNodeWithData(data1);
	square2 = getNodeWithData(data2);

	//example:
	//-10   -2   1   2   3   -9   6   10   4   70   -1

	if (data1 == square1->data && data2 == square2->data)
	{
		if (data1 > data2)
			// value of square2 is bigger than value of square1 so, square2 is p and square1 is n
			//for example data1 is 10 and data2 1 -> 10 > 1
			swapSquares(square1, square2);

		else
			// value of square1 is bigger than value of square2 so, square1 is p and square2 is n
			//for example data1 is 10 and data2 2 -> 10 < 1
			swapSquares(square2, square1);
	}

	else if (data1 != square1->data && data2 != square2->data)
		cout << "Values haven't found";

	else if (data1 != square1->data)
		cout << "data1 hasn't found";

	else
		cout << "data2 hasn't found";

}

int main()
{
	//insertAtTheBegining();
	//insertAtTheEnd();
	//updateData();
	//deleteSquare(70);
	//insertAfterData(6, 7);
	//insertBeforeData(-1, 7);
	//searchSquare(20);
	//showSquares();
	//reverseList();
	//bubbleSort();
	//replaceSquare(7, 70);

	(void)_getch(); //ignore return value of _getch()

	return 0;
}