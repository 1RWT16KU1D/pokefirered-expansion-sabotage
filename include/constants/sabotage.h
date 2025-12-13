#pragma once

/*
    New type of battle. 
    * At the start of turn, and every three subsquent turns, one random active trap
      and one random passive trap is activated.

    * Passive traps are applied throughout the field and have no activation condition.
      They are announced at the start of their activation turn.

      Examples: Graveyard (All Pokemon gain Ghost-type), Trapper's Territory (All Pokemon
      can't switch out), Bizzare Temple (All Pokemon have a 50% chance to switch moves with
      their opponent), Sin of Pride (All Dragon-type moves turn Dark-type)

    * Active traps are hidden to the player and have an activation condition.
      They are only announced when they are activated. They last for 3 turns, except when their
      effect ends, then the next turn a new trap is set.

      Examples: No Interference (Using an item cancels the effect and ends the turn),
      Shattered Dreams (If the trainer attempts to Mega Evolve, use a Z-Move, Dynamax
      or Terastallize, and other gimmicks, the action fails and the turn ends),
      Jackpot! (25% for the ability to pop-up and guarantee a crit)
*/


enum SabotageEffects
{
    SABOTAGE_EFFECT_ON_SWITCHIN,
    SABOTAGE_EFFECT_END_TURN,
    SABOTAGE_EFFECT_BATTLE_START
};

#define SABOTAGE_TRAP_NONE              0

// Passive Traps
enum SabotageTraps
{
    // Passive Traps
    SABOTAGE_TRAP_TRAPPERS_TERRITORY  = 1,  // All Pokémon cannot switch out
    SABOTAGE_TRAP_GRAVEYARD           = 2,  // All Pokémon gain Ghost-type (can have up to 3 types)
    SABOTAGE_TRAP_WRONG_INTUITION     = 3,  // Pokémon will use a different move than intended
    SABOTAGE_TRAP_ITS_RAINING_HAZARDS = 4,  // Random entry hazards are set at the start of each turn
    SABOTAGE_TRAP_BALLROOM_BONANZA    = 5,  // All Pokémon are infatuated, provided both genders exist on field
    SABOTAGE_TRAP_ABILITY_NULL        = 6,  // All abilities are nullified
    SABOTAGE_TRAP_CHILLY_WINDS        = 7,  // All moves deal additional Ice-type damage
    SABOTAGE_TRAP_HEALING_GROUNDS     = 8,  // All recovery moves heal double the amount
    SABOTAGE_TRAP_BIZZARE_TEMPLE      = 9,  // 50% chance to switch moves with opponent
    SABOTAGE_TRAP_HOT_LAVA            = 10, // All Pokémon are burned, except Fire-types
    SABOTAGE_TRAP_STAT_ROULETTE       = 11, // All Pokémon gain a random 2-stage stat boost
    SABOTAGE_TRAP_COFFEE_FIELDS       = 12, // Pokémon can't sleep; Speed either halved or doubled
    SABOTAGE_TRAP_DISTORTED_FURY      = 13, // Physical moves become Special and vice-versa

    SABOTAGE_TRAP_PASSIVE_COUNT,

    // Active Traps
    SABOTAGE_TRAP_NO_INTERFERENCE     = 14, // Using an item cancels the effect and ends the turn
    SABOTAGE_TRAP_SHATTERED_DREAMS    = 15, // Mega/Z/Dyna/Tera fail and turn ends
    SABOTAGE_TRAP_JACKPOT             = 16, // 25% chance to guarantee a critical hit
    SABOTAGE_TRAP_BANANA_PEEL         = 17, // Using a Grass-type move forces the user to switch out
    SABOTAGE_TRAP_NO_HOLDS_BARRED     = 18, // Fighting-type moves deal double damage, accuracy halved
    SABOTAGE_TRAP_SEALED_DEMON        = 19, // For that turn, all moves have double power
    SABOTAGE_TRAP_BLOOD_PACT          = 20, // KOing an opponent costs half the user's HP
    SABOTAGE_TRAP_SIN_OF_PRIDE        = 21, // All Dragon-type moves become Dark-type
    SABOTAGE_TRAP_DETONATION_DELUSION = 22, // 25% chance for any move to become Explosion
    SABOTAGE_TRAP_NOTHING_SPECIAL     = 23, // Normal-type moves become a random type

    SABOTAGE_TRAP_TOTAL_COUNT
};

#define SABOTAGE_TRAP_ACTIVE_COUNT (SABOTAGE_TRAP_TOTAL_COUNT - SABOTAGE_TRAP_PASSIVE_COUNT)

// Structure for holding trap data
struct TrapData
{
    u8 *name;
    u8 *desc;
};

extern struct TrapData gTrapData[SABOTAGE_TRAP_TOTAL_COUNT];

// Flavor Text
extern u8 sText_Name_TrappersTerritory[];
extern u8 sText_Name_Graveyard[];
extern u8 sText_Name_ItsRainingHazards[];
extern u8 sText_Name_BallroomBonanza[];
extern u8 sText_Name_AbilityNull[];
extern u8 sText_Name_ChillyWinds[];
extern u8 sText_Name_HealingGrounds[];
extern u8 sText_Name_BizzareTemple[];
extern u8 sText_Name_HotLava[];
extern u8 sText_Name_StatRoulette[];
extern u8 sText_Name_CoffeeFields[];
extern u8 sText_Name_DistortedFury[];
extern u8 sText_Name_WrongIntuition[];

extern u8 sText_Name_NoInterference[];
extern u8 sText_Name_ShatteredDreams[];
extern u8 sText_Name_Jackpot[];
extern u8 sText_Name_BananaPeel[];
extern u8 sText_Name_NoHoldsBarred[];
extern u8 sText_Name_SealedDemon[];
extern u8 sText_Name_BloodPact[];
extern u8 sText_Name_SinOfPride[];
extern u8 sText_Name_DetonationDelusion[];
extern u8 sText_Name_NothingSpecial[];


extern u8 sText_Desc_TrappersTerritory[];
extern u8 sText_Desc_Graveyard[];
extern u8 sText_Desc_ItsRainingHazards[];
extern u8 sText_Desc_BallroomBonanza[];
extern u8 sText_Desc_AbilityNull[];
extern u8 sText_Desc_ChillyWinds[];
extern u8 sText_Desc_HealingGrounds[];
extern u8 sText_Desc_BizzareTemple[];
extern u8 sText_Desc_HotLava[];
extern u8 sText_Desc_StatRoulette[];
extern u8 sText_Desc_CoffeeFields[];
extern u8 sText_Desc_DistortedFury[];
extern u8 sText_Desc_WrongIntuition[];

extern u8 sText_Desc_NoInterference[];  
extern u8 sText_Desc_ShatteredDreams[];
extern u8 sText_Desc_Jackpot[];
extern u8 sText_Desc_BananaPeel[];
extern u8 sText_Desc_NoHoldsBarred[];
extern u8 sText_Desc_SealedDemon[];
extern u8 sText_Desc_BloodPact[];
extern u8 sText_Desc_SinOfPride[];
extern u8 sText_Desc_DetonationDelusion[];
extern u8 sText_Desc_NothingSpecial[];
