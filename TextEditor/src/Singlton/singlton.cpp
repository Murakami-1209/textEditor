#include "singlton.h"

template <typename T>
T* Singleton<T>::getInstance()
{
	if (m_instance == nullptr) {
		m_instance = new T();
	}
	return m_instance;
}
