#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include "shell_test.h"

int main(int argc, char* argv[])
{
    int max_count = sizeof(g_stTotalCmdList) / sizeof(ST_CMD_LIST);
    int correct_num;
    if (argc < 2) {
        printf("less parameter : %d,which must more than 2\n", argc);
        g_stTotalCmdList[0].func(argc, argv);
        return false;
    }
    
    for (correct_num = 0; correct_num < max_count; correct_num++)
    {
        if(strcmp(argv[1], g_stTotalCmdList[correct_num].cCmd) == 0) {
            break;
        }
    }
    
    if (correct_num >= max_count)
    {
        printf("can't find this cmd : %s\n", argv[1]);
        g_stTotalCmdList[0].func(argc, argv);
        return false;
    }
    if ((g_stTotalCmdList[correct_num].iMinNum > correct_num) || (g_stTotalCmdList[correct_num].iMaxNum < correct_num))
    {
        printf("parameter number error\n");
        g_stTotalCmdList[0].func(argc, argv);
        return false;
    }
    printf("less parameter : %d,which must more than 2\n", argc);
    g_stTotalCmdList[correct_num].func(argc - 2, argv + 2);

    return true;
}

void fnShellTestHelp(int argc, char* argv[])
{
    int count = sizeof(g_stTotalCmdList) / sizeof(ST_CMD_LIST);
    for (int i = 0; i < count; i++)
    {
        printf("cmd : %s ,usage : %s\n", g_stTotalCmdList[i].cCmd, g_stTotalCmdList[i].cHelp);
    }
    return;
}

void fnShellTestExitShell(int argc, char* argv[])
{
    printf("exit shell\n");
    exit(0);
    return;
}


void fnShellTestPrintC(int argc, char* argv[])
{
    printf("string : %s", argv[0]);
    return;
}

void fnShellTestPrint(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("print %d :%s\n", i, argv[i]);
    }
    return;
}

void fnShellTestCount(int argc, char* argv[])
{
    int count = 0;
    for (int i = 0; i < argc; i++)
    {
        count += atoi(argv[i]);
    }
    printf("count : %d\n", count);
    return;

}

void test3(int argc, char* argv[])
{
    printf("test");
    return;
}