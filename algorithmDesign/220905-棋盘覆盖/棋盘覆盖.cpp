#define _CRT_SECURE_NO_SECURES
#include <iostream>
#include <cstring>

using namespace std;

// ���� 16 * 16
int a[16][16] = { 0 };
// �������̵ı��
int count = 0;
/**
 * tr �������Ͻ����ڵ���
 * c �������Ͻ����ڵ���
 * dr �������ӵ���
 * dc �������ӵ���
 * size ���̵Ĵ�С
 */
template<class T>
void ChessBoard_Coverage(T tr, T tc, T dr, T dc, T size) {
	if (size == 1) {
		//ֻʣһ�����ӵ����̲��ø��ǣ���Ϊ�Ǹ�������������
		return;
	}
	// ȫ�ֱ�������::ָ��
	T t = ::count++, s = size / 2;
	// �������Ͻǵ�����
	if (dr < tr + s && dc < tc + s) {
		// �������������Ͻ������У�ֱ�ӵݹ���ã����и���
		ChessBoard_Coverage(tr, tc, dr, dc, s);
	}
	else {
		// �������Ӳ������Ͻ������У���ô���Ͻ�������������������һö��������
		// �������Ӹ���
		a[tr + s - 1][tc + s - 1] = t;
		//��ʱ���Ͻ�Ҳ��������������ӵ������ˣ��ݹ���ã����и���
		ChessBoard_Coverage(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if (dr < tr + s && dc >= tc + s) {
		// �������������Ͻ������У�ֱ�ӵݹ���ã����и���
		ChessBoard_Coverage(tr, tc + s, dr, dc, s);
	}
	else {
		// �������Ӳ������Ͻ������У���ô���Ͻ�������������������һö��������
		// �������Ӹ���
		a[tr + s - 1][tc + s] = t;
		ChessBoard_Coverage(tr, tc + s, tr + s - 1, tc + s, s);
	}
	if (dr >= tr + s && dc < tc + s) {
		// �������������½������У�ֱ�ӵݹ���ã����и���
		ChessBoard_Coverage(tr + s, tc, dr, dc, s);
	}
	else {
		// �������Ӳ������½������У���ô���½�������������������һö��������
		// �������Ӹ���
		a[tr + s][tc + s - 1] = t;
		ChessBoard_Coverage(tr + s, tc, tr + s, tc + s - 1, s);
	}
	if (dr >= tr + s && dc >= tc + s) {
		// �������������½������У�ֱ�ӵݹ���ã����и���
		ChessBoard_Coverage(tr + s, tc + s, dr, dc, s);
	}
	else {
		// �������Ӳ������½������У���ô���½�������������������һö��������
		// �������Ӹ���
		a[tr + s][tc + s] = t;
		ChessBoard_Coverage(tr + s, tc + s, tr + s, tc + s, s);
	}
}

int main() {
	int dr = 0, dc = 0;

	cout << "�������������ӵ��������� : ";

	cin >> dr >> dc;
	//ѭ������ά������0
	for (int i = 0; i < 16; i++) {
		memset(a[i], 0, 16 * sizeof(int));
	}
	//�������ӵ�ֵ����Ϊ-1����������
	a[dr][dc] = -1;

	//���ú������������̣�����ѡ����(16 * 16)������
	ChessBoard_Coverage(0, 0, dr, dc, 16);

	// ������
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << ::count - 1 << endl;
	return 0;
}
