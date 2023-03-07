#include <iostream>
#include <string>
#include "DynObj.h"
using namespace std;

/*
	api
		test����
	impI ����
	cenlit
*/

class Api {
	//���麯��,������ȥʵ��
public:
	virtual void test(string s) = 0;
protected:
	//���캯����������,���ֽӿڵ�����
	Api() {};
};
class Impl : public Api {
public:
	void test(string s)
	{
		cout << "������Impl��,����ִ�з���: " << s << endl;
	}
};


class ImplOne : public Api {
public:
	void test(string s)
	{
		cout << "ImplOne ����ִ��: " << s << endl;
	}
};

class ImplTwo : public Api {
public:
	void test(string s)
	{
		cout << "ImplTwo ����ִ��: " << s << endl;
	}
};
/*
	���ݴ��������ͬ�������ҷ��ز�ͬ�������
*/
class Factory {
public:
	static Api* createApi(int type)
	{
		Api* pApi = nullptr;
		if (type == 1)
		{
			pApi = new ImplOne();
		}
		else if (type == 2)
		{
			pApi = new ImplTwo();
		}
		return pApi;
	}
	static Api* createApi()
	{
		return new ImplOne;
	}
};

//class ImplTwoHelper {
//public:
//	ImplTwoHelper() {
//		CObjectFactory::registerClass("ImplTwo", ImplTwoHelper::createObjFunc);
//	}
//	static void* createObjFunc() {
//		return new ImplTwo;
//	}
//};

class AutoFactory {
public:
	static Api* createApi()
	{
		Api* pApi = nullptr;
		pApi = static_cast<Api*>(CObjectFactory::createObject("ImplOne"));
		return pApi;
	}
};

void test01()
{
	Api* pApi = new Impl();
	pApi->test("love");
}

void test02()
{
	Api* pApi = Factory::createApi(1);
	pApi->test("loveMiaoW");

}

void test03()
{
	Api* pApi = AutoFactory::createApi();
	if (pApi == nullptr)
	{
		cout << "11111" << endl;
		system("pause");
	}
	pApi->test("������ȫ��֪��������Ķ�����");
}
REG_CLASS(ImplTwo)
void test04()
{
	ImplTwo* pTwo = static_cast<ImplTwo*>(CObjectFactory::createObject("ImplTwo"));
	pTwo->test("RegClass");
}
int main(int argc, char** argv)
{
	//test01();
	//test02();
	test04();
	return 0;
}