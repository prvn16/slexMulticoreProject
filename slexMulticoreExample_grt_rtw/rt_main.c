/*
 * Code generation for Simulink model "slexMulticoreExample"
 *
 * File version               : 8.13 (R2017b) 24-Jul-2017
 * File generated on          : Wed Jan 17 07:21:29 2018
 * C source code generated on : Wed Jan 17 07:21:29 2018
 *
 * Compiler specified defines:
 *   RT
 *   MODEL           = slexMulticoreExample
 *   NUMST           = 3 (Number of sample times)
 *   NCSTATES        = 0 (Number of continuous states)
 *   TID01EQ         = 0
 *                     (Set to 1 if sample time task id's 0 and 1 have equal rates)
 *
 * For more information:
 *   o Simulink Coder User's Guide
 */

#ifndef _WIN32
#define _WIN32
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT                   0x0500
#endif

#include <windows.h>
#include <process.h>
#include "rtmodel.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <float.h>
#include "slexMulticoreExample.h"      /* Model's header file */
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef EXIT_FAILURE
#define EXIT_FAILURE                   1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS                   0
#endif

#define RUN_FOREVER                    -1.0

/*====================*
 * External functions *
 *====================*/
extern void slexMulticoreExample_initialize(void);
extern void slexMulticoreExample_terminate(void);
extern void slexMulticoreExample_output(int_T tid);
extern void slexMulticoreExample_update(int_T tid);

# define MdlInitializeSizes()                                    /* No op */
# define MdlInitializeSampleTimes()                              /* No op */
# define MdlStart()                                              /* No op */
# define MdlOutputs                    slexMulticoreExample_output
# define MdlUpdate                     slexMulticoreExample_update
# define rt_CreateIntegrationData(S)                             /* No op */
# define rt_UpdateContinuousStates(S)                            /* No op */
# define MdlTerminate                  slexMulticoreExample_terminate

/*==================================*
 * Global data local to this module *
 *==================================*/
static struct {
  int_T stopExecutionFlag;
  int_T isrOverrun;
  int_T overrunFlags[NUMST];
  const char_T *errmsg;
} GBLbuf;

/*=================*
 * Local functions *
 *=================*/
#define CHECK_STATUS(status,fcn)       if (status != 0) {fprintf(stderr, "Call to %s returned error status (%d).\n", (fcn),(status)); perror((fcn)); fflush(stderr); exit(EXIT_FAILURE);}

typedef struct {
  HANDLE threadHandle;
  unsigned threadID;
  int_T index;
  HANDLE startEvent;
  HANDLE stopEvent;
  LONG exitFlag;
} ThreadInfo;

typedef struct {
  int numSamples;
  int maxNumSamples;
  double startTime[20];
  double endTime[20];
  int coreID[20];
} profileDataT;

ThreadInfo periodicThread[4];
ThreadInfo periodicTriggerThread[2];
int threadPriority[4] = { THREAD_PRIORITY_ABOVE_NORMAL,
  THREAD_PRIORITY_NORMAL,
  THREAD_PRIORITY_BELOW_NORMAL,
  THREAD_PRIORITY_LOWEST };

HANDLE rtClock[2];
HANDLE quitEvent = NULL;
profileDataT profileData[4];
int counterSamples[2];
RT_MODEL_slexMulticoreExample_T *S;
BOOL OnCtrlHandler(DWORD ctrl)
{
  SetEvent(quitEvent);
  return true;
}

double profileReadTimer(void)
{
  LARGE_INTEGER readTime;
  CHECK_STATUS(QueryPerformanceCounter(&readTime) == false,
               "QueryPerformanceCounter");
  return (double)(readTime.QuadPart);
}

void initializeNumSamplesForProfiling(void)
{
  int idx;
  int sthId[4] = { 1, 1, 2, 4 };

  for (idx = 0; idx < 4; idx++) {
    profileData[idx].numSamples = 0;
    profileData[idx].maxNumSamples = (20 -1) / sthId[idx] + 1;
  }
}

