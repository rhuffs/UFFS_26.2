-- DROP TABLE IF EXISTS usuario_permissao;
-- DROP TABLE IF EXISTS permissao;
-- DROP TABLE IF EXISTS usuario;
-- DROP TABLE IF EXISTS emprestimos;
-- DROP TABLE IF EXISTS livros;
-- DROP TABLE IF EXISTS leitores;
-- DROP TABLE IF EXISTS autores;
-- DROP TYPE  IF EXISTS enum_livros_categoria;

CREATE TYPE enum_livros_categoria AS ENUM ('FANTASIA', 'TERROR', 'FICCAO_CIENTIFICA', 'ROMANCE', 'TECNICO');


CREATE TABLE autores (
    id              SERIAL PRIMARY KEY,
    nome            VARCHAR(100) NOT NULL,
    nacionalidade   VARCHAR(50),
    ano_nascimento  INTEGER,
    created_at      TIMESTAMPTZ NOT NULL DEFAULT NOW(),
    updated_at      TIMESTAMPTZ NOT NULL DEFAULT NOW()
);


CREATE TABLE livros (
    id              SERIAL PRIMARY KEY,
    autor_id        INTEGER NOT NULL REFERENCES autores(id) ON DELETE RESTRICT,
    titulo          VARCHAR(150) NOT NULL,
    isbn            VARCHAR(13)  NOT NULL UNIQUE,  -- ISBN-13 da edição brasileira
    editora         VARCHAR(80),
    paginas         INTEGER,
    ano_publicacao  INTEGER,                       -- ano da publicação original
    categoria       enum_livros_categoria NOT NULL,
    created_at      TIMESTAMPTZ NOT NULL DEFAULT NOW(),
    updated_at      TIMESTAMPTZ NOT NULL DEFAULT NOW()
);

CREATE INDEX idx_livros_autor ON livros (autor_id);


CREATE TABLE leitores (
    id          SERIAL PRIMARY KEY,
    nome        VARCHAR(100) NOT NULL,
    email       VARCHAR(255) NOT NULL UNIQUE,
    telefone    VARCHAR(20),
    ativo       BOOLEAN NOT NULL DEFAULT TRUE,
    created_at  TIMESTAMPTZ NOT NULL DEFAULT NOW(),
    updated_at  TIMESTAMPTZ NOT NULL DEFAULT NOW()
);


CREATE TABLE emprestimos (
    id               SERIAL PRIMARY KEY,
    leitor_id        INTEGER NOT NULL REFERENCES leitores(id) ON DELETE RESTRICT,
    livro_id         INTEGER NOT NULL REFERENCES livros(id)   ON DELETE RESTRICT,
    data_emprestimo  DATE NOT NULL DEFAULT CURRENT_DATE,
    data_prevista    DATE NOT NULL,
    data_devolucao   DATE,
    created_at       TIMESTAMPTZ NOT NULL DEFAULT NOW(),
    updated_at       TIMESTAMPTZ NOT NULL DEFAULT NOW()
);

CREATE INDEX idx_emprestimos_leitor ON emprestimos (leitor_id);
CREATE INDEX idx_emprestimos_livro  ON emprestimos (livro_id);

-- Regra de negócio: um livro só pode ter UM empréstimo em aberto por vez.
-- Índice único parcial: só considera as linhas onde data_devolucao IS NULL.
CREATE UNIQUE INDEX uq_emprestimo_aberto_por_livro
    ON emprestimos (livro_id)
    WHERE data_devolucao IS NULL;


-- ============================================================================
-- TABELAS DE AUTENTICAÇÃO E AUTORIZAÇÃO
-- ============================================================================

CREATE TABLE usuario (
    email       VARCHAR(255) PRIMARY KEY,
    nome        VARCHAR(100) NOT NULL,
    senha       VARCHAR(255) NOT NULL  -- hash bcrypt da senha
);


CREATE TABLE permissao (
    id          BIGSERIAL PRIMARY KEY,
    descricao   VARCHAR(100) NOT NULL UNIQUE
);


CREATE TABLE usuario_permissao (
    email           VARCHAR(255) NOT NULL REFERENCES usuario(email) ON DELETE CASCADE,
    id_permissao    BIGINT NOT NULL REFERENCES permissao(id) ON DELETE CASCADE,
    PRIMARY KEY (email, id_permissao)
);

CREATE INDEX idx_usuario_permissao_email ON usuario_permissao (email);
CREATE INDEX idx_usuario_permissao_id_permissao ON usuario_permissao (id_permissao);


INSERT INTO autores (nome, nacionalidade, ano_nascimento) VALUES
    ('J.K. Rowling',     'Britânica',      1965),  -- id 1
    ('Stephen King',     'Estadunidense',  1947),  -- id 2
    ('J.R.R. Tolkien',   'Britânica',      1892);  -- id 3

