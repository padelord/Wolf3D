/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:53:09 by padelord          #+#    #+#             */
/*   Updated: 2019/10/09 17:37:33 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 256
# endif
# ifndef SIZEOF_LL
#  define SIZEOF_LL sizeof(long long)
# endif

# define C_BLACK	"000;000;000"
# define C_WHITE	"255;255;255"
# define C_RED		"255;000;000"
# define C_GREEN	"000;160;000"
# define C_BLUE		"000;000;255"
# define C_GIRLY	"255;125;200"
# define C_YELLOW	"255;255;000"
# define C_PINK		"255;000;255"
# define C_CYAN		"000;255;255"
# define C_GRAY		"100;100;100"

# define C_RESET "0"
# define C_BOLD "1"
# define C_FAINT "2"
# define C_ITALIC "3"
# define C_ULINE "4"
# define C_BLINK "5"

typedef	struct s_list	t_list;

struct	s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_lstbasicdel(void *content, size_t size);

int				ft_isspace(int c);
void			ft_putstr_color(const char *str, const char *attr, const char *fg,
								const char *bg);
void				ft_putchar_color(const char c, const char *attr, const char *fg,
								const char *bg);
void				ft_putendl_color(const char *str, const char *attr, const char *fg,
								const char *bg);
void			ft_cswap(char *a, char *b);
char			*ft_strrev(char *str);
int				ft_iswspace(int c);
char			*ft_staticitoa(int nb);
void			*ft_memdup(const void *src, size_t n);
void			ft_wtabdel(char **tab);
size_t			ft_min(size_t n1, size_t n2);
void			ft_putnchar(char c, size_t len);
void			ft_putnstr(const char *str, size_t n);
void			ft_lstpback(t_list **alst, t_list *new);
void			ft_putnbrendl(int nb);
void			ft_putwordtab(char **tab);
size_t			ft_lstgetsize(t_list *lst);
char			*ft_lsttostr(t_list *lst);
void			ft_displstr(t_list *lst);
int				ft_strocontent(char *src, char *content);
int				ft_ischars(char *src, char *content);
unsigned int	ft_sqrti(unsigned int n);

#endif
