#include <iostream>
#include <string>
#include "DynObj.h"
using namespace std;

/*
	api
		test函数
	impI 派生
	cenlit
*/

class Api {
	//纯虚函数,派生类去实现
public:
	virtual void test(string s) = 0;
protected:
	//构造函数保护起来,体现接口的性质
	Api() {};
};
class Impl : public Api {
public:
	void test(string s)
	{
		cout << "现在是Impl类,正在执行方法: " << s << endl;
	}
};


class ImplOne : public Api {
public:
	void test(string s)
	{
		cout << "ImplOne 正在执行: " << s << endl;
	}
};

class ImplTwo : public Api {
public:
	void test(string s)
	{
		cout << "ImplTwo 正在执行: " << s << endl;
	}
};
/*
	根据传入参数不同创建并且返回不同的类对象
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
	pApi->test("哈哈完全不知道，里面的东西了");
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