//#pragma once
#ifndef OBJDYN_H_
#define OBJDYN_H_
#include <string>
#include <map>

typedef void* (*Constructor)();
class CObjectFactory {
public:
	static void registerClass(std::string className, Constructor constructor)
	{
		constructors()[className] = constructor;
	}

	static void* createObject(const std::string& className)
	{
		Constructor constructor = NULL;
		if (constructors().find(className) != constructors().end())
		{
			constructor = constructors().find(className)->second;
		}
		if (constructor == NULL)
		{
			//std::cout << "llllllllll ";
			return NULL;
		}
		return (*constructor)();
	}
private:
	inline static std::map<std::string, Constructor>& constructors() {
		static std::map<std::string, Constructor> instance;
		return instance;
	}
};

#define REG_CLASS(class_name) \
class class_name##Helper{ \
public:	\
	class_name##Helper(){\
		CObjectFactory::registerClass(#class_name,class_name##Helper::createObjectFunc);\
	}\
	static void* createObjectFunc(){\
		return new ImplTwo;\
	}\
};\
class_name##Helper class_name##helper;
#endif