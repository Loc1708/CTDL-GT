#include <iostream>
using namespace std;


//Bài 7: Quản lý một danh sách liên kết vòng.
//a.Khai báo cấu trúc danh sách
struct Node
{
	int info;
	Node* next;
};
struct DS
{
	Node* head;
	Node* tail;
};

//b.Viết thủ tục khởi tạo danh sách rỗng
void init(DS& meo)
{
	meo.head = nullptr;
	meo.tail = nullptr;
}
//c.Viết thủ tục xuất các phần tử trong danh sách
void outLink(DS meo)
{
	Node* p = meo.head;
	while (p != nullptr)
	{
		cout << p->info;
		if(p->next != meo.head)
			cout << " --> ";
		p = p->next;
		if (p == meo.head)
			break;
	}
}
//d.Viết thủ tục thêm một phần tử vào đầu danh sách
Node* createNode(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = nullptr;
	return p;
}
void addcirFirst(DS& meo, int x)
{
	Node* p = createNode(x);
	if (meo.head == nullptr)
	{
		meo.tail = p;
	}
	else
	{
		p->next = meo.head;
	}
	meo.head = p;
	meo.tail->next = meo.head;
}
//e.Viết thủ tục xoá một phần tử trong đầu danh sách
void delFirst(DS& meo)
{
	if (meo.head != nullptr)
	{
		Node* q = meo.head;

		if (meo.head != meo.tail)
		{
			meo.head = meo.head->next;
			meo.tail->next = meo.head;

		}
		else
		{

			meo.tail = meo.head = nullptr;

		}
		delete q;
	}
}

//f.Viết thủ tục thêm một phần tử vào cuối danh sách
void addcirLast(DS& meo, int x)
{
	Node* p = createNode(x);
	if (meo.tail == nullptr)
	{
		meo.head = p;
		meo.tail = p;
		
	}
	else
	{
		meo.tail->next = p;
		meo.tail = p;
		meo.tail->next = meo.head;
		
	}
	
	
}
//g.Viết thủ tục xoá một phần tử trong cuối danh sách
void dellast(DS& meo)
{
	if (meo.tail != nullptr)
	{
		Node* q = meo.head;
		Node* parent = nullptr;
		while (q != meo.tail)
		{
			parent = q;
			q = q->next;

		}
		if (parent != nullptr)
		{
			meo.tail = parent;
			meo.tail->next = meo.head;

		}
		else
		{
			meo.tail = meo.head = nullptr;
		}
		delete q;
	}
}

//h.Viết thủ tục tìm một phần tử trong danh sách.Nếu tìm thấy, xoá phần tử này.
void timrxoa(DS& meo, int key)
{
	if (meo.head == nullptr)
		return;
	Node* p = meo.head;
	Node* parent = nullptr;
	while (p !=nullptr && p->info != key)
	{
		parent = p;
		p = p->next;
		if (p == meo.head)
			break;
	}
	if (p->info != key)
		return;
	
	if ( parent == nullptr)
			delFirst(meo);
	else if (p== meo.tail)
			dellast(meo);
	else
	{
		parent->next = p->next;
		delete p;
	}
		

	
	
}

int main()
{
	DS meo;
	init(meo);
	addcirLast(meo, 2);
	addcirLast(meo, 3);
	addcirLast(meo, 10);
	addcirLast(meo, 9);
	addcirLast(meo, 5);
	addcirLast(meo, 4);
	addcirLast(meo, 99);

	
	/*delFirst(meo);
	delFirst(meo);
	delFirst(meo);
	delFirst(meo);
	delFirst(meo);*/
	/*dellast(meo);*/
	
	
	
	
	timrxoa(meo, 10);
	

	outLink(meo);


	
	while (meo.head != nullptr)
	{
		delFirst(meo);
	}

	return 0;
}