/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:23:13 by rohidalg          #+#    #+#             */
/*   Updated: 2024/06/19 14:45:11 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_check_isnum(int num, char **argv, int i)
{
    i++;
    while(argv[i])
    {
        if(ft_atoi(argv[i]) == num)
            return (1);
        i++;
    }
    return(0);
}

static int ft_isnum(char *num)
{
    int i;
    
    i=0;
    if (num[0] == '-')
        i++;
    while (num[i])
    {
        if(!ft_isdigit(num[i]))
            return (0);
        i++;
    }
    return(1);
}

void ft_check_argv(int argc, char **argv)
{
    int i;
    long tmp;
    char **args;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else 
    {
        i = 1;
        args = argv;
    }
    while(args[i])
    {
        tmp = ft_atoi(args[i]);
        if (!ft_isnum(args[i]))
            ft_putendl_fd("ERROR!!!! \n No es un numero!!", 1);
        if (ft_check_isnum(tmp, args, i))
            ft_putendl_fd("ERROR!!!! \n No es un numero!!", 1);
        if (tmp < -2147483648 || tmp > 2147483647)
            ft_putendl_fd("ERROR!!!! \n Es muy grande!!", 1);
        i++;
    }
    if (argc == 2)
        free(args);
}


// ** trabajar tanto con varios numeros como si  llevan ""
// ** error\n si no son numeros lo que encuentra
// ** error\n si encuentra repetidos
// ** error\n si no funcionna con INT_MAX O  INT_MIN