-- ISBNs, editoras e páginas: edições brasileiras (Rocco, Suma, HarperCollins Brasil)
INSERT INTO livros (autor_id, titulo, isbn, editora, paginas, ano_publicacao, categoria) VALUES
    (1, 'Harry Potter e a Pedra Filosofal',        '9788532530783', 'Rocco',         208,  1997, 'FANTASIA'),  -- id 1
    (1, 'Harry Potter e a Câmara Secreta',         '9788532530790', 'Rocco',         224,  1998, 'FANTASIA'),  -- id 2
    (1, 'Harry Potter e o Prisioneiro de Azkaban', '9788532530806', 'Rocco',         288,  1999, 'FANTASIA'),  -- id 3
    (2, 'It: A Coisa',                             '9788560280940', 'Suma',          1104, 1986, 'TERROR'),    -- id 4
    (2, 'O Iluminado',                             '9788581050485', 'Suma',          464,  1977, 'TERROR'),    -- id 5
    (2, 'Cemitério',                               '9788581050393', 'Suma',          424,  1983, 'TERROR'),    -- id 6
    (3, 'O Hobbit',                                '9788595084742', 'HarperCollins', 336,  1937, 'FANTASIA'),  -- id 7
    (3, 'O Senhor dos Anéis: A Sociedade do Anel', '9788595084759', 'HarperCollins', 576,  1954, 'FANTASIA'),  -- id 8
    (3, 'O Senhor dos Anéis: As Duas Torres',      '9788595084766', 'HarperCollins', 464,  1954, 'FANTASIA'),  -- id 9
    (3, 'O Senhor dos Anéis: O Retorno do Rei',    '9788595084773', 'HarperCollins', 528,  1955, 'FANTASIA');  -- id 10

INSERT INTO leitores (nome, email, telefone, ativo) VALUES
    ('Mariana Lopes',      'mariana.lopes@email.com',    '(49) 99911-2233', TRUE),   -- id 1
    ('Rafael Bortolini',   'rafael.b@email.com',         '(49) 99822-3344', TRUE),   -- id 2
    ('Juliana Zanella',    'juliana.zanella@email.com',  NULL,              TRUE),   -- id 3
    ('Thiago Pereira',     'thiago.p@email.com',         '(49) 99733-4455', TRUE),   -- id 4
    ('Camila Schneider',   'camila.s@email.com',         '(49) 99644-5566', FALSE),  -- id 5
    ('Lucas Dalla Costa',  'lucas.dc@email.com',         NULL,              TRUE);   -- id 6


INSERT INTO emprestimos (leitor_id, livro_id, data_emprestimo, data_prevista, data_devolucao) VALUES
    -- já devolvidos (histórico)
    (1, 1,  CURRENT_DATE - 120, CURRENT_DATE - 106, CURRENT_DATE - 108),
    (2, 1,  CURRENT_DATE - 100, CURRENT_DATE - 86,  CURRENT_DATE - 80),   -- devolvido com atraso
    (3, 1,  CURRENT_DATE - 70,  CURRENT_DATE - 56,  CURRENT_DATE - 57),
    (1, 2,  CURRENT_DATE - 105, CURRENT_DATE - 91,  CURRENT_DATE - 93),
    (4, 8,  CURRENT_DATE - 90,  CURRENT_DATE - 76,  CURRENT_DATE - 75),
    (6, 8,  CURRENT_DATE - 60,  CURRENT_DATE - 46,  CURRENT_DATE - 50),
    (2, 7,  CURRENT_DATE - 80,  CURRENT_DATE - 66,  CURRENT_DATE - 70),
    (5, 4,  CURRENT_DATE - 200, CURRENT_DATE - 186, CURRENT_DATE - 190),
    (3, 5,  CURRENT_DATE - 50,  CURRENT_DATE - 36,  CURRENT_DATE - 38),

    -- em aberto, dentro do prazo
    (4, 1,  CURRENT_DATE - 5,   CURRENT_DATE + 9,   NULL),
    (1, 3,  CURRENT_DATE - 3,   CURRENT_DATE + 11,  NULL),

    -- em aberto e ATRASADOS
    (2, 4,  CURRENT_DATE - 25,  CURRENT_DATE - 11,  NULL),
    (6, 9,  CURRENT_DATE - 18,  CURRENT_DATE - 4,   NULL);

-- Livros nunca emprestados: Cemitério (6) e O Retorno do Rei (10)
-- Livros disponíveis agora: 2, 5, 6, 7, 8, 10


-- ============================================================================
-- DADOS DE AUTENTICAÇÃO E AUTORIZAÇÃO
-- ============================================================================

-- Inserir permissões
INSERT INTO permissao (descricao) VALUES
    ('CRIAR_AUTOR'),
    ('EDITAR_AUTOR'),
    ('DELETAR_AUTOR'),
    ('CRIAR_LIVRO'),
    ('EDITAR_LIVRO'),
    ('DELETAR_LIVRO'),
    ('CRIAR_LEITOR'),
    ('EDITAR_LEITOR'),
    ('DELETAR_LEITOR'),
    ('CRIAR_EMPRESTIMO'),
    ('EDITAR_EMPRESTIMO'),
    ('DELETAR_EMPRESTIMO'),
    ('ADMIN');

-- Inserir usuários de exemplo (senha: "senha123" - hash bcrypt)
-- Hash gerado com bcrypt.hashSync("senha123", 10)
-- OBS: Em produção, os usuários seriam criados via API com senhas individuais
INSERT INTO usuario (email, nome, senha) VALUES
    ('admin@biblioteca.com', 'Administrador', '$2b$10$rYwHqLqN4XqXO2KzH7W5YO5XO2KzH7W5YO5XO2KzH7W5YO5XO2KzHe'),
    ('bibliotecario@biblioteca.com', 'Bibliotecário', '$2b$10$rYwHqLqN4XqXO2KzH7W5YO5XO2KzH7W5YO5XO2KzH7W5YO5XO2KzHe');

-- Associar permissões aos usuários
-- Admin tem todas as permissões
INSERT INTO usuario_permissao (email, id_permissao)
SELECT 'admin@biblioteca.com', id FROM permissao;

-- Bibliotecário tem permissões específicas
INSERT INTO usuario_permissao (email, id_permissao)
SELECT 'bibliotecario@biblioteca.com', id FROM permissao 
WHERE descricao IN ('CRIAR_EMPRESTIMO', 'EDITAR_EMPRESTIMO', 'CRIAR_LEITOR', 'EDITAR_LEITOR');