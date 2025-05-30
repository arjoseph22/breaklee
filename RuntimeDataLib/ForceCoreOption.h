RUNTIME_DATA_FILE_BEGIN(forcecore_option.enc)

RUNTIME_DATA_TYPE_BEGIN(ForceCoreBase, "cabal.force_core.code")
	RUNTIME_DATA_PROPERTY(RTDataItemType, ItemType, "type")
	RUNTIME_DATA_PROPERTY(RTDataItemTypeGrade, ItemGrade, "type")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(ForceCoreBaseCode, "cont")
		RUNTIME_DATA_PROPERTY(Int32, ForceIndex, "index")
		RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "code")
		RUNTIME_DATA_PROPERTY(Int32, ForceLevel, "force_level")
		RUNTIME_DATA_PROPERTY(Int32, HasRandomRate, "randomrate_exist")
	RUNTIME_DATA_TYPE_END_CHILD(ForceCoreBaseCode)
RUNTIME_DATA_TYPE_END(ForceCoreBase)
RUNTIME_DATA_TYPE_INDEX_CHILD(ForceCoreBase, ForceCoreBaseCode, Int32, ForceEffectIndex)

RUNTIME_DATA_TYPE_BEGIN(ForceCodeEquipment, "cabal.force_core.force_code_equip")
	RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "code")
	RUNTIME_DATA_PROPERTY(Int32, ForceLevel, "CoreNum")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade1, "grade1")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade2, "grade2")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade3, "grade3")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade4, "grade4")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade5, "grade5")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade6, "grade6")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade7, "grade7")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade8, "grade8")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade9, "grade9")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade10, "grade10")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade11, "grade11")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade12, "grade12")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade13, "grade13")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade14, "grade14")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade15, "grade15")
RUNTIME_DATA_TYPE_END(ForceCodeEquipment)

RUNTIME_DATA_TYPE_BEGIN(ForceCodeAccessory, "cabal.force_core.force_code_etc")
	RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "code")
	RUNTIME_DATA_PROPERTY(Int32, ForceLevel, "CoreNum")
	RUNTIME_DATA_PROPERTY_ARRAY(Int32, AccessoryForceValueGrades, "ACSY", 14, ',')
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade5, "bike5")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade8, "bike8")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade11, "bike11")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade14, "bike14")
	RUNTIME_DATA_PROPERTY(Int32, EpauletForceValue, "epul")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade1, "Emblem1")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade2, "Emblem2")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade3, "Emblem3")
	RUNTIME_DATA_PROPERTY(Int32, UniqueEmblemForceValue, "UniqueEmblem")
RUNTIME_DATA_TYPE_END(ForceCodeAccessory)

RUNTIME_DATA_TYPE_BEGIN(ExtendedForceCodeEquipment, "cabal.force_core.extender_code_equip")
	RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "code")
	RUNTIME_DATA_PROPERTY(Int32, ForceLevel, "CoreNum")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade1, "grade1Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade2, "grade2Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade3, "grade3Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade4, "grade4Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade5, "grade5Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade6, "grade6Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade7, "grade7Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade8, "grade8Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade9, "grade9Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade10, "grade10Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade11, "grade11Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade12, "grade12Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade13, "grade13Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade14, "grade14Ex")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade15, "grade15Ex")
RUNTIME_DATA_TYPE_END(ExtendedForceCodeEquipment)

RUNTIME_DATA_TYPE_BEGIN(ExtendedForceCodeAccessory, "cabal.force_core.extender_code_etc")
	RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "code")
	RUNTIME_DATA_PROPERTY(Int32, ForceLevel, "CoreNum")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade5, "bike5Ex")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade8, "bike8Ex")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade11, "bike11Ex")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade14, "bike14Ex")
	RUNTIME_DATA_PROPERTY(Int32, EpauletForceValue, "epulEx")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade1, "Emblem1Ex")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade2, "Emblem2Ex")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade3, "Emblem3Ex")
	RUNTIME_DATA_PROPERTY(Int32, UniqueEmblemForceValue, "UniqueEmblemEx")
RUNTIME_DATA_TYPE_END(ExtendedForceCodeAccessory)

RUNTIME_DATA_TYPE_BEGIN(EpicCodeEquipment, "cabal.force_core.rare_code_equip")
	RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "code")
	RUNTIME_DATA_PROPERTY(Int32, ForceLevel, "RareNum")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade4, "grade4")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade5, "grade5")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade6, "grade6")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade7, "grade7")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade8, "grade8")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade9, "grade9")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade10, "grade10")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade11, "grade11")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade12, "grade12")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade13, "grade13")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade14, "grade14")
	RUNTIME_DATA_PROPERTY(Int32, ForceValueGrade15, "grade15")
	RUNTIME_DATA_PROPERTY(Int32, UniqueForceValueGrade1, "Uniquegrade1")
	RUNTIME_DATA_PROPERTY(Int32, UniqueForceValueGrade2, "Uniquegrade2")
RUNTIME_DATA_TYPE_END(EpicCodeEquipment)

