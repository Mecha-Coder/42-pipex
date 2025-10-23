/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:48:50 by jpaul             #+#    #+#             */
/*   Updated: 2024/07/30 14:48:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str && *str++)
		i++;
	return (i);
}

int	initialize(t_data *data, char **keep, int fd)
{
	data->skip = FALSE;
	data->loop = TRUE;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (TRUE);
	data->n = found_new_line(keep[fd]);
	if (data->n > 0)
	{
		data->line = extract(keep[fd], data->n);
		data->temp = trim(keep[fd], data->n);
	}
	return (FALSE);
}

void	reach_end(t_data *data, char **keep, int fd)
{
	if (data->readno <= 0)
	{
		data->loop = FALSE;
		data->line = keep[fd];
		data->temp = NULL;
		data->skip = TRUE;
	}
}

void	read_file(t_data *data, char **keep, int fd)
{
	while (data->loop)
	{
		data->readno = read(fd, data->buff, BUFFER_SIZE);
		if (data->readno > 0)
		{
			transform(data->buff, data->readno);
			data->n = found_new_line(data->buff);
			if (data->n > 0)
			{
				data->loop = FALSE;
				data->temp = extract(data->buff, data->n);
				data->line = join(keep[fd], data->temp);
				free(data->temp);
				data->temp = trim(data->buff, data->n);
			}
			else
			{
				data->temp = join(keep[fd], data->buff);
				if (keep[fd])
					free(keep[fd]);
				keep[fd] = data->temp;
			}
		}
		reach_end(data, keep, fd);
	}
}

char	*get_next_line(int fd)
{
	static char	*keep[LENGTH];
	t_data		data;

	if (initialize(&data, keep, fd))
		return (NULL);
	if (data.n <= 0)
		read_file(&data, keep, fd);
	if (keep[fd] && !data.skip)
		free(keep[fd]);
	keep[fd] = data.temp;
	return (data.line);
}

/*
https://miro.com/welcomeonboard/djYyTEZmb01nTjNxMXdaU2lxWnJCbmNZQnFuTFVocGpBa
FA3WXIyclZiVTZ1T3I2TmE2VDF1RmVkekhmOUlRZ3wzMDc0NDU3MzYxNzgyMDI0NjMzfDI
=?share_link_id=445591210704
int main()
{
	int fd1, fd2, fd3, fd4, fd5;
	int loop = TRUE;
	char *line1, *line2, *line3, *line4, *line5;
	int lineNo = 1;

	fd1 = open("1.txt", O_RDONLY);
	fd2 = open("2.txt", O_RDONLY);
	fd3 = open("3.txt", O_RDONLY);
	fd4 = open("4.txt", O_RDONLY);
	fd5 = open("5.txt", O_RDONLY);

	while (loop)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		line4 = get_next_line(fd4);
		line5 = get_next_line(fd5);
		if (line1 || line2 || line3 || line4 || line5)
		{
			printf("1,#%u -> %s\n\n", lineNo, line1);
			printf("2,#%u -> %s\n\n", lineNo, line2);
			printf("3,#%u -> %s\n\n", lineNo, line3);
			printf("4,#%u -> %s\n\n", lineNo, line4);
			printf("5,#%u -> %s\n\n", lineNo, line5);
			printf("-------------------------------------------------\n\n");
			lineNo++;
		}
		else
			loop = FALSE;
		if(line1) {free (line1) ; line1 = NULL;}
		if(line2) {free (line2) ; line2 = NULL;}
		if(line3) {free (line3) ; line3 = NULL;}
		if(line4) {free (line4) ; line4 = NULL;}
		if(line5) {free (line5) ; line5 = NULL;}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
}

int main()
{
	int fd;
	int loop = TRUE;
	char *line;
	int lineNo = 1;

	fd = open("6.txt", O_RDONLY);
	while (loop)
	{
		line = get_next_line(fd);

		if (line)
		{
			printf("#%u -> %s\n\n", lineNo, line);
			lineNo++;
		}
		else
			loop = FALSE;
		if(line) {free (line) ; line = NULL;}

	}
	close(fd);
}
*/