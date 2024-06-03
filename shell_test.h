#ifndef __SHELL_TEST_H__
#define __SHELL_TEST_H__

typedef struct ST_CMD_LIST
{
    char cCmd[32];
    char cHelp[256];
    int iMinNum;
    int iMaxNum;
    void (*func)(int argc, char* argv[]);
}stCmdList;


void fnShellTestHelp(int argc, char* argv[]);

void fnShellTestExitShell(int argc, char* argv[]);

void fnShellTestPrintC(int argc, char* argv[]);

void fnShellTestPrint(int argc, char* argv[]);

void fnShellTestCount(int argc, char* argv[]);

void test3(int argc, char* argv[]);


stCmdList g_stTotalCmdList[] = 
{
    {"help", "show help", 0, 0, fnShellTestHelp},
    {"exit", "exit shell", 0, 0, fnShellTestExitShell},
    {"print_c", "<char>", 1, 1, fnShellTestPrintC},
    {"print", "<num1> <num2> ...", 1, 10, fnShellTestPrint},
    {"count", "<num1> <num2> ...", 1, 20, fnShellTestCount},
    {"test3", "<char>", 1, 1, test3}
};


#endif // __SHELL_TEST_H__