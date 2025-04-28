/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:46:06 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/28 10:36:08 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base b;
    Base *new_b = b.generate();
    try{
        b.identify(new_b);
        delete new_b;
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
        delete new_b;
    }
    return (0);
}