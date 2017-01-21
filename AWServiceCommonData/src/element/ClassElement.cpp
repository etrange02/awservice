/***************************************************************
 * Name:      ClassElement.cpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-09-30
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "ClassElement.h"
#include <IVisitor.h>
#include <IUserModel.h>

using namespace AWS;

ClassElement::ClassElement(const std::string& name) : Element(name)
{
    //ctor
}

ClassElement::~ClassElement()
{
    //dtor
}

void ClassElement::visit(IVisitor& visitor)
{
    visitor.visitClass(*this);
}

void ClassElement::fill(void* destination)
{
    fill(destination, NULL);
}

void ClassElement::fill(void* destination, void*(* factory)())
{
    if (NULL == destination)
        return;

    IUserModel* userModel = (IUserModel*)destination;
    userModel->fromElement(*this);
}

void ClassElement::add(Element* element)
{
    if (NULL == element || element->getName().empty())
        return;

    m_elements[element->getName()] = element;
}

Element* ClassElement::get(const std::string& key)
{
    std::map<std::string, Element*>::iterator iter = m_elements.find(key);
    if (iter == m_elements.end())
        return NULL;

    return iter->second;
}

