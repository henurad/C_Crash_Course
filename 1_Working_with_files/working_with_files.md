# Working with files in C

C lets you open a file, write in it, read from it, append to it and finally close the file.

## Required library

To work with files in c you need to include `stdio.h` in your program

```c
#include <stdio.h>
```

## How to open a file?

Your user space program can't access files. And must grant permission from the operating system. Thus there is a function named `fopen()` that asks the os and opens a file in your program.


## Reading from a file
There are three functions to read from file:
1. `fgetc(fptr)` : to read a single character every time
    input: file pointer
    returns: next single character in the file
    termination condition: if returns EOF
2. `fgets(buff, n, fp)` : to read a string every time
    inputs: buffer , sizeof the buffer , file pointer
    returns: the read string
    termination condition: if returned value is NULL
3. `fscanf(fp, conversion_specifiers, vars)` : to read the file in the form of a formatted string
    inputs: file pointer, conversion_specifiers, vars
    returns: the number of fields that it successfully converted and assigned.
4. `fread(buffer_ptr, size, nmemb, file_ptr)
    inputs: buffer, buffer member size, number of buffer members, file pointer
    returns: 1 if data is read successfully, 0 if no data is read successfully.

### Example for fgetc(fptr)
```C
FILE *fptr = fopen("C:/Users/Amin/Desktop/myFile.txt", "r");
char c;
if(fptr != NULL){ // NULL checking. fptr is NULL when the file does not exist.
    while((c = fgetc(fptr)) != EOF){
        printf("%c", c);
    }
    fclose(fptr);
}else {
    printf("File does not exist");
}
```

### Example for fgets
The fgets() function is similar to the fgetc() but instead of a single character, it reads one string at a time
```C
FILE *fptr2 = fopen("C:/Users/Amin/Desktop/myFile.txt", "r");
if(fptr2 != NULL){
    const unsigned int N = 20;
    char buffer[N];
    while(fgets(buffer, N, fptr2) != NULL){
        printf("%s", buffer);
    }
    fclose(fptr2);
}else {
    printf("File does not exist");
}
```

### Example for fscanf
The fscanf() function returns the number of fields that it successfully converted and assigned.
```C
FILE *fptr3 = fopen("C:/Users/Amin/Desktop/names.txt", "r");
if(fptr3 != NULL){
    char name[100];
    unsigned int age;
    while(fscanf(fptr, "%s %d", name, &age) == 2){
        printf("name is: %s \n", name);
        printf("age is: %d \n\n", age);
    }
    fclose(fptr3);
}else {
    printf("File does not exist");
}
```

### Example for fread
```C
struct Person{
    char name[20];
    unsigned int age;
};

// opening the file to write binary data in it
FILE *fptr4 = fopen("C:/Users/Amin/Desktop/names.bin", "wb");
struct Person p1 = {"Amin", 20};
struct Person p2 = {"Ali", 30};

if(fptr4 != NULL){
    fwrite(&p1, sizeof(p1), 1, fptr4);
    fwrite(&p2, sizeof(p1), 1, fptr4);

    fclose(fptr4);
}else {
    printf("names.bin file does not exist");
}

fptr4 = fopen("C:/Users/Amin/Desktop/names.bin", "rb");
struct Person p3, p4;
int r;
if(fptr4 != NULL){
    r = fread(&p3, sizeof(p3), 1, fptr4);
    printf("%d", r);
    r = fread(&p4, sizeof(p4), 1, fptr4);
    printf("%d", r);
    r = fread(&p4, sizeof(p4), 1, fptr4);
    printf("%d", r);
    fclose(fptr4);
}else {
    printf("names.bin file does not exist");
}

printf("p3 name: %s \n", p3.name);
printf("p3 age: %d \n", p3.age);


printf("p4 name: %s \n", p4.name);
printf("p4 age: %d \n", p4.age);
```
