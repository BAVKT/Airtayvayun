/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:46:11 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/15 18:57:17 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H
# define RESET 				"\x1b[0m"
# define RED     			"\x1b[31m"
# define GREEN   			"\x1b[32m"
# define YELLOW  			"\x1b[33m"
# define BLUE    			"\x1b[34m"
# define MAGENTA 			"\x1b[35m"
# define CYAN    			"\x1b[36m"
# define WHITE    			"\x1b[37m"
# define RED_BOLD     		"\x1b[1;31m"
# define GREEN_BOLD   		"\x1b[1;32m"
# define YELLOW_BOLD  		"\x1b[1;33m"
# define BLUE_BOLD    		"\x1b[1;34m"
# define MAGENTA_BOLD 		"\x1b[1;35m"
# define CYAN_BOLD    		"\x1b[1;36m"
# define WHITE_BOLD   		"\x1b[1;37m"
# define WHITE_BK_RED_FG    "\x1b[47;31m"
# define BLUE_BK_WHITE_FG   "\x1b[44;37m"
# define GREEN_BK_YELLOW_FG "\x1b[42;33m"
# include <string.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 666666

typedef struct		s_lst
{
	int				fd;
	char			*str;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Char*
*/
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *str, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *str, const char *s2, size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *s2);
char				*ft_revstr(char *str);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *dst, char *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** Char
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					is_upper(char s);
char				*repeat(int n, char c);

/*
** List
*/
int					ft_lenlst(t_list *lst);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstpush(t_list lst, t_list new);

/*
** Memory
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_swap(void *a, void *b);
void				ft_memdel(void **ap);
void				ft_strdel(char **s);

/*
** Display
*/
void				ft_putstr(char *str);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putcharendl(char c);
void				ft_putnbr(int nb);
void				ft_putnbrendl(int i);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int fd, int nb);
void				ft_putstrcolor(char *str, char *color);
void				ft_putendlcolor(char *str, char *color);
void				ft_putnbrcolor(int i, char *color);

/*
** Tab
*/
int					*ft_range(int min, int max);
void				ft_foreach(int *tab, int lenght, void (*f)(int));
char				**ft_remp_tab(char **tab, int size, char *str);
void				swap_tab(void **a, void **b);
char				**ft_init_tab(int size);
char				**ft_cp_tab(char **tab, char **dst);
int					tab_len(char **tab);
void				free_tab(void **tab);
void				ft_print_tab(char **str);
char				**tab_new(int size);
char				**sort_ascii(char **tab);
char				*search_tab(char **tab, char *str);

/*
** Other
*/
int					get_next_line(int const fd, char **line);
void				ft_changecolor(char *color);
void				ft_resetcolor();
void				ft_rot(int nb, char *str, int start, int end);
char				*ft_file_to_str(char *av);
char				*no_case(char *str);

/*
** Int
*/
char				*ft_itoa(int n);
int					ft_sqrt(int nb);

#endif
