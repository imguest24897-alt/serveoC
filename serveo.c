#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen() {
    system("clear");
}

void print_banner() {
    printf("__________________________________________________                             \n");
    printf(".    __   ___  __        ___  __         ___ ___                               \n");
    printf(".   /__` |__  |__) \\  / |__  /  \\  |\\ | |__   |                                \n");
    printf(".   .__/ |___ |  \\  \\/  |___ \\__/ .| \\| |___  |                                \n");
    printf(".                                                                              \n");
    printf("__________________________________________________                             \n");
    printf(".   %s // serveo.net easy commander v1                                         \n", __FILE__);
    printf("-------------------------------------------------                              \n");
    printf(". milio48 | pescyte | IDBTE4M | javcode | zerobyte                             \n");
    printf(". remade on c by guest24897                                                    \n");
    printf("__________________________________________________                             \n");
    printf(".                                                                              \n");
    printf(".     *ssh installed required*                                                 \n");
    printf("parameter : %s [http/tcp] [local port] [option]                                 \n", __FILE__);
    printf(".                                                                              \n");
    printf("     parameter [option] : 0 = request random port                              \n");
    printf("     parameter [option] : change = change http subdomain forwarded             \n");
    printf("     parameter [option] : 4869 = custom port number to forwarding (using tcp)  \n");
    printf(".                                                                              \n");
    printf("%s http  80 0             //localhost:80 forward to public https             \n", __FILE__);
    printf(".                                                                              \n");
    printf(".                                                                              \n");
    printf("%s tcp 4869 0             //random tcp port forwarding                       \n", __FILE__);
    printf("%s tcp 4869 1945          //custom tcp port forwarding                       \n", __FILE__);
    printf(".                                                                              \n");
    printf("__________________________________________________                             \n");
}

void execute_ssh_command(const char *command) {
    printf("");
    system(command);
    printf("__________________________________________________                             \n");
}

void run_serveo(const char *type, const char *local_port, const char *option) {
    char command[256];

    if (strcmp(type, "http") == 0) {
        if (strcmp(option, "change") == 0) {
            char hash[9];
            FILE *fp = popen("echo -n $(date) | md5sum | cut -c1-8", "r");
            if (fp == NULL) {
                fprintf(stderr, "Failed to run command\n");
                exit(1);
            }
            fgets(hash, sizeof(hash), fp);
            pclose(fp);
            hash[strcspn(hash, "\n")] = 0; // Remove newline character
            snprintf(command, sizeof(command), "ssh -R 80:localhost:%s %s@serveo.net", local_port, hash);
        } else if (atoi(option) > 1) {
            snprintf(command, sizeof(command), "ssh -R %s:localhost:%s serveo.net", option, local_port);
        } else {
            snprintf(command, sizeof(command), "ssh -R 80:localhost:%s serveo.net", local_port);
        }
        execute_ssh_command(command);
    }

    if (strcmp(type, "tcp") == 0) {
        if (atoi(option) > 1) {
            snprintf(command, sizeof(command), "ssh -R %s:localhost:%s serveo.net", option, local_port);
        } else {
            snprintf(command, sizeof(command), "ssh -R 0:localhost:%s serveo.net", local_port);
        }
        execute_ssh_command(command);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [http/tcp] [local port] [option]\n", argv[0]);
        return 1;
    }

    clear_screen();
    print_banner();

    printf("Running: %s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);
    printf("__________________________________________________                             \n");

    run_serveo(argv[1], argv[2], argv[3]);

    return 0;
}
