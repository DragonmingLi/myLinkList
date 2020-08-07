#include <iostream>
using namespace std;
class myNode
{
public:
	myNode *next;  //next node
	int value;  //node's value
	myNode();  //without parameter constructor function
	myNode(int val):value(val),next(NULL){};  //with a parameter constructor function
	~myNode(){};  //the destructor function
	void createList(myNode &Head);  //create a link list
	int delNode(myNode *Head,int target);  //delete the target where have the target
	void printNode(myNode *Node);  //print the link list
	int insertNode(myNode *Node,int index,int val);  //insert the value at the index
	void updateNode(myNode *Head,int target,int val);  //update the value where have the target
};

void myNode::createList(myNode &Head)
{
	myNode *Tail ;
	Tail = &Head;
	for (int i = 0; i < 9; i++)
	{
		myNode *tmp = new myNode(i);
		Tail->next = tmp;
		Tail = Tail->next;
	}
}

int myNode::delNode(myNode *Head,int target)
{
	myNode *cur = Head->next;
	myNode *pre = Head;
	int index = 0;
	while (cur)
	{
		if (cur->value == target)
		{
			//index++;
			pre->next = cur->next;
			cur = pre->next;
			//break;
		}
		else
		{
			index++;
			pre = cur;
			cur = cur->next;
		}
	}
	return ++index;
}

void myNode::printNode(myNode *Head)
{
	myNode * cur = Head;
	while (cur)
	{
		cout << cur->value << " "; 
		cur = cur->next;
	} 
	cout << endl;
}

int myNode::insertNode(myNode *Head,int index,int val)
{
	myNode * cur = Head;
	int count = 0;
	while (cur)
	{
		if (count == index - 1)
		{
			myNode *tmp =  new myNode(val);
			tmp->next = cur->next;
			cur->next = tmp;
			break;
		}
		else
		{
			count++;
			cur = cur->next;
		}
	} 
	return ++count;
}

void myNode::updateNode(myNode *Head,int target,int val)
{
	myNode * cur = Head;
	int count = 0;
	while (cur)
	{
		if (cur->value == target)
		{
			cur->value = val;
		}
		cur = cur->next;
	} 
}

int main()
{
	myNode Head(-1);
	Head.createList(Head);
	Head.printNode(Head.next);
	Head.insertNode(Head.next,4,4);
	Head.printNode(Head.next);
	Head.updateNode(Head.next,4,10);
	Head.printNode(Head.next);
	int index = Head.delNode(Head.next,10);
	cout << index << endl;
	Head.printNode(Head.next);
	return 0;
}
