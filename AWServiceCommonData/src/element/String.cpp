/***************************************************************
 * Name:      String.cpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-10-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "String.h"

using namespace AWS;

String::String(const std::string& name) : NativeElement<std::string>(name)
{
    //ctor
}

String::~String()
{
    //dtor
}

void String::visit(IVisitor& visitor)
{
    visitor.visitString(*this);
}

std::string String::valueAsString() const
{
    return m_value;
}

void String::setStringValue(const std::string& value)
{
    m_value = value;
}

std::string String::getDefaultValue() const
{
    return "";
}

