/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:43:27 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/03 22:24:04 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 2056
# define MAX_FD 256
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
long			ft_atoi(char *str);
void			*ft_memalloc(size_t size);
int				ft_strequ(char const *s1, char const *s2);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);
char			*ft_strchr(const char *src, int n);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *str);
int             get_next_line(const int fd, char **line);

#endif
