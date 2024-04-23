#include <iostream>
#include <string.h>
using namespace std;

void itoa(int x, char str[]) {
	bool flag=true;
	if (x < 0) {
		flag = false;//���x�Ǹ����򽫱�־λ����Ϊ�٣�����xת��Ϊ��ֵ
		x = -x;
	}
	int num = 0;
	while (x != 0) {
		str[num] = char(x%10)+'0';
		x /= 10;
		num++;
	}
	if (!flag) {
		str[num] = '-';
		num++;
	}
	for (int j = 0; j < num / 2; j++) {	// ��ת����
		char temp = str[j];
		str[j] = str[num - 1 - j];
		str[num - 1 - j] = temp;
	}

	str[num] = '\0';
}

int main() {
	int x;
	char str[20];
	cin >> x;
	itoa(x, str);
	cout << str;
	cout << endl;
	system("pause");
	return 0;
}

