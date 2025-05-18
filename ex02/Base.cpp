/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:02:06 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/05/17 21:12:40 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <typeinfo>
#include <exception>

Base::Base(){

}
Base::~Base(){
    std::cout << "Base Destructor" << std::endl;
}

Base *Base::generate(void){
    int r = time(0) % 3;
    switch (r) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return 0;
    }
}
void Base::identify(Base* p){
    if (dynamic_cast<A*>(p)) {
        std::cout << "This is a Derived A" << std::endl;
    }else if (dynamic_cast<B*>(p)) {
        std::cout << "This is a Derived B" << std::endl;
    }else if (dynamic_cast<C*>(p)){
        std::cout << "This is a Derived C" << std::endl;
    } else {
        std::cout << "Unknown derived type" << std::endl;
    }
}

int try_cast(Base& derived_ref, const char* type_name){
    try{
        if (std::string(type_name) == "A") 
            (void)dynamic_cast<A&>(derived_ref);
        else if (std::string(type_name) == "B") 
            (void)dynamic_cast<B&>(derived_ref);
        else if (std::string(type_name) == "C") 
            (void)dynamic_cast<C&>(derived_ref);
        else
            return (0);
        std::cout << "type is " << type_name << std::endl;
    }
    catch(std::bad_cast &e){
        std::cout << type_name << " : casting faild" << std::endl;
        return (0);
    }
    return (1);
}
void Base::identify(Base& p){
    if (try_cast(p, "A"))
        return;
    else if (try_cast(p, "B"))
        return;
    else if (try_cast(p, "C"))
        return;
    else
        std::cout << "unknown type\n";
}