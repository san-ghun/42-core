/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:28:06 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/14 17:31:27 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    int     i;
    // int     fd[2];
    // pid_t   pid1;

    i = 0;
    (void)argc;
    while (argv[i])
        printf("argv i = %s\n", argv[i++]);
    i = 0;
    while (envp[i])
        printf("envp i = %s\n", envp[i++]);
}