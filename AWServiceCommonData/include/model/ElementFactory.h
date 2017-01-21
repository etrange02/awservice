#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include <vector>
#include <algorithm>
#include "element/ArrayElement.h"
#include "model/IUserModel.h"

namespace AWS {
    class Element;
    //class IUserModel;
}

template <typename T>
AWS::Element* factory(const std::string& name, std::vector<T>& items);
AWS::Element* factory(const std::string& name, bool source);
AWS::Element* factory(const std::string& name, const std::string& source);
AWS::Element* factory(const std::string& name, int source);
AWS::Element* factory(const std::string& name, AWS::IUserModel& userModel);


#ifndef READ

#define READRN(source, name, destination, factory)  \
    {                                               \
        AWS::Element* el = source.get(name);        \
        if (NULL != el)                             \
            el->fill(&destination, factory);        \
    }

#define READ(source, name, factory)                 \
    READRN(source, #name, name, factory)

#endif //READRN

#ifndef WRITE
#define WRITERN(destination, name, source)          \
    {                                               \
        destination->add(factory(name, source));    \
    }

#define WRITE(destination, name) \
    WRITERN(destination, #name, name)

#endif // WRITERN


template <typename T>
class VectorToArrayElement
{
    public:
        VectorToArrayElement(AWS::ArrayElement& arrayElement) : m_arrayElement(arrayElement) {}
        /** Default destructor */
        virtual ~VectorToArrayElement() {};
        void operator()(T& item)
        {
            WRITERN((&m_arrayElement), "", *item);
        };

    private:
        AWS::ArrayElement& m_arrayElement;
};

template <typename T>
AWS::Element* factory(const std::string& name, std::vector<T>& items)
{
    AWS::ArrayElement* arrayElement = new AWS::ArrayElement(name);
    VectorToArrayElement<T> translator(*arrayElement);
    for_each(items.begin(), items.end(), translator);
    return arrayElement;
};

#endif // ELEMENTFACTORY_H
