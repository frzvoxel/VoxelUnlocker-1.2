
#ifndef REGEDIT_H
#define REGEDIT_H

void CheckRun(char* RUN_PATH);
void CheckAndResetWinlogonValues(char* DEFAULT_USERINIT, char* DEFAULT_SHELL, char* WINLOGON_PATH);
void CheckRunOnce(char* RUNONCE_PATH);

#endif
