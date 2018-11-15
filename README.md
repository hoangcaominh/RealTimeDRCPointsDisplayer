# RealTimeDRCPointsDisplayer
A console application that counts DRC points for you during your run or your replay.

# What's new
DRC Points Calculator is ready for HSiFS. Misses, bombs and releases can now be counted.

- Advantages: Misses is recorded from stage 1. This means you can open your replay midrun and it still displays the previous misses. Convenient for no-bomb runs.
- Drawbacks: The bomb counter uses a boolean to check if the player is using a bomb. The counter may not increase if X key is rapidly pressed.

# Installing and Recommendation
- You just need to download the folder to whereever you want in your PC. Creating a shortcut on the desktop is recommended.
- As this is a console window, the window itself and its texts may be small. When running the application, it is recommended to change the font and the size of the text. Right-click the title of the window and select Properties. Choose the Font tab, change the text size and font to your preference, then hit OK.

# Mechanism
- Downloading part and loading part for rubric file and world record file are operated first.
- The application auto-detect any Windows maingame. Once it founds a game, data for that game will be displayed on the console window.

# Unsolved problems
- Cherry point variables in PCB are yet to be found.

# Inspiration
- [Dodging Rain Competition](https://maribelhearn.github.io/drc)
- [RealTimePPDisplayer](https://github.com/OsuSync/RealTimePPDisplayer)
- The entire Touhou community
