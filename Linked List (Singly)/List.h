#pragma once
#include"Header.h"
struct Node
{
	int reg_Num;
	string name;
	Node* next;
};

class Linked_List                     // class definition
{
public:
	void Insert_at_start();
	void Insert_after_certain_Node();
	void Insert_before_certain_Node();
	void Insert_at_End();
	void Display_List();
	void Search_node();
	void Delete_node();
private:
	Node* First_Node = NULL;
	Node* Last_Node = NULL;
};