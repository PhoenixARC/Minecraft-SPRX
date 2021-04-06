#pragma once
#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/syscall.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/process.h>
#include <netdb.h>

#pragma comment(lib, "net_stub")

#define TOC 0x014CDAB0

#include "Structs.h"
#include "Functions.h"
#include "MenuBase.h"

#define CDECL extern "C"



CDECL int _sys_printf(const char* fmt, ...);
#define printf _sys_printf

CDECL int _sys_snprintf(char* buffer, size_t len, const char* fmt, ...);
#define snprintf _sys_snprintf

CDECL size_t _sys_strlen(const char* str);
#define strlen _sys_strlen

CDECL void* _sys_memset(void* m, int c, size_t n);
#define memset _sys_memset

CDECL char* _sys_strcat(char* dest, const char* src);
#define strcat _sys_strcat

#define Color_s(a,r,g,b) (((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))

int32_t sys_dbg_read_process_memory(uint64_t address, void* data, size_t size);
int32_t sys_dbg_write_process_memory(uint64_t address, const void* data, size_t size);
int32_t sys_dbg_write_process_memory_ps3mapi(uint64_t ea, const void* data, size_t size);
int32_t sys_dbg_read_process_memory_ps3mapi(uint64_t ea, void* data, size_t size);
void PatchInJump(uint32_t address, uint32_t destination);
void HookFunctionStart(uint32_t functionStartAddress, uint32_t newFunction, uint32_t functionStub);
void UnHookFunctionStart(uint32_t functionStartAddress, uint32_t functionStub);
int32_t BranchLinkedHook(uint32_t branchFrom, uint32_t branchTo);
int32_t BranchHook(uint32_t branchFrom, uint32_t branchTo);
bool bCompare(const unsigned char* pData, const unsigned char* bMask, const char* szMask);
unsigned long FindPattern(unsigned long dwAddress, unsigned long dwLen, unsigned char* bMask, char* szMask);
char * removespace(const char * notify);
char* SendRequest(char* URL, char* Path);
void Notify(const char * notify);
