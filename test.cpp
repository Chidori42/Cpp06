#include <iostream>
#include <typeinfo>


class base{
    public:
        base &operator=(const base &other){
            (void)other;
            return (*this);
        }
        virtual void display(){
            std::cout << "this base" << std::endl;
        }
};
class derive: public base{
    public:
        void display(){
            std::cout << "this derive" << std::endl;
        }
};
int main(){
    derive d;
    base &b = dynamic_cast<base&>(d);

    b.display();

}