/***************************************************************
 * Name:      ElementFactory.cpp
 * Purpose:   Code for AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2017-01-21
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "ElementFactory.h"
#include "element/Element.h"
#include "element/ArrayElement.h"
#include "element/Boolean.h"
#include "element/String.h"
#include "element/Integer.h"
#include "model/IUserModel.h"
#include <algorithm>

using namespace AWS;


AWS::Element* factory(const std::string& name, AWS::IUserModel& userModel)
{
    return userModel.toElement(name);
}
AWS::Element* factory(const std::string& name, bool source)
{
    AWS::Boolean* boolean = new AWS::Boolean(name.empty() ? "bool" : name);
    boolean->setValue(source);
    return boolean;
}
AWS::Element* factory(const std::string& name, const std::string& source)
{
    AWS::String* str = new AWS::String(name.empty() ? "string" : name);
    str->setValue(source);
    return str;
}
AWS::Element* factory(const std::string& name, int source)
{
    AWS::Integer* integer = new AWS::Integer(name.empty() ? "integer" : name);
    integer->setValue(source);
    return integer;
}



