const mongoose = require("mongoose");

const connectDB = async () => {
  try {
    await mongoose.connect(process.env.MONGO_URI);
    console.log("Mongodb connected successfully");
  } catch (e) {
    console.error("Mongo connection failed!", e);
    process.exit(1);
  }
};

module.exports = connectDB;
