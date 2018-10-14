#pragma once

#define JEONG_BEGIN namespace JEONG {
#define JEONG_END }
#define JEONG_USING using namespace JEONG;

//클라이언트 프로젝트냐 엔진프로젝트냐에 다라서 자동으로 DLL의 import export가 정해진다.
//프로젝트속성-> 전처리기 -> 클라이언트(JEONG_IMPORT;) , 엔진(JEONG_EXPORT)
#ifdef JEONG_EXPORT
#define JEONG_DLL __declspec(dllexport)
#else
#define JEONG_DLL __declspec(dllimport)
#endif

#define SAFE_DELETE(p) if(p) {delete p; p = NULL;}
#define SAFE_RELEASE(p) if(p) {p->Release(); p = NULL;}
#define SAFE_DELETE_ARRARY(p) if(p){delete[] p; p = NULL;}

template<typename T>
void Safe_Delete_VecList(T& p)
{
	T::iterator StartIter = p.begin();
	T::iterator EndIter = p.end();

	for (; StartIter != EndIter ; StartIter++)
	{
		SAFE_DELETE((*StartIter));
	}
	p.clear();
}

template<typename T>
void Safe_Release_VecList(T& p)
{
	T::iterator StartIter = p.begin();
	T::iterator EndIter = p.end();

	for (; StartIter != EndIter; StartIter++)
	{
		SAFE_RELEASE((*StartIter));
	}
}

template<typename T>
void Safe_Release_Map(T& p)
{
	T::iterator StartIter = p.begin();
	T::iterator EndIter = p.end();

	for (; StartIter != EndIter; StartIter++)
	{
		SAFE_RELEASE(StartIter->second);
	}
}

template<typename T>
void Safe_Delete_Map(T& p)
{
	T::iterator StartIter = p.begin();
	T::iterator EndIter = p.end();

	for (; StartIter != EndIter; StartIter++)
	{
		SAFE_DELETE(StartIter->second);
	}
	p.clear();
}

#define CLASS_IN_SINGLE(Type)	\
	private:\
		static Type* Instance;\
	public: \
		static Type* Get();\
		static void Delete();\
	private: \
		Type();\
		~Type();

#define SINGLETON_VAR_INIT(Type) Type* Type::Instance = NULL; \
	Type* Type::Get()\
	{\
		if (Instance == NULL)\
			Instance = new Type;\
		return Instance;\
	}\
	void Type::Delete()\
	{\
		SAFE_DELETE(Instance);\
	}
