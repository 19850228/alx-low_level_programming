#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16

void generate_key(char *username, char *key) {
    // Simple key generation algorithm
    int i, len;
    len = strlen(username);

    for (i = 0; i < len; i++) {
        key[i] = username[i] ^ (len - i);
    }

    key[len] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return EXIT_FAILURE;
    }

    char key[MAX_KEY_LENGTH];
    generate_key(argv[1], key);

    printf("%s\n", key);

    return EXIT_SUCCESS;
}
