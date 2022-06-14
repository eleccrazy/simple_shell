#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 *
 * Desc: This header file contains all the necessary function
 * prototypes, library files, and environ variable defination used in
 * the simple_shell project for the ALX Software engineering program.
 *
 * Authors: Gizachew Bayness (eleccrazy) & Abriham Tessfaye
 *
 * Date Created: Jun 6, 2022
 *
 */

extern char **environ;

#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int _strlen(char *str);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _atoi(char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
int _isalpha(int c);
int calc_len_int(int num);
char *_itoa(unsigned int num);
void rev_str(char *arr, int len);
int _putchar(char c);
void _puts(char *str);
void prints(char *s);
void error_print(char *filename, int c, char **cmd);
void print_error(char *input, int c, char *filename);
void custome_free(char **cmd, char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int size);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);
void comment_handler(char *str);
char *my_getline();
int check_delim(char ch, const char *d);
char *my_strtok(char *s, const char *d);
char *_getenv(char *name);
char *make_path(char *token, char *value);
int command_path(char **cmd);
int _strncmp(const char *s1, const char *s2, size_t n);
void shell_exit(char **cmd, char *input, char *filename, int c);

#endif
