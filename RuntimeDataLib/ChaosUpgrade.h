RUNTIME_DATA_FILE_BEGIN(chaos_upgrade.enc)

RUNTIME_DATA_TYPE_BEGIN(ChaosUpgradeItemList, "cabal_chaos_upgrade.chaosupgrade_itemlist.item", 64)
	RUNTIME_DATA_PROPERTY(UInt64, ItemID, "index")
	RUNTIME_DATA_PROPERTY(Int32, Group, "group")
	RUNTIME_DATA_PROPERTY(Int32, ItemGrade, "max_grade")
	RUNTIME_DATA_PROPERTY(Int32, CheckLevel, "level_check")
RUNTIME_DATA_TYPE_END(ChaosUpgradeItemList)
RUNTIME_DATA_TYPE_INDEX(ChaosUpgradeItemList, UInt64, ItemID)

RUNTIME_DATA_TYPE_BEGIN(ChaosUpgradeGroupValue, "cabal_chaos_upgrade.chaosupgrade_value.chaositem", 32)
	RUNTIME_DATA_PROPERTY(Int32, Group, "group")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ChaosUpgradeGroupValueLevel, "value", 128)
		RUNTIME_DATA_PROPERTY(Int32, Level, "level")
		RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "force_id")
		RUNTIME_DATA_PROPERTY(Int32, ForceValue, "force_value")
		RUNTIME_DATA_PROPERTY(Int32, ForceValueType, "value_type")
	RUNTIME_DATA_TYPE_END_CHILD(ChaosUpgradeGroupValueLevel, 128)
RUNTIME_DATA_TYPE_END(ChaosUpgradeGroupValue)
RUNTIME_DATA_TYPE_INDEX(ChaosUpgradeGroupValue, Int32, Group)

RUNTIME_DATA_TYPE_BEGIN(ChaosUpgradeGroupCost, "cabal_chaos_upgrade.chaosneedscore", 32)
	RUNTIME_DATA_PROPERTY(Int32, Group, "group")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ChaosUpgradeGroupCostLevel, "core", 32)
		RUNTIME_DATA_PROPERTY(Int32, Level, "level")
		RUNTIME_DATA_PROPERTY(Int32, RequiredCoreCount, "needs_core")
		RUNTIME_DATA_PROPERTY(Int32, RequiredSafeCount, "needs_buffer")
		RUNTIME_DATA_PROPERTY_ARRAY(Int32, Results, "result", 6, ',')
	RUNTIME_DATA_TYPE_END_CHILD(ChaosUpgradeGroupCostLevel, 32)
RUNTIME_DATA_TYPE_END(ChaosUpgradeGroupCost)
RUNTIME_DATA_TYPE_INDEX(ChaosUpgradeGroupCost, Int32, Group)
RUNTIME_DATA_TYPE_INDEX_CHILD(ChaosUpgradeGroupCost, ChaosUpgradeGroupCostLevel, Int32, Level)

RUNTIME_DATA_TYPE_BEGIN(ChaosUpgradeSafeguardItem, "cabal_chaos_upgrade.chaosupgrade_buffer.item", 32)
	RUNTIME_DATA_PROPERTY(Int32, Group, "chaos_group")
	RUNTIME_DATA_PROPERTY(Int32, Option, "option")
RUNTIME_DATA_TYPE_END(ChaosUpgradeSafeguardItem)

RUNTIME_DATA_TYPE_BEGIN(ChaosUpgradeSafeguardItemList, "cabal_chaos_upgrade.chaosupgrade_bufferItemList.item", 16)
	RUNTIME_DATA_PROPERTY(UInt64, ItemID, "index")
	RUNTIME_DATA_PROPERTY(Int32, SafeguardType, "Buffer_kind")
	RUNTIME_DATA_PROPERTY_ARRAY(Int32, Groups, "Chaos_group", 3, ',')
RUNTIME_DATA_TYPE_END(ChaosUpgradeSafeguardItemList)

RUNTIME_DATA_FILE_END

RUNTIME_DATA_FILE_BEGIN(chaos_upgrade.xml)

RUNTIME_DATA_TYPE_BEGIN(ChaosUpgradeGroupRate, "cabal_chaos_upgrade.chaosupgrade_rate", 16)
	RUNTIME_DATA_PROPERTY(Int32, Group, "group")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ChaosUpgradeGroupRateLevel, "chaositem", 32)
		RUNTIME_DATA_PROPERTY(Int32, Level, "level")
		RUNTIME_DATA_PROPERTY_ARRAY(Int32, Rates, "rate", RUNTIME_DATA_UPGRADE_RATE_VALUE_COUNT, ',')
	RUNTIME_DATA_TYPE_END_CHILD(ChaosUpgradeGroupRateLevel, 32)
RUNTIME_DATA_TYPE_END(ChaosUpgradeGroupRate)
RUNTIME_DATA_TYPE_INDEX(ChaosUpgradeGroupRate, Int32, Group)
RUNTIME_DATA_TYPE_INDEX_CHILD(ChaosUpgradeGroupRate, ChaosUpgradeGroupRateLevel, Int32, Level)

RUNTIME_DATA_FILE_END