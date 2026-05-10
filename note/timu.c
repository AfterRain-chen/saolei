
// #define A 2
// #define B 3
// #define MAX_SIZE A+B
// typedef struct _Record_Struct
// {
//     unsigned char Env_Alarm_ID : 4;  //位段，占据一个字节的4位
//     unsigned char Parallel : 2;
//     unsigned char state;
//     unsigned char avail : 1;
// }RS;

// int main()
// {
//     RS* pointer = (RS*)malloc(sizeof(RS) * MAX_SIZE);  3//*2+3=9;分配九个字节
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main() 
// { 
//     unsigned char puc[4]; 
//     struct tagPIM
//     {
//         unsigned char ucPim1; 
//         unsigned char ucDate0 : 1; 
//         unsigned char ucDate1 : 2; 
//         unsigned char ucDate2 : 3;
//     }* PstPimData;
//     PstPimData = (struct tagPIM*)puc;
//     memset(puc, 0, 4);
//     PstPimData->ucPim1 = 2;
//     //一字节足够，2存进unPim1,即puc[0]的位置
//     PstPimData->ucDate0 = 3;
//     //3的二进制表示为11，存进ucDate0占用的1位，只保留最低位1，puc[0]变为0000 0001
//     PstPimData->ucDate1 = 4;
//     //4的二进制表示为100，存进ucDate1占用的2位，只保留最低的2位00，puc[0]仍为0000 0001
//     PstPimData->ucDate2 = 5;
//     //5的二进制表示为101，存进ucDate2占用的3位，puc[0]变为00101 001 即41，转换为十六进制29
//     printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);  //%02x表示输出两位十六进制数
//     return 0;
// }


#include <stdio.h>
union Un 
{
    short s[7];
    int n;
};
int main() 
{
    printf("%d\n", sizeof(union Un));
    printf("%d\n",sizeof(short));
    return 0;
}
