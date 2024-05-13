![Head Tracking](https://github.com/Mohammad-Elahi/Meta-Quest-Head-Tracking-App/assets/93424032/22a50174-a7da-4197-bb39-1e271f70f2bf)
# Meta-Quest-Head-Tracking-App
Meta Quest Head Tracking App

## Setup
1. Connect your Quest headset to a Windows PC with a USB-C cable and set up Meta Quest Link. You can find the setup instructions [here](https://www.meta.com/en-gb/help/quest/articles/headsets-and-accessories/oculus-link/set-up-link/)
2. Download the Oculus SDK for Windows from [here](https://developer.oculus.com/downloads/package/oculus-sdk-for-windows/)
3. Create a project folder and name it "MetaApp".  
4. Copy the LibOVR library from the Oculus SDK folder to the MetaApp folder.

## Project Files
1. Create a Text Document and name it "CMakeLists.txt".
2. Create a C++ source file and name it "main.cpp".
3. Create a new folder in the MetaApp folder and name it "build".

   
## CMakeLists.txt
Write the following code in CMakeLists.txt. Make sure to set your LibOVR path correctly:
```
cmake_minimum_required(VERSION 3.10)
project(MetaApp)

set(CMAKE_CXX_STANDARD 14)
            
#Specify the path to your LibOVR installation
set(LIBOVR_PATH C:/Users/your_LibOVR_folder_path)

include_directories(${LIBOVR_PATH}/Include)
link_directories(${LIBOVR_PATH}/Lib/Windows/x64/Release/VS2017)

add_executable(MetaApp main.cpp)
target_link_libraries(MetaApp LibOVR)
```

# main.cpp
Write the following code in main.cpp:

```
    #include <OVR_CAPI.h>
    #include <iostream>
    
        int main() {
           std::cout << "Starting program...\n";

       if (ovr_Initialize(nullptr) == ovrSuccess) {
        std::cout << "LibOVR initialized successfully.\n";

        ovrSession session;
        ovrGraphicsLuid luid;
        ovrResult result = ovr_Create(&session, &luid);

        if (result == ovrSuccess) {
            std::cout << "Session created successfully.\n";

            while (true) {
                ovrTrackingState ts = ovr_GetTrackingState(session, ovr_GetTimeInSeconds(), true);
                if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
                    ovrPosef pose = ts.HeadPose.ThePose;
                    std::cout << "Position: (" << pose.Position.x << ", " << pose.Position.y << ", " << pose.Position.z << ")\n";
                    std::cout << "Orientation: (" << pose.Orientation.x << ", " << pose.Orientation.y << ", " << pose.Orientation.z << ", " << pose.Orientation.w << ")\n";
                }
            }
            ovr_Destroy(session);
        } else {
            std::cout << "Failed to create session. Error: " << result << "\n";
        }
        ovr_Shutdown();
    } else {
        std::cout << "Failed to initialize LibOVR.\n";
    }
    return 0;
}
```
# Build
1. Download and install CMake from [here](https://cmake.org/download/)
2. Open CMake and click “Browse Source”, then choose the MetaApp folder.
3. Click “Browse Build” and choose the “build” folder in the MetaApp folder.
4. Click on “Generate”.
5. Open the Command Prompt (CMD) on your windows and navigate to the “build” folder with this command:
```
cd C:\Users\your_build_folder_path
```
6. Compile the project:
```
cmake --build .
```
7. After the build process is complete, you should see your “Debug” folder in the build directory which includes MetaApp.exe.
8. You can run the application directly from the command line:
```
cd Debug
```
```
.\MetaApp.exe
```
Note: Instead of steps 1 to 4, you can open CMD, navigate to your “build” directory, and write:
```
cd C:\Users\your_build_folder_path
```
```
cmake ..
```

Please replace `your_LibOVR_folder_path` and `your_build_folder_path` with the actual paths on your system.
