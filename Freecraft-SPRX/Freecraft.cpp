// ===================================
//
// Original code by WaffleModz HD!
//
// Open Menu with square and L1
//
// ====================================
//Sony
#include <sys/prx.h>
#include <sys/syscall.h>
#include <sys/ppu_thread.h>
#include <sys/sys_time.h>
#include <sys/time_util.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/return_code.h>
#include <sys/prx.h>
#include <sys/paths.h>
#include <cellstatus.h>
#include <cell/error.h>
#include <string.h>
 
//C-Headers (converted)
#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <cstdarg>
#include <cassert>
#include <cstddef>
#include <cmath>
#include <ctime>
 
//C++ Std Lib
#include <typeinfo>
#include <vector>
 
//C-Headers
#include <pthread.h>
#include <locale.h>
 
//Project Headers
#include "Freecraft.h"



SYS_MODULE_INFO( Freecraft_SPRX, 0, 1, 1);
SYS_MODULE_START( _Freecraft_SPRX_prx_entry );
SYS_MODULE_STOP( _Freecraft_SPRX_prx_exit );


template<typename R, typename... Arguments> inline R Call(long long function, Arguments... args) {
	int toc_t[2] = { function, TOC };
	R(*temp)(Arguments...) = (R(*)(Arguments...))&toc_t;
	return temp(args...);
}

void RenderScreen_Stub(uint32_t r3, uint32_t r4) {
	__nop(); __nop(); __nop(); __nop(); __nop();
}
void RenderScreen_Hook(uint32_t r3, uint32_t r4){ 
	// gets called every frame whilst the player is in a world
	mc = (TheMinecraft*)(0x014CF2E4);
	RenderScreen_Stub(r3, r4);
	


	printf("[A!] ScreenRenderEvent\n");

	RenderMenu();
}


#include "MenuBase.h"
extern "C" int _Freecraft_SPRX_prx_entry(void) {
	
	printf("FreeCraft SPRX!\n=================\n");
	printf("sprx loaded\n");
	self.menu.CurrentMenu = MainMenu;
	self.isMenuOpen = false;
	
	//Call<void>(0x00A7E2E8);
	HookFunctionStart(0x00A89068, *(uint32_t*)(RenderScreen_Hook), *(uint32_t*)(RenderScreen_Stub)); // Hooks the rendering event
	
	//*(uint32_t*)(0x321F0B58) = 0x325A5EF0;//325A2EE0
	return SYS_PRX_RESIDENT;
}

extern "C" int _Freecraft_SPRX_prx_exit(void) {

	printf("sprx unloaded\n");
	UnHookFunctionStart(0x00A89068, *(uint32_t*)(RenderScreen_Stub));

	return SYS_PRX_RESIDENT;
}


