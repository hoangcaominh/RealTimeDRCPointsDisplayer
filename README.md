## Note
If you find any bugs, create a new issue on Github or DM me in Discord.

## Live DRC Points Calculator
(formerly known as RealTimeDRCPointsDisplayer)
An user interface application that displays in-game information and calculates DRC points for you during your run or your replay.

## What's new
#### 1.5
- Add options for displaying information (see "Game Information" for more detail).

#### 1.4
- Update WBaWC header to work with version 1.00b.

#### 1.3
- Update MoF formula as of June 1st, 2019 and update find game function.

#### 1.2.2
- Add WBaWC Demo and update Settings window.

#### 1.2
- Add warning and MoF scoring formula.

#### 1.1
- Add Settings button.

#### 1.0
- Finish console version, move to GUI version.

## Requirements
- OS: Windows 7/8/Vista/10
- Visual C++ Redistributable for Visual Studio 2015

## Installation and Recommendation
- Extract the zip file into your desired folder and run the execution. Optionally you can create a shortcut to the execution on the desktop.
- Hit the "Find Game" button. Once it finds a game the window will be expanded with a black box on the right showing the game information.
- It is required to have Internet connection to download/update files when booting the application.
- During a DRC event, you should have the latest version of DRC Points Calculator as it contains the updated calculating formula from [Maribel Hearn](https://github.com/MaribelHearn/) and some fixed sections.

## Game Information
- "Difficulty": The difficulty yor are playing
- "Shottype": The character/team with specific type you are using
- "Misses": The number of times you lose a life
- "Bombs": The number of times you use a bomb

### Extra Box (under the Misses/Bombs box)
A group of one or more boxes for displaying certain information of specific games.

##### Perfect Cherry Blosson/PCB/Touhou 7
- "Border Breaks": The number of times you have broken a cherry border

##### Imperishable Night/IN/Touhou 8
- Box 1: The number of last spells you have captured. Depends on the difficulty/final stage there will be different maximum number of last spells.
- Box 2: The final stage you have entered, either 6A or 6B. This will be hidden if you are playing on Extra difficulty.

##### Undefined Fantastic Object/UFO/Touhou 12
- Box 1: The number of Red Ufos you have summoned
- Box 2: The number of Green Ufos you have summoned
- Box 3: The number of Blue Ufos you have summoned
- Box 4: The number of Rainbow Ufos you have summoned

##### Ten Desires/TD/Touhou 13
- "Trances": The number of times you have used a Trance

##### Hidden Star in Four Seasons/HSiFS/Touhou 16
- "Releases": The number of times you have used a Release

##### Wily Beast and Weakest Creature/WBaWC/Touhou 17
- Box 1: The number of Wolf Mode you have triggered
- Box 2: The number of Otter Mode you have triggered
- Box 3: The number of Eagle Mode you have triggered
- Box 4: The number of times you have performed a Roar Break

### Optional Boxes (under the Extra Box)
Two individual boxes for displaying one of the following: score, world record, survival points, scoring points. You can change the output type of these boxes in "Optinal Display" in Settings.

## Settings
Settings for adjusting output values (misses, bombs, data displayed in Extra Box), mainly for calculating DRC points.

## Inspiration
- [Dodging Rain Competition](https://maribelhearn.github.io/drc)
- [RealTimePPDisplayer](https://github.com/OsuSync/RealTimePPDisplayer)
- The entire Touhou community
