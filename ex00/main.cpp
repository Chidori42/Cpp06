/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:46:06 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/04/21 17:03:39 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int ac, char **av)
{
    if (ac == 2){
        ScalarConverter convert;
        convert.setStr(av[1]);
        if (convert.CheckString()
            && convert.CountCharacter('f')
            && convert.CountCharacter('.')
            && convert.CountCharacter('-')
            && convert.CountCharacter('+'))
        {
            convert.SetData();
        }
        else
            convert.ImposibleConvert();
    }
    return (0);
}