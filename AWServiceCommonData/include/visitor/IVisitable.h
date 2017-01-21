#ifndef IVISITABLE_H
#define IVISITABLE_H

namespace AWS {
    class IVisitor;
}

namespace AWS
{
    class IVisitable
    {
        public:
            virtual void visit(IVisitor& visitor) = 0;

        protected:
            /** Default constructor */
            IVisitable();
            /** Default destructor */
            virtual ~IVisitable();
    };
}

#endif // IVISITABLE_H
