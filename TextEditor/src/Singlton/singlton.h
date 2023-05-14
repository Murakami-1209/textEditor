#pragma once

template <typename T>
class Singleton
{
public:
	~Singleton();
	static T* getInstance();
protected:
	static T* m_instance;
private:
	Singleton();
};

template <typename T>
T* Singleton<T>::m_instance = nullptr;

template <typename T>
Singleton<T>::Singleton()
{
}

template <typename T>
Singleton<T>::~Singleton()
{
}