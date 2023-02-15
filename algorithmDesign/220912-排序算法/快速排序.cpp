#define _CRT_SECURE_NO_WARNINGS
/**********************************************************************
Copyright(c) 2022.09.14 09.35 MRLIU
All rigth reserved
vs2019
Դ��:https://gitee.com/loveMiaoW/vs_project.git
***********************************************************************/
#include <iostream>
#include <ctime>
using namespace std;
const int number = 13;
int count = 0;	//ȫ�ֱ�������¼����

void myPrint(int a[])
{
    //cout << "��" << ++::count << "�ν�����";
	cout << "��������: ";
	
	for (int i = 0; i < number; ++i)
	{
		cout << a[i] << "\t";
	}
    cout << endl << endl;
}
void swap(int* a,int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//��������
int partition(int a[], int left, int right)
{
    int i, j, t, temp;
    temp = a[left]; ///temp�д�ľ��ǻ�׼��
    i = left;
    j = right;
    while (true)
    {
        while (a[j] >= temp && i < j)///˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
        {
            j--;
        }
        while (a[i] <= temp && i < j)///������ߵ�
        {
            i++;
        }
        if (i >= j)
        {
            break;
        }

        swap(&a[i], &a[j]);
      /* cout << "---------------------------------------" << endl<<"\t";
        myPrint(a);
        cout << "---------------------------------------" << endl;*/
    }
    a[left] = a[i]; ///���ս���׼����λ
    a[i] = temp;
    cout << "ȷ����Ԫ����: " << a[i] <<" ����λ��: "<< i << endl;
    return i;
}
void quickSort(int a[],int left, int right)
{
    if (left < right)
    {
        int q = partition(a,left, right);
        myPrint(a);
        quickSort(a,left, q - 1);///����������ߵģ�������һ���ݹ�Ĺ���
        quickSort(a,q + 1, right);///���������ұߵ� ��������һ���ݹ�Ĺ���
    }
}
void test01()
{
	int a[] = { 49,38,65,97,76,13,27,49,10,21,8,9,-3 };
    cout << "�����ʼֵ" << endl;
    myPrint(a);
	quickSort(a, 0, sizeof(a) / sizeof(int) - 1);
}

int main(int argc,char** argv)
{
	time_t start, end;
	start = clock();
	test01();
	end = clock();

	cout << "using time:" << (double)(end - start) << "ms" << endl;
	system("pause");
	return 0;
}




