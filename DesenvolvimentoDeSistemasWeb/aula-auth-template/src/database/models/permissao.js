"use strict";

module.exports = (sequelize, DataTypes) => {
	const Permissao = sequelize.define(
		"Permissao",
		{
			id: {
				type: DataTypes.BIGINT,
				primaryKey: true,
			},
			descricao: {
				type: DataTypes.STRING,
				allowNull: false,
			},
		},
		{
			sequelize,
			tableName: "permissao",
			schema: "public",
			freezeTableName: true,
			timestamps: false,
		},
	);

	Permissao.associate = function (models) {
		Permissao.belongsToMany(models.Usuario, {
			through: models.UsuarioPermissao,
			foreignKey: "id_permissao",
			otherKey: "email",
		});
	};

	return Permissao;
};
