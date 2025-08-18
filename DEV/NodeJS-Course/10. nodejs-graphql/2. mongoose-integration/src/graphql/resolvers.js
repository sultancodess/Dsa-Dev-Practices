const Product = require("../models/Product");

const resolvers = {
  Query: {
    products: async () => await Product.find({}),
    product: async (_, { id }) => await Product.findById(id),
  },

  Mutation: {
    createProduct: async (_, args) => {
      const newlyCreatedProduct = new Product(args);

      return await newlyCreatedProduct.save();
    },

    updateProduct: async (_, { id, ...updatedFields }) => {
      return await Product.findByIdAndUpdate(id, updatedFields, { new: true });
    },

    deleteProduct: async (_, { id }) => {
      const deletedProduct = await Product.findByIdAndDelete(id);

      return !!deletedProduct;
    },
  },
};

module.exports = resolvers;
