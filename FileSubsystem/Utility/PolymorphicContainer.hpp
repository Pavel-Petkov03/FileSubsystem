#pragma once 
#include "Vector.hpp"
#include "PolymorphicPtr.hpp"

template <class T>
class Polymorphic_Container {
	Vector<Polymorphic_Ptr<T>> data;

public:
	void add(const T* elem);

	Polymorphic_Ptr<T>& operator[] (size_t index);
	const Polymorphic_Ptr<T>& operator[] (size_t index) const;

	void execute(size_t index, void (*func) (T*));
	void execute(size_t index, void (*func) (const T*)) const;
	size_t getLength() const;
};

template<class T>
void Polymorphic_Container<T>::add(const T* elem)
{
	data.pushBack(elem);
}

template<class T>
Polymorphic_Ptr<T>& Polymorphic_Container<T>::operator[](size_t index)
{
	return data[index];
}

template<class T>
const Polymorphic_Ptr<T>& Polymorphic_Container<T>::operator[](size_t index) const
{
	return data[index];
}

template<class T>
void Polymorphic_Container<T>::execute(size_t index, void(*func)(T*))
{
	func(data[index].get());
}

template<class T>
void Polymorphic_Container<T>::execute(size_t index, void(*func)(const T*)) const
{
	func(data[index].get());
}

template<class T>
size_t Polymorphic_Container<T>::getLength() const
{
	return data.getSize();
}
