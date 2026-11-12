const { Sequelize } = require("sequelize");

// new Sequelize(banco, usuario, senha, opcoes)
const sequelize = new Sequelize("postgres", "postgres", "postgres", {
    host: "localhost",
    port: 5432,
    dialect: "postgres",
    logging: false, // troque para console.log para ver o SQL gerado pelo ORM
});

module.exports = sequelize;
