#ifndef ARRAYELEMENT_H
#define ARRAYELEMENT_H

#include <vector>
#include <Element.h>

namespace AWS
{
    class ArrayElement : public Element
    {
        public:
            /** Constructor */
            ArrayElement(const std::string& name);
            /** Copy onstructor */
            ArrayElement(const ArrayElement& other);
            /** Default destructor */
            virtual ~ArrayElement();

            virtual void visit(IVisitor& visitor);
            virtual void fill(void* destination);
            virtual void fill(void* destination, void* (*factory)());
            template <typename T>
            void fill(std::vector<T>* destination);

            void add(Element* element);

        public:
            std::vector<Element*> m_elements;
    };
}

#endif // ARRAYELEMENT_H
