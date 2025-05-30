#include "ClientProtocol.h"
#include "ClientProcedures.h"
#include "ClientSocket.h"
#include "IPCProcedures.h"
#include "Notification.h"
#include "Server.h"

CLIENT_PROCEDURE_BINDING(GET_PREMIUM_SERVICE) {
	if (!(Client->Flags & CLIENT_FLAGS_VERIFIED) || Client->AccountID < 1) goto error;

	IPC_W2D_DATA_GET_PREMIUM_SERVICE* Request = IPCPacketBufferInit(Server->IPCSocket->PacketBuffer, W2D, GET_PREMIUM_SERVICE);
	Request->Header.SourceConnectionID = Connection->ID;
	Request->Header.Source = Server->IPCSocket->NodeID;
	Request->Header.Target.Group = Context->Config.WorldSvr.GroupIndex;
	Request->Header.Target.Type = IPC_TYPE_MASTERDB;
	Request->AccountID = Client->AccountID;
	IPCSocketUnicast(Server->IPCSocket, Request);
	return;

error:
	SocketDisconnect(Socket, Connection);
}

Void SendPremiumServiceList(
    ServerContextRef Context,
    SocketRef Socket,
    SocketConnectionRef Connection
) {
    PacketBufferRef PacketBuffer = SocketGetNextPacketBuffer(Socket);

    S2C_DATA_PREMIUM_BENEFIT_INFO_LIST* Response = PacketBufferInitExtended(PacketBuffer, S2C, PREMIUM_BENEFIT_INFO_LIST);
    Response->Count = Context->Runtime->Context->PremiumServiceCount;

    for (Int Index = 0; Index < Context->Runtime->Context->PremiumServiceCount; Index += 1) {
        RTDataPremiumServiceRef PremiumService = &Context->Runtime->Context->PremiumServiceList[Index];

        S2C_DATA_PREMIUM_BENEFIT_INFO* ResponseInfo = PacketBufferAppendStruct(PacketBuffer, S2C_DATA_PREMIUM_BENEFIT_INFO);
        ResponseInfo->ServiceID = PremiumService->ServiceID;
        ResponseInfo->Type = PremiumService->Type;
        ResponseInfo->XP = PremiumService->XP;
        ResponseInfo->SkillXP = PremiumService->SkillXP;
        ResponseInfo->DropRate = PremiumService->DropRate;
        ResponseInfo->AlzBombRate = PremiumService->AlzBombRate;
        ResponseInfo->WarXP = PremiumService->WarXP;
        ResponseInfo->PetXP = PremiumService->PetXP;
        ResponseInfo->AXP = PremiumService->AXP;
        ResponseInfo->TPointUp = PremiumService->TPointUp;
        ResponseInfo->AlzDropRate = PremiumService->AlzDropRate;
        ResponseInfo->BoxDropRate = PremiumService->BoxDropRate;
        ResponseInfo->ForceWingXP = PremiumService->ForceWingXP;
        ResponseInfo->Inventory1 = PremiumService->Inventory1;
        ResponseInfo->Inventory2 = PremiumService->Inventory2;
        ResponseInfo->Inventory3 = PremiumService->Inventory3;
        ResponseInfo->Inventory4 = PremiumService->Inventory4;
        ResponseInfo->Inventory5 = PremiumService->Inventory5;
        ResponseInfo->Inventory6 = PremiumService->Inventory6;
        ResponseInfo->ExtendPetSlot = PremiumService->ExtendPetSlot;
        ResponseInfo->Warehouse = PremiumService->Warehouse;
        ResponseInfo->SkillXPTDummy = PremiumService->SkillXPTDummy;
        ResponseInfo->GPSWarpMask = PremiumService->GPSWarpMask;
        ResponseInfo->UnlimitedWarp = PremiumService->UnlimitedWarp;
        ResponseInfo->AuctionHouseItemBonusSlots = PremiumService->AuctionHouseItemBonusSlots;
        ResponseInfo->AuctionHouseItemBonusQuantity = PremiumService->AuctionHouseItemBonusQuantity;
        ResponseInfo->AuctionHouseItemBonusPeriod = PremiumService->AuctionHouseItemBonusPeriod;
        ResponseInfo->AuctionHouseFeeExemption = PremiumService->AuctionHouseFeeExemption;
        ResponseInfo->AbleToBuyPremiumItemFromShop = PremiumService->AbleToBuyPremiumItemFromShop;
        ResponseInfo->RemoteShop = PremiumService->RemoteShop;
        ResponseInfo->AbleToEnterPremiumDungeon = PremiumService->AbleToEnterPremiumDungeon;
        ResponseInfo->PremiumDungeonReward = PremiumService->PremiumDungeonReward;
        ResponseInfo->RemoteWarehouse = PremiumService->RemoteWarehouse;
        ResponseInfo->CraftMasteryUp = PremiumService->CraftMasteryUp;
        ResponseInfo->RequestAmityUp = PremiumService->RequestAmityUp;
        ResponseInfo->RequestAmitySlots = PremiumService->RequestAmitySlots;
        ResponseInfo->DungeonPlayTimeIncreased = PremiumService->DungeonPlayTimeIncreased;
    }

    SocketSend(Context->ClientSocket, Connection, Response);
}

