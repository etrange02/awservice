/***************************************************************
 * Name:      IUserModel.cpp
 * Purpose:   Code AWServiceCommonData
 * Author:    David Lecoconnier (david.lecoconnier@free.fr)
 * Created:   2016-09-27
 * Copyright: David Lecoconnier (http://www.getfux.fr)
 * License:
 **************************************************************/
#include "IUserModel.h"

using namespace AWS;

IUserModel::IUserModel(const std::string& name) :
    m_name(name)
{
    //ctor
}

IUserModel::~IUserModel()
{
    //dtor
}

const std::string& IUserModel::getName() const
{
    return m_name;
}

