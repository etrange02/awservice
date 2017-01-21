#ifndef STRING_H
#define STRING_H

#include <NativeElement.h>
#include <IVisitor.h>

namespace AWS
{
    class String : public NativeElement<std::string>
    {
        public:
            /** Default constructor */
            String(const std::string& name);
            /** Default destructor */
            virtual ~String();

            virtual void visit(IVisitor& visitor);

            virtual std::string valueAsString() const;
            virtual void setStringValue(const std::string& value);

            virtual std::string getDefaultValue() const;

        protected:

        private:
    };
}

#endif // STRING_H
