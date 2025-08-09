#include <iostream>
#include <ctime>
using namespace std;

//Bài 4: Quản lý một danh sách có số phần tử khá lớn, biến động.Mỗi phần tử có kiểu int. (Dùng
//	cấu trúc Danh sách liên kết đơn)
//	a.Khai báo cấu trúc danh sách.
struct Node
{
	int info;
	Node* next;
};

//	b.Viết thủ tục khởi tạo danh sách rỗng.

void init(Node*&head)
{
	head = nullptr;
}
//	c.Viết thủ tục xuất các phần tử trong danh sách.

void outLink(Node *head)
{
	Node* p = head;
	while (p != nullptr)
	{
		cout << p->info;
		if (p->next != nullptr)
			cout << " --> ";
		p = p->next;
	}
}

//	d.Viết thủ tục tìm một phần tử trong danh sách.
Node* findKey(Node* head, int key)
{
	Node* q = head;
	while (q != nullptr && q->info != key)
		q = q->next;
	return q;
}

//	e.Viết thủ tục thêm một phần tử vào đầu danh sách.

//b1. tao createNode
Node* createNode(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = nullptr;
	return p;
}

// tao ham them vao dau va sau cua danh sach

void addFirst(Node*& head, int x)
{
	Node* p = createNode(x);
	p->next = head;
	head = p;
}


//	f.Viết thủ tục xoá phần tử đầu danh sách.

void deletefirst(Node*& head)
{
	if (head != nullptr)
	{
		Node* q = head;
		head = head->next;
		q->next = nullptr;
		delete q;
	}
}

//	g.Viết thủ tục thêm một phần tử vào cuối danh sách.
void addLast(Node*& head, int x)
{
	Node* p = createNode(x);
	Node* q = head;
	if (head == nullptr)
		head = p;
	else
	{
		while (q->next != nullptr)
		{
			q = q->next;
		}
		q->next = p;
	}
}
//	h.Viết thủ tục xoá phần tử cuối danh sách.
void deletelast(Node*& head)
{
	if (head != nullptr)
	{
		Node* q = head;
		Node* parent = nullptr;
		while (q->next != nullptr)
		{
			parent = q;
			q = q->next;

		}
		if (parent == nullptr)
			head = nullptr;
		else
			parent->next = nullptr;
		q->next = nullptr;
		delete q;
	}
	
}
//	i.Viết thủ tục tìm một phần tử trong danh sách.Nếu tìm thấy, hãy xoá phần tử này.
void findAnddelete(Node* &head, int x)
{
	Node* q = head;
	Node* parent = nullptr;
	while (q != nullptr && q->info != x)
	{
		parent = q;
		q = q->next;
	}
	if (q != nullptr)
	{
		if (parent == nullptr)
		{
			deletefirst(head);
			return;
		}
		if (q->next == nullptr)
		{
			deletelast(head);
			return;
		}
		parent->next = q->next;
		q->next = nullptr;
		delete q;
	}
}
//	j.Từ danh sách trên chuyển thành danh sách có thứ tự. (*)
void sortList(Node*& head)
{
	for (Node* i = head; i ->next!= nullptr ; i = i ->next)
	{
		for (Node* j  = i -> next;  j != nullptr; j = j ->next)
		{
			if (i->info > j->info)
				swap(i->info, j->info);
		}
	}
}



int main()
{
	Node* head;
	init(head);
	addLast(head, 10);
	addLast(head, 7);
	addLast(head, 74);
	addLast(head, 72);
	addLast(head, 66);
	addLast(head, 36);
	addLast(head, 34);
	addLast(head, 9);

	cout << "xap sep mang!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";
	sortList(head);
	outLink(head);
	cout << endl;
	cout << "tim key !!!!!!!!!!!!!!!!!!!!!! \n";
	Node*q = findKey(head, 9);
	cout << q->info << endl;
	cout << "xoa bat ki \n";
	findAnddelete(head,66);
	outLink(head);
	
	


	while (head != nullptr)
	{
		deletefirst(head);
	}


	return 0;
}