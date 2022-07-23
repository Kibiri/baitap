#include <stdio.h>
#include <string.h>

//#include <stdlib.h>

int test_atoi(char const* _string)
{
    //Variable
    int temp_store[100];    
    int store = 0;
    char* ptr;
    char adr [10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};
    char str [100];

    strcpy(str, _string);

    for (int i = 0; i < strlen(_string); i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            ptr = &str[i];
            if(*ptr == adr[j])
            {
                temp_store[i] = j;
                //printf("debug: %d\n",temp_store[i]);
            }
        }
        store = 10 * store + temp_store[i];
        //printf("debug : %d\n", store);
    }
    return store;
}

double test_strtod(char* _string, char **ptr)
{
    double store = 0;
    int t = 0;
    double f = 1;
    //f = f / 10;

    while ((_string[t] >= 48) && (_string[t] <= 57))
    {
        store = store * 10 + (_string[t] - 48);
        t++;
    }
    if (_string[t] == 46)
    {
        t++;
        while ((_string[t] >= 48) && (_string[t] <= 57))
        {
            f = f / 10;
            store = store + (_string[t] - 48) * f;
            t++;
        }
    }
    *ptr = &_string[t+1];
    return store;
}


char *test_strtok(char *string, char *delim)
{
    static char *temp; 
    static int count;  
    int i; 

    if(string != NULL)
    {
        temp = string;
        count = strlen(string);
    }

    else if(count > 0)
    {
        temp++;      
        count--;     
        string = temp;   
    }

    else
    {
        string = NULL; // cuoi chuoi
    }

    while(*temp)
    {
        i = strspn(temp, delim); // tim delimiter
        while(i > 1)        
        {
            *temp = '\0';
            temp++;
            count--;
            i--;
        }                   
        if(i == 1)          
        {                   
            *temp = '\0';
            if(count > 1)    
            {
                temp--;
                count++;     
            }
        }
        temp++;          
        count--;         
    }                   
                        
    return string;
}

void swap(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}

char *reverse(char *buffer, int i, int j)
{
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }
 
    return buffer;
}

int abs(int v) 
{
    return v * ((v>0) - (v<0));
}

void exit();
 
char *test_itoa(int value, char *buffer, int base)
{
    if (base < 2 || base > 32) 
    {
        return buffer;
    }

    if (base == 2 || base == 8 || base == 10 || base == 16)
    {
        int n = abs(value);
    
        int i = 0;
        while (n)
        {
            int r = n % base;
    
            if (r >= 10) {
                buffer[i++] = 65 + (r - 10);
            }
            else {
                buffer[i++] = 48 + r;
            }
    
            n = n / base;
        }

        if (i == 0) {
            buffer[i++] = '0';
        }

        if (value < 0) {
            buffer[i++] = '-';
        }
    
        buffer[i] = '\0';
    
        return reverse(buffer, 0, i - 1);
    }
    else 
    {
        printf("kiem tra co so\n");
        exit(1);
    }
}

int main(int argc, char const *argv[])
{
    int t;
    char *ptr;
    char strtod[] = "132.969 123 AAABBBCCC 123";
    char str[] = "321456789";
    char arr[] = "We 12.3 learning C";

    //printf("Chuyen doi : %d\n", test_atoi(str));

    //printf("strtod: %f\n",test_strtod(strtod, &ptr));
    //printf("%s\n", ptr);

    // ptr = test_strtok(arr, " ");
    // while (ptr != NULL)
    // {
    //     printf("%s\n", ptr);
    //     ptr = test_strtok(NULL, " ");
    // }

    char buffer[33];

    printf("nhap 1 so: ");
    scanf("%d", &t);

    test_itoa(t,buffer,8);

    printf("so nhi phan: %s\n", buffer);

    return 0;
}
