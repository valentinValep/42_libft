/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:28:34 by vlepille          #+#    #+#             */
/*   Updated: 2023/10/04 16:57:06 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <unistd.h>

# define CONVERSION_NUMBER 9
# define PRINTF_BUFFER_SIZE 512

int		ft_printf_fd(int fd, const char *format, ...);

typedef struct s_display_buffer_fd {
	char	buffer[PRINTF_BUFFER_SIZE];
	int		offset;
	int		total_length;
}	t_display_buffer_fd;

void	ft_write_buf_fd(
			int fd, t_display_buffer_fd *buf, char const *str, int len);

typedef void	(*t_fun_conv_fd)(va_list *, t_display_buffer_fd *buf, int fd);

void	ft_char_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);
void	ft_string_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);
void	ft_pointer_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);
void	ft_decimal_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);
void	ft_integer_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);
void	ft_unsigned_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);
void	ft_lower_hexa_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);
void	ft_upper_hexa_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);
void	ft_percent_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd);

char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
void	ft_long_to_hexa(unsigned long long nbr, char *output, int i);
char	*ft_itoa_hexa(unsigned int n, int lower);

#endif
