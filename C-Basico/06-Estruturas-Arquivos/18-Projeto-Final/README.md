# Aula 18: Projeto Final - Sistema de Gerenciamento de Biblioteca

## Objetivos da Aula
- Integrar todos os conceitos aprendidos no curso
- Desenvolver um sistema completo e funcional
- Aplicar estruturas, ponteiros, arquivos e funções
- Criar uma aplicação real com interface de usuário
- Demonstrar boas práticas de programação

## Visão Geral do Projeto

### Sistema de Gerenciamento de Biblioteca
Um sistema completo para gerenciar uma biblioteca, incluindo:
- Cadastro de livros e usuários
- Empréstimos e devoluções
- Controle de estoque
- Relatórios e estatísticas
- Persistência de dados em arquivos

### Funcionalidades Principais

#### 1. Gestão de Livros
- Cadastrar novos livros
- Buscar livros por título, autor ou categoria
- Atualizar informações de livros
- Remover livros do acervo
- Listar todos os livros

#### 2. Gestão de Usuários
- Cadastrar novos usuários
- Buscar usuários por nome ou ID
- Atualizar dados de usuários
- Verificar histórico de empréstimos
- Listar todos os usuários

#### 3. Gestão de Empréstimos
- Realizar empréstimos
- Processar devoluções
- Controlar prazos de devolução
- Aplicar multas por atraso
- Histórico de transações

#### 4. Relatórios e Estatísticas
- Relatório de livros mais emprestados
- Estatísticas de usuários
- Relatório de atrasos
- Inventário do acervo
- Relatório financeiro (multas)

#### 5. Sistema de Arquivos
- Persistência de dados em arquivos binários
- Backup e restauração de dados
- Log de operações
- Configurações do sistema

## Estrutura do Projeto

### Arquivos Principais
- `biblioteca.c` - Programa principal
- `livro.h` - Definições de estruturas e funções de livros
- `usuario.h` - Definições de estruturas e funções de usuários
- `emprestimo.h` - Definições de estruturas e funções de empréstimos
- `arquivo.h` - Funções de manipulação de arquivos
- `relatorio.h` - Funções de relatórios e estatísticas

### Estruturas de Dados

#### Livro
```c
struct Livro {
    int id;
    char titulo[100];
    char autor[100];
    char editora[100];
    char categoria[50];
    int ano_publicacao;
    int quantidade_total;
    int quantidade_disponivel;
    char isbn[20];
    char status[20];
};
```

#### Usuário
```c
struct Usuario {
    int id;
    char nome[100];
    char email[100];
    char telefone[20];
    char endereco[200];
    char tipo[20]; // "estudante", "professor", "funcionario"
    int max_emprestimos;
    int emprestimos_ativos;
    char status[20];
};
```

#### Empréstimo
```c
struct Emprestimo {
    int id;
    int livro_id;
    int usuario_id;
    char data_emprestimo[20];
    char data_devolucao_prevista[20];
    char data_devolucao_real[20];
    float multa;
    char status[20]; // "ativo", "devolvido", "atrasado"
};
```

## Funcionalidades Detalhadas

### 1. Menu Principal
```
=== SISTEMA DE GERENCIAMENTO DE BIBLIOTECA ===

1. Gestão de Livros
2. Gestão de Usuários
3. Gestão de Empréstimos
4. Relatórios e Estatísticas
5. Configurações
0. Sair

Escolha uma opção:
```

### 2. Submenu de Livros
```
=== GESTÃO DE LIVROS ===

1. Cadastrar novo livro
2. Buscar livro
3. Atualizar livro
4. Remover livro
5. Listar todos os livros
6. Relatório de estoque
0. Voltar

Escolha uma opção:
```

### 3. Submenu de Usuários
```
=== GESTÃO DE USUÁRIOS ===

1. Cadastrar novo usuário
2. Buscar usuário
3. Atualizar usuário
4. Remover usuário
5. Listar todos os usuários
6. Histórico de empréstimos
0. Voltar

Escolha uma opção:
```

### 4. Submenu de Empréstimos
```
=== GESTÃO DE EMPRÉSTIMOS ===

1. Realizar empréstimo
2. Processar devolução
3. Renovar empréstimo
4. Listar empréstimos ativos
5. Verificar atrasos
6. Aplicar multas
0. Voltar

Escolha uma opção:
```

### 5. Submenu de Relatórios
```
=== RELATÓRIOS E ESTATÍSTICAS ===

1. Livros mais emprestados
2. Usuários mais ativos
3. Relatório de atrasos
4. Estatísticas gerais
5. Inventário completo
6. Relatório financeiro
0. Voltar

Escolha uma opção:
```

