#include <vector>
#include <Windows.h>
#include <tlhelp32.h>
#include "ReadDrops.h"
#include <string>
#include "thirdparty/Memory.h"
#include "thirdparty/nanodbc.h"

Drops drops[9];

HANDLE processHandle=0;

DWORD baseofMobs = 0;


bool ReadDrops(int MobID) {

	if (processHandle != 0) CloseHandle(processHandle);

	DWORD processId;

	int baseAddress;

	char* TARGET_PROCESS_NAME = "ps_game.exe";

	Memory Memory;
	Memory.GetDebugPrivileges();
	processId = Memory.GetProcessId(TARGET_PROCESS_NAME);
	processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);
	baseAddress = Memory.GetModuleBase(processHandle, (string)TARGET_PROCESS_NAME);

	DWORD base1 = 0x00587C68;
	DWORD base2 = 0x00A81A10;

	int mobCount = 0;
	ReadProcessMemory(processHandle, (void*)(base1 + 0x00A81A0C), &mobCount, sizeof(mobCount), 0);

	if (MobID > mobCount) return false;

	ReadProcessMemory(processHandle, (void*)(base1 + base2), &baseofMobs, sizeof(baseofMobs), 0);
	baseofMobs += 0xBC + 0x8;

	int TargetMob = baseofMobs+ (0x10C * MobID);

	for (int i = 0; i < 9; i++) {
		ReadProcessMemory(processHandle, (void*)(TargetMob + i * 8), &drops[i].Grade, sizeof(drops[i].Grade), 0);
		ReadProcessMemory(processHandle, (void*)(TargetMob + 4 + i * 8), &drops[i].DropRate, sizeof(drops[i].DropRate), 0);
	}

	return true;
}




void UpdateDrops(int MobID) {

	int TargetMob = baseofMobs + (0x10C * MobID);

	nanodbc::connection connection("Driver={SQL Server Native Client 11.0};Server=127.0.0.1;Database=PS_GameDefs;Trusted_Connection=yes;", 30);
	
	for (int i = 0; i < 9; i++) {
		WriteProcessMemory(processHandle, (void*)(TargetMob + i * 8), &drops[i].Grade, sizeof(drops[i].Grade), 0);
		WriteProcessMemory(processHandle, (void*)(TargetMob + 4 + i * 8), &drops[i].DropRate, sizeof(drops[i].DropRate), 0);

		std::string Procedure = "Update PS_GameDefs.dbo.MobItems SET Grade="+std::to_string(drops[i].Grade)+ ", DropRate="+
			std::to_string(drops[i].DropRate) +" Where MobID=" + std::to_string(MobID) + " and ItemOrder=" + std::to_string(i+1);
		execute(connection, Procedure);
	}
}