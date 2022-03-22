#include "Header.h"
#include "List.h"

int main()
{
	int main_option;
	Linked_List L;
	do
	{
	Enter_again:
		cout << "\n"
			<< "1. Add user\n"
			<< "2. Search user\n"
			<< "3. Delete user\n"
			<< "4. Display all users data\n"
			<< "0. BACK\n";
		cin >> main_option;
		system("cls");

		switch (main_option)
		{
		case 1:
			int add_option;
			do
			{
			Enteragain:
				cout << "\n"
					<< "1. Add at the Start\n"
					<< "2. Add at the End\n"
					<< "3. Add after a specfic user\n"
					<< "4. Add before a specfic user\n"
					<< "0. BACK\n";

				cin >> add_option;
				system("cls");
				switch (add_option)
				{
				case 1:
					L.Insert_at_start();
					cout << "\nUser has been added";
					_getch();
					system("cls");
					break;

				case 2:
					L.Insert_at_End();
					cout << "\nUser has been added";
					_getch();
					break;

				case 3:
					L.Insert_after_certain_Node();
					cout << "\nUser has been added";
					_getch();
					system("cls");
					break;

				case 4:
					L.Insert_before_certain_Node();
					cout << "\nUser has been added";
					_getch();
					system("cls");
					break;

				case 0:
					break;

				default:
					cout << "Enter from specified.\n";
					goto Enteragain;
				}
				break;

		case 2:
			L.Search_node();
			_getch();
			system("cls");
			break;

		case 3:
			L.Delete_node();
			_getch();
			system("cls");
			break;

		case 4:
			L.Display_List();
			_getch();
			system("cls");
			break;

		case 0:
			break;

		default:
			cout << "\nEnter again and from specified\n";
			goto Enter_again;
			} while (add_option != 0);
		}
	} while (main_option != 0);
	_getch();
	system("cls");
}