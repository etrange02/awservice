/***************************************************************
 * Name:      Raw.cpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-10-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "Raw.h"
#include <IVisitor.h>

using namespace AWS;

Raw::Raw(const std::string& name) : NativeElement<std::string>(name)
{
    //ctor
}

Raw::~Raw()
{
    //dtor
}

void Raw::visit(IVisitor& visitor)
{
    visitor.visitRaw(*this);
}

std::string Raw::valueAsString() const
{
    return m_value;
}

void Raw::setStringValue(const std::string& value)
{
    setValue(value);
}

std::string Raw::getDefaultValue() const
{
    return "";
}

