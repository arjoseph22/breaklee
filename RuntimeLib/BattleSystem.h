#pragma once

#include "Base.h"
#include "Constants.h"

EXTERN_C_BEGIN

#pragma pack(push, 1)

enum {
    RUNTIME_ATTACK_TYPE_CRITICAL = 1,
    RUNTIME_ATTACK_TYPE_NORMAL,
    RUNTIME_ATTACK_TYPE_MISS,
	RUNTIME_ATTACK_TYPE_MOBSDEAD,
	RUNTIME_ATTACK_TYPE_SUCCSBUF,
	RUNTIME_ATTACK_TYPE_EXISTBUF = 10,
	RUNTIME_ATTACK_TYPE_EXTCRITLL,
	RUNTIME_ATTACK_TYPE_EXTNORML,
	RUNTIME_ATTACK_TYPE_EXTMISSN,
	RUNTIME_ATTACK_TYPE_ENCHANT,
	RUNTIME_ATTACK_TYPE_STUNFAIL,
	RUNTIME_ATTACK_TYPE_FULLFAIL,
	RUNTIME_ATTACK_TYPE_DIFFWORLD,
	RUNTIME_ATTACK_TYPE_TARGETERROR,
	RUNTIME_ATTACK_TYPE_ABSORBED,
	RUNTIME_ATTACK_TYPE_BLOCK = 27,
	RUNTIME_ATTACK_TYPE_PROTECT = 28,
};

enum {
	RUNTIME_COMBO_TIMING_MISS		= 0,
	RUNTIME_COMBO_TIMING_LOW		= 1,
	RUNTIME_COMBO_TIMING_MEDIUM		= 2,
	RUNTIME_COMBO_TIMING_HIGH		= 3,
	RUNTIME_COMBO_TIMING_INVALID	= 4,
};

enum {
	RUNTIME_ATTRIBUTE_NONE,

	RUNTIME_ATTRIBUTE_EXP,

	RUNTIME_ATTRIBUTE_LEVEL,

	RUNTIME_ATTRIBUTE_STR,
	RUNTIME_ATTRIBUTE_DEX,
	RUNTIME_ATTRIBUTE_INT,

	RUNTIME_ATTRIBUTE_HP_CURRENT,
	RUNTIME_ATTRIBUTE_HP_MAX,
	RUNTIME_ATTRIBUTE_HP_ABSORB,
	RUNTIME_ATTRIBUTE_HP_ABSORB_LIMIT,
	RUNTIME_ATTRIBUTE_HP_REGEN,
	RUNTIME_ATTRIBUTE_HP_REGEN_UP,
	RUNTIME_ATTRIBUTE_HP_REGEN_DOWN,
	RUNTIME_ATTRIBUTE_HP_CURSE,
	RUNTIME_ATTRIBUTE_HP_CURSE_RESIST,
	RUNTIME_ATTRIBUTE_HP_HEAL_INCREASE,
	RUNTIME_ATTRIBUTE_HP_HEAL_DECREASE,

	RUNTIME_ATTRIBUTE_MP_CURRENT,
	RUNTIME_ATTRIBUTE_MP_MAX,
	RUNTIME_ATTRIBUTE_MP_ABSORB,
	RUNTIME_ATTRIBUTE_MP_ABSORB_LIMIT,
	RUNTIME_ATTRIBUTE_MP_REGEN,
	RUNTIME_ATTRIBUTE_MP_CURSE,

	RUNTIME_ATTRIBUTE_SP_CURRENT,
	RUNTIME_ATTRIBUTE_SP_MAX,
	RUNTIME_ATTRIBUTE_SP_REGEN,
	RUNTIME_ATTRIBUTE_SP_CONSUMPTION_DECREASE,

	RUNTIME_ATTRIBUTE_BP_CURRENT,
	RUNTIME_ATTRIBUTE_BP_MAX,
	RUNTIME_ATTRIBUTE_BP_CONSUMPTION_DECREASE,

	RUNTIME_ATTRIBUTE_RAGE_CURRENT,
	RUNTIME_ATTRIBUTE_RAGE_MAX,

	RUNTIME_ATTRIBUTE_ATTACK,
	RUNTIME_ATTRIBUTE_ATTACK_PVP,
	RUNTIME_ATTRIBUTE_ATTACK_PVE,
	RUNTIME_ATTRIBUTE_ATTACK_PERCENT,

