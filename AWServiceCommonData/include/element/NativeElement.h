#ifndef NATIVEELEMENT_H
#define NATIVEELEMENT_H

#include <element/Element.h>

namespace AWS
{
    template <typename T>
    class NativeElement : public Element
    {
        public:
            /** Default constructor */
            NativeElement(const std::string& name);
            /** Default destructor */
            virtual ~NativeElement();
            /** Copy constructor
             *  \param other Object to copy from
             */
            NativeElement(const NativeElement& other);
            /** Assignment operator
             *  \param other Object to assign from
             *  \return A reference to this
             */
            NativeElement& operator=(const NativeElement& other);

            bool hasValue() const;
            const T& value() const;
            virtual std::string valueAsString() const = 0;
            virtual void setValue(const T& value);
            virtual void setStringValue(const std::string& value) = 0;

            virtual void fill(void* destination);
            virtual void fill(void* destination, void* (*factory)());
            virtual T getDefaultValue() const = 0;

        protected:
            T m_value;
            bool m_hasValue;
    };
}
#include "../../src/element/NativeElement.t.hpp"

#endif // NATIVEELEMENT_H
