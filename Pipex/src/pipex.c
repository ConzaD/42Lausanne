/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:04:29 by dconza            #+#    #+#             */
/*   Updated: 2023/12/23 17:02:30 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void exec(char *cmd, char **env)
{
    // Sépare la commande en tokens (mots) et récupère le chemin du binaire à exécuter
    char **s_cmd;
    char *path;

    s_cmd = ft_split(cmd, ' ');
    path = get_path(s_cmd[0], env);

    // Exécute le binaire avec les arguments et l'environnement fournis
    if (execve(path, s_cmd, env) == -1)
    {
        // Gère le cas où l'exécution échoue en affichant un message d'erreur
        ft_putstr_fd("pipex: command not found: ", 2);
        ft_putendl_fd(s_cmd[0], 2);
        ft_free_tab(s_cmd);
        exit(0);
    }
}

void child(char **av, int *p_fd, char **env)
{
    // Ouvre le fichier d'entrée et redirige l'entrée standard vers ce fichier
    int fd = open_file(av[1], 0);
    dup2(fd, 0);

    // Redirige la sortie standard vers le côté écriture du tube (pipe)
    dup2(p_fd[1], 1);
    close(p_fd[0]);

    // Exécute la commande du premier argument avec l'environnement donné
    exec(av[2], env);
}

void parent(char **av, int *p_fd, char **env)
{
    // Ouvre le fichier de sortie et redirige la sortie standard vers ce fichier
    int fd = open_file(av[4], 1);
    dup2(fd, 1);

    // Redirige l'entrée standard vers le côté lecture du tube (pipe)
    dup2(p_fd[0], 0);
    close(p_fd[1]);

    // Exécute la commande du troisième argument avec l'environnement donné
    exec(av[3], env);
}

int main(int ac, char **av, char **env)
{
    // Vérifie le nombre d'arguments, gère les erreurs si nécessaire
    int p_fd[2];
    pid_t pid;

    if (ac != 5)
        exit_handler(1);

    // Crée un tube (pipe) pour la communication entre les processus
    if (pipe(p_fd) == -1)
        exit(-1);

    // Crée un processus fils
    pid = fork();
    if (pid == -1)
        exit(-1);

    // Si c'est le processus fils, exécute la fonction child
    if (!pid)
        child(av, p_fd, env);

    // Si c'est le processus parent, exécute la fonction parent
    parent(av, p_fd, env);
}
