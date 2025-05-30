cmake_minimum_required(VERSION 3.17.5)

project(breaklee VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG=1")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/CMake)

option(CONFIG_BUILD_TARGET_AUCTION_SVR "Build Auction Server" ON)
option(CONFIG_BUILD_TARGET_BREAKLEE "Build Breaklee" ON)
option(CONFIG_BUILD_TARGET_CHAT_SVR "Build Chat Server" ON)
option(CONFIG_BUILD_TARGET_LOGIN_SVR "Build Login Server" ON)
option(CONFIG_BUILD_TARGET_MASTER_DBAGENT "Build Master DB Agent" ON)
option(CONFIG_BUILD_TARGET_MASTER_SVR "Build Master Server" ON)
option(CONFIG_BUILD_TARGET_PARTY_SVR "Build Party Server" ON)
option(CONFIG_BUILD_TARGET_WORLD_SVR "Build World Server" ON)
option(CONFIG_BUILD_TARGET_CLIENT "Build Client" ON)
option(CONFIG_BUILD_TARGET_EDITOR "Build Editor" ON)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

if (MSVC)
    add_compile_options(/ZI)
endif()

find_package(libuv REQUIRED)
find_package(lua REQUIRED)
find_package(ODBC REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(ZLIB REQUIRED)

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)

file(COPY ${PROJECT_SOURCE_DIR}/ServerData/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/Data/)
file(COPY ${PROJECT_SOURCE_DIR}/Scripts/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/Scripts/)
file(COPY ${PROJECT_SOURCE_DIR}/Shaders/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/Shaders/)

set(CORE_LIB_DIR ${PROJECT_SOURCE_DIR}/CoreLib)
set(CRYPTO_LIB_DIR ${PROJECT_SOURCE_DIR}/CryptoLib)
set(NET_LIB_DIR ${PROJECT_SOURCE_DIR}/NetLib)
set(RUNTIME_DATA_LIB_DIR ${PROJECT_SOURCE_DIR}/RuntimeDataLib)
set(RUNTIME_LIB_DIR ${PROJECT_SOURCE_DIR}/RuntimeLib)

file(GLOB CORE_LIB_HEADERS ${CORE_LIB_DIR}/*.h)
file(GLOB CORE_LIB_SOURCES ${CORE_LIB_DIR}/*.c)

file(GLOB CRYPTO_LIB_HEADERS ${CRYPTO_LIB_DIR}/*.h)
file(GLOB CRYPTO_LIB_SOURCES ${CRYPTO_LIB_DIR}/*.c)

file(GLOB NET_LIB_HEADERS ${NET_LIB_DIR}/*.h)
file(GLOB NET_LIB_SOURCES ${NET_LIB_DIR}/*.c)

file(GLOB RUNTIME_DATA_LIB_HEADERS ${RUNTIME_DATA_LIB_DIR}/*.h)
file(GLOB RUNTIME_DATA_LIB_SOURCES ${RUNTIME_DATA_LIB_DIR}/*.c)

file(GLOB RUNTIME_LIB_HEADERS ${RUNTIME_LIB_DIR}/*.h)
file(GLOB RUNTIME_LIB_SOURCES ${RUNTIME_LIB_DIR}/*.c)

set(SHARED_HEADERS_DIR ${PROJECT_SOURCE_DIR}/Shared)
file(GLOB SHARED_HEADERS ${SHARED_HEADERS_DIR}/*.h)

add_library(CoreLib STATIC ${CORE_LIB_HEADERS} ${CORE_LIB_SOURCES})
target_link_libraries(CoreLib PRIVATE ${ZLIB_LIBRARIES} ${libuv_LIBRARIES} ${ODBC_LIBRARIES})
target_include_directories(CoreLib PUBLIC ${PROJECT_SOURCE_DIR} ${ZLIB_INCLUDE_DIR} ${libuv_INCLUDE_DIR} ${ODBC_INCLUDE_DIRS})

add_library(CryptoLib STATIC ${CRYPTO_LIB_HEADERS} ${CRYPTO_LIB_SOURCES})
target_link_libraries(CryptoLib PRIVATE CoreLib openssl::openssl)
target_include_directories(CryptoLib PUBLIC ${PROJECT_SOURCE_DIR} ${OpenSSL_INCLUDE_DIR})

add_library(NetLib STATIC ${NET_LIB_HEADERS} ${NET_LIB_SOURCES})
target_link_libraries(NetLib PRIVATE CryptoLib CoreLib lua::lua)
target_include_directories(NetLib PUBLIC ${PROJECT_SOURCE_DIR} ${lua_INCLUDE_DIR})

add_library(RuntimeDataLib STATIC ${RUNTIME_DATA_LIB_HEADERS} ${RUNTIME_DATA_LIB_SOURCES})
target_link_libraries(RuntimeDataLib PRIVATE CoreLib)
target_include_directories(RuntimeDataLib PUBLIC ${PROJECT_SOURCE_DIR})

add_library(RuntimeLib STATIC ${RUNTIME_LIB_HEADERS} ${RUNTIME_LIB_SOURCES})
target_link_libraries(RuntimeLib PRIVATE CoreLib RuntimeDataLib lua::lua)
target_include_directories(RuntimeLib PUBLIC ${PROJECT_SOURCE_DIR} ${lua_INCLUDE_DIR})

if(CONFIG_BUILD_TARGET_AUCTION_SVR)
    set(AUCTION_SVR_DIR ${PROJECT_SOURCE_DIR}/AuctionSvr)
    
    file(GLOB AUCTION_SVR_HEADERS ${AUCTION_SVR_DIR}/*.h)
    file(GLOB AUCTION_SVR_SOURCES ${AUCTION_SVR_DIR}/*.c)

    add_executable(AuctionSvr ${AUCTION_SVR_HEADERS} ${AUCTION_SVR_SOURCES} ${SHARED_HEADERS})
    target_include_directories(AuctionSvr PUBLIC ${PROJECT_SOURCE_DIR} ${SHARED_HEADERS_DIR})
    target_link_libraries(AuctionSvr PRIVATE NetLib CoreLib CryptoLib)
    
    if(WIN32)
        target_link_libraries(AuctionSvr PRIVATE ${AUCTION_SVR_DIR}/main.res)
    endif()
endif()

if(CONFIG_BUILD_TARGET_BREAKLEE)
    set(BREAKLEE_DIR ${PROJECT_SOURCE_DIR}/Breaklee)

    file(GLOB BREAKLEE_HEADERS ${BREAKLEE_DIR}/*.h)
    file(GLOB BREAKLEE_SOURCES ${BREAKLEE_DIR}/*.c)
    
    add_executable(breaklee ${BREAKLEE_HEADERS} ${BREAKLEE_SOURCES} ${SHARED_HEADERS})
    target_include_directories(breaklee PUBLIC ${PROJECT_SOURCE_DIR} ${SHARED_HEADERS_DIR})
    target_link_libraries(breaklee PRIVATE NetLib CoreLib CryptoLib)
endif()

if(CONFIG_BUILD_TARGET_CHAT_SVR)
    set(CHAT_SVR_DIR ${PROJECT_SOURCE_DIR}/ChatSvr)
    
    file(GLOB CHAT_SVR_HEADERS ${CHAT_SVR_DIR}/*.h)
    file(GLOB CHAT_SVR_SOURCES ${CHAT_SVR_DIR}/*.c)

    add_executable(ChatSvr ${CHAT_SVR_HEADERS} ${CHAT_SVR_SOURCES} ${SHARED_HEADERS})
    target_include_directories(ChatSvr PUBLIC ${PROJECT_SOURCE_DIR} ${SHARED_HEADERS_DIR})
    target_link_libraries(ChatSvr PRIVATE NetLib CoreLib CryptoLib)
    
    if(WIN32)
        target_link_libraries(ChatSvr PRIVATE ${CHAT_SVR_DIR}/main.res)
    endif()
endif()

if(CONFIG_BUILD_TARGET_LOGIN_SVR)
    set(LOGIN_SVR_DIR ${PROJECT_SOURCE_DIR}/LoginSvr)
    
    file(GLOB LOGIN_SVR_HEADERS ${LOGIN_SVR_DIR}/*.h)
    file(GLOB LOGIN_SVR_SOURCES ${LOGIN_SVR_DIR}/*.c)

    add_executable(LoginSvr ${LOGIN_SVR_HEADERS} ${LOGIN_SVR_SOURCES} ${SHARED_HEADERS})
    target_include_directories(LoginSvr PUBLIC ${PROJECT_SOURCE_DIR} ${OPENSSL_INCLUDE_DIR} ${SHARED_HEADERS_DIR})
    target_link_libraries(LoginSvr PRIVATE NetLib CoreLib CryptoLib)

    if(WIN32)
        target_link_libraries(LoginSvr PRIVATE ${LOGIN_SVR_DIR}/main.res)
    endif()
endif()

if(CONFIG_BUILD_TARGET_MASTER_DBAGENT)
    set(MASTER_DBAGENT_DIR ${PROJECT_SOURCE_DIR}/MasterDBAgent)
    
    file(GLOB MASTER_DBAGENT_HEADERS ${MASTER_DBAGENT_DIR}/*.h)
    file(GLOB MASTER_DBAGENT_SOURCES ${MASTER_DBAGENT_DIR}/*.c)

    add_executable(MasterDBAgent ${MASTER_DBAGENT_HEADERS} ${MASTER_DBAGENT_SOURCES} ${SHARED_HEADERS})
    target_include_directories(MasterDBAgent PUBLIC ${PROJECT_SOURCE_DIR} ${SHARED_HEADERS_DIR})
    target_link_libraries(MasterDBAgent PRIVATE NetLib CoreLib CryptoLib RuntimeLib RuntimeDataLib)
    
    if(WIN32)
        target_link_libraries(MasterDBAgent PRIVATE ${MASTER_DBAGENT_DIR}/main.res)
    endif()
endif()

if(CONFIG_BUILD_TARGET_MASTER_SVR)
    set(MASTER_SVR_DIR ${PROJECT_SOURCE_DIR}/MasterSvr)
    
    file(GLOB MASTER_SVR_HEADERS ${MASTER_SVR_DIR}/*.h)
    file(GLOB MASTER_SVR_SOURCES ${MASTER_SVR_DIR}/*.c)

    add_executable(MasterSvr ${MASTER_SVR_HEADERS} ${MASTER_SVR_SOURCES} ${SHARED_HEADERS})
    target_include_directories(MasterSvr PUBLIC ${PROJECT_SOURCE_DIR} ${SHARED_HEADERS_DIR})
    target_link_libraries(MasterSvr PRIVATE NetLib CoreLib CryptoLib RuntimeLib RuntimeDataLib)
    
    if(WIN32)
        target_link_libraries(MasterSvr PRIVATE ${MASTER_SVR_DIR}/main.res)
    endif()
endif()

if(CONFIG_BUILD_TARGET_PARTY_SVR)
    set(PARTY_SVR_DIR ${PROJECT_SOURCE_DIR}/PartySvr)
    
    file(GLOB PARTY_SVR_HEADERS ${PARTY_SVR_DIR}/*.h)
    file(GLOB PARTY_SVR_SOURCES ${PARTY_SVR_DIR}/*.c)

    add_executable(PartySvr ${PARTY_SVR_HEADERS} ${PARTY_SVR_SOURCES} ${SHARED_HEADERS})
    target_include_directories(PartySvr PUBLIC ${PROJECT_SOURCE_DIR} ${SHARED_HEADERS_DIR})
    target_link_libraries(PartySvr PRIVATE NetLib CoreLib CryptoLib RuntimeLib RuntimeDataLib)
    
    if(WIN32)
        target_link_libraries(PartySvr PRIVATE ${PARTY_SVR_DIR}/main.res)
    endif()
endif()

if(CONFIG_BUILD_TARGET_WORLD_SVR)
    set(WORLD_SVR_DIR ${PROJECT_SOURCE_DIR}/WorldSvr)
    
    file(GLOB WORLD_SVR_HEADERS ${WORLD_SVR_DIR}/*.h)
    file(GLOB WORLD_SVR_SOURCES ${WORLD_SVR_DIR}/*.c)
        
    add_executable(WorldSvr ${WORLD_SVR_HEADERS} ${WORLD_SVR_SOURCES} ${SHARED_HEADERS})
    target_include_directories(WorldSvr PUBLIC ${PROJECT_SOURCE_DIR} ${SHARED_HEADERS_DIR})
    target_link_libraries(WorldSvr PRIVATE NetLib CoreLib CryptoLib RuntimeLib RuntimeDataLib)

    if(WIN32)
        target_link_libraries(WorldSvr PRIVATE ${WORLD_SVR_DIR}/main.res)
    endif()
endif()

if(CONFIG_BUILD_TARGET_EDITOR)
    find_package(libsquish REQUIRED)

    set(TEXTURE_LIB_DIR ${PROJECT_SOURCE_DIR}/TextureLib)
    
    file(GLOB TEXTURE_LIB_HEADERS ${TEXTURE_LIB_DIR}/*.h)
    file(GLOB TEXTURE_LIB_SOURCES ${TEXTURE_LIB_DIR}/*.c ${TEXTURE_LIB_DIR}/*.cpp)
    
    add_library(TextureLib STATIC ${TEXTURE_LIB_HEADERS} ${TEXTURE_LIB_SOURCES})
    target_link_libraries(TextureLib PRIVATE CoreLib libsquish::libsquish)
    target_include_directories(TextureLib PUBLIC ${PROJECT_SOURCE_DIR} libsquish::libsquish)
endif()

if(CONFIG_BUILD_TARGET_CLIENT)
    find_package(DirectX REQUIRED)
    find_package(raylib REQUIRED)

    set(UI_LIB_DIR ${PROJECT_SOURCE_DIR}/UILib)

    file(GLOB UI_LIB_HEADERS ${UI_LIB_DIR}/*.h)
    file(GLOB UI_LIB_SOURCES ${UI_LIB_DIR}/*.c)
    
    add_library(UILib STATIC ${UI_LIB_HEADERS} ${UI_LIB_SOURCES})
    set_target_properties(UILib PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(UILib PRIVATE CoreLib RuntimeDataLib RuntimeLib ${LUA_LIBRARIES} ${DirectX_LIBRARIES} ${raylib_LIBRARIES})
    target_include_directories(UILib PUBLIC ${PROJECT_SOURCE_DIR} ${lua_INCLUDE_DIR} ${DirectX_INCLUDE_DIRS} ${raylib_INCLUDE_DIR})
    
    set(CLIENT_DIR ${PROJECT_SOURCE_DIR}/Client)
    
    file(GLOB CLIENT_HEADERS ${CLIENT_DIR}/*.h)
    file(GLOB CLIENT_SOURCES ${CLIENT_DIR}/*.c ${CLIENT_DIR}/*.cpp)

	add_executable(Client ${CLIENT_HEADERS} ${CLIENT_SOURCES})
    set_target_properties(Client PROPERTIES LINKER_LANGUAGE CXX)
	set_target_properties(Client PROPERTIES WIN32_EXECUTABLE TRUE)
	target_link_libraries(Client CoreLib CryptoLib NetLib RuntimeDataLib RuntimeLib UILib ${DirectX_LIBRARIES})
	target_include_directories(Client PUBLIC ${PROJECT_SOURCE_DIR} ${DirectX_INCLUDE_DIRS})
endif()

if(CONFIG_BUILD_TARGET_EDITOR)
    find_package(raylib REQUIRED)
    
    set(EDITOR_DIR ${PROJECT_SOURCE_DIR}/Editor)
    
    file(GLOB EDITOR_HEADERS ${EDITOR_DIR}/*.h)
    file(GLOB EDITOR_SOURCES ${EDITOR_DIR}/*.c ${EDITOR_DIR}/*.cpp)

	add_executable(Editor ${EDITOR_HEADERS} ${EDITOR_SOURCES} ${SHARED_HEADERS})
    #set_target_properties(Editor PROPERTIES LINKER_LANGUAGE CXX)
	#set_target_properties(Editor PROPERTIES WIN32_EXECUTABLE TRUE)
	target_link_libraries(Editor CoreLib RuntimeDataLib RuntimeLib TextureLib ${raylib_LIBRARIES})
	target_include_directories(Editor PUBLIC ${PROJECT_SOURCE_DIR} ${SHARED_HEADERS_DIR} ${raylib_INCLUDE_DIR})
endif()

if(NOT WIN32)
    target_link_libraries(CoreLib PRIVATE m dl)
    target_link_libraries(NetLib PRIVATE m)
    target_link_libraries(RuntimeDataLib PRIVATE m)
    target_link_libraries(RuntimeLib PRIVATE m)

    if(CONFIG_BUILD_TARGET_LOGIN_SVR)
        target_link_libraries(LoginSvr PRIVATE m)
    endif()
endif()
