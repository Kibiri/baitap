#include <stdio.h>

int str_compare(char str1[], char str2[])
{
    int equal = 0;
    int count1, count2;
    
    while (str1[count1] != '\0') 
        count1++;
    while (str2[count2] != '\0')
        count2++;
    if (count1 == count2)
    {
        return 1;
    }
    else {
        return 0;
    }
}

int max_value(int arr[], size_t length)
{
    int temp = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > temp)
        {
            temp = arr[i];
        }
    }
    return temp;
}

int min_value(int arr[], size_t length)
{
    int temp = arr[0];
    for (int i = 0; i < length; i++)
    { 

        if (arr[i] < temp)
        {
            temp = arr[i];
        }
    }
    return temp;
}

int orderMin_Max(int arr[], size_t length)
{
    int temp;
    for (int i = 0; i <= length - 1; i++)
    { 
        for(int j = i + 1; j < length; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printf("%d ", arr[i]);
    }
}

int orderMax_Min(int arr[], size_t length)
{
    int temp;
    for (int i = 0; i <= length - 1; i++)
    { 
        for(int j = i + 1; j < length; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printf("%d ", arr[i]);
    }
}

int	main(int argc, char **argv)
{
    char strA[200], strB[200];
    int arr[] = {5,2,6,4};
    
    printf("Nhap mang thu 1: ");
    gets(strA);
    printf("Nhap mang thu 2: ");
    gets(strB);

    if(str_compare(strA,strB) == 1)
    {
        printf("2 chuoi bang nhau.\n");
    }
    else {
        printf("2 chuoi ko bang nhau.\n");
    }

    // printf("So lon nhat trong mang : %d\n", max_value(arr, 4));
    // printf("So nho nhat trong mang : %d\n", min_value(arr, 4));

    // printf("Thu tu tang dan: ");
    // orderMin_Max(arr, 4);
    // printf("\nThu tu giam dan: ");
    // orderMax_Min(arr, 4);

    return 0;
}