void profile_task_start(int taskId)
{
  if (profileData[taskId].numSamples < profileData[taskId].maxNumSamples) {
    profileData[taskId].coreID[profileData[taskId].numSamples] =
      GetCurrentProcessorNumber();
    profileData[taskId].startTime[profileData[taskId].numSamples] =
      profileReadTimer();
  }
}

void profile_task_end(int taskId)
{
  if (profileData[taskId].numSamples < profileData[taskId].maxNumSamples) {
    profileData[taskId].endTime[profileData[taskId].numSamples] =
      profileReadTimer();
    profileData[taskId].numSamples++;
  }
}

void writeProfileDataToHTMLFile(void)
{
  FILE *fptr;
  int i, j, numCores;
  time_t timeVar;
  char timeStr[32];
  char comma;
  LARGE_INTEGER ul;
  SYSTEM_INFO sysinfo;
  const char *taskNames[4] = {
    "Task1"
    , "Task2"
    , "Task3"
    , "Task4"
  };

  int isSynthesizedTask[4] = {
    0
    , 0
    , 0
    , 0
  };

  const char *parentTriggerNames[4] = {
    "Core1"
    , "Core1"
    , "Core2"
    , "Core2"
  };

  int sthId[4] = { 1, 1, 2, 4 };

  CHECK_STATUS(QueryPerformanceFrequency(&ul) == false,
               "QueryPerformanceFrequency");
  GetSystemInfo(&sysinfo);
  numCores = sysinfo.dwNumberOfProcessors;
  if ((fptr=fopen("slexMulticoreExample_ProfileReport.html","w")) == NULL) {
    (void)fprintf(stderr,"*** Error opening profileData.m");
    return;
  }

  fprintf(fptr, "<!DOCTYPE html>\n<html>\n");
  fprintf(fptr,
          "<link rel=\"stylesheet\" type = \"text/css\" href = \"file:///C:/Program Files/MATLAB/R2017b/toolbox/simulink/simulink/+Simulink/+SoftwareTarget/profiling.css\"/>\n");
  timeVar = time(NULL);
  sprintf(timeStr, "%s", ctime(&timeVar));
  timeStr[strlen(timeStr)-1] = 0;
  fprintf(fptr, "<script>var data = { \n""\"model\":\"slexMulticoreExample\",\n"
          "\"timeStamp\"      : \"%s\",\n" "\"simulationTime\" : %f,\n"
          "\"nCores\"         : %d,\n"
          "\"unitSec\"        : \"microseconds\",\n", timeStr, (20-1)*0.1,
          numCores);
  fprintf(fptr, "\"tasks\": [");
  comma = ' ';
  for (i = 0; i < 4; i++) {
    fprintf(fptr,
            "%c {\"name\" : \"%s\", \"synthesized\" : %d, \"parentTrigger\" : \"%s\"}",
            comma, taskNames[i], isSynthesizedTask[i], parentTriggerNames[i]);
    comma = ',';
  }

  fprintf(fptr, "],\n");
  fprintf(fptr, "\"execTimes\": [");
  comma = ' ';
  for (i = 0; i < 4; i++) {
    char comma2 = ' ';
    fprintf(fptr, "%c [", comma);
    for (j = 0; j < profileData[i].numSamples; j++) {
      double locExecTime;
      locExecTime = (profileData[i].endTime[j] - profileData[i].startTime[j])/
        ((double)ul.QuadPart) * 1000000;
      fprintf(fptr, "%c %f", comma2, locExecTime);
      comma2 = ',';
    }

    fprintf(fptr, "]");
    comma = ',';
  }

  fprintf(fptr, "],\n");
  fprintf(fptr, "\"coreIDs\": [");
  comma = ' ';
  for (i = 0; i < 4; i++) {
    char comma2 = ' ';
    fprintf(fptr, "%c [", comma);
    for (j = 0; j < 20; j++) {
      if (j % sthId[i] == 0) {
        int sample = j / sthId[i];
        if (sample < profileData[i].numSamples) {
          fprintf(fptr, "%c %d", comma2, profileData[i].coreID[sample]);
        }
      } else if (j / sthId[i] < profileData[i].numSamples) {
        fprintf(fptr, "%c -1", comma2);
      }

      comma2 = ',';
    }

    fprintf(fptr, "]");
    comma = ',';
  }

  fprintf(fptr, "]};\n");
  fprintf(fptr, "</script>\n");
  fprintf(fptr,
          "<script type = \"text/javascript\" src = \"file:///C:/Program Files/MATLAB/R2017b/toolbox/simulink/simulink/+Simulink/+SoftwareTarget/concurrentExecutionProfiling.js\">\n");
  fprintf(fptr, "</script>\n</html>");
  (void)fclose(fptr);
}

