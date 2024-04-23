#include <iostream>
using namespace std;
#define ElemType int
typedef struct LNode
{
	ElemType data;
	struct LNode * next;

}LNode,*LinkList;


//��ʼ��
void InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
}

//����������
void CreateList(LinkList& L) {//ͷ�巨
	//����һ������Ϊn�ĵ�����L���������
	int n;
	LNode* p;
	cout << "�����봴���ĵ������ȣ� " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//��ӡ����
void printList(const LinkList& L) {
	LinkList p = L->next;
	
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//��ֵ���Ҳ�ɾ��
void byValueDel(LinkList& L, ElemType x) {
	LinkList p;
	LinkList q;
	p = L;//p����ָ����һ���ڵ㣬q����ָ��ǰ�ڵ�
	q = p->next;
	while (q != NULL) {
		if (q->data == x) {
			p->next = q->next;
			delete q;
			cout << "ɾ���ɹ���" << endl;
			return;
		}
		p = q;
		q = q->next;
	}
	cout << "�������в�����ֵ���� " << x << " �Ľڵ�!" << endl;
}

//��λ�ò��Ҳ�ɾ��
void byPosDel(LinkList& L,int pos) {
	LinkList p = L;
	LinkList q;
	int cnt = 0;//������
	while (p!=NULL && cnt<pos-1)
	{
		p = p->next;
		cnt++;
	}
	if ( pos < 1 || !(p->next)) {
		cout << "ɾ��λ�ò��Ϸ���ɾ��ʧ��" << endl;
		return;
	}
	q = p->next;
	p->next =q->next;
	delete q;
	cout << "ɾ���ɹ�" << endl;
}

int main() {
	int x;
	LinkList L;
	InitList(L);
	CreateList(L);
	cout << "����������Ϊ�� ";
	printList(L);

	cout << "��������Ҫɾ����ֵ" << endl;
	cin >> x;
	byValueDel(L, x);
	printList(L);

	cout << "��������ɾ��Ԫ�ص�λ��" << endl;
	cin >> x;
	byPosDel(L, x);
	printList(L);

	system("pause");
	return 0;
}


