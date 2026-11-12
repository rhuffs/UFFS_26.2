const { DataTypes } = require("sequelize");
const sequelize = require("../connection");

const Emprestimo = sequelize.define(
    "Emprestimo",
    {
        leitorId: {
            type: DataTypes.INTEGER,
            allowNull: false,
            field: "leitor_id",
        },
        livroId: {
            type: DataTypes.INTEGER,
            allowNull: false,
            field: "livro_id",
        },
        dataEmprestimo: {
            type: DataTypes.DATEONLY,
            allowNull: false,
            defaultValue: DataTypes.NOW,
            field: "data_emprestimo",
        },
        dataPrevista: {
            type: DataTypes.DATEONLY,
            allowNull: false,
            field: "data_prevista",
        },
        dataDevolucao: { type: DataTypes.DATEONLY, field: "data_devolucao" },
    },
    { timestamps: false, tableName: "emprestimos" },
);

Emprestimo.associate = (models) => {
    Emprestimo.belongsTo(models.Leitor, { foreignKey: "leitorId", as: "leitor" });
    Emprestimo.belongsTo(models.Livro, { foreignKey: "livroId", as: "livro" });
};

module.exports = Emprestimo;