	RUNTIME_ATTRIBUTE_MAGIC_ATTACK,
	RUNTIME_ATTRIBUTE_MAGIC_ATTACK_PVP,
	RUNTIME_ATTRIBUTE_MAGIC_ATTACK_PVE,
	RUNTIME_ATTRIBUTE_MAGIC_ATTACK_PERCENT,

	RUNTIME_ATTRIBUTE_DEFENSE,
	RUNTIME_ATTRIBUTE_DEFENSE_PVP,
	RUNTIME_ATTRIBUTE_DEFENSE_PVE,
	RUNTIME_ATTRIBUTE_DEFENSE_PERCENT,

	RUNTIME_ATTRIBUTE_ATTACK_RATE,
	RUNTIME_ATTRIBUTE_ATTACK_RATE_PVP,
	RUNTIME_ATTRIBUTE_ATTACK_RATE_PVE,

	RUNTIME_ATTRIBUTE_DEFENSE_RATE,
	RUNTIME_ATTRIBUTE_DEFENSE_RATE_PVP,
	RUNTIME_ATTRIBUTE_DEFENSE_RATE_PVE,

	RUNTIME_ATTRIBUTE_CRITICAL_RATE,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_PVP,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_PVE,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_RESIST,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_RESIST_PVE,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_IGNORE_RESIST,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_IGNORE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_IGNORE_RESIST_PVE,
	RUNTIME_ATTRIBUTE_CRITICAL_RATE_MAX,

	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE,
	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE_PVP,
	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE_PVE,
	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE_RESIST,
	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE_RESIST_PVE,
	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE_IGNORE_RESIST,
	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE_IGNORE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_CRITICAL_DAMAGE_IGNORE_RESIST_PVE,

	RUNTIME_ATTRIBUTE_NORMAL_DAMAGE,
	RUNTIME_ATTRIBUTE_NORMAL_DAMAGE_PVP,
	RUNTIME_ATTRIBUTE_NORMAL_DAMAGE_PVE,

	RUNTIME_ATTRIBUTE_MIN_DAMAGE,

	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP,
	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP_PVP,
	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP_PVE,
	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP_RESIST,
	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP_RESIST_PVP,
	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP_RESIST_PVE,
	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP_IGNORE_RESIST,
	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP_IGNORE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_SWORD_SKILL_AMP_IGNORE_RESIST_PVE,

	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP,
	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP_PVP,
	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP_PVE,
	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP_RESIST,
	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP_RESIST_PVP,
	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP_RESIST_PVE,
	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP_IGNORE_RESIST,
	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP_IGNORE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_MAGIC_SKILL_AMP_IGNORE_RESIST_PVE,

	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP,
	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP_PVP,
	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP_PVE,
	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP_RESIST,
	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP_RESIST_PVP,
	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP_RESIST_PVE,
	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP_IGNORE_RESIST,
	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP_IGNORE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_ALL_SKILL_AMP_IGNORE_RESIST_PVE,

	RUNTIME_ATTRIBUTE_EVASION,
	RUNTIME_ATTRIBUTE_EVASION_PVP,
	RUNTIME_ATTRIBUTE_EVASION_PVE,
	RUNTIME_ATTRIBUTE_EVASION_RESIST,
	RUNTIME_ATTRIBUTE_EVASION_RESIST_PVP,
	RUNTIME_ATTRIBUTE_EVASION_RESIST_PVE,
	RUNTIME_ATTRIBUTE_EVASION_IGNORE_RESIST,
	RUNTIME_ATTRIBUTE_EVASION_IGNORE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_EVASION_IGNORE_RESIST_PVE,
	RUNTIME_ATTRIBUTE_EVASION_ABSOLUTE,
	RUNTIME_ATTRIBUTE_EVASION_COMPLETE,

	RUNTIME_ATTRIBUTE_FINAL_DAMAGE_INCREASE,
	RUNTIME_ATTRIBUTE_FINAL_DAMAGE_INCREASE_PVP,
	RUNTIME_ATTRIBUTE_FINAL_DAMAGE_INCREASE_PVE,

	RUNTIME_ATTRIBUTE_FINAL_DAMAGE_DECREASE,
	RUNTIME_ATTRIBUTE_FINAL_DAMAGE_DECREASE_PVP,
	RUNTIME_ATTRIBUTE_FINAL_DAMAGE_DECREASE_PVE,

	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_PVP,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_PVE,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_PERCENT,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_RESIST,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_RESIST_PVP,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_RESIST_PVE,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_IGNORE_RESIST,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_IGNORE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_DAMAGE_REDUCTION_IGNORE_RESIST_PVE,

