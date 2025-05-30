#ifndef CONFIG_BEGIN
#define CONFIG_BEGIN(__NAMESPACE__)
#endif

#ifndef CONFIG_PARAMETER
#define CONFIG_PARAMETER(__TYPE__, __NAME__, __PATH__, __DEFAULT__)
#endif

#ifndef CONFIG_PARAMETER_ARRAY
#define CONFIG_PARAMETER_ARRAY(__TYPE__, __LENGTH__, __NAME__, __PATH__, __DEFAULT__)
#endif

#ifndef CONFIG_END
#define CONFIG_END(__NAMESPACE__)
#endif

CONFIG_BEGIN(MasterSvr)
CONFIG_PARAMETER(UInt8, GroupIndex, "MasterSvr.GroupIndex", 21)
CONFIG_PARAMETER(UInt16, Port, "MasterSvr.Port", 38161)
CONFIG_PARAMETER(UInt32, MaxRouteCount, "MasterSvr.MaxRouteCount", 32)
CONFIG_PARAMETER(UInt32, MaxWorldCount, "MasterSvr.MaxWorldCount", 32)
CONFIG_PARAMETER(Timestamp, LocalTimeOffset, "MasterSvr.LocalTimeOffset", 3600)
CONFIG_PARAMETER(Int32, LogLevel, "MasterSvr.LogLevel", 5)
CONFIG_END(MasterSvr)

CONFIG_BEGIN(NetLib)
CONFIG_PARAMETER(Int32, ReadBufferSize, "NetLib.ReadBufferSize", 0x20000)
CONFIG_PARAMETER(Int32, WriteBufferSize, "NetLib.WriteBufferSize", 0x20000)
CONFIG_PARAMETER(Int32, PacketBufferBacklogSize, "NetLib.PacketBufferBacklogSize", 8)
CONFIG_PARAMETER(Bool, LogPackets, "NetLib.LogPackets", 0)
CONFIG_END(NetLib)

#undef CONFIG_BEGIN
#undef CONFIG_PARAMETER
#undef CONFIG_PARAMETER_ARRAY
#undef CONFIG_END
