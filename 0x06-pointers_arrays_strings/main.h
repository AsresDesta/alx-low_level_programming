#ifnder MAIN_H
#define MAIN-H
/**
 * File: main.h
 *
 * Desc: header file containing prototypes for all functions
 * used in the 0x06.c - more pointers, array and strings directory.
 */
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void reverse_array(int *a, int n);
char *string_toupper(char *str);
char *cap_string(char *);
char *leet(char *);
char *rot13(char *);
void print_number(int n);
char *infinite_add(char *nl, char *r, int size_r);
void print_buffer(char *b, int size);
