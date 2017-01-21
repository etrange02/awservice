#ifndef RAW_H
#define RAW_H

#include <NativeElement.h>

namespace AWS
{
    class Raw : public NativeElement<std::string>
    {
        public:
            /** Default constructor */
            Raw(const std::string& name);
            /** Default destructor */
            virtual ~Raw();

            virtual void visit(IVisitor& visitor);

            virtual std::string valueAsString() const;
            virtual void setStringValue(const std::string& value);

            virtual std::string getDefaultValue() const;

        protected:

        private:
    };
}

#endif // RAW_H
