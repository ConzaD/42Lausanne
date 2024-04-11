/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:01:23 by dconza            #+#    #+#             */
/*   Updated: 2024/03/12 11:19:53 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Sépare la commande en tokens (mots) et
// récupère le chemin du binaire à exécuter
// Exécute le binaire avec les arguments et l'environnement fournis
// Gère le cas où l'exécution échoue en affichant un message d'erreur
void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(0);
	}
}

// Ouvre le fichier d'entrée et redirige l'entrée standard vers ce fichier
// Redirige la sortie standard vers le côté écriture du tube (pipe)
// Exécute la commande du premier argument avec l'environnement donné
void	child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(av[2], env);
}

// Ouvre le fichier de sortie et redirige la sortie standard vers ce fichier
// Redirige l'entrée standard vers le côté lecture du tube (pipe)
// Exécute la commande du troisième argument avec l'environnement donné
void	parent(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(av[3], env);
}

// Vérifie le nombre d'arguments, gère les erreurs si nécessaire
// Crée un tube (pipe) pour la communication entre les processus
// Crée un processus fils
// Si c'est le processus fils, exécute la fonction child
// Si c'est le processus parent, exécute la fonction parent
int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
		exit_handler(1);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(av, p_fd, env);
	parent(av, p_fd, env);
}
