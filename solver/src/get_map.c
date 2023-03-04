/*
** EPITECH PROJECT, 2023
** Sudoki
** File description:
** get_map
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LIMIT_Y 11
#define LIMIT_X 21
#define ARRETE "|------------------|\n"

int size_tab(char **tab)
{
    int i = 0;
    if (!tab)
        return 0;
    for (; tab[i] != NULL; ++i) {
    }
    return i;
}

void print_tab(char **tab)
{
    for(int i = 0; tab[i] != NULL; i++) {
        printf("%s", tab[i]);
    }
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; ++i) {
        free(tab[i]);
    }
    free(tab);
}

static char **add_value(char **tab, char *str)
{
    int i = 0;
    char **new_tab = malloc(sizeof(char *) * (size_tab(tab) + 2));

    if (!tab) {
        new_tab[i] = malloc(strlen(str) + 1 * sizeof(char));
        new_tab[i] = strcpy(new_tab[i], str);
        new_tab[i + 1] = NULL;
        return new_tab;
    }
    for (i = 0; tab[i] != NULL; ++i) {
        new_tab[i] = malloc(strlen(tab[i]) + 1 * sizeof(char));
        new_tab[i] = strcpy(new_tab[i], tab[i]);
    }
    new_tab[i] = malloc(strlen(str) + 1 * sizeof(char));
    new_tab[i] = strcpy(new_tab[i], str);
    new_tab[i + 1] = NULL;
    free_tab(tab);
    return new_tab;
}

void print_line(int *line)
{
    for (int i = 0; i != 9; ++i) {
        printf("%d", line[i]);
    }
    printf("\n");
}

void print_map(int **map)
{
    for (int i = 0; i != 9; ++i) {
        print_line(map[i]);
    }
}

static int *convert_line(char *str)
{
    int *line = malloc(sizeof(int) * 9);
    int inc = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (i % 2)
            continue;
        if (str[i + 1] == '\0') {
            if (str[i] != '\n')
                return NULL;
        } else if ((i == 0 || str[i + 2] == '\0')) {
            if (str[i] != '|')
                return NULL;
        } else {
            if (str[i] == ' ')
                line[inc] = 0;
            else 
                line[inc] = str[i] - '0';
            ++inc;
        }
            
    }
    return line;
}

static int **convert_map(char **tab)
{
    int **map = malloc(sizeof(int *) * 9);
    int inc = 0;

    if (size_tab(tab) != LIMIT_Y)
        return NULL;
    for (int i = 0; tab[i]; ++i) {
        if (strlen(tab[i]) != LIMIT_X) {
            return NULL;
        }
        if (i == 0 || i == LIMIT_Y - 1) {
            if (strcmp(tab[i], ARRETE) != 0)
                return NULL;
        } else {
            map[inc] = convert_line(tab[i]);
            if (map[inc] == NULL)
                return NULL;
            inc++;
        }
    }
    return map;
}

int **get_map(void)
{
    char *line = NULL;
    size_t len = 0;
    char **tab = NULL;
    int **map = NULL;

    while (getline(&line, &len, stdin) != -1 ) {
        tab = add_value(tab, line);
    }
    map = convert_map(tab);
    if (map == NULL) {
        printf("ERROR\n");
        return NULL;
    }
    free_tab(tab);
    free(line);
    return map;
}