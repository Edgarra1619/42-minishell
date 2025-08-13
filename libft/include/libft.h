/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:33:53 by vde-albu          #+#    #+#             */
/*   Updated: 2025/07/24 12:11:25 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int		ft_isalpha(const int c);
int		ft_isdigit(const int c);
int		ft_isalnum(const int c);
int		ft_isascii(const int c);
int		ft_isprint(const int c);
int		ft_isspace(const int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_delim(const char *s, const char delim);
int		ft_max(const int n1, const int n2);
int		ft_min(const int n1, const int n2);
int		ft_abs(const int n);
int		ft_clamp(const int n, const int min, const int max);
float	ft_clampf(const float n, const float min, const float max);
int		ft_sign(const int n);
float	ft_signf(const float n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
int		ft_atoi_hex(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strappend(char **str1, const char *str2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(const int n);
size_t	ft_itoa_cpy(char *const str, const int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(const char c, const int fd);
void	ft_putstr_fd(const char *s, const int fd);
void	ft_putendl_fd(const char *s, const int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)());
void	ft_lstclear(t_list **lst, void (*del)());
void	ft_lstiter(t_list *lst, void (*f)());
t_list	*ft_lstmap(t_list *lst, void *(*f)(), void (*del)());

#endif
