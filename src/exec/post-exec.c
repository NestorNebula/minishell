/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post-exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:43:33 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/05 18:43:51 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "exec.h"
#include "file.h"

void	close_files(t_command *command)
{
	t_dll	*file_node;
	t_file	*file;

	if (command == NULL)
		return ;
	file_node = command->in_files;
	while (file_node != NULL && file_node->data != NULL)
	{
		file = file_node->data;
		if (file->status == F_OK && file->type == FILE_REG)
			close(file->fd);
		file_node = file_node->next;
	}
	file_node = command->out_files;
	while (file_node != NULL && file_node->data != NULL)
	{
		file = file_node->data;
		if (file->status == F_OK && file->type == FILE_REG)
			close(file->fd);
		file_node = file_node->next;
	}
}
