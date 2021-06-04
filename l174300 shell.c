#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include <dirent.h>

struct File
{
	char path_of_file[100];
	char name_of_file[100];
	char password[100];
};
struct stack1
{
	char path_of_stack[30][100];
	int size_of_stack;
};
void push( struct stack1 *temp_value,char *value)
{
	if (temp_value->size_of_stack<30)
	{
		strcpy(temp_value->path_of_stack[temp_value->size_of_stack], value);
		temp_value->size_of_stack++;
	}
	else
	{
		printf("stack is not empty!\n");
	}
	return;
}
void pop(struct stack1 *temp_value1)
{
	if (temp_value1->size_of_stack>0){
		temp_value1->size_of_stack--;
		chdir(temp_value1->path_of_stack[temp_value1->size_of_stack]);
	}
	else
	{
		printf("stack is not full!\n");
	}
}
void top(struct stack1 temp_value2)
{
	if (temp_value2.size_of_stack > 0)
	{
		printf("%s\n", temp_value2.path_of_stack[temp_value2.size_of_stack - 1]);
	}
	else
	{
		printf("stack is not full!\n");
	}
}
void fnc(struct File temp_val[], int* size){
	char path[100];
	char pass[20];
	int cnt = 0;
	getcwd(path, 100);
	printf("password: ");
	scanf("%[^\n]%*c", pass);
	struct File files[20];
	if (size>0)
	{
		int i, j = 0;
		for (i=0; i < *size; i++)
		if (strcmp(path, temp_val[i].path_of_file) != 0 || strcmp(pass, temp_val[i].password) != 0)
		{
			strcpy(files[j++].name_of_file, temp_val[i].name_of_file);
			strcpy(files[j++].path_of_file, temp_val[i].path_of_file);
			strcpy(files[j++].password, temp_val[i].password);
			cnt++;
		}
		if (cnt<*size)
		{
			for (i = 0; i<*size - 1; i++)
			{
				strcpy(temp_val[i].name_of_file, files[i].name_of_file);
				strcpy(temp_val[i].path_of_file, files[i].path_of_file);
				strcpy(temp_val[i].password, files[i].password);
			}
			*size = *size - 1;
		}
		else
		{
			printf("password is wrong\n");
		}
	}
	return;
}

void myls(struct File temp_val[], int* size)
{
	char path[100];
	struct dirent *point1;
	int i, flag;
	DIR *point2 = opendir("."); 
	if (point2 == NULL)
	{ 
		printf("it is not open the current directory");
		return;
	}
	getcwd(path, 100);
	
	while ((point1 = readdir(point2)) != NULL){
		flag = 0;
		for (i = 0; i<*size; i++)
		if (strcmp(temp_val[i].path_of_file, path) == 0 && strcmp(temp_val[i].name_of_file, point1->d_name) == 0)
			flag++;
		if (flag == 0)
			printf("%s\n", point1->d_name);
	}
	closedir(point2);
	return;
}
void myPrivate(char* fileName,struct File temp_val[], int* size)
{
	struct dirent *point1; 
	int flag = 1;
	DIR *point2 = opendir("."); 
	while ((point1 = readdir(point2)) != NULL)
	if (strcmp(fileName, point1->d_name) == 0)
		flag = 0;
	closedir(point2);
	if (flag == 0)
	if (*size<30){
		char pass[20];
		printf("password: ");
		scanf("%[^\n]%*c", pass);
		char path[100];
		getcwd(path, 100);
		strcpy(temp_val[*size].path_of_file, path);
		strcpy(temp_val[*size].name_of_file, fileName);
		strcpy(temp_val[*size].password, pass);
		*size = *size + 1;
		printf("%s secured!\n", fileName);
	}
	else
		printf("no further files secured.\n");
	else
		printf("No further file found in the current directory.\n");
	return;
}

void mycd(char* temp){
	if (chdir(temp) != 0)
		printf("No such directory found\n");
	return;
}

void mypwd(){
	char path[100];
	getcwd(path, 100);
	printf("%s\n", path);
	return;
}


void function2(char *ary)
{
 char *ary11;
 ary11=(char*)malloc (sizeof(char*));
 char *ary12;
 ary12=(char*)malloc (sizeof(char*));
 char *ary1;
 ary1=(char*)malloc (sizeof(char*));
 char *ary2;
 ary2=(char*)malloc (sizeof(char*));
 int k=0,s1=0,s2=0;
 char key;
 while(ary[k]!='>'||ary[k]!='<')
 {
   ary1[s1]=ary[k];
   k=k+1;
   s1=s1+1;
 }
 ary1[s1]='\0';
 key=ary[k];
 k=k+1;
 while(ary[k]!='\0')
 {
  ary2[s2]=ary[k];
  s2=s2+1;
 }
 ary2[s2]='\0';
int m=0;
k=0;
while(ary1[k]!=' ')
 {
  ary11[m]=ary1[k];
  m++;
 }
 ary11[m]='\0';
m=0;
 k=k+1;
while(ary1[k]!='\0')
 {
  ary12[m]=ary1[k];
  m++;
 }
 ary12[m]='\0';

int cnt2=0;
int pid1 =fork();
	if(pid1==0)
	{
        int ret = execlp("/bin/ary11","ary11","l174300",(char *)0); 
	}
        else if(pid1>0)
	{   
		int pid2 =fork();
		if(pid2>0)
                {
		 wait(NULL);
		}
                else if(pid2==0)
		{
		 int ret = execlp("/bin/key","key","l174300",(char *)0); 
		}
	   
        }
}


