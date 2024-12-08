<h1 align = "center";>Typing-Test-Game</h1>

A basic Typing Test Game on the **CLI(Command-Line-Interface)**.Made with ** Python** and ** C**

---

##  Features

The Game provides multiple rounds with increasing difficulty.Players can connect to a central server to update their stats, retrieve a leaderboard.


- **Client-Server Architecture**: 
  - The server is implemented in Python to manage player stats and the leaderboard.
  - The client is implemented in C, allowing players to connect to the server and perform various actions.
- **Socket Communication**:
  - Uses ~~TCP/IP~~ for data transmission between the client and server.

---

##  How It Works
1. ** Server**:
   - Listens for incoming client connections on a specified port.
   - Processes commands from clients such as updating scores or fetching the leaderboard.
   - (other details to be added.)

2. ** Client**:
   - Uses an external API to fetch a dataset of sentences.
   - Conducts the Typing Test.
   - Connects to the server over a defined IP address and port.
   - Sends commands to update player stats or retrieve the leaderboard.
   - (other details to be added.)

---

##  Disclaimer

#### The game is in developement stage,so bugs are expected.

