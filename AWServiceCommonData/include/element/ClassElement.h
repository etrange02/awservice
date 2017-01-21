#ifndef CLASSELEMENT_H
#define CLASSELEMENT_H

#include <map>
#include <Element.h>

namespace AWS
{
    class ClassElement : public Element
    {
        public:
            /** Constructor */
            ClassElement(const std::string& name);
            /** Copy onstructor */
            ClassElement(const ClassElement& other);
            /** Default destructor */
            virtual ~ClassElement();

            virtual void visit(IVisitor& visitor);

            virtual void fill(void* destination);
            virtual void fill(void* destination, void* (*factory)());

            void add(Element* element);
            Element* get(const std::string& key);

        private:
            std::map<std::string, Element*> m_elements;
    };
}

#endif // CLASSELEMENT_H
