/***************************************************************
 * Name:      NativeElement.t.hpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-09-30
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "NativeElement.h"

using namespace AWS;


template <typename T>
NativeElement<T>::NativeElement(const std::string& name) : Element(name),
    m_hasValue(false)
{
    //ctor
}

template <typename T>
NativeElement<T>::~NativeElement()
{
    //dtor
}

template <typename T>
NativeElement<T>::NativeElement(const NativeElement& other)
{
    this = &other;
}

template <typename T>
NativeElement<T>& NativeElement<T>::operator=(const NativeElement& other)
{
    if (this == &other) return *this; // handle self assignment
    *this = (Element&) other;
    m_value = other.m_value;
    m_hasValue = other.m_hasValue;
    return *this;
}

template <typename T>
bool NativeElement<T>::hasValue() const
{
    return m_hasValue;
}

template <typename T>
const T& NativeElement<T>::value() const
{
    return m_value;
}

template <typename T>
void NativeElement<T>::setValue(const T& value)
{
    m_value = value;
    m_hasValue = true;
}

template <typename T>
void NativeElement<T>::fill(void* destination)
{
    fill(destination, NULL);
}

template <typename T>
void NativeElement<T>::fill(void* destination, void* (*factory)())
{
    if (NULL == destination)
        return;

    T& destinationCasted = *static_cast<T*>(destination);

    if (hasValue())
    {
        destinationCasted = value();
    }
    else
    {
        destinationCasted = getDefaultValue();
    }
}

