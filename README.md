# [Meta Quest Head Tracking App](https://github.com/Mohammad-Elahi/Meta-Quest-Head-Tracking-App)
![Head Tracking](https://github.com/Mohammad-Elahi/Meta-Quest-Head-Tracking-App/assets/93424032/9201989b-c155-4892-95e6-50cbdd64b1f3)

## Description
The Meta Quest Head Tracking App is a real-time head-tracking application for Meta Quest users. Developed with the [LibOVR](https://developer.oculus.com/documentation/native/pc/dg-libovr/) library, it leverages the Oculus SDK to interact with the Meta Quest headset, capturing the position and orientation of the user’s head at any given moment. 

## license
This project utilizes the Oculus SDK and other supporting material provided by [Meta](https://www.meta.com/). The Oculus SDK and other supporting material are subject to the Oculus proprietary license.

## Setup
1. Ensure no other Meta software is installed
2. Connect Quest to PC via USB-C
3. Set up Meta Quest Link [here](https://www.meta.com/en-gb/help/quest/articles/headsets-and-accessories/oculus-link/set-up-link/) 
4. Download Oculus SDK for Windows [here](https://developer.oculus.com/downloads/package/oculus-sdk-for-windows/)
5. Create project folder "MetaApp"
6. Copy LibOVR library to MetaApp folder (From Oculus SDK folder)

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

# Author
Mohammad Elahi, TU Dresden, Vodafone Chair, mohammad.elahi@mailbox.tu-dresden.de

## How to Cite

If you use this software in your research, please cite it as follows:

Elahi, M. (2024). MetaQuest-HeadTracker_App: The Meta Quest Head Tracking App is a real-time head-tracking application for Meta Quest users. GitHub. https://github.com/Mohammad-Elahi/MetaQuest-HeadTracker_App

For BibTeX:
![MetaApp](https://github.com/Mohammad-Elahi/Meta-Quest-Head-Tracking-App/assets/93424032/6509ac2b-b1df-43fd-8240-744c490ded6a)
```
@software{Elahi2024,
  author = {Elahi, Mohammad},
  title = {MetaQuest-HeadTracker_App: The Meta Quest Head Tracking App is a real-time head-tracking application for Meta Quest users},
  year = {2024},
  publisher = {GitHub},
  journal = {GitHub repository},
  url = {https://github.com/Mohammad-Elahi/MetaQuest-HeadTracker_App}
}

```

