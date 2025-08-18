const products = require("../data/products");

const resolvers = {
  Query: {
    products: () => products,
    product: (_, { id }) => products.find((item) => item.id === id),
  },

  Mutation: {
    createProduct: (_, { title, category, price, inStock }) => {
      const newlyCreatedProduct = {
        id: String(products.length + 1),
        title,
        category,
        price,
        inStock,
      };

      products.push(newlyCreatedProduct);
      return newlyCreatedProduct;
    },

    deleteProduct: (_, { id }) => {
      const index = products.findIndex((product) => product.id === id);
      if (index === -1) return false;

      products.splice(index, 1);

      return true;
    },

    updateProduct: (_, { id, ...updates }) => {
      const index = products.findIndex((product) => product.id === id);
      if (index === -1) return null;

      const updatedProduct = {
        ...products[index],
        ...updates,
      };

      products[index] = updatedProduct;

      return updatedProduct;
    },
  },
};

module.exports = resolvers;
