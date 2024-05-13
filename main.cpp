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

