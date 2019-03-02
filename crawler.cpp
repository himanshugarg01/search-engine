#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include <sys/types.h>
#include <sys/stat.h>
#define HASH_SIZE 100

#define Url_Length 1000

//#define SEED_URL "http://www.chitkara.edu.in"

#define MAX_URL_PER_PAGE 1000

#define INTERVAL_TIME 10
using namespace std;
char base_url[]="www.chitkara.edu.in";
char *str1,*str2,*str3;
int depth;
void copyFile()
{
  
}
void getPage(char *url)
{
char urlbuffer[Url_Length+300]={0};
strcat(urlbuffer, "wget -O ");
strcat(urlbuffer,"~/Desktop/se/temp.txt ");
strcat(urlbuffer, url);
//strcat(urlbuffer, " --proxy-user=user1 --proxy-password=user1");
system(urlbuffer);
copyFile();
}
void testDir(char *dir)
{
  struct stat statbuf;
  if ( stat(dir, &statbuf) == -1 )
  {
    fprintf(stderr, "-----------------\n");
    fprintf(stderr, "Invalid directory\n");
    fprintf(stderr, "-----------------\n");
    exit(1);
  }

  //Both check if there's a directory and if it's writable
  if ( !S_ISDIR(statbuf.st_mode) )
  {
    fprintf(stderr, "-----------------------------------------------------\n");
    fprintf(stderr, "Invalid directory entry. Your input isn't a directory\n");
    fprintf(stderr, "-----------------------------------------------------\n");
    exit(1);
  }

  if ( (statbuf.st_mode & S_IWUSR) != S_IWUSR )
  {
    fprintf(stderr, "------------------------------------------\n");
    fprintf(stderr, "Invalid directory entry. It isn't writable\n");
    fprintf(stderr, "------------------------------------------\n");
    exit(1);
  }
}
void checkDepth()
{

  if(str2[0]>='1'&&str2[0]<='5'&&str2[1]=='\0')
  {
    depth=str2[0]-48;
  }
  else
  {
    printf("Invalid depth");
  }
}
void validateUrl()
{
char str[strlen(str1)+20]="wget --spider ";
strcat(str,str1);
    if(!system(str))
    {
    printf("Valid URL");
    getPage(str1);
    }
  else
    printf("Invalid URL");
}
void checkUrl()
{
int i,flag=0;
for(i=0;base_url[i]!='\0';i++)
{
  if(base_url[i]!=str1[i])
  {
    flag=1;
      printf("Invalid url");
    break;
  }
}
if(flag==0)
{
  validateUrl();
}
}
void checkCreteria(int n)
{
  if(n==4)
  {
checkDepth();
checkUrl();
testDir(str3);
  }
  else
  {
    printf("Invalid input");
  }
}
int main(int argc,char *argv[])
{
  str1=argv[1];
  str2=argv[2];
  str3=argv[3];
//  cout<<str1<<endl<<str2<<endl<<str3;
checkCreteria(argc);
//crawl(str);
return 0;
}
