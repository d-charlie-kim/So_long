/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:27:00 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/01 19:58:51 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"
# include "stdio.h"

int		get_next_line(int fd, char **line);
int		ft_save(char **line, char **save);
void	ft_repeat(char **temp, char **save, char *buffer, ssize_t size);
int		ft_return_zero(char **line, char **save, char *buffer, ssize_t size);
int		ft_return_one(char **line, char **save, char *buffer, ssize_t size);
int		ft_check(char *str, ssize_t size);
void	ft_memcpy(char *dst, char *src, ssize_t n);
int		ft_strlen(char *str);
void	gnl_error(char *str, char *ptr1, char *ptr2);

#endif