	RUNTIME_ATTRIBUTE_ACCURACY,
	RUNTIME_ATTRIBUTE_ACCURACY_PVP,
	RUNTIME_ATTRIBUTE_ACCURACY_PVE,
	RUNTIME_ATTRIBUTE_ACCURACY_RESIST,
	RUNTIME_ATTRIBUTE_ACCURACY_RESIST_PVP,
	RUNTIME_ATTRIBUTE_ACCURACY_RESIST_PVE,

	RUNTIME_ATTRIBUTE_PENETRATION,
	RUNTIME_ATTRIBUTE_PENETRATION_PVP,
	RUNTIME_ATTRIBUTE_PENETRATION_PVE,
	RUNTIME_ATTRIBUTE_PENETRATION_RESIST,
	RUNTIME_ATTRIBUTE_PENETRATION_RESIST_PVP,
	RUNTIME_ATTRIBUTE_PENETRATION_RESIST_PVE,
	RUNTIME_ATTRIBUTE_PENETRATION_IGNORE_RESIST,
	RUNTIME_ATTRIBUTE_PENETRATION_IGNORE_RESIST_PVP,
	RUNTIME_ATTRIBUTE_PENETRATION_IGNORE_RESIST_PVE,

	RUNTIME_ATTRIBUTE_STUN_CURRENT_DURATION,
	RUNTIME_ATTRIBUTE_STUN,
	RUNTIME_ATTRIBUTE_STUN_RESIST,
	RUNTIME_ATTRIBUTE_STUN_IGNORE_RESIST,

	RUNTIME_ATTRIBUTE_DOWN_CURRENT_DURATION,
	RUNTIME_ATTRIBUTE_DOWN,
	RUNTIME_ATTRIBUTE_DOWN_RESIST,
	RUNTIME_ATTRIBUTE_DOWN_IGNORE_RESIST,

	RUNTIME_ATTRIBUTE_KNOCK_BACK_CURRENT_DURATION,
	RUNTIME_ATTRIBUTE_KNOCK_BACK,
	RUNTIME_ATTRIBUTE_KNOCK_BACK_RESIST,
	RUNTIME_ATTRIBUTE_KNOCK_BACK_IGNORE_RESIST,

	RUNTIME_ATTRIBUTE_IMMOBILITY_CURRENT_DURATION,
	RUNTIME_ATTRIBUTE_IMMOBILITY,
	RUNTIME_ATTRIBUTE_IMMOBILITY_RESIST,

	RUNTIME_ATTRIBUTE_SUPPRESSION_CURRENT_DURATION,
	RUNTIME_ATTRIBUTE_SUPPRESSION, // When Suppression is in effect, afflicted character cannot move or use skills.
	RUNTIME_ATTRIBUTE_SUPPRESSION_PERCENT,
	RUNTIME_ATTRIBUTE_SUPPRESSION_DURATION,
	RUNTIME_ATTRIBUTE_SUPPRESSION_RESIST,

	RUNTIME_ATTRIBUTE_SILENCE_CURRENT_DURATION,
	RUNTIME_ATTRIBUTE_SILENCE, // When Silence is in effect, afflicted character cannot use any skills.
	RUNTIME_ATTRIBUTE_SILENCE_PERCENT,
	RUNTIME_ATTRIBUTE_SILENCE_DURATION,
	RUNTIME_ATTRIBUTE_SILENCE_RESIST,

	RUNTIME_ATTRIBUTE_ROOT_CURRENT_DURATION,
	RUNTIME_ATTRIBUTE_ROOT, // When Root is in effect, afflicted character cannot move or use skills related to movement.
	RUNTIME_ATTRIBUTE_ROOT_PERCENT,
	RUNTIME_ATTRIBUTE_ROOT_DURATION,

	RUNTIME_ATTRIBUTE_PETRIFY_CURRENT_DURATION,
	RUNTIME_ATTRIBUTE_PETRIFY,

	RUNTIME_ATTRIBUTE_DAMAGE_ABSORB,
	RUNTIME_ATTRIBUTE_DAMAGE_REFLECT,