int32_t sys_dbg_read_process_memory(uint64_t address, void* data, size_t size)
{
	system_call_4(904, (uint64_t)sys_process_getpid(), address, size, (uint64_t)data);
	return_to_user_prog(int32_t);
}
int32_t sys_dbg_write_process_memory(uint64_t address, const void* data, size_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), address, size, (uint64_t)data);
	return_to_user_prog(int32_t);
}
int32_t sys_dbg_write_process_memory_ps3mapi(uint64_t ea, const void* data, size_t size)
{
	system_call_6(8, 0x7777, 0x32, (uint64_t)sys_process_getpid(), (uint64_t)ea, (uint64_t)data, (uint64_t)size);
	return_to_user_prog(int32_t);
}
int32_t sys_dbg_read_process_memory_ps3mapi(uint64_t ea, void* data, size_t size)
{
	system_call_6(8, 0x7777, 0x31, (uint64_t)sys_process_getpid(), (uint64_t)ea, (uint64_t)data, (uint64_t)size);
	return_to_user_prog(int32_t);
}
void PatchInJump(uint32_t address, uint32_t destination) {
	int FuncBytes[4];
	FuncBytes[0] = 0x3D600000 + ((destination >> 16) & 0xFFFF);
	if (destination & 0x8000) FuncBytes[0] += 1;
	FuncBytes[1] = 0x396B0000 + (destination & 0xFFFF);
	FuncBytes[2] = 0x7D6903A6;
	FuncBytes[3] = 0x4E800420;
	for (int i = 0; i < 4; i++) {
		*(int*)(address + (i * 4)) = FuncBytes[i];
	}
}
void HookFunctionStart(uint32_t functionStartAddress, uint32_t newFunction, uint32_t functionStub) {
	uint32_t normalFunctionStub[8], hookFunctionStub[4];
	sys_dbg_read_process_memory_ps3mapi(functionStartAddress, normalFunctionStub, 0x10);
	sys_dbg_read_process_memory(functionStartAddress, normalFunctionStub, 0x10);
	normalFunctionStub[4] = 0x3D600000 + ((functionStartAddress + 0x10 >> 16) & 0xFFFF);
	normalFunctionStub[5] = 0x616B0000 + (functionStartAddress + 0x10 & 0xFFFF);
	normalFunctionStub[6] = 0x7D6903A6;
	normalFunctionStub[7] = 0x4E800420;
	sys_dbg_write_process_memory_ps3mapi(functionStub, normalFunctionStub, 0x20);
	sys_dbg_write_process_memory(functionStub, normalFunctionStub, 0x20);
	hookFunctionStub[0] = 0x3D600000 + ((newFunction >> 16) & 0xFFFF);
	hookFunctionStub[1] = 0x616B0000 + (newFunction & 0xFFFF);
	hookFunctionStub[2] = 0x7D6903A6;
	hookFunctionStub[3] = 0x4E800420;
	sys_dbg_write_process_memory_ps3mapi(functionStartAddress, hookFunctionStub, 0x10);
	sys_dbg_write_process_memory(functionStartAddress, hookFunctionStub, 0x10);
}
void UnHookFunctionStart(uint32_t functionStartAddress, uint32_t functionStub) {
	uint32_t normalFunctionStub[4];
	sys_dbg_read_process_memory(functionStub, normalFunctionStub, 0x10);
	sys_dbg_write_process_memory(functionStartAddress, normalFunctionStub, 0x10);

	sys_dbg_read_process_memory_ps3mapi(functionStub, normalFunctionStub, 0x10);
	sys_dbg_write_process_memory_ps3mapi(functionStartAddress, normalFunctionStub, 0x10);
}
int32_t BranchLinkedHook(uint32_t branchFrom, uint32_t branchTo)
{
	uint32_t branch;
	if (branchTo > branchFrom)
		branch = 0x48000001 + (branchTo - branchFrom);
	else
		branch = 0x4C000001 - (branchFrom - branchTo);
	return sys_dbg_write_process_memory_ps3mapi(branchFrom, &branch, 4);
}
int32_t BranchHook(uint32_t branchFrom, uint32_t branchTo)
{
	uint32_t branch;
	if (branchTo > branchFrom)
		branch = 0x48000000 + (branchTo - branchFrom);
	else
		branch = 0x4C000000 - (branchFrom - branchTo);
	return sys_dbg_write_process_memory_ps3mapi(branchFrom, &branch, 4);
}
bool bCompare(const unsigned char* pData, const unsigned char* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;

	return (*szMask) == 0;
}
unsigned long FindPattern(unsigned long dwAddress, unsigned long dwLen, unsigned char* bMask, char* szMask)
{
	for (unsigned long i = 0; i < dwLen; i++)
		if (bCompare((unsigned char*)(dwAddress + i), bMask, szMask))
			return (unsigned long)(dwAddress + i);

	return 0;
}


char * removespace(const char * notify) {
	char buffer[0x500];
	strcat(buffer, notify);
	for (int i = 0; i < 0x500; i++) {
		if (buffer[i] == ' ') {
			buffer[i] = '+';
		}
	}
	return buffer;
}
char* SendRequest(char* URL, char* Path) {
	struct sockaddr_in SocketAddress;
	char bufferReturn[500];
	char RequestBuffer[1000];
	memset(RequestBuffer, 0x00, 1000);
	SocketAddress.sin_addr.s_addr = *((unsigned long*)gethostbyname(URL)->h_addr);
	SocketAddress.sin_family = AF_INET;
	SocketAddress.sin_port = htons(80);
	int Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(Socket, (struct sockaddr *)&SocketAddress, sizeof(SocketAddress)) != 0) {
		return "";
	}
	strcat(RequestBuffer, "GET /");
	strcat(RequestBuffer, Path);
	strcat(RequestBuffer, "\r\nConnection: close\r\n\r\n");

	send(Socket, RequestBuffer, strlen(RequestBuffer), 0);
	while (recv(Socket, bufferReturn, 500, 0) > 0) {
		return bufferReturn;
	}
	socketclose(Socket);
}
void Notify(const char * notify) {
	char buffer[0x200];
	snprintf(buffer, 0x200, "notify.ps3mapi?msg=%s", notify);
	printf("%s\n", buffer);
	SendRequest("127.0.0.1", buffer);
}
