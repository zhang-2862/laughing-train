#include <iostream>
using namespace std;
#define ElemType int
typedef struct LNode
{
	ElemType data;
	struct LNode * next;

}LNode,*LinkList;


//初始化
void InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
}

//创建单链表
void CreateList(LinkList& L) {//头插法
	//创建一个长度为n的单链表L，逆序插入
	int n;
	LNode* p;
	cout << "请输入创建的单链表长度： " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//打印链表
void printList(const LinkList& L) {
	LinkList p = L->next;
	
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//按值查找并删除
void byValueDel(LinkList& L, ElemType x) {
	LinkList p;
	LinkList q;
	p = L;//p用来指向上一个节点，q用来指向当前节点
	q = p->next;
	while (q != NULL) {
		if (q->data == x) {
			p->next = q->next;
			delete q;
			cout << "删除成功！" << endl;
			return;
		}
		p = q;
		q = q->next;
	}
	cout << "该链表中不存在值等于 " << x << " 的节点!" << endl;
}

//按位置查找并删除
void byPosDel(LinkList& L,int pos) {
	LinkList p = L;
	LinkList q;
	int cnt = 0;//计数器
	while (p!=NULL && cnt<pos-1)
	{
		p = p->next;
		cnt++;
	}
	if ( pos < 1 || !(p->next)) {
		cout << "删除位置不合法，删除失败" << endl;
		return;
	}
	q = p->next;
	p->next =q->next;
	delete q;
	cout << "删除成功" << endl;
}

int main() {
	int x;
	LinkList L;
	InitList(L);
	CreateList(L);
	cout << "创建的链表为： ";
	printList(L);

	cout << "请输入想要删除的值" << endl;
	cin >> x;
	byValueDel(L, x);
	printList(L);

	cout << "请输入想删除元素的位置" << endl;
	cin >> x;
	byPosDel(L, x);
	printList(L);

	system("pause");
	return 0;
}