unsigned __stdcall Core1TaskScheduler(void *arg)
{
  volatile boolean_T noErr;
  DWORD waitResult;
  HANDLE orTimer;
  LARGE_INTEGER orDueTime;
  HANDLE eventArray[2];
  int_T i;
  int_T taskCounters[2] = { 0, 0 };

  int_T taskTicks[2] = { 1, 1 };

  int_T taskId[2] = { 0, 1 };

  noErr = (rtmGetErrorStatus(slexMulticoreExample_M) == (NULL)) &&
    (counterSamples[0] < 20);
  eventArray[0] = quitEvent;
  eventArray[1] = rtClock[0];
  orTimer = CreateWaitableTimer(NULL, false, NULL);
  orDueTime.QuadPart = (LONGLONG)(0.1 * 1e7 * -1);
  while (noErr) {
    /* Wait for the next event from the timer */
    waitResult = WaitForMultipleObjects(2, eventArray, false, INFINITE);
    if ((waitResult == WAIT_OBJECT_0) || (waitResult == WAIT_FAILED)) {
      /* The quitEvent is set or the wait failed */
      noErr = false;
      continue;
    }

    CHECK_STATUS(SetWaitableTimer(orTimer, &orDueTime, 0, NULL, NULL, false) ==
                 false, "SetWaitableTimer");
    for (i = 0; i < 2; i++) {
      if (taskCounters[i] == 0) {
        waitResult = WaitForSingleObject(periodicThread[taskId[i]].stopEvent, 0);
        if (waitResult == WAIT_TIMEOUT) {
          printf("Overrun - rate for periodic task %d too fast.\n", taskId[i]);
          WaitForSingleObject(periodicThread[taskId[i]].stopEvent, INFINITE);
        }
      }
    }

    noErr = (rtmGetErrorStatus(slexMulticoreExample_M) == (NULL)) &&
      (counterSamples[0] < 20);
    if (noErr) {
      counterSamples[0]+=1;
      for (i = 0; i <2; i++) {
        if (taskCounters[i] == 0) {
          SetEvent(periodicThread[taskId[i]].startEvent);
        }
      }

      for (i = 0; i <2; i++) {
        taskCounters[i]++;
        if (taskCounters[i] > (taskTicks[i]-1)) {
          taskCounters[i] = 0;
        }
      }
    } else {
      for (i = 0; i < 2; i++) {
        if (taskCounters[i] != 0) {
          WaitForSingleObject(periodicThread[taskId[i]].stopEvent,INFINITE);
        }
      }
    }

    if (WaitForSingleObject(orTimer, 0) == WAIT_OBJECT_0) {
      printf("Overrun - periodic trigger 0 base rate too fast.\n");
    }
  }                                    /* while */

  for (i = 0; i < 2; i++) {
    InterlockedIncrement(&periodicThread[taskId[i]].exitFlag);
    SetEvent(periodicThread[taskId[i]].startEvent);
  }

  _endthreadex(0);
  return 0;
}

