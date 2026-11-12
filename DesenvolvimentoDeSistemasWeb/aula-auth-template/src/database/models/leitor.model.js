const { DataTypes } = require("sequelize");
const sequelize = require("../connection");

const Leitor = sequelize.define(
    "Leitor",
    {
        id: { type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true },
        nome: { type: DataTypes.STRING(100), allowNull: false, field: "nome" },
        email: { type: DataTypes.STRING(255), allowNull: false, unique: true, field: "email" },
        telefone: { type: DataTypes.STRING(20), field: "telefone" },
        ativo: {
            type: DataTypes.BOOLEAN,
            allowNull: false,
            defaultValue: true,
            field: "ativo",
        },
    },
    { timestamps: false, tableName: "leitores" }
);


module.exports = Leitor;