RUNTIME_DATA_TYPE_BEGIN(EpicCodeAccessory, "cabal.force_core.rare_code_etc")
	RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "code")
	RUNTIME_DATA_PROPERTY(Int32, ForceLevel, "RareNum")
	RUNTIME_DATA_PROPERTY_ARRAY(Int32, AccessoryForceValueGrades, "ACSY", 14, ',')
	RUNTIME_DATA_PROPERTY_ARRAY(Int32, UniqueAccessoryForceValueGrades, "UniqueACSY", 14, ',')
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade5, "bike5")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade8, "bike8")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade11, "bike11")
	RUNTIME_DATA_PROPERTY(Int32, VehicleForceValueGrade14, "bike14")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade1, "Emblem1")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade2, "Emblem2")
	RUNTIME_DATA_PROPERTY(Int32, EmblemForceValueGrade3, "Emblem3")
	RUNTIME_DATA_PROPERTY(Int32, UniqueEmblemForceValue, "UniqueEmblem")
RUNTIME_DATA_TYPE_END(EpicCodeAccessory)

RUNTIME_DATA_TYPE_BEGIN(ForceCodeCost, "cabal.force_core.fcore_cost_init.fcore_cost")
	RUNTIME_DATA_PROPERTY(Int32, CostGrade, "equip_lv")
	RUNTIME_DATA_PROPERTY(Int32, FilledSlotCount, "active_opt")
	RUNTIME_DATA_PROPERTY(Int32, CurrencyCost, "cost")
RUNTIME_DATA_TYPE_END(ForceCodeCost)

RUNTIME_DATA_TYPE_BEGIN(ForceCodeRate, "cabal.force_core.fcore_rate_init.fcore_rate")
	RUNTIME_DATA_PROPERTY(Int32, ItemType, "item_type")
	RUNTIME_DATA_PROPERTY(Int32, FilledSlotCount, "active_opt")
	RUNTIME_DATA_PROPERTY(Int32, ItemUpgradeLevel, "enchant_level")
	RUNTIME_DATA_PROPERTY(Int32, Rate1, "equal0_rate")
	RUNTIME_DATA_PROPERTY(Int32, Rate2, "equal1_rate")
	RUNTIME_DATA_PROPERTY(Int32, Rate3, "equal2_rate")
RUNTIME_DATA_TYPE_END(ForceCodeRate)

RUNTIME_DATA_TYPE_BEGIN(ForceCodeRateBase, "cabal.force_core.fcore_success_rate")
	RUNTIME_DATA_PROPERTY(Int32, DefaultRate, "default")
	RUNTIME_DATA_PROPERTY(Int32, VehicleBikeRate, "bike_same_op")
	RUNTIME_DATA_PROPERTY(Int32, EmblemRate, "Emblem_same_op")
RUNTIME_DATA_TYPE_END(ForceCodeRateBase)
RUNTIME_DATA_TYPE_INDEX_SINGLE(ForceCodeRateBase)

RUNTIME_DATA_TYPE_BEGIN(UniqueOptionPoolItem, "cabal.Unique_option_pool.unique_item")
	RUNTIME_DATA_PROPERTY(UInt64, ItemID, "item_index")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(UniqueOptionPoolItemForce, "force_code")
		RUNTIME_DATA_PROPERTY(Int32, ForceEffectIndex, "force_code")
		RUNTIME_DATA_TYPE_BEGIN_CHILD(UniqueOptionPoolItemForceValue, "unique_value")
			RUNTIME_DATA_PROPERTY(Int32, Index, "Order")
			RUNTIME_DATA_PROPERTY(Int32, ForceValue, "Value")
			RUNTIME_DATA_PROPERTY(Int32, ForceValueType, "Value_type")
		RUNTIME_DATA_TYPE_END_CHILD(UniqueOptionPoolItemForceValue)
	RUNTIME_DATA_TYPE_END_CHILD(UniqueOptionPoolItemForce)
RUNTIME_DATA_TYPE_END(UniqueOptionPoolItem)
RUNTIME_DATA_TYPE_INDEX(UniqueOptionPoolItem, UInt64, ItemID)

RUNTIME_DATA_FILE_END

RUNTIME_DATA_FILE_BEGIN(DIR_PATH(Upgrade, EpicOptionPool.xml))

RUNTIME_DATA_TYPE_BEGIN(EpicOptionPool, "EpicOptionPool.Pool")
	RUNTIME_DATA_PROPERTY(Int32, Index, "id")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(EpicOptionPoolValue, "Epic")
		RUNTIME_DATA_PROPERTY(Int32, EpicOption, "id")
		RUNTIME_DATA_PROPERTY(Int32, EpicGrade, "grade")
		RUNTIME_DATA_PROPERTY(Int32, Rate, "rate")
	RUNTIME_DATA_TYPE_END_CHILD(EpicOptionPoolValue)
RUNTIME_DATA_TYPE_END(EpicOptionPool)
RUNTIME_DATA_TYPE_INDEX(EpicOptionPool, Int32, Index)

RUNTIME_DATA_FILE_END
