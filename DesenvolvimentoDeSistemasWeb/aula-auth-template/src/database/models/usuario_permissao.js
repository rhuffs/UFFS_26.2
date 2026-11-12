"use strict";

module.exports = (sequelize, DataTypes) => {
	const UsuarioPermissao = sequelize.define(
		"UsuarioPermissao",
		{
			email: {
				type: DataTypes.STRING,
				primaryKey: true,
				references: {
					model: "usuario",
					key: "email",
				},
			},
			id_permissao: {
				type: DataTypes.BIGINT,
				primaryKey: true,
				references: {
					model: "permissoes",
					key: "id",
				},
			},
		},
		{
			sequelize,
			tableName: "usuario_permissao",
			schema: "public",
			freezeTableName: true,
			timestamps: false,
		},
	);

	UsuarioPermissao.associate = function (models) {
		UsuarioPermissao.belongsTo(models.Usuario, {
			foreignKey: "email",
			targetKey: "email",
		});
		UsuarioPermissao.belongsTo(models.Permissao, {
			foreignKey: "id_permissao",
			targetKey: "id",
			as: "Permissao",
		});
	};

	return UsuarioPermissao;
};
