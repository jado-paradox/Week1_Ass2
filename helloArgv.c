#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void print_help() {
    printf("Usage: ./helloArgv [options]\n");
    printf("Options:\n");
    printf("  -m         Print a morning welcome message\n");
    printf("  -e         Print an evening welcome message\n");
    printf("  -m [num]   Print [num] morning welcome messages\n");
    printf("  -e [num]   Print [num] evening welcome messages\n");
    printf("  --help     Display this help message\n");
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Hello, World!\n");
        return 0;
    }

    int i, morning_count = 0, evening_count = 0;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-m") == 0) {
            if (i + 1 < argc && isdigit(argv[i + 1][0])) {
                morning_count = atoi(argv[i + 1]);
                i++;
            } else {
                morning_count = 1;
            }
        } else if (strcmp(argv[i], "-e") == 0) {
            if (i + 1 < argc && isdigit(argv[i + 1][0])) {
                evening_count = atoi(argv[i + 1]);
                i++;
            } else {
                evening_count = 1;
            }
        } else {
            printf("Unknown option: %s\n", argv[i]);
            print_help();
            return 1;
        }
    }

    for (i = 0; i < morning_count; i++) {
        printf("Good morning!\n");
    }

    for (i = 0; i < evening_count; i++) {
        printf("Good evening!\n");
    }

    return 0;
}