unsigned __stdcall Core2TaskScheduler(void *arg)
{
  volatile boolean_T noErr;
  DWORD waitResult;
  HANDLE orTimer;
  LARGE_INTEGER orDueTime;
  HANDLE eventArray[2];
  int_T i;
  int_T taskCounters[2] = { 0, 0 };

  int_T taskTicks[2] = { 1, 2 };

  int_T taskId[2] = { 2, 3 };

  noErr = (rtmGetErrorStatus(slexMulticoreExample_M) == (NULL)) &&
    (counterSamples[1] < 20);
  eventArray[0] = quitEvent;
  eventArray[1] = rtClock[1];
  orTimer = CreateWaitableTimer(NULL, false, NULL);
  orDueTime.QuadPart = (LONGLONG)(0.2 * 1e7 * -1);
  while (noErr) {
    /* Wait for the next event from the timer */
    waitResult = WaitForMultipleObjects(2, eventArray, false, INFINITE);
    if ((waitResult == WAIT_OBJECT_0) || (waitResult == WAIT_FAILED)) {
      /* The quitEvent is set or the wait failed */
      noErr = false;
      continue;
    }

    CHECK_STATUS(SetWaitableTimer(orTimer, &orDueTime, 0, NULL, NULL, false) ==
                 false, "SetWaitableTimer");
    for (i = 0; i < 2; i++) {
      if (taskCounters[i] == 0) {
        waitResult = WaitForSingleObject(periodicThread[taskId[i]].stopEvent, 0);
        if (waitResult == WAIT_TIMEOUT) {
          printf("Overrun - rate for periodic task %d too fast.\n", taskId[i]);
          WaitForSingleObject(periodicThread[taskId[i]].stopEvent, INFINITE);
        }
      }
    }

    noErr = (rtmGetErrorStatus(slexMulticoreExample_M) == (NULL)) &&
      (counterSamples[1] < 20);
    if (noErr) {
      counterSamples[1]+=2;
      for (i = 0; i <2; i++) {
        if (taskCounters[i] == 0) {
          SetEvent(periodicThread[taskId[i]].startEvent);
        }
      }

      for (i = 0; i <2; i++) {
        taskCounters[i]++;
        if (taskCounters[i] > (taskTicks[i]-1)) {
          taskCounters[i] = 0;
        }
      }
    } else {
      for (i = 0; i < 2; i++) {
        if (taskCounters[i] != 0) {
          WaitForSingleObject(periodicThread[taskId[i]].stopEvent,INFINITE);
        }
      }
    }

    if (WaitForSingleObject(orTimer, 0) == WAIT_OBJECT_0) {
      printf("Overrun - periodic trigger 1 base rate too fast.\n");
    }
  }                                    /* while */

  for (i = 0; i < 2; i++) {
    InterlockedIncrement(&periodicThread[taskId[i]].exitFlag);
    SetEvent(periodicThread[taskId[i]].startEvent);
  }

  _endthreadex(0);
  return 0;
}

unsigned __stdcall periodicTask(void *arg)
{
  DWORD waitResult;
  ThreadInfo* info = (ThreadInfo*)arg;
  volatile boolean_T noErr = true;
  while (noErr) {
    waitResult = WaitForSingleObject(info->startEvent,INFINITE);
    if ((waitResult != WAIT_OBJECT_0) || info->exitFlag) {
      /* Wait failed or exitFlag is set */
      noErr = false;
      continue;
    }

    profile_task_start(info->index);
    MdlOutputs(info->index);
    MdlUpdate(info->index);
    profile_task_end(info->index);
    SetEvent(info->stopEvent);
  }

  _endthreadex(0);
  return 0;
}

