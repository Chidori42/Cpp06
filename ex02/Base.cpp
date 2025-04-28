/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:02:06 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/28 10:37:11 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
void Base::identify(Base& p){
    if (dynamic_cast<A*>(&p)) {
        std::cout << "This is a Derived A" << std::endl;
    }else if (dynamic_cast<B*>(&p)) {
        std::cout << "This is a Derived B" << std::endl;
    }else if (dynamic_cast<C*>(&p)){
        std::cout << "This is a Derived C" << std::endl;
    } else {
        std::cout << "Unknown derived type" << std::endl;
    }
}