/***************************************************************
 * Name:      ArrayElement.cpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-09-29
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "ArrayElement.h"
#include "NativeElement.h"
#include "Integer.h"
#include "Boolean.h"
#include "Real.h"
#include "String.h"
#include <IVisitor.h>
#include <algorithm>
#include <iostream>

using namespace AWS;

bool removeAll(Element* element) { delete element; return true; }

/** \brief Constructor
 *
 * \param name const std::string&
 *
 */
ArrayElement::ArrayElement(const std::string& name) : Element(name)
{
    //ctor
}

/** \brief Destructor
 */
ArrayElement::~ArrayElement()
{
    std::remove_if(m_elements.begin(), m_elements.end(), removeAll);
}

void ArrayElement::visit(IVisitor& visitor)
{
    visitor.visitArray(*this);
}

void ArrayElement::fill(void* destination)
{
    fill(destination, NULL);
}

void ArrayElement::fill(void* destination, void* (*factory)())
{
    if (NULL == destination)
        return;

    std::vector<void*>& destinationCasted = *static_cast<std::vector<void*>*>(destination);

    for (std::vector<Element*>::iterator iter = m_elements.begin(); iter != m_elements.end(); ++iter)
    {
        Integer* e = dynamic_cast<Integer*>(*iter);
        Real* r = dynamic_cast<Real*>(*iter);
        String* s = dynamic_cast<String*>(*iter);
        if (NULL != e)
        {
            if (e->hasValue())
                destinationCasted.push_back((void*)(e->value()));
        }
        else if (NULL != r)
        {
            std::vector<double>& realDestination = *static_cast<std::vector<double>*>(destination);
            if (r->hasValue())
                realDestination.push_back(r->value());
        }
        else if (NULL != s)
        {
            std::vector<std::string>& stringDestination = *static_cast<std::vector<std::string>*>(destination);
            if (s->hasValue())
                stringDestination.push_back(s->value());
        }
        else if (NULL != factory)
        {
            void* object = factory();
            (*iter)->fill(object);
            destinationCasted.push_back(object);
        }
    }
}
/*
template <typename T>
void ArrayElement::fill(std::vector<T>* destination)
{
    if (NULL == destination)
        return;

    std::vector<T> destinationCasted = *static_cast<std::vector<T>*>(destination);

    for (std::vector<Element*>::iterator iter = m_elements.begin(); iter != m_elements.end(); ++iter)
    {
        NativeElement<int>* e = static_cast<NativeElement<int>*>(*iter);
        if (NULL != e)
        {
            NativeElement<T>* el = static_cast<NativeElement<T>*>(*iter);
            if (el->hasValue())
                destinationCasted.push_back(e->value());
                //std::cout << el->value() << std::endl;
        }
        //else if (NULL != factory)
        {
           // T* object = factory();
           // (*iter)->fill(object);
//            destinationCasted.push_back(object);
        }
    }
}*/

void ArrayElement::add(Element* element)
{
    m_elements.push_back(element);
}


//template void ArrayElement::fill<int>(std::vector<int>* destination);
//template void ArrayElement::fill<long>(std::vector<long>* destination);
