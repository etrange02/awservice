/***************************************************************
 * Name:      DateTime.cpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-10-02
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "DateTime.h"
#include <IVisitor.h>

using namespace AWS;

DateTime::DateTime(const std::string& name) : NativeElement<std::string>(name)
{
    //ctor
}

DateTime::~DateTime()
{
    //dtor
}

void DateTime::visit(IVisitor& visitor)
{
    visitor.visitDateTime(*this);
}

std::string DateTime::valueAsString() const
{
    return m_value;
}

void DateTime::setStringValue(const std::string& value)
{

}

std::string DateTime::getDefaultValue() const
{
    return "";
}

