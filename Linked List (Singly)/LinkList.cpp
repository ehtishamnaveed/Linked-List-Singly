#include "Header.h"
#include "List.h"
void Linked_List::Insert_at_start()            // insert in start
{
	if (First_Node == NULL)
	{
		Node* newNode = new Node();
		cout << "Enter Registration Number: ";
		cin >> newNode->reg_Num;
		cin.ignore(INT_MAX, '\n');
		cout << "Enter User Name: ";
		cin.clear();
		getline(cin, newNode->name);
		newNode->next = NULL;
		First_Node = newNode;
		Last_Node = newNode;
	}
	else
	{
		Node* newNode = new Node();
		cout << "Enter Registration Number: ";
		cin >> newNode->reg_Num;
		cin.ignore(INT_MAX, '\n');
		cout << "Enter User Name: ";
		cin.clear();
		getline(cin, newNode->name);
		newNode->next = First_Node;
		First_Node = newNode;
	}
}

//////////////////
void Linked_List::Insert_after_certain_Node()
{
	if (First_Node == NULL)
		cout << "\nList is empty";
	else
	{
		Display_List();
		int req_reg_num;
		cout << "\nEnter User ID: ";
		cin >> req_reg_num;

		Node* temp = First_Node;
		while (temp != NULL)
		{
			if (temp->reg_Num == req_reg_num)
			{
				cout << "Following User will be added after the user with ID '" << req_reg_num << "'\n";
				Node* newNode = new Node();
				cout << "Enter Registration Number: ";
				cin >> newNode->reg_Num;
				cin.ignore(INT_MAX, '\n');
				cout << "Enter User Name: ";
				cin.clear();
				getline(cin, newNode->name);
				newNode->next = temp->next;
				temp->next = newNode;
				break;
			}
			temp = temp->next;
		}
	}
}

//////////////////
void Linked_List::Insert_before_certain_Node()
{
	if (First_Node == NULL)
		cout << "\nList is empty";
	else
	{
		Display_List();
		int req_reg_num;
		cout << "\nEnter User ID: ";
		cin >> req_reg_num;

		Node* temp = First_Node;
		Node* prev_node = First_Node;
		while (temp != NULL)
		{
			if (temp == First_Node && temp->reg_Num == req_reg_num)
			{
				cout << "Following User will be added after the user with ID '" << req_reg_num << "'\n";
				Node* newNode = new Node();
				cout << "Enter Registration Number: ";
				cin >> newNode->reg_Num;
				cin.ignore(INT_MAX, '\n');
				cout << "Enter User Name: ";
				cin.clear();
				getline(cin, newNode->name);
				newNode->next = First_Node;
				First_Node = newNode;
				break;
			}
			else
			{
				if (temp->reg_Num == req_reg_num)
				{
					Node* newNode = new Node();
					cout << "Enter Registration Number: ";
					cin >> newNode->reg_Num;
					cin.ignore(INT_MAX, '\n');
					cout << "Enter User Name: ";
					cin.clear();
					getline(cin, newNode->name);
					newNode->next = temp;
					prev_node->next = newNode;
					break;
				}
			}
			prev_node = temp;
			temp = temp->next;
		}
	}
}

//////////////////
void Linked_List::Insert_at_End()            // insert in end
{
	if (First_Node == NULL)
	{
		Node* newNode = new Node();
		cout << "Enter Registration Number: ";
		cin >> newNode->reg_Num;
		cin.ignore(INT_MAX, '\n');
		cout << "Enter User Name: ";
		cin.clear();
		getline(cin, newNode->name);
		newNode->next = NULL;
		First_Node = newNode;
		Last_Node = newNode;
	}
	else
	{
		Node* newNode = new Node();
		cout << "Enter Registration Number: ";
		cin >> newNode->reg_Num;
		cin.ignore(INT_MAX, '\n');
		cout << "Enter User Name: ";
		cin.clear();
		getline(cin, newNode->name);
		newNode->next = NULL;
		Last_Node->next = newNode;
		Last_Node = newNode;
	}
}

//////////////////
void Linked_List::Search_node()
{
	Node* temp = First_Node;
	int req_reg_num;

	if (First_Node == NULL)
		cout << "\nNot found";

	else
	{
		cout << "\nEnter the Registrartion ID: ";
		cin >> req_reg_num;

		while (temp != NULL)
		{
			if (temp->reg_Num == req_reg_num)
			{
				cout << "\nMatch Found\n";
				cout << "Registration Number: " << temp->reg_Num << "\n";
				cout << "User Name: " << temp->name << "\n";
				break;
			}
			temp = temp->next;
		}
		cout << "\nItem not found";
	}
}

//////////////////
void Linked_List::Delete_node()
{
	Node* temp = First_Node;
	Node* prev_node = First_Node;
	int req_reg_num, found = 0;

	if (First_Node == NULL)
		cout << "\nNot found";

	while (temp != NULL)
	{
		cout << "\nEnter the Registrartion ID: ";
		cin >> req_reg_num;

		if (temp == First_Node && temp->reg_Num == req_reg_num)
		{
			found++;
			cout << "\nMatch Found\n";
			cout << "Registration Number: " << temp->reg_Num << "\n";
			cout << "User Name: " << temp->name << "\n";
			char option;

		Input:
			cout << "\nNOTE: Following will be deleted (y/n): ";
			cin >> option;

			switch (option)
			{
			case 'y':  case 'Y':
				First_Node = temp->next;
				delete temp;
				break;

			case 'n':  case 'N':
				break;

			default:
				cout << "\nEnter y/n";
				goto Input;
			}
		}
		else
		{
			if (temp->reg_Num == req_reg_num)
			{
				found++;
				cout << "\nMatch Found\n";
				cout << "Registration Number: " << temp->reg_Num << "\n";
				cout << "User Name: " << temp->name << "\n";
				char option;

			Input_Again:
				cout << "\nNOTE: Following will be deleted (y/n): ";
				cin >> option;

				switch (option)
				{
				case 'y':  case 'Y':
					prev_node->next = temp->next;
					delete temp;
					break;

				case 'n':  case 'N':
					break;

				default:
					cout << "\nEnter y/n";
					goto Input_Again;
				}
			}
		}
		prev_node = temp;
		temp = temp->next;
	}
	if (found == 0)
		cout << "\nData do not exists in list";
}

//////////////////
void Linked_List::Display_List()            // display the whole list
{
	int a = 0;
	Node* temp = First_Node;
	if (First_Node == NULL)
		cout << "\n\nList is Empty";
	else
	{
		while (temp != NULL)
		{
			a++;
			cout << " " << a << " Node\n";
			cout << "Registration Number: " << temp->reg_Num << "\n";
			cout << "User Name: " << temp->name << "\n\n";
			temp = temp->next;
		}
		cout << "Total records found: " << a;
	}
}