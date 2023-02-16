#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int archive(char *filename);
int unarchive(char *filename);

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("Too fewer arguments specified. See mai_tar -h");
	}
	else {
		if (strcmp(argv[1], "-h") == 0) {
			printf("Usage: mai_tar [-a | -u] <filename>\nUse -a flag to archive and -u to unarchive");
		}
		else if (strcmp(argv[1], "-a") == 0) {
			archive(argv[2]);	
		}
		else if (strcmp(argv[1], "-u") == 0) {
			unarchive(argv[2]);
		}
		else {
			printf("%s - unknown flag", argv[1]);
		}
	}
	return 0;
}

int archive(char *filename) {
	char command[255];
	strcpy(command, "tar -c ");
        strcat(command, filename);
	strcat(command, " -f ");
	strcat(command, strcat(filename, "_archive"));	
	system(command);
}

int unarchive(char *filename) {
	char command[255];
	strcpy(command, "tar -xf ");
	strcat(command, filename);
	system(command);
}