## Recursos Avançados

### 1. Sistema de Busca
- Busca por título (parcial)
- Busca por autor
- Busca por categoria
- Busca por ISBN
- Filtros combinados

### 2. Validações
- Verificação de dados obrigatórios
- Validação de formato de email
- Verificação de ISBN válido
- Controle de limites de empréstimo
- Verificação de disponibilidade

### 3. Sistema de Multas
- Cálculo automático de multas
- Diferentes valores por tipo de usuário
- Histórico de pagamentos
- Relatórios de inadimplência

### 4. Backup e Restauração
- Backup automático dos dados
- Restauração de backup
- Exportação de dados
- Importação de dados

### 5. Log de Operações
- Registro de todas as operações
- Data e hora das transações
- Identificação do usuário do sistema
- Auditoria completa

## Arquivos de Dados

### 1. Arquivos Binários
- `livros.dat` - Dados dos livros
- `usuarios.dat` - Dados dos usuários
- `emprestimos.dat` - Dados dos empréstimos
- `config.dat` - Configurações do sistema

### 2. Arquivos de Texto
- `log.txt` - Log de operações
- `backup.txt` - Backup em formato texto
- `relatorios.txt` - Relatórios exportados

## Exemplos de Uso

### Cadastrando um Livro
```
=== CADASTRAR NOVO LIVRO ===

ID: 1001
Título: O Senhor dos Anéis
Autor: J.R.R. Tolkien
Editora: Martins Fontes
Categoria: Fantasia
Ano de publicação: 1954
Quantidade total: 5
ISBN: 978-8533613379

Livro cadastrado com sucesso!
```

### Realizando um Empréstimo
```
=== REALIZAR EMPRÉSTIMO ===

ID do livro: 1001
ID do usuário: 2001

Verificando disponibilidade...
Livro disponível!

Verificando limite do usuário...
Usuário pode emprestar mais 2 livros.

Empréstimo realizado com sucesso!
Data de devolução: 15/01/2025
```

### Gerando Relatório
```
=== RELATÓRIO DE LIVROS MAIS EMPRESTADOS ===

1. O Senhor dos Anéis - 15 empréstimos
2. Harry Potter - 12 empréstimos
3. O Hobbit - 10 empréstimos
4. 1984 - 8 empréstimos
5. Dom Casmurro - 7 empréstimos

Total de empréstimos: 52
```

## Benefícios do Projeto

### 1. Integração de Conceitos
- Variáveis e tipos de dados
- Estruturas de controle
- Funções e modularização
- Arrays e strings
- Ponteiros e memória
- Estruturas e arquivos

### 2. Desenvolvimento de Habilidades
- Análise de problemas
- Design de sistemas
- Implementação de funcionalidades
- Teste e depuração
- Documentação de código

### 3. Aplicação Prática
- Sistema real e funcional
- Interface de usuário
- Persistência de dados
- Relatórios e estatísticas
- Controle de acesso

## Próximos Passos

Após completar este projeto, você estará preparado para:
- Desenvolver sistemas mais complexos
- Trabalhar com bancos de dados
- Implementar interfaces gráficas
- Criar aplicações web
- Contribuir para projetos open source

## Conclusão

Este projeto final representa a culminação de todo o aprendizado do curso de C básico. Através dele, você demonstra domínio dos conceitos fundamentais e capacidade de aplicá-los em um sistema real e funcional.

O sistema de gerenciamento de biblioteca é apenas um exemplo - você pode adaptar os conceitos aprendidos para criar qualquer tipo de aplicação que desejar!

## Resumo do Curso

### Conceitos Aprendidos
1. **Variáveis e Tipos** - Fundamentos da programação
2. **Estruturas de Controle** - Lógica de programação
3. **Funções** - Modularização e reutilização
4. **Arrays e Strings** - Estruturas de dados básicas
5. **Ponteiros** - Manipulação de memória
6. **Estruturas** - Dados complexos
7. **Arquivos** - Persistência de dados

### Habilidades Desenvolvidas
- Resolução de problemas
- Pensamento algorítmico
- Debugging e teste
- Documentação de código
- Boas práticas de programação

### Próximos Passos
- Cursos avançados de C
- Outras linguagens de programação
- Desenvolvimento de software
- Contribuição para projetos
- Continuar aprendendo!

Parabéns por completar o curso de C básico! 🎉 