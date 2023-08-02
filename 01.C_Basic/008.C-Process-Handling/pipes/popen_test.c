#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define PATH_MAX 1000

int main(int argc, char** argv)
{
    FILE *fp;
    int status;
    char path[PATH_MAX];

    fp = popen("ls *", "r");

    while (fgets(path, PATH_MAX, fp) != NULL)
        printf("%s", path);

    pclose(fp);
    exit(EXIT_SUCCESS);
}