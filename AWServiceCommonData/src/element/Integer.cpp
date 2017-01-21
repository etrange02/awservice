/***************************************************************
 * Name:      Integer.cpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-09-30
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "Integer.h"
#include <IVisitor.h>

using namespace AWS;

Integer::Integer(const std::string& name) : NativeElement<long>(name)
{
    m_value = 0;
    //ctor
}

Integer::~Integer()
{
    //dtor
}

void Integer::visit(IVisitor& visitor)
{
    visitor.visitInteger(*this);
}

std::string Integer::valueAsString() const
{
    return std::to_string(m_value);
}

void Integer::setStringValue(const std::string& value)
{
    setValue(stol(value));
}

long Integer::getDefaultValue() const
{
    return 0;
}

