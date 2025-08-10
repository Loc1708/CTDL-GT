#include <iostream>
using namespace std;

//Bài 6: Quản lý một danh sách có số phần tử khá lớn, biến động.Mỗi phần tử có kiểu int.Thường
//có nhu cầu truy suất phần tử đứng trước và phần tử đứng sau phần tử đang truy xuất. (Danh sách
//	liên kết kép)
//	a.Khai báo cấu trúc danh sách
struct Node
{
	int key;
	Node* next;
	Node* prev;
};
//	b.Viết thủ tục khai báo danh sách rỗng
struct DS
{
	Node* head;
	Node* tail;
};
void init(DS& meo)
{
	meo.head = nullptr;
	meo.tail = nullptr;
}
//	c.Xuất các phần tử trong danh sách.
void outLink(DS meo)
{
	Node* p = meo.head;
	while (p != nullptr)
	{
		cout << p->key;
		if (p->next != nullptr)
			cout << " --> ";
		p = p->next;
	}
}
//	d.Viết thủ tục thêm phần tử vào đầu danh sách
Node* createNode(int x)
{
	Node* p = new Node;
	p->key = x;
	p->next = nullptr;
	p->prev = nullptr;
	return p;
}

void addFirst(DS & meo, int x)
{
	Node* p = createNode(x);
	p->next = meo.head;
	if (meo.head == nullptr)
	{
		meo.tail = p;
	}
	else
	{
		meo.head->prev = p;
	}
	meo.head = p;
}

//	e.Viết thủ tục thêm một phần tử vào cuối danh sách.
void addLast(DS& meo, int x)
{
	Node* p = createNode(x);
	p->prev = meo.tail;
	if (meo.tail == nullptr)
		meo.head = p;
	else
	{
		meo.tail->next = p;
	}
	meo.tail = p;
}

//	f.Viết thủ tục xoá phần tử đầu danh sách
void delFirst(DS& meo)
{
	if (meo.head != nullptr)
	{
		Node* p = meo.head;
		meo.head = meo.head->next;
		if (meo.head == nullptr)
		{
			meo.tail = nullptr;
		}
		else
		{
			meo.head->prev = nullptr;
		}
		delete p;
		
	}
}
//	g.Viết thủ tục xoá phần tử cuối danh sách
void delLast(DS& meo)
{
	if( meo. tail != nullptr)
	{
		Node* p = meo.tail;
		meo.tail = meo.tail->prev;
		if (meo.tail == nullptr)
			meo.head = nullptr;
		else
		{
			meo.tail->next = nullptr;
		}
		delete p;
	}
	
}

//	h.Viết thủ tục tìm một phần tử trong danh sách.Nếu tìm thấy, xoá phần tử này
void findKeyanddel(DS& meo, int key)
{
	Node* q = meo.head;
	while (q != nullptr && q->key != key)
		q = q->next;
	if (q != NULL)
	{
		if (q->prev == nullptr) // nam o dau
		{
			delFirst(meo);
			
		}
		else if (q->next == nullptr) // nam o cuoi
		{
			delLast(meo);
			
		}
		else
		{
			q->next->prev = q->prev;
			q->prev->next = q->next;
			delete q;
			
		}
		

	}
		
}
//	i.Viết thủ tục tìm một phần tử có giá trị bằng với giá trị x hoặc gần nhất và lớn hơn phần tử x
//	nhập vào; Thêm một phần tử trước phần tử tìm thấy.

void addkeyfirst(DS& meo, int key, int add)
{
	Node* q = meo.head;
	while (q != nullptr && q->key != key)
		q = q->next;
	if (q != nullptr)
	{
		Node* p = createNode(add);
		if (q->prev == nullptr)
		{
			addFirst(meo,add);
		}
		else
		{
			p->prev = q->prev;
			q->prev->next = p;
			p->next = q;
			q->prev = p;
		}
	}

}

// them sau
void addKeyafter(DS& meo, int key, int add)
{
	Node* q = meo.head;
	while (q != nullptr && q->key != key)
		q = q->next;
	if (q != nullptr)
	{
		Node* p = createNode(add);
		if (q->next == nullptr)
		{
			addLast(meo, add);
		}
		else
		{
			p->next = q->next;
			q->next->prev = p;
			q->next = p;
			p->prev = q;
		}
	}
}


int main()
{
	DS meo;
	init(meo);
	//addFirst(meo, 2);
	//addFirst(meo, 9);
	//addFirst(meo, 1);
	//addFirst(meo, 5);

	addLast(meo, 2);
	addLast(meo, 9);
	addLast(meo, 1);
	addLast(meo, 5);
	
	findKeyanddel(meo, 1);
	
	addkeyfirst(meo, 5, 11);
	addKeyafter(meo,2, 100);
	
	outLink(meo);


	while (meo.head != nullptr)
	{
		delFirst(meo);
	}

	return 0;
}