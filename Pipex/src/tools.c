/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:36:16 by dconza            #+#    #+#             */
/*   Updated: 2023/12/23 17:02:30 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void exit_handler(int n_exit)
{
    // Fonction de gestion de sortie, affiche un message d'usage si n_exit est 1
    if (n_exit == 1)
        ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
    exit(0);
}

int open_file(char *file, int in_or_out)
{
    // Ouvre un fichier en mode lecture ou écriture, en fonction de in_or_out
    int ret;

    if (in_or_out == 0)
        ret = open(file, O_RDONLY, 0777);
    if (in_or_out == 1)
        ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (ret == -1)
        exit(0);
    return (ret);
}

void ft_free_tab(char **tab)
{
    // Libère la mémoire allouée pour un tableau de chaînes de caractères
    size_t i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char *check_fonction(char *name, char **env)
{
    // Vérifie si une variable d'environnement spécifique existe et la renvoie
    int i;
    int j;
    char *sub;

    i = 0;
    while (env[i])
    {
        j = 0;
        while (env[i][j] && env[i][j] != '=')
            j++;
        sub = ft_substr(env[i], 0, j);
        if (ft_strcmp(sub, name) == 0)
        {
            free(sub);
            return (env[i] + j + 1);
        }
        free(sub);
        i++;
    }
    return (NULL);
}

char *get_path(char *cmd, char **env)
{
    // Recherche le chemin complet du binaire à partir du PATH de l'environnement
    int i;
    char *exec;
    char **allpath;
    char *path_part;
    char **s_cmd;

    i = -1;
    allpath = ft_split(check_fonction("PATH", env), ':');
    s_cmd = ft_split(cmd, ' ');
    while (allpath[++i])
    {
        path_part = ft_strjoin(allpath[i], "/");
        exec = ft_strjoin(path_part, s_cmd[0]);
        free(path_part);
        // Vérifie si le fichier est exécutable et existe
        if (access(exec, F_OK | X_OK) == 0)
        {
            ft_free_tab(s_cmd);
            return (exec);
        }
        free(exec);
    }
    ft_free_tab(allpath);
    ft_free_tab(s_cmd);
    // Si le binaire n'est pas trouvé dans le PATH, retourne la commande telle quelle
    return (cmd);
}
