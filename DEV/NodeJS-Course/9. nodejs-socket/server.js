const express = require("express");
const http = require("http");
const socketIo = require("socket.io");

const app = express();

const server = http.createServer(app);

//initiate socket.io and attch this to the http server
const io = socketIo(server);

app.use(express.static("public"));

const users = new Set();

io.on("connection", (socket) => {
  console.log("A user is now connected");

  //handle users when they will join the chat
  socket.on("join", (userName) => {
    users.add(userName);
    socket.userName = userName;

    //broadcast to all clients/users that a new user has joined
    io.emit("userJoined", userName);

    //Send the updated user list to all clients
    io.emit("userList", Array.from(users));
  });

  //handle incoming chat message
  socket.on("chatMessage", (message) => {
    //broadcast the received message to all connected clients
    io.emit("chatMessage", message);
  });

  //handle user disconnection
  socket.on("disconnect", () => {
    console.log("An User is disconnected", socket.userName);

    users.forEach((user) => {
      if (user === socket.userName) {
        users.delete(user);

        io.emit("userLeft", user);

        io.emit("userList", Array.from(users));
      }
    });
  });
});

const PORT = 3000;
server.listen(PORT, () => {
  console.log(`Server is now running on http://localhost:${PORT}`);
});
