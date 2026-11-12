const { DataTypes } = require("sequelize");
const sequelize = require("../connection");

// timestamps: false -> o Sequelize não lê nem grava createdAt/updatedAt
// field mapeia o atributo camelCase para a coluna snake_case
const Autor = sequelize.define(
    "Autor",
    {
        nome: { type: DataTypes.STRING(100), allowNull: false },
        nacionalidade: { type: DataTypes.STRING(50) },
        anoNascimento: { type: DataTypes.INTEGER, field: "ano_nascimento" },
    },
    { timestamps: false, tableName: "autores" },
);

Autor.associate = (models) => {
    Autor.hasMany(models.Livro, { foreignKey: "autorId", as: "livros" });
};

module.exports = Autor;
