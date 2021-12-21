#pragma once



typedef struct Drops {
	int ItemOrder;
	int Grade;
	int DropRate;
};

extern bool ReadDrops(int MobID);
extern void UpdateDrops(int MobID);
extern Drops drops[9];