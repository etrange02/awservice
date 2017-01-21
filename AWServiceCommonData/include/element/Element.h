#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include "visitor/IVisitable.h"

namespace AWS
{
    class Element : public IVisitable
    {
        public:
            /** Constructor */
            Element(const std::string& name) : m_name(name) {};
            /** Copy onstructor */
            Element(const Element& other) {};
            /** Default destructor */
            virtual ~Element() {};

            const std::string getName() const {return m_name;};

            virtual void fill(void* destination) = 0;
            virtual void fill(void* destination, void* (*factory)()) = 0;

        protected:

        private:
            /** Default constructor */
            Element() {};

        private:
            std::string m_name;
    };
}

#endif // ELEMENT_H
