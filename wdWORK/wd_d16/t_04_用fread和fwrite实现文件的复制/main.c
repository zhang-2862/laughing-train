#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4096
//用 fread / fwrite 实现文件的复制。
//
//// copyFile.c
//int main(int argc, char* argv[]); ​
int main(int argc, char* argv[]) {
	FILE* src= fopen(argv[1],"rb");
	if (!src) {
		fprintf(stderr, "%s open failed\n.", argv[1]);
		exit(1);
	}
	FILE* dst = fopen(argv[2], "wb");
	if (!dst) {
		fprintf(stderr, "%s open failed\n.", argv[2]);
		fclose(src);
		exit(1);
	}

	int n=0;
	char buffer[MAX_SIZE];
	while ((n=fread(buffer,1,MAX_SIZE,src))>0) {
		fwrite(buffer, 1, n, dst);
	}

	fclose(src);
	fclose(dst);

	return 0;
}