void function1(char *ary)
{
 char *ary11;
 ary11=(char*)malloc (sizeof(char*));
 char *ary12;
 ary12=(char*)malloc (sizeof(char*));
 char *ary1;
 ary1=(char*)malloc (sizeof(char*));
 char *ary2;
 ary2=(char*)malloc (sizeof(char*));
 int k=0,s1=0,s2=0;
 while(ary[k]!='|')
 {
   ary1[s1]=ary[k];
   k=k+1;
   s1=s1+1;
 }
 ary1[s1]='\0';
 k=k+1;
 while(ary[k]!='\0')
 {
  ary2[s2]=ary[k];
  s2=s2+1;
 }
 ary2[s2]='\0';
int m=0;
k=0;
while(ary1[k]!=' ')
 {
  ary11[m]=ary1[k];
  m++;
 }
 ary11[m]='\0';
m=0;
 k=k+1;
while(ary1[k]!='\0')
 {
  ary12[m]=ary1[k];
  m++;
 }
 ary12[m]='\0';

int pid1 =fork();

	if(pid1==0)
	{
        int ret = execlp("/bin/ary11","ary11","l174300",(char *)0); 
	}
        else if(pid1>0)
	{
		wait(NULL);		   
 		
        }
}

int main(){
	int no_of_file = 0;
	struct stack1 stackp;
	struct File file[20];
	stackp.size_of_stack = 0;
	char input[100] = { "\0" };
	char command[10][50];
	char delim[2] = { " " };
	char path[100];
	char temp_directory[20];
	char current_directory[20];
	int  i=0, j=0, cnt=0;
	char* token;
	printf("Opening shell....\n");
	sleep(1);
	while (1)
        {
		cnt = 0;
		getcwd(path, 100);
		delim[0] = '/';
		token = strtok(path, delim);
		while (token != NULL) {
			strcpy(current_directory, token);
			token = strtok(NULL, delim);
		}
		printf("\033[1;31m");
		printf("17L-4300 ");
		printf("\033[1;34m");
		printf("-");
		printf("\033[0m");
		printf("\033[1;30m");
		printf("%s", current_directory);
		printf("\033[0m");
		printf(">");
		scanf("%[^\n]%*c", input);
		delim[0] = ' ';
		token = strtok(input, delim);

int m=0,counters=0,counterg=0,counterl=0;
while(token[m]!='\0')
{
 if(token[m]=='|')
 {
   counters=counters+1;
 }
 if(token[m]=='>')
 {
   counters=counters+1;
 }
 if(token[m]=='<')
 {
   counters=counters+1;
 }
 if(counters>=2)
 {
  printf("illegal command");
  break;
 }
 m=m+1;
}

if(counters==1 && counterl==0&&counterg==0)
 {
  function1(token);
 }
if(counters==0 )
 {
  if(counterl==1||counterg==1)
    {
     function1(token); 
    }
 }



		while (token != NULL) 
                {
			strcpy(command[cnt++], token);
			token = strtok(NULL, delim);
		}

		if (strcmp(command[0], "ls") == 0)
		if (cnt>1)
		if (strcmp(command[1], "-private") == 0)
			fnc(file, &no_of_file);
		else
			printf("No such command found\n");
		else
			myls(file, &no_of_file);
		else if (strcmp(command[0], "private") == 0)
			myPrivate(command[1],file, &no_of_file);
		else if (strcmp(command[0], "cd") == 0){
			if (cnt>2)
                        {
				strcat(command[1], " ");
				strcat(command[1], command[2]);
			}
			mycd(command[1]);
		}
		else if (strcmp(command[0], "pwd") == 0)
			mypwd();
		else if (strcmp(command[1], "push") == 0)
                        {
			getcwd(path, 100);
			if (chdir(command[0]) == 0)
				push(&stackp, path);
			else
				printf("no such directory found!\n");
		}
		else if (strcmp(command[0], "pop") == 0)
		if (cnt>1)
		if (strcmp(command[1], "-showtop") == 0)
			top(stackp);
		else
			printf("No such command found!\n");
		else
			pop(&stackp);
		else if (strcmp(command[0], "exit") == 0)
			break;
		else
			printf("No such command found, !\n");
	}
	printf("Exiting shell....\n");
	sleep(1);
	return 0;
}
