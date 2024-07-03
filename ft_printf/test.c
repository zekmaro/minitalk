/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:59:43 by anarama           #+#    #+#             */
/*   Updated: 2024/04/25 11:31:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	ft_printf("%");
	ft_printf("\n");
	printf("%   s");
}
// spaces after % and a flag (is it bouns?)
// just %
// null in s, null in p
// nothing
// nulls in d and i
// > int max, < int min, int min
// %%% (and return should be minus 1)
// % and random letter (whats wrong wit q,m,t...?)
// % and not a letter
// % and escape sequences
// empty specifiers (should be undefined behaviour?)

// if theres any char after % printf prints it