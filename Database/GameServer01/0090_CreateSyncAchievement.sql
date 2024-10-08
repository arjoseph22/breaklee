CREATE PROCEDURE SyncAchievement (
    IN InCharacterID INT,
    IN InTotalScore INT,
    IN InNormalScore INT,
    IN InQuestScore INT,
    IN InDungeonScore INT,
    IN InItemsScore INT,
    IN InPvpScore INT,
    IN InWarScore INT,
    IN InHuntingScore INT,
    IN InCraftScore INT,
    IN InCommunityScore INT,
    IN InSharedScore INT,
    IN InSpecialScore INT,
    IN InGeneralMemoirScore INT,
    IN InSharedMemoirScore INT,
    IN InDisplayTitle SMALLINT UNSIGNED,
    IN InEventTitle SMALLINT UNSIGNED,
    IN InGuildTitle SMALLINT UNSIGNED,
    IN InWarTitle SMALLINT UNSIGNED,
    IN InSlotCount INT,
    IN InRewardSlotCount INT,
    IN InSlotData BLOB,
    IN InRewardSlotData BLOB
)
BEGIN
    UPDATE Achievement
    SET
        TotalScore = InTotalScore,
        NormalScore = InNormalScore,
        QuestScore = InQuestScore,
        DungeonScore = InDungeonScore,
        ItemsScore = InItemsScore,
        PvpScore = InPvpScore,
        WarScore = InWarScore,
        HuntingScore = InHuntingScore,
        CraftScore = InCraftScore,
        CommunityScore = InCommunityScore,
        SharedScore = InSharedScore,
        SpecialScore = InSpecialScore,
        GeneralMemoirScore = InGeneralMemoirScore,
        SharedMemoirScore = InSharedMemoirScore,
        DisplayTitle = InDisplayTitle,
        EventTitle = InEventTitle,
        GuildTitle = InGuildTitle,
        WarTitle = InWarTitle,
        SlotCount = InSlotCount,
        RewardSlotCount = InRewardSlotCount,
        SlotData = InSlotData,
        RewardSlotData = InRewardSlotData
    WHERE CharacterID = InCharacterID;
END;
