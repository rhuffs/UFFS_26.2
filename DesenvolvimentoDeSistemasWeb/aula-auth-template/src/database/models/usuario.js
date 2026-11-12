"use strict";

module.exports = (sequelize, DataTypes) => {
	const Usuario = sequelize.define(
		"Usuario",
		{
			email: {
				type: DataTypes.STRING,
				primaryKey: true,
			},
			nome: {
				type: DataTypes.STRING,
				allowNull: false,
			},
			senha: {
				type: DataTypes.STRING,
				allowNull: false,
			},
		},
		{
			sequelize,
			tableName: "usuario",
			schema: "public",
			freezeTableName: true,
			timestamps: false,
		},
	);

	Usuario.associate = function (models) {
		Usuario.belongsToMany(models.Permissao, {
			through: models.UsuarioPermissao,
			foreignKey: "email",
			otherKey: "id_permissao",
		});
	};

	return Usuario;
};
