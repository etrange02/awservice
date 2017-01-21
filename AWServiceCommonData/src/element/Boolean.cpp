/***************************************************************
 * Name:      Boolean.cpp
 * Purpose:   Code for AWServiceCommonDataTest
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-10-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "element/Boolean.h"
#include <IVisitor.h>
#include <ctype.h>
#include <algorithm>

using namespace AWS;

Boolean::Boolean(const std::string& name) : NativeElement<bool>(name)
{
    m_value = false;
}

Boolean::~Boolean()
{
    //dtor
}

void Boolean::visit(IVisitor& visitor)
{
    visitor.visitBoolean(*this);
}

std::string Boolean::valueAsString() const
{
    return m_value ? "true" : "false";
}

void Boolean::setStringValue(const std::string& value)
{
    std::string lowerCaseValue;
    std::transform(value.begin(), value.end(), std::back_inserter(lowerCaseValue), tolower);
    m_value = (lowerCaseValue == "true");
}

bool Boolean::getDefaultValue() const
{
    return false;
}