	RUNTIME_ATTRIBUTE_MOVEMENT_SPEED,
	RUNTIME_ATTRIBUTE_MOVEMENT_SPEED_PERCENT,

	RUNTIME_ATTRIBUTE_WING_DAMAGE,
	RUNTIME_ATTRIBUTE_WING_DAMAGE_ACTIVATE,
	RUNTIME_ATTRIBUTE_WING_PROTECT_ACTIVATE,

	//---
	
	RUNTIME_ATTRIBUTE_INCREASE_BATTLE_MODE_DURATION,
	RUNTIME_ATTRIBUTE_INCREASE_AURA_MODE_DURATION,

	RUNTIME_ATTRIBUTE_ADD_DAMAGE,
	RUNTIME_ATTRIBUTE_ADD_DAMAGE_PVP,
	RUNTIME_ATTRIBUTE_ADD_DAMAGE_PVE,

	RUNTIME_ATTRIBUTE_SKILL_EXP,
	RUNTIME_ATTRIBUTE_SKILL_EXP_PERCENT,

	RUNTIME_ATTRIBUTE_ALZ_DROP_AMOUNT,
	RUNTIME_ATTRIBUTE_ALZ_DROP_RATE,
	RUNTIME_ATTRIBUTE_ALZ_BOMB_RATE,

	RUNTIME_ATTRIBUTE_DROP_RATE,

	RUNTIME_ATTRIBUTE_BOX_DROP_RATE,

    RUNTIME_ATTRIBUTE_AXP_RATE,
    
    RUNTIME_ATTRIBUTE_WAR_EXP_RATE,
    
    RUNTIME_ATTRIBUTE_PARTY_EXP_RATE,
    
    RUNTIME_ATTRIBUTE_EXP_RATE,
    
    RUNTIME_ATTRIBUTE_PET_EXP_RATE,
    
    RUNTIME_ATTRIBUTE_FORCE_WING_EXP_RATE,
    
    RUNTIME_ATTRIBUTE_REGEN_SP,

	RUNTIME_ATTRIBUTE_ABSOLUTE_DAMAGE,
    RUNTIME_ATTRIBUTE_ABSOLUTE_DAMAGE_RESIST,

	RUNTIME_ATTRIBUTE_COUNT
};

struct _RTBattleStyleLevelFormulaData {
	Int32 BattleStyleIndex;
	Int32 BaseHP;
	Int32 DeltaHP;
	Int32 DeltaHP2;
	Int32 BaseMP;
	Int32 DeltaMP;
};

struct _RTBattleStyleClassFormulaData {
	Int32 BattleStyleIndex;
	Int32 Attack[2];
	Int32 MagicAttack[2];
	Int32 Defense[2];
	Int32 AttackRate[2];
	Int32 DefenseRate[2];
	Int32 DamageReduction[2];
	Int32 Accuracy[2];
	Int32 Penetration[2];
	Int32 AccuracyPenalty[2];
	Int32 PenetrationPenalty[2];
};

struct _RTBattleStyleSlopeData {
	Int32 Penalty;
	Int32 Slope;
	Int32 Intercept;
};

struct _RTBattleStyleSlopeFormulaData {
	Int32 SlopeID;
	Int32 SlopeCount;
	struct _RTBattleStyleSlopeData Slopes[RUNTIME_MEMORY_MAX_SLOPE_DATA_COUNT];
};

struct _RTBattleStyleStatsFormulaData {
	Int32 BattleStyleIndex;
	Int32 Attack[3];
	Int32 AttackSlopeID;
	Int32 MagicAttack[3];
	Int32 MagicAttackSlopeID;
	Int32 DamageReduction[3];
	Int32 DamageReductionSlopeID;
	Int32 Evasion[3];
	Int32 EvasionSlopeID;
	Int32 AttackRate[3];
	Int32 AttackRateSlopeID;
	Int32 DefenseRate[3];
	Int32 DefenseRateSlopeID;
	Int32 ResistCriticalRate[3];
	Int32 ResistCriticalRateSlopeID;
	Int32 ResistSkillAmp[3];
	Int32 ResistSkillAmpSlopeID;
	Int32 ResistCriticalDamage[3];
	Int32 ResistCriticalDamageSlopeID;
	Int32 ResistUnmovable[3];
	Int32 ResistUnmovableSlopeID;
	Int32 ResistStun[3];
	Int32 ResistStunSlopeID;
	Int32 ResistDown[3];
	Int32 ResistDownSlopeID;
	Int32 ResistKnockback[3];
	Int32 ResistKnockbackSlopeID;
	Int32 HP[3];
	Int32 HPSlopeID;
	Int32 MP[3];
	Int32 MPSlopeID;
	Int32 IgnorePenetration[3];
	Int32 IgnorePenetrationSlopeID;
};