int main(int argc, char *argv[])
{
  int i, j;
  LARGE_INTEGER stNanoSec;
  LONG stMilliPeriod;
  SYSTEM_INFO sysinfo;
  DWORD_PTR processMask;
  DWORD_PTR systemMask;
  DWORD_PTR threadMask;
  int coreAffinity[4][1];
  int numCores;
  int priority[4];

  /* Unused arguments */
  (void)(argc);
  (void)(argv);
  priority[0] = threadPriority[0];
  coreAffinity[0][0] = 0;
  priority[1] = threadPriority[0];
  coreAffinity[1][0] = 0;
  priority[2] = threadPriority[1];
  coreAffinity[2][0] = 1;
  priority[3] = threadPriority[2];
  coreAffinity[3][0] = 1;
  CHECK_STATUS(SetConsoleCtrlHandler((PHANDLER_ROUTINE)OnCtrlHandler, true) ==
               false, "SetConsoleCtrlHandler");
  for (i = 0; i < 2; i++) {
    rtClock[i] = NULL;
  }

  for (i = 0 ; i < 2; i++) {
    counterSamples[i] = 0;
  }

  initializeNumSamplesForProfiling();
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(slexMulticoreExample_M, 0);

  /* Set the priority of the main thread */
  CHECK_STATUS(SetThreadPriority(GetCurrentThread(),
    THREAD_PRIORITY_TIME_CRITICAL) == false, "SetThreadPriority");

  /* Create & initialize events used for thread synchronization */
  quitEvent = CreateEvent(NULL, true, false, NULL);
  CHECK_STATUS(quitEvent == NULL,"CreateEvent");
  for (i = 0; i < 2; i++) {
    rtClock[i] = CreateWaitableTimer(NULL, false, NULL);
    CHECK_STATUS(rtClock[i] == NULL,"CreateWaitableTimer");
  }

  /************************
   * Initialize the model *
   ************************/
  S = slexMulticoreExample_M;
  slexMulticoreExample_initialize();
  if (rtmGetErrorStatus(S) != NULL) {
    puts("Error during model registration");
    exit(EXIT_FAILURE);
  }

  MdlInitializeSizes();
  MdlInitializeSampleTimes();
  MdlStart();
  GetSystemInfo(&sysinfo);
  numCores = sysinfo.dwNumberOfProcessors;
  CHECK_STATUS(GetProcessAffinityMask(GetCurrentProcess(), &processMask,
    &systemMask) == FALSE, "GetProcessAffinityMask");

  /* Create periodic threads */
  for (i = 0; i < 4; i++) {
    periodicThread[i].index = (int_T) i;
    periodicThread[i].exitFlag = 0;

    /* Create the events that will be used by the thread */
    periodicThread[i].startEvent = CreateEvent(NULL, false, false, NULL);
    CHECK_STATUS(periodicThread[i].startEvent == NULL, "CreateEvent");
    periodicThread[i].stopEvent = CreateEvent(NULL, false, true, NULL);
    CHECK_STATUS(periodicThread[i].stopEvent == NULL, "CreateStopEventEvent");

    /* Create the thread in suspended mode */
    periodicThread[i].threadHandle = (HANDLE)_beginthreadex(NULL, 0,
      &periodicTask, &periodicThread[i], CREATE_SUSPENDED, &periodicThread[i].
      threadID);
    CHECK_STATUS(periodicThread[i].threadID == 0,"_beginthreadex");

    /* Set the thread priority */
    CHECK_STATUS(SetThreadPriority(periodicThread[i].threadHandle, priority[i]) ==
                 false, "SetThreadPriority");

    /* Create the thread mask */
    threadMask = 0;
    for (j = 0; j < 1; j++) {
      if ((coreAffinity[i][j] >= 0) && (coreAffinity[i][j] < numCores)) {
        /* Set the (coreAffinity[i][j]+1)th rightmost bit in threadMask */
        threadMask |= (1 << coreAffinity[i][j]);
      }
    }

    /* Set the core affinity */
    if (threadMask != 0) {
      CHECK_STATUS(SetThreadAffinityMask(periodicThread[i].threadHandle,
        threadMask) == 0, "SetThreadAffinityMask");
    }

    /* Start the thread */
    CHECK_STATUS(ResumeThread(periodicThread[i].threadHandle) == -1,
                 "ResumeThread");
  }

  /* Create periodic trigger threads */
  {
    periodicTriggerThread[0].index = 0;
    periodicTriggerThread[0].exitFlag = 0;
    periodicTriggerThread[0].startEvent = NULL;
    periodicTriggerThread[0].stopEvent = NULL;

    /* Create the thread in suspended mode */
    periodicTriggerThread[0].threadHandle = (HANDLE)_beginthreadex(NULL, 0,
      &Core1TaskScheduler, NULL, CREATE_SUSPENDED, &periodicTriggerThread[0].
      threadID);
    CHECK_STATUS(periodicTriggerThread[0].threadHandle == 0,"_beginthreadex");

    /* Set the periodic trigger thread priority */
    CHECK_STATUS(SetThreadPriority(periodicTriggerThread[0].threadHandle,
      THREAD_PRIORITY_HIGHEST) == false, "SetThreadPriority");

    /* Start the periodic trigger thread */
    CHECK_STATUS(ResumeThread(periodicTriggerThread[0].threadHandle) == -1,
                 "ResumeThread");
  }

  {
    periodicTriggerThread[1].index = 0;
    periodicTriggerThread[1].exitFlag = 0;
    periodicTriggerThread[1].startEvent = NULL;
    periodicTriggerThread[1].stopEvent = NULL;

    /* Create the thread in suspended mode */
    periodicTriggerThread[1].threadHandle = (HANDLE)_beginthreadex(NULL, 0,
      &Core2TaskScheduler, NULL, CREATE_SUSPENDED, &periodicTriggerThread[1].
      threadID);
    CHECK_STATUS(periodicTriggerThread[1].threadHandle == 0,"_beginthreadex");

    /* Set the periodic trigger thread priority */
    CHECK_STATUS(SetThreadPriority(periodicTriggerThread[1].threadHandle,
      THREAD_PRIORITY_HIGHEST) == false, "SetThreadPriority");

    /* Start the periodic trigger thread */
    CHECK_STATUS(ResumeThread(periodicTriggerThread[1].threadHandle) == -1,
                 "ResumeThread");
  }

  /* Real-time scheduling timer */
  stNanoSec.QuadPart = (LONGLONG)(0.1 * 1e7 * -1);
  stMilliPeriod = (LONG)(0.1 * 1e3);
  CHECK_STATUS(SetWaitableTimer(rtClock[0], &stNanoSec, stMilliPeriod, NULL,
    NULL, false) == false, "SetWaitableTimer");
  stNanoSec.QuadPart = (LONGLONG)(0.2 * 1e7 * -1);
  stMilliPeriod = (LONG)(0.2 * 1e3);
  CHECK_STATUS(SetWaitableTimer(rtClock[1], &stNanoSec, stMilliPeriod, NULL,
    NULL, false) == false, "SetWaitableTimer");

  /* Wait for a stopping condition. */
  for (i = 0; i < 2; i++) {
    WaitForSingleObject(periodicTriggerThread[i].threadHandle, INFINITE);
  }

  /* Clean up */
  for (i = 0; i< 2; i++) {
    if (rtClock[i] != NULL) {
      CloseHandle(rtClock[i]);
    }

    if (periodicTriggerThread[i].threadHandle != NULL) {
      CloseHandle(periodicTriggerThread[i].threadHandle);
    }
  }

  if (quitEvent != NULL) {
    CloseHandle(quitEvent);
  }

  for (i = 0; i < 4; i++) {
    if (periodicThread[i].startEvent != NULL) {
      CloseHandle(periodicThread[i].startEvent);
    }

    if (periodicThread[i].stopEvent != NULL) {
      CloseHandle(periodicThread[i].stopEvent);
    }

    if (periodicThread[i].threadHandle != NULL) {
      CloseHandle(periodicThread[i].threadHandle);
    }
  }

  printf("**stopping the model**\n");
  fflush(stdout);
  if (rtmGetErrorStatus(slexMulticoreExample_M) != NULL) {
    fprintf(stderr, "\n**%s**\n", rtmGetErrorStatus(slexMulticoreExample_M));
  }

  MdlTerminate();
  writeProfileDataToHTMLFile();
  return 0;
}
