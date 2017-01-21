/***************************************************************
 * Name:      Real.cpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-10-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "Real.h"
#include <IVisitor.h>

using namespace AWS;

Real::Real(const std::string& name) : NativeElement<double>(name)
{
    m_value = 0.0;
}

Real::~Real()
{
}

void Real::visit(IVisitor& visitor)
{
    visitor.visitReal(*this);
}

std::string Real::valueAsString() const
{
    return std::to_string(m_value);
}

void Real::setStringValue(const std::string& value)
{
    setValue(stod(value));
}

double Real::getDefaultValue() const
{
    return 0.0;
}

