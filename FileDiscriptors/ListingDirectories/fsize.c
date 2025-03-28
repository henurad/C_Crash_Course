#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 1024


void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));


int main(int argc, char **argv){
    if(argc == 1){
        fsize(".");
    } else {
        while(--argc > 0){
            fsize(*++argv);
        }
    }
}

/* Print size of file "name" */
void fsize(char *name){
    struct stat stbuf;

    if(stat(name, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if((stbuf.st_mode & S_IFMT) == S_IFDIR){
        dirwalk(name, fsize);
    }
    printf("%8ld %s\n", stbuf.st_size, name);
}

void dirwalk(char *dir, void (*fcn)(char *)){
    char name[MAX_PATH];
    DIR *dfd;
    struct dirent *dp;

    if((dfd = opendir(dir)) == NULL){
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }

    while((dp = readdir(dfd)) != NULL){
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
            continue;
        }

        if(strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)){
            fprintf(stderr, "dirwalk: name %s/%s is too long\n", dir, dp->d_name);
        } else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }

    closedir(dfd);
}