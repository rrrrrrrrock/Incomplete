#define _CRT_SECURE_NO_WARNINGS 1
#include< stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int compare(char* version1, char* version2) {
    // write code here
    int prelen1 = 0, prelen2 = 0, suclen1 = 0, suclen2 = 0;//每一个需要比较的修改号在字符串中的开始位置和结束位置
    int i, j;
    while (1)//(*(version1 + suclen1) != '\0' && *(version2 + suclen2) != '\0')
    {
        //如果遇到了一个修改号结束的位置‘\0’‘.’，则开始比较当前的两个修改号
        if ((*(version1 + suclen1) == '.' || *(version1 + suclen1) == '\0') && (*(version2 + suclen2) == '.' || *(version2 + suclen2) == '\0'))
        {
            if (suclen1 - prelen1 > suclen2 - prelen2)
            {
                return 1;
            }
            else if (suclen1 - prelen1 < suclen2 - prelen2)
            {
                return -1;
            }
            else
            {
                i = suclen1 - 1;
                j = suclen2 - 1;
                while (i >= prelen1 && j >= prelen2)
                {
                    if (*(version1 + i) > *(version2 + j))
                    {
                        return 1;
                    }
                    else if (*(version1 + i) < *(version2 + j))
                    {
                        return -1;
                    }
                    else
                    {
                        i--;
                        j--;
                    }
                }
                if (*(version1 + suclen1) == '\0' || *(version2 + suclen2) == '\0')
                {
                    break;
                }
                suclen1++;
                suclen2++;
                prelen1 = suclen1;
                prelen2 = suclen2;
            }
        }
        //不用比较继续向前走
        if ((*(version1 + suclen1) != '.') && (*(version1 + suclen1) != '\0'))
        {
            //处理前面的0
            if ((*(version1 + suclen1) == '0') && (prelen1 == suclen1))
            {
                prelen1++;
            }
            suclen1++;
        }
        //不用比较继续向前走
        if ((*(version2 + suclen2) != '.') && (*(version2 + suclen2) != '\0'))
        {
            //处理前面的0
            if ((*(version2 + suclen2) == '0') && (prelen2 == suclen2))
            {
                prelen2++;
            }
            suclen2++;
        }
    }
    if (*(version1 + suclen1) == '\0')
    {
        while (*(version2 + suclen2) != '\0')
        {
            if ((*(version2 + suclen2) > '0') && (*(version2 + suclen2) <= '9'))
            {
                return -1;
            }
            suclen2++;
        }
    }
    if (*(version2 + suclen2) == '\0')
    {
        while (*(version1 + suclen1) != '\0')
        {
            if (((*(version1 + suclen1) > '0') && (*(version1 + suclen1) <= '9')))
            {
                return 1;
            }
            suclen1++;
        }
    }
    return 0;
}