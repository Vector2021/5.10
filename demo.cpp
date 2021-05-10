#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct node {
	//表示数据域
	int age;
	char name[20];
	//表示指针域
	struct node* next;
}Student;

//创建链表
Student* creatList(int n) {
	//在堆上动态申请一个头节点，一般头节点不存储数据。（如果在栈上申请的话，调用一次creat之后就会被释放掉）
	Student* head = new Student;
	//构造一个pre节点用来记录上一个节点，(每构造一个新的节点都需要上一个节点指向这个新创建的节点,pre最开始等于p的上一个节点也就是head节点)
	Student* pre = head;
	//构造节点
	for (int i = 0; i < n; i++)
	{
		Student* p = new Student; //创建n个节点
		printf("请输入%d个学生的姓名和年龄：", i + 1);
		cin >> p->name;
		cin >> p->age;
		
		pre->next = p;
		pre = p;
		//到最后需要加一个判断条件 迭代判断看是否到达最后一个节点
		p->next = NULL; 
	}
	return head;
}

int length(Student * head)
{
	Student* p = head->next;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

void InsterElement(Student* head,int index)
{
	if (index < 0 || index > length(head))
	{
		throw"Out of rang";
	}
		Student* pre = head;	
		for (int i = 0; i < index; ++i)
		{
			pre = pre->next;
		}			
		Student * newNode = new Student;
		cout << "请输入新节点的姓名和年龄：";
		cin >> newNode->name >> newNode->age;
		newNode->next = pre->next;
		pre->next = newNode;
	
}

void DeleteElement(Student* head, int index)
{
	if (index < 0 || index > length(head) - 1)
	{
		throw"Out of rang";
	}
	Student* pre = head;
	for (int i = 0; i < index; ++i)
	{
		pre = pre->next;
	}
	Student* p = pre->next;//这个p表示要被删除的节点
	pre->next = pre->next->next;
	delete p;
}

void display(Student* head)
{
	Student* p = head->next;
	while (p != NULL)
	{
		cout << p->name << "," << p->age << endl;
		p = p->next;
	}
}


int main()
{
	int n = 5;
	Student *head = creatList(n);
	//cout << length(head) << endl;
	//InsterElement(head, 0);
	int index = 0;
	cout << "请输入要删除节点的位置：";
	cin >> index;
	DeleteElement(head,index);
	display(head);
	return 0;
}
	

//class Solution {
//private:vector<vector<int>> T;
//public:
//    int maximumWealth(vector<vector<int>>& accounts) {
//        int m = accounts.size();
//        int n = accounts[0].size();
//        int num = 0;
//        vector<int> new_account[99];
//        for (int i = 0; i < m; ++i)
//        {
//            int temp = 0;
//            for (int j = 0; j < n; ++j)
//            {
//                temp += accounts[i][j];
//                new_account.push_back(temp);
//            }
//            //if(temp>num)
//            //num =temp;
//        }
//        sort(new_account.begin(), new_account.end());
//
//        return new_account(new_account[new_account.size() - 1]);
//        //return num;
//    }
//};


//template<template T>
////定义一个节点模板；
//struct Node {
//	T date;
//	Node* next;
//	Node() : next(nullptr) {}
//	Node(const T& d) : data(d), next(nullptr) {}
//};


//class A
//{
//public:
//    void PrintA()
//    {
//        cout << _a << endl;
//    }
//
//    void Show()
//    {
//        cout << "Show()" << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    Date* p = NULL;
//    p->PrintA();
//    p->Show();
//}    
//


//class Solution {
//public:
//    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//        int len = flowerbed.size();
//        int count = 0;
//        for (int i = 1; i < len - 1; ++i)
//        {
//            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
//                count += 1;
//            flowerbed[i] ^= 1;
//        }
//        if (count >= n)
//            return true;
//        return false;
//    }
//};
//int main()
//{
//    int flowerbed[5] = {1,0,0,0,1};
//    int n = 2;
//    return 0;
//}



//string ZH(string str)
//{
//	string new_str = "";
//	for (int i = 0; i <= str.length(); ++i)
//	{
//		if (str[i] == '_')
//			str[i + 1] -= 32;
//		else
//		    new_str.push_back(str[i]);
//	}
//	return new_str;
//}
//int main()
//{
//	string str;
//	while (cin >> str)
//		cout << ZH(str) << endl;
//	return 0;
//}


//#include<iostream>
//#pragma warning (disable:4996)
//using namespace std;
//class person
//{
//private:
//	char _name[20];
//	char _sex[3];
//	int _age;
//
//public:
//	void Printf()
//	{
//		cout << _name << " " << _sex << " " << _age << endl;
//	}
//	void showInfo(const char* name,const char* sex, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_sex, sex);
//		_age = age;
//	}
//
//};
//
//
//int main()
//{
//	person s;
//    s.showInfo("Llef","男",21);
//	s.Printf();
//	return 0;
//}


//struct L 
//{
//	char _name[20];
//	char _sex[3];
//	int _age;
//
//	void ID(const char* name,const char* sex,int age)
//	{
//		strcpy(_name, name);
//		strcpy(_sex, sex);
//		_age = age;
//
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _sex << " " << _age << endl;
//	}
//};
//int main()
//{
//	L s;
//	s.ID("ljc", "nan", 21);
//	return 0;
//
//}