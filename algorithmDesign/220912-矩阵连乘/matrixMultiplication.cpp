#define _CRT_SECURE_NO_WARNINGS
/**********************************************************************
Copyright(c) 2022.09.12 15.38 MRLIU
All rigth reserved
vs2019
Դ��:https://gitee.com/loveMiaoW/vs_project.git
***********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class MATRIX {
public:
	MATRIX();															//���캯�� ����������������
	~MATRIX();															//�������� �ͷž���ռ�õĿռ�
	void creatMatrix(MATRIX* M,int matrixNumber);
	void matrixMultiply(MATRIX* M, int** m, int** n, int matrixNumber);	//�㷨����--����������
	void traceBack(MATRIX* M, int** n, int i, int j);					//���ݻ������
public:
	int row;															//��������
	int col;															//��������
	string name;														//��������
};

// ���캯��
MATRIX::MATRIX()
{

}

//��������
MATRIX::~MATRIX()
{

}

//�������
//�������� ���� ����
void MATRIX::creatMatrix(MATRIX* M, int matrixNumber)
{
	cout << "please initialization matrix(matrixName row col:A1 2 3)" << endl;
	for (int i = 0; i < matrixNumber; i++)
	{
		cout << "input " << i + 1<< " matrix info: ";
		cin >> M[i].name >> M[i].row >> M[i].col;
	}
}
/*
	�ø߼�ָ�����εͼ�ָ�� -> ����ָ������һ��ָ�� -> ����ָ�����ζ���ָ��
*/
void MATRIX::matrixMultiply(MATRIX* M, int** m, int** n, int matrixNumber)
{
	for (int r = 2; r <= matrixNumber; ++r) 
	{																		//��������������ˣ�����[1,n]
		for (int i = 0; i < matrixNumber - r + 1; ++i) 
		{																	//i��0��ʼ����Ҫ�ǵ�һ��������Ϣ��0���ڴ浥Ԫ��
			int j = i + r - 1;												//j��ʾĩβ�ľ���										
			m[i][j] = m[i + 1][j] + M[i].row * M[i].col * M[j].col;		//��ʼ��k=i�ָ�
			n[i][j] = i;													//��¼�ָ��k
			for (int k = i + 1; k < j; ++k) 
			{																//k��iһֱ��j-1
				int t = m[i][k] + m[k + 1][j] + M[i].row * M[k].col * M[j].col;
				if (t < m[i][j]) {											//ȡ��Сֵ
					m[i][j] = t;
					n[i][j] = k;
				}
			}
		}
	}
}

//����ָ���������
void MATRIX::traceBack(MATRIX* M, int** n, int i, int j)
{
	if (i == j)
	{
		cout << M[i].name;
		return;
	}
	cout << "(";
	traceBack(M, n, i, n[i][j]);
	traceBack(M, n, n[i][j] + 1, j);
	cout << ")";
}

void test01()
{
	//MATRIX����ָ�� M 
	//MATRIX* M;
	MATRIX mat;
	int matrixNumber = 0;
	cout << "please input matrix number: ";
	cin >> matrixNumber;
	MATRIX* M = new MATRIX[matrixNumber];
	mat.creatMatrix(M, matrixNumber);

	int** m = new int* [matrixNumber];
	for (int i = 0; i < matrixNumber; i++) 									//��̬��ά����
	{
		m[i] = new int[matrixNumber];
	}

	int** n = new int* [matrixNumber];
	for (int i = 0; i < matrixNumber; i++)
	{
		n[i] = new int[matrixNumber];
	}

	for (int i = 0; i < matrixNumber; i++)									//��m��n��Ԫ��ȫ����Ϊ -1
	{	
		for (int j = 0; j < matrixNumber; j++)
		{
			m[i][j] = -1;
			n[i][j] = -1;
		}
		m[i][i] = n[i][i] = 0;												//�Խ�����Ϊ 0 
	}

	mat.matrixMultiply(M, m, n, matrixNumber);


	//���[i,j]֮���������С�ĳ˷������Լ��м�ķֽ���k
	cout << "\n��[i,j],��С�ĳ˷�������\n";
	for (int i = 0; i < matrixNumber; i++) {
		for (int j = 0; j < matrixNumber; j++)
			cout << m[i][j] << "\t";
		cout << "\n";
	}
	cout << "\n��[i,j],�м�Ͽ�k�ļ�¼��\n";
	for (int i = 0; i < matrixNumber; i++) {
		for (int j = 0; j < matrixNumber; j++)
			cout << n[i][j] << "\t";
		cout << "\n";
	}

	//�������
	cout << "\n��������������ţ�" << endl;
	cout << "���ٳ˷������� " << m[0][matrixNumber - 1] << "�Σ�����˳�� ";
	mat.traceBack(M, n, 0, matrixNumber - 1);

	cout << endl;
	//�ڴ��ͷ�
	for (int i = 0; i < matrixNumber; ++i) {
		delete[] n[i];
		delete[] m[i];
	}
	delete[] n;
	delete[] m;
	delete[] M;
}
int main()
{
	//freopen("./input.txt", "r", stdin);
	test01();
	system("pause");
	return 0;
}