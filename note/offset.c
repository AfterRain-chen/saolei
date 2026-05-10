// //宏实现计算结构体中某变量对于首地址的偏移量
// #include <stdio.h>
// #include <stddef.h>
// #include <stdlib.h> 

// #define OFFSET_OF(strc, member) ((char *)(&strc.member) - (char *)(&strc))
// #define OFFSET_OF2(type, member) (size_t)&(((type*)0)->member) 

// typedef struct stu
// {
//     char c1;
//     int a;
//     char c2;
// } stu;

// int main()
// {
//     stu s1;
//     size_t my_offset_c1 = OFFSET_OF(s1, c1);
//     size_t my_offset_a = OFFSET_OF(s1, a);
//     size_t my_offset_c2 = OFFSET_OF(s1, c2);

//     //标准offsetof
//     size_t std_offset_c1 = offsetof(stu, c1);
//     size_t std_offset_a = offsetof(stu, a);
//     size_t std_offset_c2 = offsetof(stu, c2);

//     printf("My macro offsets:\n");
//     printf("c1 = %zu, a = %zu, c2 = %zu\n", my_offset_c1, my_offset_a, my_offset_c2);

//     printf("Standard offsetof:\n");
//     printf("c1 = %zu, a = %zu, c2 = %zu\n", std_offset_c1, std_offset_a, std_offset_c2);

//     system("pause");
// }