struct _RTBattleStyleRankData {
	Int32 Level;
	Int32 ConditionSTR;
	Int32 ConditionDEX;
	Int32 ConditionINT;
	Int32 SkillIndex[2];
	Int32 SkillSlot[2];
};

struct _RTBattleStyleSkillRankData {
	Int32 SkillRank;
	Int32 SkillLevelExp;
};

struct _RTBattleStyleSkillFormulaData {
	Int32 BattleStyleIndex;
	Int32 SkillRankCount;
	struct _RTBattleStyleSkillRankData SkillRanks[RUNTIME_MEMORY_MAX_SKILL_RANK_DATA_COUNT];
};

struct _RTBattleStyleRankFormulaData {
	Int32 BattleStyleIndex;
	Int32 RankCount;
	struct _RTBattleStyleRankData Ranks[RUNTIME_MEMORY_MAX_BATTLE_RANK_DATA_COUNT];
};

struct _RTBattleAttributes {
	Int32 Seed;
	Int64 Values[RUNTIME_ATTRIBUTE_COUNT];
};

struct _RTFinalBattleAttributes {
	Int64 Attack;
	Int64 Defense;
	Int64 CriticalDamage;
	Int64 SkillAmp;
	Int64 AddDamage;
	Int64 MinDamage;
	Int64 AbsoluteDamage;
	Int64 DamageReduction;
	Int64 DamageReductionPercent;
	Int64 NormalDamageAmp;
	Int64 FinalDamageIncrease;
	Int64 FinalDamageDecrease;
	Int64 CriticalRate;
	Int64 MissRate;
	Int64 BlockRate;
};
typedef struct _RTFinalBattleAttributes RTFinalBattleAttributes;

struct _RTBattleResult {
	UInt8 AttackType;
	Bool IsDead;
	Int64 TotalDamage;
	Int64 AppliedDamage;
	Int64 AdditionalDamage;
	Int64 Exp;
	Int64 SkillExp;
	Timestamp Delay;
};
typedef struct _RTBattleResult RTBattleResult;

#pragma pack(pop)

Int64 RTCalculateBaseHP(
	Int64 SkillRank,
	Int64 BaseHP,
	Int64 DeltaHP,
	Int64 Level,
	Int64 BattleRank,
	Int64 DeltaHP2
);

Int64 RTCalculateBaseMP(
	Int64 SkillRank,
	Int64 BaseMP,
	Int64 DeltaMP,
	Int64 Level,
	Int64 BattleRank,
	Int64 DeltaMP2
);

Int32 RTCalculateSPReward(
	Int32 SkillExp,
	Int32 ComboLevel,
	Int32 ComboTiming
);

Int32 RTCalculateSPRegen(
	Int32 CurrentSP
);

RTBattleResult RTCalculateNormalAttackResult(
	RTRuntimeRef Runtime,
	RTWorldContextRef WorldContext,
	Int32 DamageType,
	Bool IsPVE,
	RTBattleAttributesRef Attacker,
	RTBattleAttributesRef Defender,
	RTMovementRef AttackerMovement,
	RTMovementRef DefenderMovement
);

RTBattleResult RTCalculateSkillAttackResult(
	RTRuntimeRef Runtime,
	RTWorldContextRef WorldContext,
	Int32 SkillLevel,
	RTCharacterSkillDataRef Skill,
	Bool IsPVE,
	RTBattleAttributesRef Attacker,
	RTBattleAttributesRef Defender,
	RTMovementRef AttackerMovement,
	RTMovementRef DefenderMovement
);

RTBattleResult RTCalculateMobAttackResult(
	RTRuntimeRef Runtime,
	RTWorldContextRef WorldContext,
	RTDataMobAttackDataRef AttackData,
	RTDataMobSkillRef SkillData,
	Int32 PhysicalAttackMin,
	Int32 PhysicalAttackMax,
	RTBattleAttributesRef Attacker,
	RTBattleAttributesRef Defender,
	RTMovementRef AttackerMovement,
	RTMovementRef DefenderMovement
);

EXTERN_C_END
