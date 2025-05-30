RUNTIME_DATA_FILE_BEGIN(DIR_PATH(Loot, LotteryItemPool.xml))

RUNTIME_DATA_TYPE_BEGIN(LotteryItemPool, "LotteryItemPool.Pool")
	RUNTIME_DATA_PROPERTY(Int32, PoolID, "PoolID")
	RUNTIME_DATA_TYPE_BEGIN_CHILD(LotteryItemPoolItem, "Item")
		RUNTIME_DATA_PROPERTY(UInt64, ItemID, "ItemID")
		RUNTIME_DATA_PROPERTY(UInt64, ItemOption, "ItemOption")
		RUNTIME_DATA_PROPERTY(Int32, ItemDuration, "ItemDuration")
		RUNTIME_DATA_PROPERTY(Int32, OptionPoolIndex, "OptionPoolID")
		RUNTIME_DATA_PROPERTY(Int32, Rate, "Rate")
	RUNTIME_DATA_TYPE_END_CHILD(LotteryItemPoolItem)
RUNTIME_DATA_TYPE_END(LotteryItemPool)
RUNTIME_DATA_TYPE_INDEX(LotteryItemPool, Int32, PoolID)

RUNTIME_DATA_FILE_END