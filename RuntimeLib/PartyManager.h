#pragma once

#include "Base.h"
#include "Party.h"

EXTERN_C_BEGIN

struct _RTPartyManager {
    AllocatorRef Allocator;
    MemoryPoolRef PartyPool;
    MemoryPoolRef PartyInvitationPool;
    MemoryPoolRef SoloPartyPool;
    DictionaryRef CharacterToPartyEntity;
    DictionaryRef CharacterToPartyInvite;
};

RTPartyManagerRef RTPartyManagerCreate(
    AllocatorRef Allocator,
    Index MaxPartyCount
);

Void RTPartyManagerDestroy(
    RTPartyManagerRef PartyManager
);

RTPartyRef RTPartyManagerCreateParty(
    RTPartyManagerRef PartyManager,
    Index CharacterIndex,
    RTEntityID CharacterID,
    Int32 PartyType
);

RTPartyRef RTPartyManagerCreatePartyRemote(
    RTPartyManagerRef PartyManager,
    RTPartyRef RemoteParty
);

Void RTPartyManagerDestroyParty(
    RTPartyManagerRef PartyManager,
    RTPartyRef Party
);

Void RTPartyManagerDestroyPartyRemote(
    RTPartyManagerRef PartyManager,
    RTPartyRef RemoteParty
);

RTPartyRef RTPartyManagerGetPartyByCharacter(
    RTPartyManagerRef PartyManager,
    Index CharacterIndex
);

RTPartyRef RTPartyManagerGetParty(
    RTPartyManagerRef PartyManager,
    RTEntityID PartyID
);

Bool RTPartyManagerRemoveMember(
    RTPartyManagerRef PartyManager,
    Index CharacterIndex
);

EXTERN_C_END
