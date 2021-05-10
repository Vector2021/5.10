#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct node {
	//��ʾ������
	int age;
	char name[20];
	//��ʾָ����
	struct node* next;
}Student;

//��������
Student* creatList(int n) {
	//�ڶ��϶�̬����һ��ͷ�ڵ㣬һ��ͷ�ڵ㲻�洢���ݡ��������ջ������Ļ�������һ��creat֮��ͻᱻ�ͷŵ���
	Student* head = new Student;
	//����һ��pre�ڵ�������¼��һ���ڵ㣬(ÿ����һ���µĽڵ㶼��Ҫ��һ���ڵ�ָ������´����Ľڵ�,pre�ʼ����p����һ���ڵ�Ҳ����head�ڵ�)
	Student* pre = head;
	//����ڵ�
	for (int i = 0; i < n; i++)
	{
		Student* p = new Student; //����n���ڵ�
		printf("������%d��ѧ�������������䣺", i + 1);
		cin >> p->name;
		cin >> p->age;
		
		pre->next = p;
		pre = p;
		//�������Ҫ��һ���ж����� �����жϿ��Ƿ񵽴����һ���ڵ�
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
		cout << "�������½ڵ�����������䣺";
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
	Student* p = pre->next;//���p��ʾҪ��ɾ���Ľڵ�
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
	cout << "������Ҫɾ���ڵ��λ�ã�";
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
////����һ���ڵ�ģ�壻
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
//    s.showInfo("Llef","��",21);
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