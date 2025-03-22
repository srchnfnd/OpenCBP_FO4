#pragma once
#include <unordered_set>
#include <set>
#include <map>
#include <vector>

#include <concurrent_vector.h>
#include <concurrent_unordered_map.h>
#include <concurrent_unordered_set.h>

#include "f4se/GameReferences.h"
#include "unordered_dense.h"

#pragma warning(disable : 4996)

class Configuration
{
};

struct whitelistSex
{
    bool male;
    bool female;
};

typedef std::unordered_map<std::string, float> configEntry_t; // Map settings for a particular bone
typedef std::unordered_map<std::string, configEntry_t> config_t; // Settings for a set of bones
typedef std::unordered_map<std::string, std::unordered_map<std::string, whitelistSex>> whitelist_t;


struct armorOverrideData
{
    bool isFilterInverted;
    std::unordered_set<UInt32> slots;
    std::unordered_set<UInt32> armors;
    config_t config;
};

struct actorOverrideData
{
    bool isFilterInverted;
    std::unordered_set<UInt32> actors;
    config_t config;
};

extern bool playerOnly;
extern bool femaleOnly;
extern bool maleOnly;
extern bool npcOnly;
extern bool useWhitelist;
extern unsigned long logActor;

extern int configReloadCount;
extern config_t config;
extern std::unordered_map<UInt32, armorOverrideData> configArmorOverrideMap;
extern std::unordered_map<UInt32, actorOverrideData> configActorOverrideMap;
extern whitelist_t whitelist;
extern std::vector<std::string> raceWhitelist;
extern std::unordered_set<UInt32> usedSlots;
extern std::unordered_map<UInt64, config_t> cachedConfigs;
extern std::set<UInt32> priorities;

bool LoadConfig();
void DumpWhitelistToLog();