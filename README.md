# [Meta Quest Head Tracker](https://github.com/Mohammad-Elahi/Meta-Quest-Head-Tracker)
<img src="https://github.com/Mohammad-Elahi/Meta-Quest-Head-Tracking-App/assets/93424032/9201989b-c155-4892-95e6-50cbdd64b1f3" alt="Head Tracking" width="400">

A newer and enhanced version is now available:

- **XR Head Tracker Pro** — [GitHub Repository](https://github.com/Mohammad-Elahi/MetaQuest_XRHeadTracker_Pro)  
- **Now on Meta Quest Store** — [Download / View on Store](https://www.meta.com/experiences/28111394221781002/)  

---

## Description
The Meta Quest Head Tracking App is a real-time head-tracking application for Meta Quest users. Developed in C++ using the [LibOVR](https://developer.oculus.com/documentation/native/pc/dg-libovr/) library, it leverages the Oculus SDK to interact with the Meta Quest headset, capturing the position and orientation of the user’s head at any given moment. 

## Preview

![MetaApp](https://github.com/Mohammad-Elahi/Meta-Quest-Head-Tracking-App/assets/93424032/6509ac2b-b1df-43fd-8240-744c490ded6a)

## License
This project utilizes the Oculus SDK and other supporting material provided by [Meta](https://www.meta.com/). The Oculus SDK and other supporting material are subject to the Oculus proprietary license.

## Setup Prerequisites
1. Ensure no other Meta software is installed.
2. Connect Quest to PC via USB-C.
3. Set up Meta Quest Link [here](https://www.meta.com/en-gb/help/quest/articles/headsets-and-accessories/oculus-link/set-up-link/).
4. Download and install [CMake](https://cmake.org/download/).

> **Note:** The `LibOVR` SDK files required to build this project are already included in this repository. You do not need to download them manually.

## Build Instructions

**1. Clone the repository:**
Open your Command Prompt (CMD) or PowerShell and run:
```sh
git clone https://github.com/Mohammad-Elahi/MetaQuest-HeadTracker-App.git
cd MetaQuest-HeadTracker-App
```

**2. Generate the build files using CMake:**
```sh
cmake -B build
```

**3. Compile the project:**
```sh
cmake --build build --config Debug
```
*(This will compile the project using MSVC. The output executable will be placed in `build\Debug\MetaApp.exe`).*

**4. Run the application:**
```sh
.\build\Debug\MetaApp.exe
```

## Author
**Mohammad Elahi**  
Research Assistant at Vodafone Chair for Mobile Communications Systems, TU Dresden  
mohammad.elahi@mailbox.tu-dresden.de

## How to Cite

If you use this software in your research, please cite it as follows:

Elahi, M. (2024). MetaQuest-HeadTracker_App: The Meta Quest Head Tracking App is a real-time head-tracking application for Meta Quest users. GitHub. https://github.com/Mohammad-Elahi/MetaQuest-HeadTracker_App

**BibTeX:**
```bibtex
@software{Elahi2024,
  author = {Elahi, Mohammad},
  title = {MetaQuest-HeadTracker_App: The Meta Quest Head Tracking App is a real-time head-tracking application for Meta Quest users},
  year = {2024},
  publisher = {GitHub},
  journal = {GitHub repository},
  url = {https://github.com/Mohammad-Elahi/MetaQuest-HeadTracker_App}
}
```
