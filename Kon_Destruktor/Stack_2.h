#pragma once

/*
	Gefunden auf http://www.mathematik.uni-ulm.de/numerik/
	cpp/ws16/doc/cpp-lecture/stack-tutorial/example01/index.html
*/


class Stack_2
{
    public:
        Stack_2()
            : top(nullptr)
        {
        }

        ~Stack_2()
        {
            while(!empty()) {
                pop();
            }
        }

        bool empty() const
        {
            return !top;
        }

        void push(double value)
        {
            Element *add = new Element;
            add->last    = top;
            add->value   = value;
            top          = add;
        }

        double pop()
        {
            assert(!empty());

            Element *remove = top;
            top             = remove->last;
            double  value   = remove->value;
            delete remove;
            return value;
        }

        void print(const char *txt) const
        {
            std::cout << txt << ": ";
            print_elements(top);
            std::cout << ";" << std::endl;
        }

    private:
        struct Element
        {
            double      value;
            Element     *last;
        };

        void print_elements(const Element *top) const
        {
            if (top) {
                print_elements(top->last);
                std::cout << "   " << top->value;
            }
        }

        Element     *top;
};
