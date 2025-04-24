/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:00:29 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/24 00:06:41 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base{
    public:
        Base();
        virtual ~Base();
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

class A :public Base{

};
class B :public Base{
    
};
class C :public Base{
    
};

#endif