CLIENT_PROCEDURE_BINDING(PREMIUM_BENEFIT_INFO_LIST) {
    SendPremiumServiceList(Context, Socket, Connection);
}

IPC_PROCEDURE_BINDING(D2W, GET_PREMIUM_SERVICE) {
	if (!ClientConnection || !Client) return;

    S2C_DATA_GET_PREMIUM_SERVICE* Response = PacketBufferInit(SocketGetNextPacketBuffer(Context->ClientSocket), S2C, GET_PREMIUM_SERVICE);
    Response->ServiceType = Packet->ServiceType;
    Response->ExpirationDate = Packet->ExpiredAt;
    SocketSend(Context->ClientSocket, ClientConnection, Response);

	S2C_DATA_NFY_PREMIUM_SERVICE* Notification = PacketBufferInit(SocketGetNextPacketBuffer(Context->ClientSocket), S2C, NFY_PREMIUM_SERVICE);
	Notification->ServiceType = Packet->ServiceType;
	Notification->ExpirationDate = Packet->ExpiredAt;
	SocketSend(Context->ClientSocket, ClientConnection, Notification);

	S2C_DATA_NFY_BUDDY_POINTS* UnknownNotification = PacketBufferInit(SocketGetNextPacketBuffer(Context->ClientSocket), S2C, NFY_BUDDY_POINTS);
	/*
	UnknownNotification->Unknown1[0] = 4;
	UnknownNotification->Unknown1[1] = 1;
	UnknownNotification->Unknown1[2] = 2;
	UnknownNotification->Unknown1[3] = 0;
	UnknownNotification->Unknown1[4] = 20;
	UnknownNotification->Unknown1[5] = 1;
	*/
	SocketSend(Context->ClientSocket, ClientConnection, UnknownNotification);
}

