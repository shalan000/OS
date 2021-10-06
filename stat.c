#include <stdio.h>
#include <sys/stat.h>
int main()
{
char path[100];
struct stat stats;
printf("Enter source file path: ");
scanf("%s", path);
if (stat(path, &stats) == 0)
{
//printFileProperties(stats);
printf("\nFile size: %ld Bytes\n", stats.st_size);
}
else
{
printf("Unable to get file properties.\n");
printf("Please check whether '%s' file exists.\n",path);
}
}
