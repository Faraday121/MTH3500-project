#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>		//_getch()
#include<stdlib.h>		//system()
#include<string.h>		//strlen()
#define Length 10
void Menu();
void InputStudent();
void SearchStudent();
void ModifyStudent();
void DeleteStudent();
void generate();

int main() {
	while (1){
		Menu();
		char ch = _getch();
		switch (ch){
		case '1':
			InputStudent();
			break;
		case '2':
			SearchStudent();
			break;
		case '3':
			ModifyStudent();
			break;
		case '4':
			DeleteStudent();
			break;
		case '5':
			generate();
			break;
		case '0':
			return 0;
			break;
		default:
			printf("Wrong input,no function available\n\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
void Menu() {
	printf("*********************************************************\n");
	printf("*\tWelcome to use the student management system\t*\n");
	printf("*\t\tselect the function you need\t\t*\n");
	printf("*********************************************************\n");
	printf("*\t\t1.input new student record\t\t*\n");
	printf("*\t\t2.search student record\t\t\t*\n");
	printf("*\t\t3.modify student record\t\t\t*\n");
	printf("*\t\t4.delete student record\t\t\t*\n");
	printf("*\t\t5.generate student form\t\t\t*\n");
	printf("*\t\t0.Exit system\t\t\t\t*\n");
	printf("*********************************************************\n");
}
void InputStudent() {

	char* token;
	char help[256];
	FILE* fp;
	fp = fopen("student.dat", "r");
	fscanf(fp, "%s", help);
	token = strtok(help, ",");
	int t[100] = { 0 };
	int i = 0;
	while (token != NULL) {
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	int matrix;
	int score;

	printf("Pls input matric number(from 100 to 999)£º\n");
	scanf("%d", &matrix);
	printf("Pls input score£º(from 0 to 10)\n");
	scanf("%d", &score);
	printf("Matrix:%d,Score:%d", matrix, score);
	
	for (i = 0; i < Length; i += 2) {
		if (t[i] == 0) {
			t[i] = matrix;
			t[i + 1] = score;
			break;
		}
	}

	//update new array into file
	FILE* pFile = fopen("student.dat", "w");

	////write data 
	for (i = 0; i < Length; i += 2) {
		fprintf(pFile, "%d,%d,", t[i], t[i + 1]);
	}
	printf("Successfully updated\n");

	fclose(pFile);
	fclose(fp);

	system("pause");
	system("cls");
}
void SearchStudent(){
	int Inputid;
	printf("Pls input the matric you want to search£º\n");
	scanf("%d", &Inputid);

	char* token;
	char help[256];
	FILE* fp;
	fp = fopen("student.dat", "r");
	fscanf(fp, "%s", help);
	token = strtok(help, ",");
	int t[100] = {0};
	int i = 0;
	while (token != NULL) {
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	for (i = 0; i < 10; i++) {
		if (t[i] == Inputid) {
			printf("Student matrix is :%d\tThe score is :%d\n", t[i], t[i + 1]);
			break;
		}
	}
	fclose(fp);
	system("pause");
	system("cls");
}

void ModifyStudent() {

	char* token;
	char help[256];
	FILE* fp;
	fp = fopen("student.dat", "r");
	fscanf(fp, "%s", help);
	token = strtok(help, ",");
	int t[100] = { 0 };
	int i = 0;
	while (token != NULL) {
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	printf("Input matric number\n");
	printf("Select which student you want to modify:\n");
	int target;
	scanf("%d", &target);
	printf("Input the updated score:\n");
	int newscore;
	scanf("%d",&newscore);
	for (i = 0; i < Length; i+=2) {
		if (t[i] == target) {
			t[i + 1] = newscore;
		}
	}

	//update new array into file
	FILE* pFile = fopen("student.dat", "w");

	////write data 
	for (i = 0; i < Length; i += 2) {
		fprintf(pFile, "%d,%d,",t[i],t[i+1]);
	}
	printf("Successfully updated\n");

	fclose(pFile);
	fclose(fp);

	system("pause");
	system("cls");
}
void DeleteStudent() {

	char* token;
	char help[256];
	FILE* fp;
	fp = fopen("student.dat", "r");
	fscanf(fp, "%s", help);
	token = strtok(help, ",");
	int t[100] = { 0 };
	int i = 0;
	while (token != NULL) {
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	printf("Input matric number\n");
	printf("Select which student you want to delete:\n");
	int target;
	scanf("%d", &target);

	for (i = 0; i < Length; i += 2) {
		if (t[i] == target) {
			t[i] = 0;
			t[i + 1] = 0;
			break;
		}
	}

	//update new array into file
	FILE* pFile = fopen("student.dat", "w");

	////write data 
	for (i = 0; i < Length; i += 2) {
		fprintf(pFile, "%d,%d,", t[i], t[i + 1]);
	}
	printf("Successfully deleted\n");

	fclose(pFile);
	fclose(fp);
	system("pause");
	system("cls");
}

void generate() {

	char* token;
	char help[256];
	FILE* fp;
	fp = fopen("student.dat", "r");
	fscanf(fp, "%s", help);
	token = strtok(help, ",");
	int t[100] = { 0 };
	int i = 0;
	while (token != NULL) {
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	for (i = 0; i < 10; i=i+2) {
		if (t[i] != 0) {
			printf("Student matrix is :%d\tThe score is :%d\n", t[i], t[i + 1]);
		}
		else if (t[i] == 0) {
			break;
		}
	}

	fclose(fp);
	system("pause");
	system("cls");
}