CLIENT_PROCEDURE_BINDING(PURCHASE_PREMIUM_SERVICE) {
    if (!Character) goto error;

    S2C_DATA_PURCHASE_PREMIUM_SERVICE* Response = PacketBufferInit(SocketGetNextPacketBuffer(Socket), S2C, PURCHASE_PREMIUM_SERVICE);
    Response->Result = 1;
    Response->ServiceType = Packet->ServiceType;

    if (Packet->ServiceType == CSC_PURCHASE_PREMIUM_SERVICE_TYPE_GIFTBOX_COMPLETE) {
        Int32 PacketLength = sizeof(C2S_DATA_PURCHASE_PREMIUM_SERVICE) + sizeof(C2S_DATA_PURCHASE_PREMIUM_SERVICE_GIFTBOX);
        if (Packet->Length != PacketLength) goto error;

        C2S_DATA_PURCHASE_PREMIUM_SERVICE_GIFTBOX* Data = (C2S_DATA_PURCHASE_PREMIUM_SERVICE_GIFTBOX*)&Packet->Data[0];

        RTGiftBoxSlotRef GiftBoxSlot = RTCharacterGetGiftBox(Runtime, Character, Data->SlotIndex);
        if (!GiftBoxSlot) goto error;

        RTDataGiftBoxConditionRef GiftBoxCondition = RTRuntimeDataGiftBoxConditionGet(Runtime->Context, Data->SlotIndex);
        if (!GiftBoxCondition) goto error;
        if (GiftBoxSlot->ResetCount >= GiftBoxCondition->DailyResetCount) goto error;

        RTDataGiftBoxPricePoolRef PricePool = RTRuntimeDataGiftBoxPricePoolGet(Runtime->Context, Data->SlotIndex);
        if (!PricePool) goto error;

        RTDataGiftBoxPricePoolValueRef PricePoolValue = RTRuntimeDataGiftBoxPricePoolValueGet(PricePool, GiftBoxSlot->ReceivedCount);
        if (!PricePoolValue) goto error;

        if (!RTCharacterConsumeForceGem(Runtime, Character, PricePoolValue->Price)) goto error;

        Response->Result = 0;
        GiftBoxSlot->ElapsedTime = GiftBoxSlot->CooldownTime;
        GiftBoxSlot->ResetCount += 1;
    }

    if (Packet->ServiceType == CSC_PURCHASE_PREMIUM_SERVICE_TYPE_MYTH_RESURRECT) {
        CSC_DATA_PURCHASE_PREMIUM_SERVICE_TYPE_MYTH_RESURRECT* Data = (CSC_DATA_PURCHASE_PREMIUM_SERVICE_TYPE_MYTH_RESURRECT*)&Packet->Data[0];

        Int32 PacketLength = sizeof(C2S_DATA_PURCHASE_PREMIUM_SERVICE) + sizeof(CSC_DATA_PURCHASE_PREMIUM_SERVICE_TYPE_MYTH_RESURRECT) + (Data->InventorySlotCount * sizeof(UInt16));

        if (Packet->Length != PacketLength) {
            goto error;
        }

        UInt32 GemCost = RTCharacterMythMasteryGetRebirthGemCost(Runtime, Character);

        if (!RTCharacterConsumeForceGem(Runtime, Character, GemCost) || !RTCharacterMythMasteryGetCanRebirth(Runtime, Character)) {
            //TODO: handle error
            goto error;
        }

        RTCharacterMythMasteryRebirth(Runtime, Character, Data->InventorySlotIndex[0]);

        Response->Result = 0;
    }

    if (Packet->ServiceType == CSC_PURCHASE_PREMIUM_SERVICE_TYPE_HONOR_MEDAL_RESET) {
        Int32 PacketLength = sizeof(C2S_DATA_PURCHASE_PREMIUM_SERVICE) + sizeof(C2S_DATA_PURCHASE_PREMIUM_SERVICE_HONOR_MEDAL_RESET);
        if (Packet->Length != PacketLength) goto error;

        C2S_DATA_PURCHASE_PREMIUM_SERVICE_HONOR_MEDAL_RESET* Data = (C2S_DATA_PURCHASE_PREMIUM_SERVICE_HONOR_MEDAL_RESET*)&Packet->Data[0];
        UInt32 GemCost = 5 * Data->GroupIndex;

        if (!RTCharacterConsumeForceGem(Runtime, Character, GemCost)) {
            //TODO: handle error
            goto error;
        }

        RTCharacterDebugDeleteHonorMedalCategory(Runtime, Character, Data->GroupIndex + 1);

        Response->Result = 0;
    }

    Response->ForceGemCount = Character->Data.AccountInfo.ForceGem;
    Response->Unknown1 = 0;
    SocketSend(Socket, Connection, Response);
    return;

error:
    SocketDisconnect(Socket, Connection);
}
