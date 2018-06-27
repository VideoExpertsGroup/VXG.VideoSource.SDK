cmake_minimum_required(VERSION 2.8)

set(JANSSON_BUILD_DIR        lib CACHE PATH "Jansson build directory")
set(LIBWEBSOCKETS_BUILD_DIR  lib CACHE PATH "Libwebsockets build directory")

message(${JANSSON_BUILD_DIR})
message(${LIBWEBSOCKETS_BUILD_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

set (CMAKE_CXX_FLAGS "-std=c++11 -fPIC")

include_directories(${JANSSON_BUILD_DIR}/include
                    ${LIBWEBSOCKETS_BUILD_DIR}/include
)

find_library(
              jansson
              NAMES libjansson.a
              NO_DEFAULT_PATH
              HINTS "${JANSSON_BUILD_DIR}/lib"
)

find_library(
              libwebsockets
              NAMES libwebsockets.a
              NO_DEFAULT_PATH
              HINTS "${LIBWEBSOCKETS_BUILD_DIR}/lib"
)


add_library( # Specifies the name of the library.
          cloudsdk

          # Sets the library as a shared library.
          SHARED

          # Provides a relative path to your source file(s).
	    Enums/CloudReturnCodes.h

	    cloud/core/CameraManager/CameraManager.cpp
	    cloud/core/CameraManager/CameraManager.h
	    cloud/core/CameraManager/CameraManagerByeReasons.h 
	    cloud/core/CameraManager/CameraManagerCommands.h 
	    cloud/core/CameraManager/CameraManagerConfig.h 
	    cloud/core/CameraManager/CameraManagerDoneStatus.h 
	    cloud/core/CameraManager/CameraManagerParams.h 
	    cloud/core/CameraManager/ICameraManagerCallback.h 
	    cloud/core/CameraManager/StreamConfig.h 
	    cloud/core/CameraManager/StreamConfigAudio.h 
	    cloud/core/CameraManager/StreamConfigVideo.h 

	    cloud/core/CloudCommon/CloudRegToken.h 
	    cloud/core/CloudCommon/CloudToken.h 

	    cloud/core/CloudAPI.h
	    cloud/core/CloudAPIEndPoints.h 
	    cloud/core/CloudHelpers.h 
	    cloud/core/Uri.h 

	    Interfaces/ICloudStreamerCallback.h 

	    Objects/CloudShareConnection.h

	    utils/_cunk.h 
	    utils/base64.c 
	    utils/base64.h 
	    utils/Context.h 
	    utils/MLog.cpp 
	    utils/MLog.h 
	    utils/utils.cpp 
	    utils/utils.h 
	    utils/windefsws.cpp 
	    utils/windefsws.h 
	    utils/wswrap.cpp 
	    utils/wswrap.h 

	    CloudSDK.h
	    CloudStreamerSDK.cpp 
	    CloudStreamerSDK.h 
)

target_link_libraries( # Specifies the target library.
                       cloudsdk
                       ${jansson}
                       ${libwebsockets}
)