#pragma once
#include <iostream>

template <class T, T* (*factory)(int number)>
class Polymorphic_Ptr {
	T* data = nullptr;

	void copyFrom(const Polymorphic_Ptr<T, factory>& other);
	void moveFrom(Polymorphic_Ptr<T, factory>&& other);
	void free();

public:
	Polymorphic_Ptr() = default;
	Polymorphic_Ptr(T* data);
	Polymorphic_Ptr(const Polymorphic_Ptr<T, factory>& other);
	Polymorphic_Ptr(Polymorphic_Ptr<T, factory>&& other) noexcept;

	Polymorphic_Ptr<T, factory>& operator=(const Polymorphic_Ptr<T, factory>& other);
	Polymorphic_Ptr<T, factory>& operator=(Polymorphic_Ptr<T, factory>&& other) noexcept;

	~Polymorphic_Ptr();

	T* operator->();
	const T* operator->() const;

	T& operator*();
	const T& operator*() const;

	void reset(T* data);

	T* get();
	const T* get() const;

	template <class T, T* (*factory)(int number)>
	friend std::ostream& operator<<(std::ostream& ofs, const Polymorphic_Ptr<T, factory>& ptr);

	template <class T, T* (*factory)(int number)>
	friend std::istream& operator>>(std::istream& ifs, Polymorphic_Ptr<T, factory>& ptr);
};
template <class T, T* (*factory)(int number)>
void Polymorphic_Ptr<T, factory>::copyFrom(const Polymorphic_Ptr<T, factory>& other)
{
	data = other.data->clone();
}

template <class T, T* (*factory)(int number)>
void Polymorphic_Ptr<T, factory>::moveFrom(Polymorphic_Ptr<T, factory>&& other)
{
	data = other.data;
	other.data = nullptr;
}

template <class T, T* (*factory)(int number)>
void Polymorphic_Ptr<T, factory>::free()
{
	delete data;
}
template <class T, T* (*factory)(int number)>
Polymorphic_Ptr<T, factory>::Polymorphic_Ptr(T* data) : data(data)
{

}
template <class T, T* (*factory)(int number)>
 Polymorphic_Ptr<T, factory>::Polymorphic_Ptr(const Polymorphic_Ptr<T, factory>& other)
{
	copyFrom(other);
}

 template <class T, T* (*factory)(int number)>
Polymorphic_Ptr<T, factory>::Polymorphic_Ptr(Polymorphic_Ptr<T, factory>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <class T, T* (*factory)(int number)>
Polymorphic_Ptr<T, factory>& Polymorphic_Ptr<T, factory>::operator=(const Polymorphic_Ptr<T, factory>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T, T* (*factory)( int number)>
Polymorphic_Ptr<T, factory>& Polymorphic_Ptr<T, factory>::operator=(Polymorphic_Ptr<T, factory>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <class T, T* (*factory)(int number)>
Polymorphic_Ptr<T, factory>::~Polymorphic_Ptr()
{
	free();
}

template <class T, T* (*factory)(int number)>
T* Polymorphic_Ptr<T, factory>::operator->()
{
	return data;
}

template <class T, T* (*factory)( int number)>
const T* Polymorphic_Ptr<T, factory>::operator->() const
{
	return data;
}

template <class T, T* (*factory)( int number)>
T& Polymorphic_Ptr<T, factory>::operator*()
{
	if (data == nullptr) {
		throw std::runtime_error("ptr is nullptr");
	}
	return *data;
}

template <class T, T* (*factory)( int number)>
const T& Polymorphic_Ptr<T, factory>::operator*() const
{
	if (data == nullptr) {
		throw std::runtime_error("ptr is nullptr");
	}
	return *data;
}

template <class T, T* (*factory)( int number)>
void Polymorphic_Ptr<T, factory>::reset(T* data)
{
	if (this->data != data) {
		free();
		this->data = data;
	}
}

template <class T, T* (*factory)( int number)>
T* Polymorphic_Ptr<T, factory>::get()
{
	return data;
}

template <class T, T* (*factory)( int number)>
const T* Polymorphic_Ptr<T, factory>::get() const
{
	return data;
}


template <class T, T* (*factory)( int number)>
std::ostream& operator<<(std::ostream& ofs, const Polymorphic_Ptr<T, factory>& ptr)
{
	if (ptr.get()) {
		ptr->serialise(ofs);
	}
	return ofs;
}
template <class T, T* (*factory)( int number)>
std::istream& operator>>(std::istream& ifs, Polymorphic_Ptr<T, factory>& ptr)
{
	int number;
	ifs >> number;
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	ptr = factory(number);
	ptr->deserialise(ifs);
	return ifs;
}



