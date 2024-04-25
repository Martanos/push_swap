/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/27 12:20:38 by malee             #+#    #+#             */
/*   Updated: 2024/03/27 12:20:38 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	init_handlers(t_conversion_handlers *handlers)
{
	handlers[0] = (t_conversion_handlers){"c", &handle_char};
	handlers[1] = (t_conversion_handlers){"s", &handle_string};
	handlers[2] = (t_conversion_handlers){"p", &handle_pointer};
	handlers[3] = (t_conversion_handlers){"x", &handle_lower_hex};
	handlers[4] = (t_conversion_handlers){"X", &handle_upper_hex};
	handlers[5] = (t_conversion_handlers){"i", &handle_int};
	handlers[6] = (t_conversion_handlers){"d", &handle_int};
	handlers[7] = (t_conversion_handlers){"u", &handle_uint};
	handlers[8] = (t_conversion_handlers){"ld", &handle_int};
	handlers[9] = (t_conversion_handlers){"\0", NULL};
}

int	execute_handler(va_list *ap, const char **format,
		t_conversion_handlers *handlers)
{
	ssize_t count;
	const char *specifier;
	size_t idx;

	specifier = *format;
	idx = 0;
	while (handlers[idx].handler)
	{
		if (ft_strncmp(handlers[idx].specifier, specifier,
				ft_strlen(handlers[idx].specifier)) == 0)
		{
			count = handlers[idx].handler(ap);
			(*format) += ft_strlen(handlers[idx].specifier);
			return (count);
		}
		idx++;
	}
	count = write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	t_conversion_handlers handlers[10];
	ssize_t count;
	const char *str;

	init_handlers(handlers);
	va_start(ap, format);
	count = 0;
	str = format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				count += write(1, str++, 1);
			else
				count += execute_handler(&ap, &str, handlers);
		}
		else
			count += write(1, str++, 1);
	}
	va_end(ap);
	return (count);
}

// int main() {
//     printf("Test 6: (void *)LONG_MIN, (void *)LONG_MAX\n");
//     printf("Actual: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
//     ft_printf("Custom: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);

//     printf("\nTest 8: (void *)ULONG_MAX, (void *)-ULONG_MAX\n");
//     printf("Actual: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
//     ft_printf("Custom: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);

//     printf("\nTest 9: (void *)0, (void *)0\n");
//     printf("Actual: %p %p \n", (void *)0, (void *)0);
//     ft_printf("Custom: %p %p \n", (void *)0, (void *)0);

//     return (0);
// }
