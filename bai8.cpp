#include <iostream>
using namespace std;
#define M 100

//Bài 8: Quản lý một stack có tối đa 100 phần tử, mỗi phần tử trong stack có kiểu int.

//a.Khai báo cấu trúc stack
 struct Stack
{
	int top;
	int a[M];

};
//b.Viết thủ tục khỏi tạo stack rỗng
 void init(Stack& s)
 {
	 s.top = -1;
 }
//c.Viết thủ tục xét stack rỗng
 bool isEmpty(Stack& s)
 {
	 return s.top == -1;
 }
//d.Viết thủ tục xét stack đầy
 bool isFull(Stack& s)
 {
	 return s.top == M - 1;
 }
//e.Viết thủ tục thêm một phần tử vào stack
 void pushStack(Stack& s, int x)
 {
	 if (!isFull(s))
	 {
		 s.a[++s.top] = x;
	 }
 }

//f.Viết thủ tục xoá một phần tử trong stack và xuất ra màn hình

 int getStack(Stack s)
 {
	 return s.a[s.top];
 }


 void popstack(Stack& s)
 {
	 if (!isEmpty(s))
		 s.top--;
 }



int main()
{
	Stack s;
	init(s);
	pushStack(s, 10);
	pushStack(s, 6);
	pushStack(s, 4);
	pushStack(s, 8);
	pushStack(s, 99);

	while (!isEmpty(s))
	{
		cout << getStack(s) << endl;
		popstack(s);
	}

	return 0;
}