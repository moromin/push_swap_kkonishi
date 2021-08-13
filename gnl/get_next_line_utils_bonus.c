#include "get_next_line_bonus.h"

char	*gnl_strjoin(char **s1, char const *s2, size_t size1, size_t size2)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!*s1 || !s2)
		return (NULL);
	tmp = *s1;
	*s1 = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!*s1)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size1 + size2)
	{
		if (i < size1)
			(*s1)[i] = tmp[i];
		else if (i < size1 + size2)
			(*s1)[i] = s2[j++];
		i++;
	}
	(*s1)[i] = '\0';
	free(tmp);
	return (*s1);
}

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_strdup(const char *src, char **dst, size_t len)
{
	size_t	i;
	char	*tmp;

	if (!src)
		return (NULL);
	i = 0;
	tmp = *dst;
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!*dst)
		return (NULL);
	while (i < len)
	{
		(*dst)[i] = src[i];
		i++;
	}
	(*dst)[i] = '\0';
	free(tmp);
	return (*dst);
}

void	node_delete(t_gnl **data, t_gnl *tmp)
{
	t_gnl	*tmp_prev;

	tmp_prev = tmp->prev;
	if (tmp->prev)
		tmp_prev->next = tmp->next;
	else
		*data = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp_prev;
	free(tmp);
	tmp = NULL;
}
