#pragma once
#include <iostream>
#include <ostream>

template <typename F>
class Vector
{
    F* data;
    size_t size;
    size_t capacity;

    void free();
    void copyFrom(const Vector<F>& other);
    void moveFrom(Vector<F>&& other);
    void resize(size_t newCapacity);

public:
    Vector();
    Vector(const Vector<F>& other);
    Vector(Vector<F>&& other);

    Vector<F>& operator=(const Vector<F>& other);
    Vector<F>& operator=(Vector<F>&& other);

    void pushBack(const F& element);
    void pushBack(F&& element);

    void popBack();

    void insert(const F& element, size_t index);
    void insert(F&& element, size_t index);

    void erase(size_t index);

    void clear();

    const F operator[](size_t index) const;
    F& operator[](size_t index);

    bool isEmpty() const;
    size_t getSize() const;

    ~Vector();
    friend std::ostream& operator<<(std::ostream&, const Vector<F>& vector);
};

template <typename F>
void Vector<F>::free()
{
    delete[] data;
    data = nullptr;
}

template <typename F>
void Vector<F>::copyFrom(const Vector<F>& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new F[capacity];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename F>
void Vector<F>::moveFrom(Vector<F>&& other)
{
    size = other.size;
    capacity = other.capacity;
    data = other.data;

    other.data = nullptr;
}

template <typename F>
void Vector<F>::resize(size_t newCapacity)
{
    F* newData = new F[newCapacity];

    for (size_t i = 0; i < size; i++)
    {
        newData[i] = std::move(data[i]);
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename F>
Vector<F>::Vector()
{
    capacity = 8;
    size = 0;

    data = new F[capacity];
}

template <typename F>
Vector<F>::Vector(const Vector<F>& other)
{
    copyFrom(other);
}

template <typename F>
Vector<F>::Vector(Vector<F>&& other)
{
    moveFrom(std::move(other));
}

template <typename F>
Vector<F>& Vector<F>::operator=(const Vector<F>& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

template <typename F>
Vector<F>& Vector<F>::operator=(Vector<F>&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

template <typename F>
void Vector<F>::pushBack(const F& element)
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }

    data[size++] = element;
}

template <typename F>
void Vector<F>::pushBack(F&& element)
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }

    data[size++] = std::move(element);
}

template <typename F>
void Vector<F>::popBack()
{
    if (isEmpty())
    {
        throw std::runtime_error("Cannot remove element from empty vector!");
    }

    if (size * 4 == capacity)
    {
        resize(capacity / 2);
    }

    size--;
}

template <typename F>
void Vector<F>::insert(const F& element, size_t index)
{
    if (index >= size)
    {
        throw std::runtime_error("Cannot insert element at non-existing index!");
    }

    if (size == capacity)
    {
        resize(2 * capacity);
    }

    for (size_t i = size; i > index; i--)
    {
        data[i] = std::move(data[i - 1]);
    }

    data[index] = element;
    size++;
}

template <typename F>
void Vector<F>::insert(F&& element, size_t index)
{
    if (index >= size)
    {
        throw std::runtime_error("Cannot insert element at non-existing index!");
    }

    if (size == capacity)
    {
        resize(2 * capacity);
    }

    for (size_t i = size; i > index; i--)
    {
        data[i] = std::move(data[i - 1]);
    }

    data[index] = std::move(element);
    size++;
}


template <typename F>
void Vector<F>::erase(size_t index)
{
    if (index >= size)
    {
        throw std::runtime_error("Cannot erase element at non-existing index!");
    }

    if (size * 4 == capacity)
    {
        resize(capacity / 2);
    }

    size--;

    for (size_t i = index; i < size; i++)
    {
        data[i] = std::move(data[i + 1]);
    }
}

template <typename F>
void Vector<F>::clear()
{
    free();
    size = 0;
    capacity = 8;
    data = new F[capacity];
}


template<typename F>
const F Vector<F>::operator[](size_t index) const
{
    return data[index];
}

template <typename F>
F& Vector<F>::operator[](size_t index)
{
    return data[index];
}

template <typename F>
Vector<F>::~Vector()
{
    free();
}

template <typename F>
bool Vector<F>::isEmpty() const
{
    return size == 0;
}

template <typename F>
size_t Vector<F>::getSize() const
{
    return size;
}

template <typename F>
std::ostream& operator<<(std::ostream& ofs, const Vector<F>& vector) {
    ofs << vector.getSize() << std::endl;
    return ofs;
}
